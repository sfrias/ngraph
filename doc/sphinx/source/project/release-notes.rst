.. ngraph/release-notes:

Release Notes
#############

The latest |version| download below:

* `Format .zip`_ 
* `Format tar.gz`_ 

See also: https://github.com/NervanaSystems/ngraph/releases for previous versions. 


CHANGELOG |release|
===================

nGraph 0.18.1
--------------

+ Work-around for ``mkl-dnn`` 
+ Event tracing improvements
+ Gaussian error function
+ Begin tracking framework node names
+ ONNX quantization
+ More fusions
+ Fixes reference convolution accumulation bug


nGraph v0.17.0
--------------

+ Allow negative padding in more places
+ Add code generation for some quantized ops
+ Preliminary dynamic shape support
+ Initial distributed ops
+ **API Change** -- ``Pad`` op takes ``CoordinateDiff`` instead of ``Shape`` pad values to allow for negative padding.


nGraph v0.16.0
--------------

+ ``NodeInput`` and ``NodeOutput`` classes prepare for simplifications of ``Node``
+ Test improvements
+ Additional quantization ops
+ Performance improvements
+ Fix memory leak
+ Concat optimization
+ Doc updates


.. _Format .zip: https://github.com/NervanaSystems/ngraph/archive/v0.18.1-rc.0.zip
.. _Format tar.gz: https://github.com/NervanaSystems/ngraph/archive/v0.18.1-rc.0.tar.gz