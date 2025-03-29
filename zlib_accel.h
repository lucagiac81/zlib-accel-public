// Copyright (C) 2025 Intel Corporation
// SPDX-License-Identifier: Apache-2.0

#pragma once
#pragma GCC visibility push(default)

#include <zlib.h>

// Visible for testing
enum ExecutionPath { UNDEFINED, ZLIB, QAT, IAA };
ExecutionPath zlib_accel_get_deflate_execution_path(z_streamp strm);
ExecutionPath zlib_accel_get_inflate_execution_path(z_streamp strm);

#pragma GCC visibility pop
