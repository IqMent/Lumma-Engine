//
// Created by iqment on 3/15/25.
//

#ifndef LUMMAENGINE_MEMZERO_H
#define LUMMAENGINE_MEMZERO_H
extern "C" {
#include <stddef.h>

void memzero(void *const pnt, const size_t len);
};
#endif //LUMMAENGINE_MEMZERO_H
