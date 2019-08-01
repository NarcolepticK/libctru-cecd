/**
 * @file cecdu.h
 * @brief CECD:u service.
 */
#pragma once

#include <3ds/types.h>
#include <3ds/result.h>
#include <3ds/services/fs.h>

/// Initializes CECD:u
Result cecduInit(void);

/// Exits CECD:u
void cecduExit(void);