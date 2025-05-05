// Copyright (C) 2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#ifdef ENABLE_STATISTICS

#include "statistics.h"

#include <thread>

#include "config/config.h"
#include "logging.h"

// clang-format off
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
// clang-format on

thread_local uint64_t stats[STATS_COUNT];

void ResetStats() {
  for (int i = 0; i < STATS_COUNT; i++) {
    stats[i] = 0;
  }
}

uint64_t GetStat(Statistic stat) {
  return stats[stat];
}

void CopyStats(uint64_t* copy) {
  for (int i = 0; i < STATS_COUNT; i++) {
    copy[i] = stats[i];
  }
}

void PrintStats() {
  if ((stats[DEFLATE_COUNT] + stats[INFLATE_COUNT]) %
          config::log_stats_samples !=
      0) {
    return;
  }

  std::stringstream printed_stats;
  printed_stats << "Thread: " << std::this_thread::get_id() << std::endl;
  for (int i = 0; i < STATS_COUNT; i++) {
    printed_stats << stat_names[i] << " = " << stats[i] << std::endl;
  }

  LogStats(printed_stats.str().c_str());
}

#endif
