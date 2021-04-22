TOOLKIT:=bmwilli.pytoolkit
TOOLKIT_SAMPLES:=${TOOLKIT}.samples
.phony: all toolkit impl doc copysamples clean cleancheckin

all: toolkit impl doc

pythonpackages:
	# pip3 install xxxxxx -t opt/python/packages
	pip3 install future -t opt/python/packages
	pip3 install dill -t opt/python/packages

toolkit: impl python
	spl-make-toolkit -m -i . || exit 1

doc:
	spl-make-doc -i . || exit 1

python:
	if [ -d opt/python/streams ]; then \
	make pythonpackages; \
	python3 $(STREAMS_INSTALL)/toolkits/com.ibm.streamsx.topology/bin/spl-python-extract.py -i .; \
	fi

impl:
	if [ -f impl/Makefile ]; then make -C impl; fi

cleancheckin: clean
	rm -f etc/toolkit.vim
	rm -fr doc
	rm -fr samples
	rm -fr opt/python/packages
	rm -fr opt/.splpy
	rm -fr impl/nl

clean:
	spl-make-toolkit -c -i .
	if [ -f impl/Makefile ]; then make -C impl clean; fi

copysamples:
	-rm -fr samples
	-mkdir samples
	cp -r ../${TOOLKIT_SAMPLES}/* samples || exit 0
	make -C samples clean || exit 0

