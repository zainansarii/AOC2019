#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MIN 284639
#define MAX 748759
#define DECIMAL 10

int main(void){

  char string[10] = {0};
  int i, n, count = 0, test = 315342;
  bool rule1, rule2;

  for(n = MIN; n < MAX; n++){

    rule1 = false;
    rule2 = true;

    itoa(n, string, DECIMAL);

    for(i = 0; i < strlen(string) - 1; i++){
      if(string[i] == string[i+1]){
        rule1 = true;
      }
    }
    for(i = 0; i < strlen(string) - 1; i++){
      if(string[i + 1] < string[i]){
        rule2 = false;
      }
    }
    if(rule1 == true && rule2 == true){
      count++;
    }
  }
  printf("%d", count);
  return 0;
}
