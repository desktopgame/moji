#ifndef MOJI_IO_H
#define MOJI_IO_H
#include <moji/type.h>
#include <stdarg.h>
#include <stdio.h>
#include <wchar.h>

#if defined(MOJI_MULTIBYTE)
#define moji_fgetc(fp) ((moji_number_t)fgetc(fp))
#define moji_printf(fmt, ...) (printf(fmt, __VA_ARGS__))
#define moji_vprintf(fmt, ap) (vprintf(fmt, ap))
#define moji_fprintf(fp, fmt, ...) (fprintf(fp, fmt, __VA_ARGS__))
#define moji_vfprintf(fp, fmt, ap) (vfprintf(fp, fmt, ap))

#elif defined(MOJI_WIDECHAR)
#define moji_fgetc(fp) ((moji_number_t)fwgetc(fp))
#define moji_printf(fmt, ...) (wprintf(fmt, ##__VA_ARGS__))
#define moji_vprintf(fmt, ap) (vwprintf(fmt, ap))
#define moji_fprintf(fp, fmt, ...) (fwprintf(fp, fmt, __VA_ARGS__))
#define moji_vfprintf(fp, fmt, ap) (vfwprintf(fp, fmt, ap))

#endif

#endif