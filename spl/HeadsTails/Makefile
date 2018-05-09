.PHONY: all standalone distributed clean 

SPLC_FLAGS ?= --data-directory  -a
SPLC = $(STREAMS_INSTALL)/bin/sc
SPL_CMD_ARGS ?= 
SPL_MAIN_COMPOSITE = HeadsTails

all: distributed

standalone:
	$(SPLC) $(SPLC_FLAGS) -T -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

distributed:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

clean: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE)

submit:
	streamtool submitjob --jobname $(SPL_MAIN_COMPOSITE) output/$(SPL_MAIN_COMPOSITE.sab

cancel:
	streamtool canceljob --jobnames $(SPL_MAIN_COMPOSITE)

