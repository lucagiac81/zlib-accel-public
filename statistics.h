#pragma once

#include <atomic>
#include <sstream>

#ifdef ENABLE_STATISTICS
#define INCREMENT_STAT(stat) stats["stat"]++
#define INCREMENT_STAT_COND(stat, cond) if (cond) stats["stat"]++
#else
#define INCREMENT_STAT(stat)
#define INCREMENT_STAT_COND(stat, cond)
#endif

std::map<std::string, std::atomic<uint64_t>> stats = {
  {"deflate_count", 0},
  {"deflate_iaa_count", 0},
  {"deflate_qat_count", 0},
  {"deflate_zlib_count", 0},
  {"deflate_error_count", 0},
  {"deflate_iaa_error_count", 0},
  {"deflate_qat_error_count", 0},
};

std::string PrintStatistics() {
  std::stringstream printedStats;
  for (const auto& pair : stats) {
    printedStats << pair.first << " = " << pair.second << std::endl;
  }
  return printedStats.str();
}




