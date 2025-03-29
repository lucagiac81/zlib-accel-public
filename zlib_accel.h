// Copyright (C) 2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <zlib.h>

enum ConfigTag {
  USE_QAT_COMPRESS,
  USE_QAT_UNCOMPRESS,
  USE_IAA_COMPRESS,
  USE_IAA_UNCOMPRESS,
  USE_ZLIB_COMPRESS,
  USE_ZLIB_UNCOMPRESS,
  IAA_COMPRESS_PERCENTAGE,
  IAA_DECOMPRESS_PERCENTAGE,
  IAA_PREPEND_EMPTY_BLOCK,
  QAT_PERIODICAL_POLLING,
  QAT_COMPRESSION_LEVEL,
  LOG_LEVEL
};

enum ExecutionPath { UNDEFINED, ZLIB, QAT, IAA };

// Non-zlib APIs (for testing or non-transparent applications)
ZEXTERN void ZEXPORT zlib_accel_set_config(ConfigTag tag, int value);
ZEXTERN int ZEXPORT zlib_accel_get_config(ConfigTag tag);
ZEXTERN ExecutionPath ZEXPORT
zlib_accel_get_deflate_execution_path(z_streamp strm);
ZEXTERN ExecutionPath ZEXPORT
zlib_accel_get_inflate_execution_path(z_streamp strm);
