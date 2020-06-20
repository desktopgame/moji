#ifndef MOJI_TYPE_H
#define MOJI_TYPE_H
#include <moji/config.h>
#include <wchar.h>
#include <wctype.h>

#if defined(MOJI_MULTIBYTE)
typedef char moji_t;
typedef int moji_number_t;
#elif defined(MOJI_WIDECHAR)
typedef wchar_t moji_t;
typedef wint_t moji_number_t;
#else
typedef char moji_t;
typedef int moji_number_t;
#endif
#endif