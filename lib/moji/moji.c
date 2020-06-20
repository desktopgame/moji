#include <locale.h>
#include <moji/moji.h>
#include <moji/config.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <Windows.h>
#endif

void moji_set_locale() { setlocale(LC_ALL, ""); }

wchar_t *moji_to_wide_char(const char *s) {
#ifdef _WIN32
  int str_len = (int)strlen(s);
  int num_chars = MultiByteToWideChar(CP_UTF8, 0, s, str_len, NULL, 0);
  wchar_t* wstrTo = (wchar_t*)malloc((num_chars + 1) * sizeof(wchar_t));
  if (wstrTo) {
  	MultiByteToWideChar(CP_UTF8, 0, s, str_len, wstrTo, num_chars);
  	wstrTo[num_chars] = L'\0';
  }
  return wstrTo;
#else
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
#endif
}

char *moji_to_multi_byte(const wchar_t *s) {
#ifdef _WIN32
  int wstr_len = (int)wcslen(s);
  int num_chars = WideCharToMultiByte(CP_UTF8, 0, s, wstr_len, NULL, 0, NULL, NULL);
  char* strTo = (char*)malloc((num_chars + 1) * sizeof(char));
  if (strTo)
  {
  	WideCharToMultiByte(CP_UTF8, 0, s, wstr_len, strTo, num_chars, NULL, NULL);
  	strTo[num_chars] = '\0';
  }
  return strTo;
#else
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
#endif
}