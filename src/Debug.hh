#ifndef DEBUG_HH
#define DEBUG_HH

#include <cstdio>

#ifdef DEBUG
#define DBG(...) { __VA_ARGS__ }
#define DBG_LOG(...) printf("[Debug] " __VA_ARGS__); putchar('\n')

#else
#define DBG(...)
#define DBG_LOG(fmt, ...)
#endif

#endif
