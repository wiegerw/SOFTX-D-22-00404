// Copyright (C) 2023 Maximilian Reininghaus
// Released under MIT License
// license available in LICENSE file, or at
// http://www.opensource.org/licenses/mit-license.php

#include <cstddef>

#include <cnpy++/buffer.hpp>

cnpypp::InMemoryBuffer::InMemoryBuffer(size_t size)
    : buffer{std::make_unique<std::byte[]>(size)} {}

std::byte const* cnpypp::InMemoryBuffer::data() const { return buffer.get(); };

std::byte* cnpypp::InMemoryBuffer::data() {
  return const_cast<std::byte*>(
      static_cast<InMemoryBuffer const&>(*this).data());
}
