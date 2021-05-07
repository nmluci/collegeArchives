#include <stdio.h>
#include "libs/extensions.h"
#include <string.h>

int main()
{
  char a[100], b[100];
  printf("Masukan kata atau kalimat\n");
  gets(a);
  strcpy(b, a);
  strrev(b);
  if (strcmp(a, b) == 0)
    printf("Kata atau kalimat ini merupakan palindrom.\n");
  else
    printf("Kata atau kalimat ini bukan merupakan palindrom.\n");
  return 0;
}
  