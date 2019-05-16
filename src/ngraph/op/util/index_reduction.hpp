//*****************************************************************************
// Copyright 2017-2019 Intel Corporation
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

#include <memory>
#include <string>
#include <type_traits>
#include <utility>

#include "ngraph/op/op.hpp"

namespace ngraph
{
    template <typename A>
    class Attribute
    {
        template <typename C, typename V>
        static V value_helper(V C::*);
        template <typename C, typename V>
        static C class_helper(V C::*);

        static A v_helper;

    public:
        Attribute(const std::string& name, A ptr)
            : m_name(name)
            , m_ptr(ptr)
        {
        }
        using value_type = decltype(value_helper(v_helper));
        using class_type = decltype(class_helper(v_helper));

        template <typename T>
        value_type get_value(T ths)
        {
            return ths->*m_ptr;
        }
        std::string m_name;
        A m_ptr;
    };
    namespace op
    {
        namespace util
        {
            class IndexReduction : public Op
            {
                template <typename A>
                A get_attribute(A& attr)
                {
                    return attr;
                }

                template <typename A>
                typename A::value_type get_attribute(A& attr) const
                {
                    return attr.get_value(this);
                }

                template <typename A, typename V>
                void set_attribute(A& attr, V value)
                {
                    //notify_changed();
                    attr = value;
                }

            public:
                size_t get_reduction_axis() const { return get_attribute(axis_attr); }
                void set_reduction_axis(size_t value) { set_attribute(m_axis, value); }
                /// \brief Change the reduction axes

                element::Type get_index_element_type() const { return m_index_element_type; }
                void set_index_element_type(element::Type& index_element_type);
                IndexReduction();
                IndexReduction(const std::shared_ptr<Node>& arg,
                               size_t axis,
                               const element::Type& index_element_type);

                IndexReduction(const std::string& node_type,
                               const std::shared_ptr<Node>& arg,
                               size_t axis,
                               const element::Type& index_element_type);

            protected:
                size_t m_axis;
                element::Type m_index_element_type;

                static Attribute<decltype(&IndexReduction::m_axis)> axis_attr;

                void validate_and_infer_types() override;
                virtual void generate_adjoints(autodiff::Adjoints& adjoints,
                                               const NodeVector& deltas) override;
            };
        }
    }
}
