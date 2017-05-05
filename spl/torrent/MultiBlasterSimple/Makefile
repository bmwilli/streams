.PHONY: all standalone distributed clean 

SPLC_FLAGS ?= -a -k --data-directory=data
SPLC = $(STREAMS_INSTALL)/bin/sc
SPL_CMD_ARGS ?= 
SPL_MAIN_COMPOSITE = MultiBlast

all: distributed
run: standalone
	output/bin/standalone

standalone:
	$(SPLC) $(SPLC_FLAGS) -T -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

distributed:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

clean: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE)
