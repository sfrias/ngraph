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

#include <memory>

#include "ngraph/runtime/cpu/cpu_aligned_buffer.hpp"
#include "ngraph/runtime/cpu/cpu_mkl_allocator.hpp"
#include "ngraph/util.hpp"

using namespace ngraph;

runtime::cpu::CPUAlignedBuffer::CPUAlignedBuffer(size_t byte_size,
                                                 size_t alignment,
                                                 ngraph::runtime::cpu::CPUAllocator* cpu_allocator)
{
    m_byte_size = byte_size;
    m_cpu_allocator = cpu_allocator;
    if (m_byte_size > 0)
    {
        size_t allocation_size = m_byte_size + alignment;
        m_allocated_buffer = static_cast<char*>(m_cpu_allocator->malloc(allocation_size));
        m_aligned_buffer = m_allocated_buffer;
        size_t mod = size_t(m_aligned_buffer) % alignment;

        if (mod != 0)
        {
            m_aligned_buffer += (alignment - mod);
        }
    }
    else
    {
        m_allocated_buffer = nullptr;
        m_aligned_buffer = nullptr;
    }
}

runtime::cpu::CPUAlignedBuffer::~CPUAlignedBuffer()
{
    if (m_allocated_buffer != nullptr)
    {
        m_cpu_allocator->free(m_allocated_buffer);
    }
}
