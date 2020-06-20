#define MOJI_WIDECHAR
#include <moji/moji.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  moji_set_locale();
  moji_printf(MOJI_T(こんにちは世界));
  return 0;
}