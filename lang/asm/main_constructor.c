#include <stdio.h>

int main() {
     return 43;
}

__attribute__((constructor))
  void myconstructor() {
       printf("myconstructor\n");
  }
