/*
 * Copyright (c) 2023, stelar7 <dudedbz@gmail.com>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibCrypto/Authentication/HMAC.h>
#include <LibCrypto/Hash/PBKDF2.h>
#include <LibCrypto/Hash/SHA1.h>
#include <LibCrypto/Hash/SHA2.h>
#include <LibTest/TestCase.h>

// https://www.rfc-editor.org/rfc/rfc6070#section-2
TEST_CASE(test_vector_1_sha1)
{
    Array<u8, 8> const password {
        0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64
    };
    Array<u8, 4> const salt {
        0x73, 0x61, 0x6c, 0x74
    };
    Array<u8, 20> const expected {
        0x0c, 0x60, 0xc8, 0x0f, 0x96, 0x1f, 0x0e, 0x71,
        0xf3, 0xa9, 0xb5, 0x24, 0xaf, 0x60, 0x12, 0x06,
        0x2f, 0xe0, 0x37, 0xa6
    };
    u32 iterations = 1;
    u32 derived_key_length_bytes = 20;

    auto result = MUST(Crypto::Hash::PBKDF2::derive_key<Crypto::Authentication::HMAC<Crypto::Hash::SHA1>>(password, salt, iterations, derived_key_length_bytes));

    EXPECT_EQ(result, expected.span());
}

TEST_CASE(test_vector_2_sha1)
{
    Array<u8, 8> const password {
        0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64
    };
    Array<u8, 4> const salt {
        0x73, 0x61, 0x6c, 0x74
    };
    Array<u8, 20> const expected {
        0xea, 0x6c, 0x01, 0x4d, 0xc7, 0x2d, 0x6f, 0x8c,
        0xcd, 0x1e, 0xd9, 0x2a, 0xce, 0x1d, 0x41, 0xf0,
        0xd8, 0xde, 0x89, 0x57
    };
    u32 iterations = 2;
    u32 derived_key_length_bytes = 20;

    auto result = MUST(Crypto::Hash::PBKDF2::derive_key<Crypto::Authentication::HMAC<Crypto::Hash::SHA1>>(password, salt, iterations, derived_key_length_bytes));

    EXPECT_EQ(result, expected.span());
}

TEST_CASE(test_vector_1_sha256)
{
    Array<u8, 8> const password {
        0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64
    };
    Array<u8, 4> const salt {
        0x73, 0x61, 0x6c, 0x74
    };
    Array<u8, 20> const expected {
        0x12, 0x0f, 0xb6, 0xcf, 0xfc, 0xf8, 0xb3, 0x2c,
        0x43, 0xe7, 0x22, 0x52, 0x56, 0xc4, 0xf8, 0x37,
        0xa8, 0x65, 0x48, 0xc9
    };
    u32 iterations = 1;
    u32 derived_key_length_bytes = 20;

    auto result = MUST(Crypto::Hash::PBKDF2::derive_key<Crypto::Authentication::HMAC<Crypto::Hash::SHA256>>(password, salt, iterations, derived_key_length_bytes));

    EXPECT_EQ(result, expected.span());
}

TEST_CASE(test_vector_2_sha256)
{
    Array<u8, 8> const password {
        0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64
    };
    Array<u8, 4> const salt {
        0x73, 0x61, 0x6c, 0x74
    };
    Array<u8, 20> const expected {
        0xae, 0x4d, 0x0c, 0x95, 0xaf, 0x6b, 0x46, 0xd3,
        0x2d, 0x0a, 0xdf, 0xf9, 0x28, 0xf0, 0x6d, 0xd0,
        0x2a, 0x30, 0x3f, 0x8e
    };
    u32 iterations = 2;
    u32 derived_key_length_bytes = 20;

    auto result = MUST(Crypto::Hash::PBKDF2::derive_key<Crypto::Authentication::HMAC<Crypto::Hash::SHA256>>(password, salt, iterations, derived_key_length_bytes));

    EXPECT_EQ(result, expected.span());
}

TEST_CASE(test_vector_3_sha256)
{
    Array<u8, 8> const password {
        0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64
    };
    Array<u8, 4> const salt {
        0x73, 0x61, 0x6c, 0x74
    };
    Array<u8, 20> const expected {
        0xc5, 0xe4, 0x78, 0xd5, 0x92, 0x88, 0xc8, 0x41,
        0xaa, 0x53, 0x0d, 0xb6, 0x84, 0x5c, 0x4c, 0x8d,
        0x96, 0x28, 0x93, 0xa0
    };
    u32 iterations = 4096;
    u32 derived_key_length_bytes = 20;

    auto result = MUST(Crypto::Hash::PBKDF2::derive_key<Crypto::Authentication::HMAC<Crypto::Hash::SHA256>>(password, salt, iterations, derived_key_length_bytes));

    EXPECT_EQ(result, expected.span());
}

TEST_CASE(test_vector_4_sha256)
{
    Array<u8, 24> const password {
        0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64,
        0x50, 0x41, 0x53, 0x53, 0x57, 0x4f, 0x52, 0x44,
        0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64
    };
    Array<u8, 36> const salt {
        0x73, 0x61, 0x6c, 0x74, 0x53, 0x41, 0x4c, 0x54,
        0x73, 0x61, 0x6c, 0x74, 0x53, 0x41, 0x4c, 0x54,
        0x73, 0x61, 0x6c, 0x74, 0x53, 0x41, 0x4c, 0x54,
        0x73, 0x61, 0x6c, 0x74, 0x53, 0x41, 0x4c, 0x54,
        0x73, 0x61, 0x6c, 0x74
    };
    Array<u8, 25> const expected {
        0x34, 0x8c, 0x89, 0xdb, 0xcb, 0xd3, 0x2b, 0x2f,
        0x32, 0xd8, 0x14, 0xb8, 0x11, 0x6e, 0x84, 0xcf,
        0x2b, 0x17, 0x34, 0x7e, 0xbc, 0x18, 0x00, 0x18,
        0x1c
    };
    u32 iterations = 4096;
    u32 derived_key_length_bytes = 25;

    auto result = MUST(Crypto::Hash::PBKDF2::derive_key<Crypto::Authentication::HMAC<Crypto::Hash::SHA256>>(password, salt, iterations, derived_key_length_bytes));

    EXPECT_EQ(result, expected.span());
}

TEST_CASE(test_vector_5_sha256)
{
    Array<u8, 9> const password {
        0x70, 0x61, 0x73, 0x73, 0x00, 0x77, 0x6f, 0x72,
        0x64
    };
    Array<u8, 5> const salt {
        0x73, 0x61, 0x00, 0x6c, 0x74
    };
    Array<u8, 16> const expected {
        0x89, 0xb6, 0x9d, 0x05, 0x16, 0xf8, 0x29, 0x89,
        0x3c, 0x69, 0x62, 0x26, 0x65, 0x0a, 0x86, 0x87
    };
    u32 iterations = 4096;
    u32 derived_key_length_bytes = 16;

    auto result = MUST(Crypto::Hash::PBKDF2::derive_key<Crypto::Authentication::HMAC<Crypto::Hash::SHA256>>(password, salt, iterations, derived_key_length_bytes));

    EXPECT_EQ(result, expected.span());
}