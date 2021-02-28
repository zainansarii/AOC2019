#include <stdio.h>
#include <stdlib.h>

void read_input(int a[100][4]);

int main(void)
{
  int arr[100][4];
  read_input(arr);

  return 0;
}

void read_input(int a[100][4]){
  FILE *fp;
  int i;

  if((fp = fopen("input.txt", "r")) == NULL){
    printf("Error: failed to open file");
    exit(1);
  }
  for(i = 0; i < 100; i++){
    for(j = 0; j < 4; j++){
      fscanf(fp, "%d", &a[i][j]);
    }
  }
}
