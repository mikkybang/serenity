/*
 * Copyright (c) 2021, Ali Mohammad Pur <mpfard@serenityos.org>
 * Copyright (c) 2023, Tim Flynn <trflynn89@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/Optional.h>
#include <LibJS/Forward.h>
#include <LibJS/Heap/GCPtr.h>
#include <LibJS/Runtime/ArrayBuffer.h>
#include <LibWasm/AbstractMachine/AbstractMachine.h>
#include <LibWeb/Bindings/ExceptionOrUtils.h>
#include <LibWeb/Bindings/PlatformObject.h>

namespace Web::WebAssembly {

struct MemoryDescriptor {
    u32 initial { 0 };
    Optional<u32> maximum;
};

class Memory : public Bindings::PlatformObject {
    WEB_PLATFORM_OBJECT(Memory, Bindings::PlatformObject);

public:
    static WebIDL::ExceptionOr<JS::NonnullGCPtr<Memory>> construct_impl(JS::Realm&, MemoryDescriptor& descriptor);

    WebIDL::ExceptionOr<u32> grow(u32 delta);
    WebIDL::ExceptionOr<JS::NonnullGCPtr<JS::ArrayBuffer>> buffer() const;

    Wasm::MemoryAddress address() const { return m_address; }

private:
    Memory(JS::Realm&, Wasm::MemoryAddress);

    virtual JS::ThrowCompletionOr<void> initialize(JS::Realm&) override;

    Wasm::MemoryAddress m_address;
};

}