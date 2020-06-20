#define MOJI_MULTIBYTE
#include <errno.h>
#include <moji/moji.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
  moji_set_locale();
  const wchar_t* word = L"Lこんにちは世界";
  const char* word2 = moji_to_multi_byte(word);
  moji_printf("%s\n", word2);
  free((void*)word2);
  return 0;
}