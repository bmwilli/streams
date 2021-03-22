# NOTE: This makefile is designed to be run from one level up in the directory
# hierarchy compared to where it resides. For instance, if this makefile is
# located at 'output/build/Makefile', then it can be launched as:
# 'make -f build/Makefile' from the 'output' directory.

SHELL=/bin/bash
ifeq ($(CXX),)
  CXX=g++
endif
ifeq ($(CXX_LN),)
  CXX_LN=g++
endif
PKGCONFIG := /opt/ibm/InfoSphere_Streams/4.3.0.2/bin/dst-pe-pkg-config-alternative.sh
SPL_BUNDLE_BUILDER := /opt/ibm/InfoSphere_Streams/4.3.0.2/system/impl/bin/spl-bundle-builder
SO_INCLUDE := $(shell $(PKGCONFIG) --cflags dst-spl-pe-install)
SO_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install)
SO_STAND_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install-standalone)
SPL_CXXFLAGS = -Wall -Wno-unused -Wno-sign-compare
SPL_CXXFLAGS += -D_REENTRANT -fPIC -finline-functions -fmessage-length=0
SPL_CXXFLAGS += $(SO_INCLUDE) -O3 -DNDEBUG  -std=gnu++98 
SPL_LDFLAGS = $(SO_LIB)

SPL_TYPES = build/type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.o \
            build/type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/Sink.o \
                build/operator/DataFeed/DataFeed.o \
                build/operator/DataFeed/ParserOutput/ParserOutput.o 
SPL_SO_BINS = bin/Sink.so \
              bin/DataFeed.DataFeed.so \
              bin/DataFeed.ParserOutput.ParserOutput.so 

SPL_ADL_FILE = app.Nested1.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/brian/git/bmwilli/streams/spl/NestedParallelism')
SPL_OUTPUT_DIR = $(shell printf '%q' 'output')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone app.Nested1.sab

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.o: \
	    src/type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.h \
	    src/type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring connectionConfig,rstring fname,rstring lnam...string parserConfig>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.cpp

build/type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.o: \
	    src/type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.h \
	    src/type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring connectionConfig,rstring fname,rstring lname,uint64 i>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.cpp

build/type:
	-@mkdir -m 775 build/type

operators: $(SPL_OPERATORS)

-include build/operator/Sink.d
build/operator/Sink.o: \
	    src/operator/Sink.h \
	    src/operator/Sink.cpp\
	    build/dep/operator/Sink.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] Sink'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.2/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"app.Nested1.adl\" -c $(SPL_CXXFLAGS) src/operator/Sink.cpp

-include build/operator/DataFeed/DataFeed.d
build/operator/DataFeed/DataFeed.o: \
	    src/operator/DataFeed/DataFeed.h \
	    src/operator/DataFeed/DataFeed.cpp\
	    build/dep/operator/DataFeed/DataFeed.dep  \
	    build/cppOptions \
	    | build/operator/DataFeed
	@echo ' [CXX-operator] DataFeed.DataFeed'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.2/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"app.Nested1.adl\" -c $(SPL_CXXFLAGS) src/operator/DataFeed/DataFeed.cpp

-include build/operator/DataFeed/ParserOutput/ParserOutput.d
build/operator/DataFeed/ParserOutput/ParserOutput.o: \
	    src/operator/DataFeed/ParserOutput/ParserOutput.h \
	    src/operator/DataFeed/ParserOutput/ParserOutput.cpp\
	    build/dep/operator/DataFeed/ParserOutput/ParserOutput.dep  \
	    build/cppOptions \
	    | build/operator/DataFeed/ParserOutput
	@echo ' [CXX-operator] DataFeed.ParserOutput.ParserOutput'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.2/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"app.Nested1.adl\" -c $(SPL_CXXFLAGS) src/operator/DataFeed/ParserOutput/ParserOutput.cpp

build/operator/DataFeed:
	-@mkdir -m 775 -p build/operator/DataFeed

build/operator:
	-@mkdir -m 775 -p build/operator

build/operator/DataFeed/ParserOutput:
	-@mkdir -m 775 -p build/operator/DataFeed/ParserOutput

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SOSink = \
	    build/operator/Sink.o \
	    build/type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.o 

bin/Sink.so: \
	$(SOSink) \
	build/dep/Sink.so \
	build/ldOptions
	@echo ' [LD-so] so Sink'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/Sink.so -fPIC -shared $(SOSink) $(SPL_LDFLAGS)

SODataFeed.DataFeed = \
	    build/operator/DataFeed/DataFeed.o \
	    build/type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.o 

bin/DataFeed.DataFeed.so: \
	$(SODataFeed.DataFeed) \
	build/dep/DataFeed.DataFeed.so \
	build/ldOptions
	@echo ' [LD-so] so DataFeed.DataFeed'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DataFeed.DataFeed.so -fPIC -shared $(SODataFeed.DataFeed) $(SPL_LDFLAGS)

SODataFeed.ParserOutput.ParserOutput = \
	    build/operator/DataFeed/ParserOutput/ParserOutput.o \
	    build/type/BeJwrMSk2NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpkAF5AOBc.o \
	    build/type/BeJwrMS02NEvOz8tLTS7JzM9zzs9Ly0wvNk3LS8xNLTbNAVGhhpnFhkYFiUXFqUUQeQAbPBQW.o 

bin/DataFeed.ParserOutput.ParserOutput.so: \
	$(SODataFeed.ParserOutput.ParserOutput) \
	build/dep/DataFeed.ParserOutput.ParserOutput.so \
	build/ldOptions
	@echo ' [LD-so] so DataFeed.ParserOutput.ParserOutput'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DataFeed.ParserOutput.ParserOutput.so -fPIC -shared $(SODataFeed.ParserOutput.ParserOutput) $(SPL_LDFLAGS)

standalone: bin/standalone.exe

build/standalone/standalone.o: \
	    src/standalone/standalone.h \
	    src/standalone/standalone.cpp  \
	    build/cppOptions \
	    | build/standalone
	@echo ' [CXX-standalone] standalone'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/standalone/standalone.cpp

bin/standalone.exe: build/standalone/standalone.o build/ldOptions
	@echo ' [LD-standalone] standalone'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/standalone.exe build/standalone/standalone.o $(SO_STAND_LIB)
	@echo ' [LN-standalone] standalone '
	@ln -sf standalone bin/app.Nested1
build/standalone:
	-@mkdir -m 775 build/standalone

sablink:

	@ln -sf ../app.Nested1.sab bin/sab

bundle: app.Nested1.sab

-include build/dep/app.Nested1.sab.d
app.Nested1.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/app.Nested1.sab.d bin/standalone.exe
	@echo ' [Bundle] app.Nested1.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) app.Nested1.sab

