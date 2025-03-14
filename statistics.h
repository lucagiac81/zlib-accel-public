#pragma once

#ifdef ENABLE_STATISTICS
#define INCREMENT_STAT(stat) stats["stat"]++
#define INCREMENT_STAT_COND(cond, stat) if (cond) stats["stat"]++
#define PRINT_STATS PrintStatistics()
#else
#define INCREMENT_STAT(stat)
#define INCREMENT_STAT_COND(cond, stat)
#define PRINT_STATS
#endif

#ifdef ENABLE_STATISTICS
#include <atomic>
#include <map>
#include <sstream>

#include "logging.h"

thread_local std::map<std::string, uint64_t> stats = {
  {"deflate_count", 0},
  {"deflate_error_count", 0},
  {"deflate_qat_count", 0},
  {"deflate_qat_error_count", 0},
  {"deflate_iaa_count", 0},
  {"deflate_iaa_error_count", 0},
  {"deflate_zlib_count", 0},

  {"inflate_count", 0},
  {"inflate_error_count", 0},
  {"inflate_qat_count", 0},
  {"inflate_qat_error_count", 0},
  {"inflate_iaa_count", 0},
  {"inflate_iaa_error_count", 0},
  {"inflate_zlib_count", 0}
};

void PrintStatistics() {
  std::stringstream printedStats;
  for (const auto& pair : stats) {
    printedStats << pair.first << " = " << pair.second << std::endl;
  }
  Log(LogLevel::LOG_STATS, printedStats.str().c_str());
}
#endif



