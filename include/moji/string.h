#ifndef MOJI_STRING_H
#define MOJI_STRING_H

#if defined(MOJI_MULTIBYTE)
#define moji_len(str) (strlen(str))

#elif defined(MOJI_WIDECHAR)
#define moji_len(str) (wcslen(str))

#endif
#endif