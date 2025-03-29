// Copyright (C) 2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <string>

namespace config {
__attribute__((visibility("default"))) extern int use_qat_compress;
__attribute__((visibility("default"))) extern int use_qat_uncompress;
__attribute__((visibility("default"))) extern int use_iaa_compress;
__attribute__((visibility("default"))) extern int use_iaa_uncompress;
__attribute__((visibility("default"))) extern int use_zlib_compress;
__attribute__((visibility("default"))) extern int use_zlib_uncompress;
__attribute__((visibility("default"))) extern int iaa_compress_percentage;
__attribute__((visibility("default"))) extern int iaa_decompress_percentage;
__attribute__((visibility("default"))) extern int iaa_prepend_empty_block;
__attribute__((visibility("default"))) extern int qat_periodical_polling;
__attribute__((visibility("default"))) extern int qat_compression_level;
__attribute__((visibility("default"))) extern std::string log_file;
__attribute__((visibility("default"))) extern int log_level;

bool LoadConfigFile(std::string& file_content,
                    const char* filePath = "/etc/zlib-accel.conf");
}  // namespace config
