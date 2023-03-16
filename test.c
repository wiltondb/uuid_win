
#include <stdio.h>
#include <string.h>
#include "uuid.h"

int main() {
	char strbuf[40];
  memset(strbuf, '\0', sizeof(strbuf));

  uuid_t uu_time;
  uuid_generate_time(uu_time);
  uuid_unparse(uu_time, strbuf);
  printf("%s\n", strbuf);

  uuid_t uu_random;
  uuid_generate_random(uu_random);
  uuid_unparse(uu_random, strbuf);
  printf("%s\n", strbuf);

  return 0;
}