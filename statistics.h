#pragma once

#include <atomic>

#ifdef ENABLE_STATISTICS
#define INCREMENT_STAT(stat) stat++
#define INCREMENT_STAT_COND(stat, cond) if (cond) stat++
#else
#define INCREMENT_STAT(stat)
#define INCREMENT_STAT_COND(stat, cond)
#endif

class Statistics {
 public:
  std::atomic<uint64_t> deflate_count;
  std::atomic<uint64_t> deflate_iaa_count;
  std::atomic<uint64_t> deflate_qat_count;
  std::atomic<uint64_t> deflate_zlib_count;
  std::atomic<uint64_t> deflate_error_count;
  std::atomic<uint64_t> deflate_iaa_error_count;
  std::atomic<uint64_t> deflate_qat_error_count;

  std::atomic<uint64_t> inflate_count;
  std::atomic<uint64_t> inflate_iaa_count;
  std::atomic<uint64_t> inflate_qat_count;
  std::atomic<uint64_t> inflate_zlib_count;
  std::atomic<uint64_t> inflate_error_count;
  std::atomic<uint64_t> inflate_iaa_error_count;
  std::atomic<uint64_t> inflate_qat_error_count;
};
