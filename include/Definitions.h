#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <assert.h>

#define APP_ASSERT(expr) assert(expr)
#define NOT_IMPLEMENTED() APP_ASSERT(0 && "NOT IMPLEMENTED!");
#define FORCEINLINE __attribute__((always_inline))

#endif