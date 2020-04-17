.PHONY: all distributed clean 

SPLC_FLAGS ?= 
SPLC = $(STREAMS_INSTALL)/bin/sc
#SPL_CMD_ARGS ?= -t ${STREAMS_INSTALL}/toolkits
#SPL_CMD_ARGS ?= -t /opt/ibm/toolkits
SPL_CMD_ARGS ?= -t ${HOME}/git/bmwilli/streamsx.jdbc
SPL_MAIN_COMPOSITE = Mytest

all: distributed

distributed:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

clean: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE)

