#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MIN 284639
#define MAX 748759
#define DECIMAL 10

bool rule1(char* string);
bool rule2(char* string);

int main(void){

  int n, count = 0;
  char string[10] = {0};

  for(n = MIN; n < MAX; n++){
    itoa(n, string, DECIMAL);
    if(rule1(string) == true && rule2(string) == true){
      count++;
    }
  }
  printf("%d", count);
  return 0;
}

bool rule1(char* string){
  int i, j, temp;
  for(i = 0; i < strlen(string) - 1; i++){
    temp = 0;
    if(string[i] == string[i+1]){
      for(j = 0; j <strlen(string); j++){
        if(string[j] == string[i]){
          temp++;
        }
      }
      if(temp == 2){
        return true;
      }
    }
  }
  return false;
}

bool rule2(char* string){
  int i;
  for(i = 0; i < strlen(string) - 1; i++){
    if(string[i + 1] < string[i]){
      return false;
    }
  }
  return true;
}
