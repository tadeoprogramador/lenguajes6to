#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
  
union numero_binario {
  float num;
  unsigned char sel[4];
}resultado;

int main (){
  printf("Introduzca su número (puede ser con punto) = "); //con coma la toma como caracter
  __fpurge(stdin);
  scanf ("%f", &resultado.num);
  char i=3;
  printf("Su número en hexadecimal es: 0x");
  do{
    printf("%.2X", resultado.sel[i]);
    i--;
  }while(i>=0);
  return 0;
  }

