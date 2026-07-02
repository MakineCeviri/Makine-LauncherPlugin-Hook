// SPDX-License-Identifier: AGPL-3.0-only
// Copyright (c) 2026 Makine Çeviri. Commons Clause applies — see LICENSE.

#pragma once

#include <string>
#include <expected>

namespace makine {

enum class ErrorCode {
    OK = 0,
    FileNotFound,
    FileAccessDenied,
    InvalidFormat,
    InvalidArgument,
    InvalidOffset,
    ParseError,
    DecompressionFailed,
    NotSupported,
    NotImplemented,
    UnsupportedVersion,
    NetworkError,
    IOError,
    Unknown,
};

struct Error {
    ErrorCode code;
    std::string message;

    Error(ErrorCode c, std::string msg) : code(c), message(std::move(msg)) {}
};

template<typename T>
using Result = std::expected<T, Error>;

using VoidResult = std::expected<void, Error>;

} // namespace makine
