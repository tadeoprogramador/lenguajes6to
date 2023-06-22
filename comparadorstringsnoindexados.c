#include <stdio.h>

#define LIMIT 10

int compar_de_strings(char *, char *);

int main(void) {
  char string1[LIMIT] = {0};
  char string2[LIMIT] = {0};
  char *pun = &string1[0];
  char *pun2 = &string2[0];
  int comparacion;
  printf("Ingrese el primer string: ");
  scanf("%s", string1);
  printf("Ingrese el segundo string: ");
  scanf("%s", string2);
  comparacion = compar_de_strings(pun, pun2);
  printf("%d", comparacion);
  return 0;
}

int compar_de_strings(char *pun, char *pun2) {
  for (int i = 0; i < LIMIT; i++){
    if ((*(pun++)) != (*(pun2++))){
      return (0);
    }
  }
  return (1);
}

