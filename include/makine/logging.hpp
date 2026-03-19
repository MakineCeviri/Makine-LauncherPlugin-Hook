#pragma once

#include <cstdio>

namespace makine::log {
    constexpr const char* PARSER = "parser";
    constexpr const char* MEMORY = "memory";
    constexpr const char* HOOK   = "hook";
} // namespace makine::log

#ifdef MAKINE_DEBUG_LOG
  #define MAKINE_LOG_DEBUG(cat, fmt, ...) \
      std::fprintf(stderr, "[DEBUG][%s] " fmt "\n", cat, ##__VA_ARGS__)
  #define MAKINE_LOG_INFO(cat, fmt, ...) \
      std::fprintf(stderr, "[INFO][%s] " fmt "\n", cat, ##__VA_ARGS__)
  #define MAKINE_LOG_WARN(cat, fmt, ...) \
      std::fprintf(stderr, "[WARN][%s] " fmt "\n", cat, ##__VA_ARGS__)
  #define MAKINE_LOG_ERROR(cat, fmt, ...) \
      std::fprintf(stderr, "[ERROR][%s] " fmt "\n", cat, ##__VA_ARGS__)
#else
  #define MAKINE_LOG_DEBUG(cat, fmt, ...) ((void)0)
  #define MAKINE_LOG_INFO(cat, fmt, ...)  ((void)0)
  #define MAKINE_LOG_WARN(cat, fmt, ...)  ((void)0)
  #define MAKINE_LOG_ERROR(cat, fmt, ...) ((void)0)
#endif
