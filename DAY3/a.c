#include <stdio.h>
#include <stdlib.h>

typedef struct instruction{
  char direction;
  int length;
} instruction;

void read_input(instruction a[], char* filename);

int main(void)
{
  instruction wire1[300];
  read_input(wire1, "input1.txt");

}

void read_input(instruction a[], char* filename)
{
  FILE *fp;
  int i, j;
  char data[10000];

  if((fp = fopen(filename, "r")) == NULL){
    printf("Error: failed to open file");
    exit(1);
  }

  for(i = 0; i < 10000; i++){
    fscanf(fp, "%c%*[',']", &data[i]);
  }

}
