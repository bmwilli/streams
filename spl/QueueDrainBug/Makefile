.PHONY: all distributed clean 

SPLC_FLAGS ?= -a
SPLC = $(STREAMS_INSTALL)/bin/sc
SPL_CMD_ARGS ?= 
SPL_MAIN_COMPOSITE1 = TestIngest
SPL_MAIN_COMPOSITE2 = TestBuffer


all: distributed1 distributed2

distributed1:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE1) $(SPL_CMD_ARGS)
distributed2:
	$(SPLC) $(SPLC_FLAGS) -M $(SPL_MAIN_COMPOSITE2) $(SPL_CMD_ARGS)

clean: clean1 clean2
clean1: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE1)
clean2: 
	$(SPLC) $(SPLC_FLAGS) -C -M $(SPL_MAIN_COMPOSITE2)

submit: submit1 submit2
submit1:
	streamtool submitjob --jobname $(SPL_MAIN_COMPOSITE1) output/$(SPL_MAIN_COMPOSITE1).sab
submit2:
	streamtool submitjob --jobname $(SPL_MAIN_COMPOSITE2) output/$(SPL_MAIN_COMPOSITE2).sab

cancel: cancel1 cancel2
cancel1:
	streamtool canceljob --jobnames $(SPL_MAIN_COMPOSITE1)
cancel2:
	streamtool canceljob --jobnames $(SPL_MAIN_COMPOSITE2)
