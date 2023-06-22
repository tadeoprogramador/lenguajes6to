#include <stdio.h>
#include <string.h>
#include <math.h>

int compar_de_strings(char string1 [10], char string2 [10]);

int main(){
  char string1 [10];
  char string2 [10];
  printf("Introduzca su primer string \n");
  scanf("%s", string1);
  printf("Introduzca su segundo string \n");
  scanf("%s", string2);
  compar_de_strings(string1, string2);
}


int compar_de_strings(char string1 [10], char string2 [10]){
  int i;
  for(i=0; string1[i] != '\0' || string2[i] != '\0'; i++){
    if (string1[i]==string2[i]) {
      printf ("1");
    }
    else 
      printf ("0");
    }  
}