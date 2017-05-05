#!/bin/bash -x

rm -f data/*

for test in Blaster BlasterRelay; do
  for trans in tcp tor; do
    streamtool lsjobs -i $trans | grep Running | awk '{print $1}' | xargs -r streamtool canceljob -i $trans
    s=16
    while [ $s -le 16777216 ]; do
      for i in $(seq 0 2); do
        sed "s/REPLACEME/$s/g" $test.spl.template > $test.spl
        make
#        streamtool submitjob -i $trans -C fusionScheme=legacy output/$test.sab
        streamtool submitjob -i $trans output/$test.sab
        while [ ! -s data/$test.txt ]; do
          sleep 3
        done
        mv data/$test.txt data/${test}_${trans}_${s}_${i}.txt
        streamtool lsjobs -i $trans | grep Running | awk '{print $1}' | xargs streamtool canceljob -i $trans
      done
      (( s *= 2 ))
    done
  done
done
