#include <stdio.h>
#include <stdio_ext.h>
#include <math.h>

void selector (char respuesta, int x, int *punter);
void pasref (int x,int *punter);
void pasvalor (int x);

int main(void) {  
  int x;
  int*punter = &x;
  char respuesta;
  printf("¿De qué valor es su variable?");
  scanf("%d", &x);
  printf("Si desea hacer pasaje por referencia, escriba 1 \nSi desea hacer pasaje por valor, escriba 2 \n");
  __fpurge(stdin);
  scanf("%c", &respuesta);
  selector (respuesta, x, punter);
  printf ("El valor de x es de %d \n", x);
}

void selector (char respuesta, int x, int *punter){
  if (respuesta == '1'){
    pasref(x, punter);
  }
  else pasvalor(x);
}

void pasref(int x, int *punter){
  *punter = *punter + 1;
  printf ("El valor de retorno es: %d \n", *punter);
}

void pasvalor(int j) {
  j++;
  printf ("El valor de retorno es: %d \n", j);
}