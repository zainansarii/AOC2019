/*determine what pair of inputs produces the output 19690720*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INSTRUCTIONLEGNTH 4

void read_input(int a[]);
void run_programme(int a[]);
void find_inputs(int *noun, int *verb, int a[], int b[]);
void arrcpy(int a[], int b[]);

int main(void)
{
  int noun = 0, verb = 0, arr1[200], arr2[200];
  read_input(arr1);
  arrcpy(arr2, arr1);
  find_inputs(&noun, &verb, arr1, arr2);

  printf("noun = %d, verb = %d", noun, verb);

  return 0;
}

void find_inputs(int *noun, int *verb, int a[], int b[])
{
  int i, j;

  for(i = 0; i < 100; i++){
    for(j = 0; j < 100; j++){

      a[1] = i;
      a[2] = j;

      run_programme(a);
      if(a[0] == 19690720){
        *noun = i;
        *verb = j;
        return;
      }
      arrcpy(a, b);
    }
  }
}

void run_programme(int a[]){

  int opcode, index1, index2, index3, i = 0;
  bool isfinished = false;

  while(isfinished == false || a[i] != -1){
    opcode = a[i];
    index1 = a[i + 1];
    index2 = a[i + 2];
    index3 = a[i + 3];

    switch(opcode){
      case 1:
        a[index3] = a[index1] + a[index2];
        break;
      case 2:
        a[index3] = a[index1] * a[index2];
        break;
      case 99:
        isfinished = true;
        break;
    }
    i = i + INSTRUCTIONLEGNTH;
  }
}

void read_input(int a[]){
  FILE *fp;
  int i, j;

  for(i = 0; i < 200; i++){
    a[i] = -1;
  }

  if((fp = fopen("input.txt", "r")) == NULL){
    printf("Error: failed to open file");
    exit(1);
  }
  for(i = 0; i < 200; i++){
    fscanf(fp, "%d%*c", &a[i]);
  }
}

void arrcpy(int a[], int b[])
{
  int i;

  for(i = 0; i < 200; i++){
    a[i] = b[i];
  }

}
