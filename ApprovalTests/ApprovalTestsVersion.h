#pragma once

#include "ApprovalTests/ApprovalsMacroDefaults.h"

#define APPROVAL_TESTS_VERSION_MAJOR 9
#define APPROVAL_TESTS_VERSION_MINOR 0
#define APPROVAL_TESTS_VERSION_PATCH 0
#define APPROVAL_TESTS_VERSION_STR "9.0.0"

#define APPROVAL_TESTS_VERSION                                                           \
    (APPROVAL_TESTS_VERSION_MAJOR * 10000 + APPROVAL_TESTS_VERSION_MINOR * 100 +         \
     APPROVAL_TESTS_VERSION_PATCH)
