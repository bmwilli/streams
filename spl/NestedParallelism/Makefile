.PHONY: all standalone distributed clean submit

SPLC_FLAGS ?= --data-directory  -a
SPLC = $(STREAMS_INSTALL)/bin/sc
SPL_CMD_ARGS ?= 
BASE_NAME = Nested1
#BASE_NAME = Nested2
NAMESPACE = app
SPL_MAIN_COMPOSITE = $(NAMESPACE)::$(BASE_NAME)
SAB_FILE = $(NAMESPACE).$(BASE_NAME)

all: distributed

standalone:
	$(SPLC) $(SPLC_FLAGS) -T -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

distributed:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

clean: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE)

submit:
	streamtool submitjob --jobname $(SPL_MAIN_COMPOSITE) output/$(SAB_FILE).sab \
		-P connectionConfigList="Connection0","Connection1","Connection2" -P connectionCount=3 \
	  -P parserCount=2 \
	  -P parserConfigList="[['A','B'],['C','D'],['E','F']]" \
	  -g Nested1_config.json

preview:
	streamtool submitjob --preview --jobname $(SPL_MAIN_COMPOSITE) output/$(SAB_FILE).sab \
		-P connectionConfigList="Connection0","Connection1","Connection2" -P connectionCount=3 \
	  -P parserCount=2 \
	  -P parserConfigList="[['A','B'],['C','D'],['E','F']]" \
	  -g Nested1_config.json

cancel:
	streamtool canceljob --jobnames $(SPL_MAIN_COMPOSITE)
