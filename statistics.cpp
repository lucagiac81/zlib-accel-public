// Copyright (C) 2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#ifdef ENABLE_STATISTICS

#include "statistics.h"

#include "config/config.h"
#include "logging.h"

thread_local uint64_t stats[STATS_COUNT];

void PrintStatistics() {
  if ((stats[DEFLATE_COUNT] + stats[INFLATE_COUNT]) % config::log_stats_samples != 0) {
    return;
  }

  std::stringstream printedStats;
  for (int i = 0; i < STATS_COUNT; i++) {
    printedStats << stat_names[i] << " = " << stats[i] << std::endl;
  }

  LogStats(printedStats.str().c_str());
}

#endif
