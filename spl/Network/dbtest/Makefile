.PHONY: all distributed clean 

SPLC_FLAGS ?= 
SPLC = $(STREAMS_INSTALL)/bin/sc
ST = $(STREAMS_INSTALL)/bin/streamtool
#APP_NAME = DBTest
APP_NAME = DBSample
SPL_MAIN_COMPOSITE = $(APP_NAME)
SPL_FILE_BASE = $(APP_NAME)
SPL_SAB = $(SPL_FILE_BASE).sab
DATA_DIR = /tmp/$(APP_NAME)

SPL_CMD_ARGS ?= --data-directory=$(DATA_DIR) --num-make-threads=4
ST_ARGS ?= -C parallelRegionConfig=channelIsolation 
#SUBMIT_ARGS ?= -P sourceWidth=8
SUBMIT_ARGS ?= 

all: distributed

datadir:
	mkdir -p $(DATA_DIR)
distributed:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE) $(SPL_CMD_ARGS)

clean: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE)

run: datadir
	./output/bin/$(SPL_FILE_BASE) 

submit: datadir
	$(ST) submitjob $(ST_ARGS) output/$(SPL_SAB) --jobname $(APP_NAME) $(SUBMIT_ARGS)


cancel: 
	$(ST) canceljob --jobnames $(APP_NAME)
