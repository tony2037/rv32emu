#pragma once

#if defined(__GNUC__) || defined(__clang__)
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

/* Pattern Matching for C macros.
 * https://github.com/pfultz2/Cloak/wiki/C-Preprocessor-tricks,-tips,-and-idioms
 */

/* In Visual Stido, __VA_ARGS__ is treated as a separate parameter. */
#define FIX_VC_BUG(x) x

/* catenate */
#define PRIMITIVE_CAT(a, ...) FIX_VC_BUG(a##__VA_ARGS__)

#define IIF(c) PRIMITIVE_CAT(IIF_, c)
/* run the 2nd parameter */
#define IIF_0(t, ...) __VA_ARGS__
/* run the 1st parameter */
#define IIF_1(t, ...) t
