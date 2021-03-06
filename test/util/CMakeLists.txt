# ******************************************************************************
# Copyright 2017-2019 Intel Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ******************************************************************************

set (SRC
    autodiff/backprop_function.cpp
    all_close_f.cpp
    float_util.cpp
    test_tools.cpp
    test_control.cpp
    test_case.cpp
)

add_library(ngraph_test_util STATIC ${SRC})
if(NGRAPH_LIB_VERSIONING_ENABLE)
    set_target_properties(ngraph_test_util PROPERTIES
        VERSION ${NGRAPH_VERSION})
endif()
target_include_directories(ngraph_test_util PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_link_libraries(ngraph_test_util ngraph libgtest)

install(TARGETS ngraph_test_util DESTINATION ${NGRAPH_INSTALL_LIB})
