// SPDX-License-Identifier: AGPL-3.0-only
// Copyright (c) 2026 Makine Çeviri. Commons Clause applies — see LICENSE.

#pragma once

#include <string>

namespace makine {

class Metrics {
public:
    static Metrics& instance() { static Metrics m; return m; }

    struct Timer { ~Timer() = default; };
    Timer timer(const char*) { return {}; }
    void increment(const char*) {}
};

} // namespace makine
