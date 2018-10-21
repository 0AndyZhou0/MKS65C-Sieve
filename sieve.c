#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

int main(int argc, char * argv[]){
  int iterations = 1;
  int target = 1000000;
  if(argc > 1){
    target = atoi(argv[1]);
  }
  if(argc > 2){
    iterations = atoi(argv[2]);
  }


  int ans = 0;
  while(iterations>0){
      ans=sieve(target);
      iterations--;
      printf("The n=%d prime is %d\n", target, ans );
      //this is to modify which prime to
      //potentially avoid CPU caching
      target++;
  }
  return 0;
}

int sieve(int n){
  if(n == 1){
    return 2;
  }
  int i = 1;
  int max;
  if(n > 5000){
    max = .575 * n * log(n);
  }else{
    max = .65 * n * log(n) + 5;
  }
  char nums[max];
  int index = 1;
  int increment;
  int temp;
  while(i < n || index < max){
    while(nums[index]){
      index++;
    }
    increment = index * 2 + 1;
    temp = index;
    for(;temp < max;temp += increment){
      nums[temp] = 1;
    }
    i++;
    if(i == n){
      return increment;
    }
  }
  return 0;
}
