/* SPDX-License-Identifier: GPL-2.0 */
/*
 * KUnit API to allow symbols to be conditionally visible during KUnit
 * testing
 *
 * Copyright (C) 2022, Google LLC.
 * Author: Rae Moar <rmoar@google.com>
 */

#ifndef _BACKPORT_KUNIT_VISIBILITY_H
#define _BACKPORT_KUNIT_VISIBILITY_H

#if LINUX_VERSION_IS_GEQ(6,2,0)
#include_next <kunit/visibility.h>
#else
#define VISIBLE_IF_KUNIT static
#define EXPORT_SYMBOL_IF_KUNIT(symbol)
#endif

#endif /* _BACKPORT_KUNIT_VISIBILITY_H */
