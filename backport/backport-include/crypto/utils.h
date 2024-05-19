#ifndef __BACKPORT_CRYPTO_UTILS_H
#define __BACKPORT_CRYPTO_UTILS_H

#if LINUX_VERSION_IS_GEQ(6,4,0)
#include_next <crypto/utils.h>
#else
#include <crypto/algapi.h>
#endif

#endif
