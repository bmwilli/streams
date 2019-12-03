.PHONY: all distributed clean 

SPLC_FLAGS ?= 
SPLC = $(STREAMS_INSTALL)/bin/sc
ST = $(STREAMS_INSTALL)/bin/streamtool
SPL_NAMESPACE = network.apps
APP_NAME = IpfixIngest
SPL_MAIN_COMPOSITE = $(SPL_NAMESPACE)::$(APP_NAME)
SPL_FILE_BASE = $(SPL_NAMESPACE).$(APP_NAME)
SPL_SAB = $(SPL_FILE_BASE).sab
DATA_DIR = /tmp/$(SPL_NAMESPACE)/$(APP_NAME)

SPL_CMD_ARGS ?= --data-directory=$(DATA_DIR) --num-make-threads=4
ST_ARGS ?= -C parallelRegionConfig=channelIsolation 
SUBMIT_ARGS ?= -P sourceWidth=8

all: distributed

datadir:
	mkdir -p $(DATA_DIR)
distributed:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

clean: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE)

run: datadir
	./output/bin/$(SPL_FILE_BASE) pcapDirectory=/ibm/NETWORK_DATA/ingest sourceWidth=1 
	#./output/bin/$(SPL_FILE_BASE) pcapDirectory=/ibm/STREAMS_INSTALL/singlePCAP

submit: datadir
	$(ST) submitjob $(ST_ARGS) output/$(SPL_SAB) --jobname $(APP_NAME) $(SUBMIT_ARGS)


cancel: 
	$(ST) canceljob --jobnames $(APP_NAME)
