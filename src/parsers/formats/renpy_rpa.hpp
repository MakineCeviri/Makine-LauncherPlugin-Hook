/**
 * @file renpy_rpa.hpp
 * @brief Ren'Py RPA archive format structures
 * @copyright (c) 2026 Makine Team
 */

#pragma once

#include "makine/error.hpp"
#include "makine/types.hpp"

#include <cstdint>
#include <string>
#include <vector>

namespace makine::formats {

enum class RpaVersion {
    V2,
    V3,
};

struct RpaHeader {
    RpaVersion version = RpaVersion::V3;
    uint64_t indexOffset = 0;
    uint64_t xorKey = 0;
};

struct RpaIndexEntry {
    std::string path;
    uint64_t dataOffset = 0;
    uint64_t dataLength = 0;
    std::vector<uint8_t> prefix;
};

struct RpaArchive {
    RpaHeader header;
    std::vector<RpaIndexEntry> entries;
};

// Public API
[[nodiscard]] Result<RpaArchive> parseRpaArchive(const fs::path& rpaPath);

[[nodiscard]] Result<std::vector<uint8_t>> extractRpaEntry(
    const fs::path& rpaPath,
    const RpaIndexEntry& entry
);

} // namespace makine::formats
