#!/usr/bin/env python
# encoding: utf-8

from waflib.Task import Task
from waflib.TaskGen import extension 

class sproc(Task):
	# protoc expects the input proto file to be an absolute path.
	run_str = '${SPROC} ${SRC[0].abspath()} -c ${TGT[0].abspath()} -H ${TGT[1].abspath()}'
	color   = 'BLUE'
	ext_out = ['.h', '.cpp']

@extension('.sproc')
def process_sproc(self, node):
	cpp_node = node.change_ext('.cpp')
	hpp_node = node.change_ext('.h')
	self.create_task('sproc', node, [cpp_node, hpp_node])
	self.source.append(cpp_node)

def configure(conf):
	conf.find_program('sproc', var='SPROC')

