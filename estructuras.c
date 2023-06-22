#include <stdio.h>
#include <stdio_ext.h>
#define LIM 10
#define ES 4

void buscadordealumnos ();
void registralumnos ();

struct Alumno {
  char NombreDeAlumno[LIM];
  char Mail [LIM];
  char Esp[ES];
  int Curso;
  int Num;
  int exis;
}ficha[LIM];

int main(){
  registralumnos();
  buscadordealumnos();
}

void registralumnos(){
  char cont;
  for(int SEN=0; SEN<LIM; SEN++){
    printf("¿Desea guardar un alumno en esta ficha (s para sí, n para no)? ");
    scanf("%c", &cont);
    __fpurge(stdin);
    if (cont == 's'){
      __fpurge(stdin);
      printf("Nombre del Alumno:  \n");
      fgets(ficha[SEN].NombreDeAlumno, 30, stdin);
      __fpurge(stdin);
      printf("Curso:  \n");
      scanf ("%d", &ficha[SEN].Curso);
      __fpurge(stdin);
      printf("Especialidad:  \n");
      scanf("%s", ficha[SEN].Esp);
      __fpurge(stdin);
      printf("Número:  \n");
      scanf ("%d", &ficha[SEN].Num);
      __fpurge(stdin);
      printf("Mail:  \n");
      scanf("%s", ficha[SEN].Mail);
      __fpurge(stdin);
      ficha[SEN].exis = 1;  
    }
    else {
      ficha[SEN].exis = 0;  
    }
  }
}

void buscadordealumnos(){
  int bus;
  char cont;
  printf("¿Desea buscar alguna ficha (s para sí, n para no)?");
  scanf ("%c", &cont);
  if (cont == 's') {
    do{
      printf("¿Qué ficha desea buscar?");
      cont = 0; 
      scanf("%d", &bus);
      if (ficha[bus].exis == 1){
        printf ("%s", ficha[bus].NombreDeAlumno);
        printf ("%d \n", ficha[bus].Curso);
        printf ("%s \n", ficha[bus].Esp);
        printf ("%d \n", ficha[bus].Num);
        printf ("%s \n", ficha[bus].Mail);
      }
      else {
        printf("No guardo datos en esta ficha \n");
      }
      __fpurge(stdin);
      printf ("¿Desea buscar alguna otra ficha? \n");      
      scanf ("%c", &cont); 
    }while (cont == 's');
  }
  printf("Gracias por usar el servicio");
  }
