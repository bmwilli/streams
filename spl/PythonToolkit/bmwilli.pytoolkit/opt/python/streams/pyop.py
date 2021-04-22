import logging
from streamsx.spl import spl
import streamsx.ec as ec  # Streams execution context

def spl_namespace():
  return "bmwilli.pytoolkit"

@spl.primitive_operator(output_ports=['MODIFIED', 'ORIGINAL'])
class MyOperator(spl.PrimitiveOperator):
  def __init__(self, multiplier=2):

    # Parameters
    self.multiplier = multiplier

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


  # Take in the attribute we care about
  @spl.input_port(style='position')
  def data(self, x, *otherargs_):
  #def data(self, x):
    #self.trace.info("+++ Received data x: " + str(x) + ", otherargs: " + otherargs_)
    newvalue = x * self.multiplier
    # sum function concatenates python tuple values
    self.submit('ORIGINAL',(x,) + otherargs_)
    self.submit('MODIFIED',(x*self.multiplier,) + otherargs_)
    #self.submit('ORIGINAL',(x,))
    #self.submit('MODIFIED',(x*self.multiplier,))

  # Using dictionary tuple
  @spl.input_port(style='position')
  def changeMultiplier(self, multiplier):
    self.trace.info("### Received change to mulitplier: " + str(multiplier))
    self.multiplier = multiplier



  def __exit__(self, exc_type, exc_value, traceback):
    # Do any close stuff here
    self.trace.debug("*** MyOperator exiting")
    self.shutdown = True
    pass