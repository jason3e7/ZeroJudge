 /*
  * @file swap.c
  * @author Jason3e7
  * @algorithm swap
  * @date 201710131130
  */

#include <stdio.h>

void swap(int *a, int *b){
   int temp;
   temp = *b;
   *b = *a;
   *a = temp;   
}

int main() {
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		swap(&a, &b); 
		printf("%d %d\n", a, b);
	}
	return 0;
}



