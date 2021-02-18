.PHONY: all clean

LIBS:=${STREAMS_INSTALL}/lib/com.ibm.streams.operator.jar
LIBS:=${LIBS}:../opt/myjlib.jar

all:
	mkdir -p java/bin
	find java/src -name *.java | xargs javac -cp ${LIBS} -d java/bin

clean:
	rm -rf java/bin/*
	find java/src -name *StreamsModel.java | xargs rm -f
