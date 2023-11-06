#include <stdio.h>

int main(int argc, char** argv){
  printf("Hola Mundo ALSE!\n");
  printf("Número de argumentos: %d\n", argc);
  for(int i=0; i<argc; i++){
    printf("Argumento : %s\n", argv[i]);
  }
  printf("Argumento 1: %s\n", argv[0]);

  return 0;
}