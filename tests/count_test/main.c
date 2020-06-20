#define MOJI_WIDECHAR
#include <moji/moji.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  moji_set_locale();
  moji_printf(L"「こんにちは世界」の文字数は %d です。\n",
              moji_len(MOJI_T(こんにちは世界)));
  return 0;
}