.. guides/index:


#######
Guides
#######

From concept to production to scale:  Where to get started? 

Framework Users
===============

Application developers already familiar with popular :abbr:`(DL) Deep Learning` 
frameworks can get started quickly by following the integration guide below for 
a respective framework. This is a great place to begin if you are investigating 
different kinds of previously-tested examples to adapt. See :
doc:`frameworks/validated/list` for some examples we've tested. 

.. toctree::
   :maxdepth: 1

   tensorflow_integ.rst
   mxnet_integ.rst
   paddle_integ.rst
   onnx_integ.rst



Framework Developers
====================

Programs designed for :abbr:`ASIC (Application-Specific Integrated Circuits)` 
may need to gather very specific data from a specific environment and have limited 
resources in terms of memory, battery life, or bandwidth. Application developers 
working on highly customized / customizable solutions such as these may want to 
begin with a more lightweight framework, one less widely-supported than the popular 
options above. Prototyping can be done easily with your CPU, and when your application 
is ready to deploy, it will stay performant thanks to transformers handled by Intel® 
Architecture (IA).

The following articles may also be helpful:

.. toctree::
   :maxdepth: 1

   ../frameworks/index.rst
   ../frameworks/validated/list.rst
   ../frameworks/generic-configs.rst


Infrastructure Admins
=====================

*  Datacenter administrators seeking to optimize performance for existing training or 
   inference workloads on frameworks running within their network can get started by 
   reading up on nGraph's :term:`bridge` documentation and seeing how various 
   :doc:`../framework/index` implement a bridge. Tuning a workload  

