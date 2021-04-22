import logging
from streamsx.spl import spl
import streamsx.ec as ec  # Streams execution context

def spl_namespace():
  return "bmwilli.pytoolkit"

@spl.source()
class MySource(object):
  def __init__(self,stop,start=0):
    # Parameters
    self.stop = stop
    self.start = start

    # Instance variables
    self.shutdown = False

    # Logging
    self.log = logging.getLogger("com.ibm.streams.log")
    self.trace = logging.getLogger(__name__)
    

  def __enter__(self):
    # Do any open stuff and create metrics
    self.log.info("*** MySource enter log")
    self.trace.info("*** MySource enter trace")
    self.log.info("*** MySource Log message")
    self.trace.info("*** MySource Trace message")

    self.metric_mycount = ec.CustomMetric(self, "mycount")

  def __iter__(self):
    self.x = self.start
    return self

  def __next__(self):
    if self.shutdown:
      return None

    otuple = {"x":self.x}

    if self.x > self.stop:
      otuple = None
    else:
      self.x +=1
      self.metric_mycount += 1
      self.trace.info("### Just updated self.metric_mycount to: " + str(self.metric_mycount.value))

    return otuple
    

  def next(self):
    return self.__next__() # for python 2

  def __exit__(self, exc_type, exc_value, traceback):
    # Do any close stuff here
    self.trace.debug("*** MySource exiting")
    self.shutdown = True
    pass