#include <stdio.h>
#include <math.h>
#include <stdlib.h>

union num {
  float decimal;  
  struct {
    unsigned int mantisa: 23;
    unsigned int exponente: 8;
    unsigned int bitdesigno: 1;
  }_4bytes;
}num;

void compexp();
void compman ();

int main() { 
  printf("Introduzca su número decimal=");
  scanf("%f", &num.decimal);
  printf("El bit de signo de su número es: %d|", num._4bytes.bitdesigno);
  compexp ();
  printf ("|");  
  compman ();
  return 0;
}

void compman (){
  for (int i = 22; i >= 0; i--){
    printf ("%d", (num._4bytes.mantisa >> i) & 1);
  }

}

void compexp (){
  for(int i = 7; i >= 0; i--) {
    printf ( "%d" ,(num._4bytes.exponente >> i) & 1);
  }
}



