// Copyright (C) 2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once

#define VISIBLE_FOR_TESTING __attribute__((visibility("default")))
#include <stdint.h>

#ifdef ENABLE_STATISTICS
#define INCREMENT_STAT(stat) stats[stat]++
#define INCREMENT_STAT_COND(cond, stat) \
  if (cond) stats[stat]++
#else
#define INCREMENT_STAT(stat)
#define INCREMENT_STAT_COND(cond, stat)
#endif

enum Statistic {
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

#ifdef ENABLE_STATISTICS
extern thread_local uint64_t stats[STATS_COUNT];
#endif

VISIBLE_FOR_TESTING bool AreStatsEnabled();
VISIBLE_FOR_TESTING void ResetStats();
VISIBLE_FOR_TESTING uint64_t GetStat(Statistic stat);

#ifdef ENABLE_STATISTICS
void PrintStats();
#else
#define PrintStats(...)
#endif
