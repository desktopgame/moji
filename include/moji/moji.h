#ifndef MOJI_MOJI_H
#define MOJI_MOJI_H
#include <moji/io.h>
#include <moji/string.h>
#include <moji/type.h>

#if defined(MOJI_MULTIBYTE)
#define MOJI_T(a) (#a)
#elif defined(MOJI_WIDECHAR)
#define MOJI_T(a) (L## #a)
#endif

void moji_set_locale();

wchar_t* moji_to_wide_char(const char* s);

char* moji_to_multi_byte(const wchar_t* s);
#endif