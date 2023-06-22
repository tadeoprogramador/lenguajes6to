#include <stdio.h>
#include <stdio_ext.h>
#define N 20
#define aprobado 7

int promedi (int valores[]);
int notas (int valores[]);

int main(void) {
  int valores[N];
  char i = 0;
  for (i = 0; i < 20; i++) {
    printf("Introduzca la nota del alumno %d: ", i+1);
    scanf("%d", &valores[i]);
  }
  notas(valores);
  promedi(valores);
}

int notas(int valores[]){
  int CantApro = 0;
  int CantDesa = 0;
  char i2 = 0;
  for (i2 = 0; i2 < 20; i2++){
    if (valores[i2] >= aprobado){
      CantApro++;
    }else{
      CantDesa++;
    }
  }
  printf("\nEsta es la cantidad de alumnos aprobados: %d\n",CantApro);
  printf("Esta es la cantidad de alumnos desaprobados: %d\n",CantDesa);
}

int promedi (int valores[]){
  char i3 = 0;
  float resultado=0;
  float promedio;
  for (i3 = 0; i3 < 20; i3++){
    resultado = resultado+valores[i3];
    promedio = resultado/20;
  }
  printf("%f", promedio);
}