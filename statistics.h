#pragma once

#ifdef ENABLE_STATISTICS
#define INCREMENT_STAT(stat) stats[stat]++
#define INCREMENT_STAT_COND(cond, stat) if (cond) stats[stat]++
#else
#define INCREMENT_STAT(stat)
#define INCREMENT_STAT_COND(cond, stat)
#endif

#ifdef ENABLE_STATISTICS
#include <atomic>
#include <map>
#include <sstream>

#include "logging.h"

enum Statistics {
	DEFLATE_COUNT = 0,
	DEFLATE_ERROR_COUNT,
	DEFLATE_QAT_COUNT,
	DEFLATE_QAT_ERROR_COUNT,
	DEFLATE_IAA_COUNT,
	DEFLATE_IAA_ERROR_COUNT,
	DEFLATE_ZLIB_COUNT,

    INFLATE_COUNT,
	INFLATE_ERROR_COUNT,
	INFLATE_QAT_COUNT,
	INFLATE_QAT_ERROR_COUNT,
	INFLATE_IAA_COUNT,
	INFLATE_IAA_ERROR_COUNT,
	INFLATE_ZLIB_COUNT,

	STATS_COUNT
};

const std::string stat_names[STATS_COUNT] {
	"deflate_count",
	"deflate_error_count",
    "deflate_qat_count",
    "deflate_qat_error_count",
    "deflate_iaa_count",
    "deflate_iaa_error_count",
    "deflate_zlib_count",

    "inflate_count",
    "inflate_error_count",
    "inflate_qat_count",
    "inflate_qat_error_count",
    "inflate_iaa_count",
    "inflate_iaa_error_count",
    "inflate_zlib_count"
};

thread_local uint64_t stats[STATS_COUNT];

void PrintStatistics() {
  if ((stats[DEFLATE_COUNT] + stats[INFLATE_COUNT]) % 100 != 0) {
    return;
  }

  std::stringstream printedStats;
  for (int i = 0; i < STATS_COUNT; i++) {
    printedStats << stat_names[i] << " = " << stats[i] << std::endl;
  }
  Log(LogLevel::LOG_STATS, printedStats.str().c_str());
}
#else
#define PrintStatistics()
#endif



