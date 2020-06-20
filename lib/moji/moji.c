#include <locale.h>
#include <moji/moji.h>
#include <stdlib.h>
#include <string.h>

void moji_set_locale() { setlocale(LC_ALL, ""); }

wchar_t *moji_to_wide_char(const char *s) {
  size_t mbslen = mbstowcs(NULL, s, 0);
  if (mbslen == (size_t)-1) {
    return NULL;
  }
  wchar_t *w = malloc(sizeof(wchar_t) * mbslen);
  memset(w, '\0', sizeof(wchar_t) * mbslen);
  size_t result = mbstowcs(w, s, mbslen);
  if (result == (size_t)-1) {
    return NULL;
  }
  return w;
}

char *moji_to_multi_byte(const wchar_t *s) {
  size_t wblen = wcstombs(NULL, s, 0);
  if (wblen == (size_t)-1) {
    return NULL;
  }
  char *m = malloc(sizeof(char) * wblen);
  memset(m, '\0', sizeof(char) * wblen);
  size_t result = wcstombs(m, s, wblen);
  if (result == (size_t)-1) {
    return NULL;
  }
  return m;
}