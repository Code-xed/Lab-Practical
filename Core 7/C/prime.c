#include <stdio.h>
int prime(int n) {
  int count = 1;
  for (int i = 2; i <= n; i++) {
    if (i % n == 0) {
      count++;
      }
    }
  if (count == 2) {
    return 1;
    }
  else {
    return 0;
    }
  }

int main() {
  int a;
  printf("Enter A number to check if its a prime or not:/n");
  scanf("%d", &a);
  if (prime(a)) {
    printf("Is prime");
    }
  else {
    printf("Is not a Prime");
    }
  }
  

