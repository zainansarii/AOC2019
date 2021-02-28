#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INSTRUCTIONLEGNTH 4

void read_input(int a[]);

int main(void)
{
  int arr[200];
  int i, opcode, index1, index2, index3;
  bool isfinished = false;

  /*zero out array*/
  for(i = 0; i < 200; i++){
    arr[i] = -1;
  }

  /*initialise array*/
  read_input(arr);
  i = 0;

  arr[1] = 12;
  arr[2] = 2;

  while(arr[i] != -1){
    printf("%d ", arr[i]);
    i++;
  }

  /*do stuff*/
  i = 0;

  while(isfinished == false){
    opcode = arr[i];
    index1 = arr[i + 1];
    index2 = arr[i + 2];
    index3 = arr[i + 3];

    switch(opcode){
      case 1:
        arr[index3] = arr[index1] + arr[index2];
        break;
      case 2:
        arr[index3] = arr[index1] * arr[index2];
        break;
      case 99:
        isfinished = true;
        break;
    }
    i = i + INSTRUCTIONLEGNTH;
  }

  printf("\n\n");
  i = 0;
  while(arr[i] != -1){
    printf("%d ", arr[i]);
    i++;
  }

  return 0;
}

void read_input(int a[]){
  FILE *fp;
  int i, j;
  if((fp = fopen("input.txt", "r")) == NULL){
    printf("Error: failed to open file");
    exit(1);
  }
  for(i = 0; i < 200; i++){
    fscanf(fp, "%d%*c", &a[i]);
  }
}
