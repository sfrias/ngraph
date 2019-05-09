//*****************************************************************************
// Copyright 2018-2019 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#pragma once

#include "ngraph/coordinate_diff.hpp"
#include "ngraph/node.hpp"

namespace ngraph
{
    namespace builder
    {
        namespace quantization
        {
            std::shared_ptr<Node> QuantizedLinearMatmul(std::shared_ptr<Node> input,
                                                        std::shared_ptr<Node> filter,
                                                        std::shared_ptr<Node> input_scale,
                                                        std::shared_ptr<Node> input_zero_point,
                                                        std::shared_ptr<Node> filter_scale,
                                                        std::shared_ptr<Node> filter_zero_point,
                                                        std::shared_ptr<Node> output_scale,
                                                        std::shared_ptr<Node> output_zero_point);

            std::shared_ptr<Node> QuantizedLinearMatmulInteger(std::shared_ptr<Node> input,
                                                               std::shared_ptr<Node> filter);
        }
    }
}
