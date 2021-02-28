#include <stdio.h>
#include <stdlib.h>

int fuelRequired(int mass);
void read_input(int a[]);

int main(void)
{
  int i, arr[100];
  int temp, fuel = 0;
  read_input(arr);

  for(i = 0; i < 100; i++){

    /*calculate fuel required by the module*/
    temp = fuelRequired(arr[i]);
    fuel = fuel + temp;

    /*calculate fuel required by the fuel for that module*/
    while((fuelRequired(temp)) >= 0){
      temp = fuelRequired(temp);
      fuel = fuel + temp;
    }
  }
  printf("%d\n", fuel);
}

void read_input(int a[]){
  FILE *fp;
  int i;

  if((fp = fopen("input.txt", "r")) == NULL){
    printf("Error: failed to open file");
    exit(1);
  }
  for(i = 0; i < 100; i++){
    fscanf(fp, "%d", &a[i]);
  }
}

int fuelRequired(int mass){
  return (mass / 3) - 2;
}
