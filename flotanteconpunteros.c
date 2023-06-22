#include <stdio.h>
#include <stdio_ext.h>

void conversor(unsigned char *puntero);

int main(void) {
  char respuesta;
  do{
    float flotante = 0;
    printf("Introduzca su número flotante: ");
    __fpurge(stdin);
    scanf ("%f", &flotante);
    unsigned char *puntero = (unsigned char*) &flotante;
    conversor(puntero);
    printf("\nDesea volver a utilizar de vuelta el programa, escriba 's', si no, presione cualquier letra: ");
    __fpurge(stdin);
    scanf("%c", &respuesta);
  }while (respuesta == 's');
  printf("Gracias por usar el programan\n");
  return 0;
}

void conversor(unsigned char *puntero) {
  for (int i = 3; i>=0; i--){
    printf("%.2x", *(puntero + i));
  }
}