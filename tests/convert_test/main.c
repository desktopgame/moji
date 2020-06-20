#define MOJI_WIDECHAR
#include <moji/moji.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  moji_set_locale();
  const char* word = "こんにちは世界";
  const wchar_t* word2 = moji_to_wide_char(word);
  moji_printf(L"%ls\n", word2);
  free((void*)word2);
  return 0;
}