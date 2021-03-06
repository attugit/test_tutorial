#! /usr/bin/env python
# encoding: utf-8

VERSION='0.0.1'
APPNAME='example'

top = '.'
out = 'build'
flags = [
  '-std=c++11',
  '-Wall',
  '-Wextra',
  '-Wshadow',
  '-Wunused',
  '-pedantic',
  '-pedantic-errors',
  '-Werror'
]

def options(opt):
  opt.load('compiler_cxx')
  opt.load('boost')
  opt.load('sproc')
  opt.load('waf_unit_test')

def configure(conf):
  conf.setenv('base')
  conf.load('waf_unit_test')
  conf.define('APPNAME', APPNAME)
  conf.define('VERSION', VERSION)
  conf.load('compiler_cxx')
  conf.load('boost')
  conf.check_boost()
  conf.load('sproc')
  conf.env.CXXFLAGS += flags
  for variant in ['debug', 'release', 'coverage']:
    conf.setenv('base')
    newenv = conf.env.derive()
    newenv.detach()
    conf.setenv(variant, newenv)

  conf.setenv('debug')
  conf.env.CXXFLAGS += ['-g', '-O0']
  conf.env.DEFINES += ['DEBUG']

  conf.setenv('coverage')
  conf.env.CXXFLAGS += ['-g', '-O0', '-fprofile-arcs', '-ftest-coverage', '-pg']
  conf.env.DEFINES += ['NDEBUG']
  conf.env.LIB += ['gcov']
  conf.env.LINKFLAGS += ['-pg']

  conf.setenv('release')
  conf.env.CXXFLAGS += ['-O3', '-march=native', '-fPIC', '-fno-rtti']
  conf.env.DEFINES += ['NDEBUG']

import os
from waflib.Tools import waf_unit_test
def build(bld):
  if not bld.variant:
    bld.fatal('try "waf --help"')
  bld.env.INCLUDES += ['.', bld.bldnode.abspath()]
  bld(
    source       = bld.path.ant_glob(['src/**/*.cpp']),
    target       = 'SOURCE',
    features     = 'cxx',
    install_path = None,
  )
  bld(
    source       = bld.path.ant_glob(['src/**/*.sproc']),
    target       = 'GENERATED',
    features     = 'cxx',
    install_path = None,
  )
  bld.env.INCLUDES += ['gtest', 'gtest/include']
  bld(
    source       = bld.path.ant_glob(['gtest/src/gtest-all.cc', 'gtest/src/gtest_main.cc']),
    target       = 'GTEST',
    features     = 'cxx',
    install_path = None,
  )
  bld.env.INCLUDES += ['gmock', 'gmock/include']
  bld(
    source       = bld.path.ant_glob(['gmock/src/gmock-all.cc']),
    target       = 'GMOCK',
    features     = 'cxx',
    install_path = None,
  )
  bld.env.LIB += ['pthread']
  for suite in os.listdir('./test'):
    if 'ignore' not in suite and os.path.isdir(os.path.join('./test', suite)):
      bld(
        source       = bld.path.ant_glob(['test/%s/**/*.cpp'%suite]),
        target       = 'ut_' + str(suite),
        features     = 'cxx cxxprogram test',
        use          = ['SOURCE', 'GENERATED', 'GTEST', 'GMOCK'],
        install_path = None,
      )
  bld.add_post_fun(waf_unit_test.summary)
  bld.add_post_fun(waf_unit_test.set_exit_code)


from waflib.Build import BuildContext
from waflib.Build import CleanContext
from waflib.Build import InstallContext
from waflib.Build import UninstallContext

for ctx in (BuildContext, CleanContext, InstallContext, UninstallContext):
  name = ctx.__name__.replace('Context','').lower()
  class debug(ctx):
    cmd = name
    variant = 'debug'
  class release(ctx):
    cmd = name + '_release'
    variant = 'release'
  class coverage(ctx):
    cmd = name + '_coverage'
    variant = 'coverage'
