#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

/*
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
*/

int sieve(int n){
  if(n == 1){
    return 2;
  }
  //if(n == 2){
  //  return 3;
  //}

  //All the variables
  int i = 1;
  int index = 1;
  int prime;
  int temp;
  int max;


  //determines size of array (divided by 2 to ignore even numbers)
  if(n > 5000){
    max = .575 * n * log(n);
  }else{
    max = .65 * n * log(n) + 5;
  }

  char *nums = (char*)calloc(max,sizeof(char));

  while(i < n){
    //finds next index that refers to a prime
    while(nums[++index]);

    prime = index * 2 + 1;

    //marks all multiples of prime
    temp = index;
    while((temp += prime) < max){
      nums[temp] = 1;
    }
    //for(temp = index;temp < max;temp += prime){
    //  nums[temp] = 1;
    //}

    //checks if we have reached the nth prime
    if(++i == n){
      return prime;
    }
  }
  return 0;
}
