.PHONY: debug configure release clean all

debug:
	./waf build

configure:
	./waf configure

release:
	./waf build_release

clean:
	./waf distclean

all: clean configure
	./waf build --alltest
	./waf release --alltest
