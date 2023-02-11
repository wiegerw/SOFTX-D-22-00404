// Copyright (C) 2023 Maximilian Reininghaus
// Released under MIT License
// license available in LICENSE file, or at
// http://www.opensource.org/licenses/mit-license.php

#pragma once

#include <cstddef>
#include <iostream>
#include <memory>
#include <string>

namespace cnpypp {

class buffer
{
  protected:
    buffer() = default;

  public:
    virtual ~buffer() = default;
    virtual std::byte* data() = 0;
    [[nodiscard]] virtual std::byte const* data() const = 0;
};

class in_memory_buffer : public buffer
{
  public:
    explicit in_memory_buffer(size_t size)
        : buffer{std::make_unique<std::byte[]>(size)}
    {}

    in_memory_buffer(in_memory_buffer const&) = delete;
    in_memory_buffer(in_memory_buffer&&) = default;
    ~in_memory_buffer() override = default;

    std::byte* data() override
    {
      return buffer.get();
    };

    [[nodiscard]] std::byte const* data() const override
    {
      return const_cast<std::byte*>(static_cast<in_memory_buffer const&>(*this).data());
    }

  private:
    std::unique_ptr<std::byte[]> buffer;
};

} // namespace cnpypp
