.PHONY: all clean composite

impl:
	make -C ./impl

clean_impl:
	make clean -C ./impl

composite:
	sc -M com.acme.test::JavaNativeFunctions

all: impl composite

clean: clean_impl;
	sc -C -M com.acme.test::JavaNativeFunctions
