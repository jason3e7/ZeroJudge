 /*
  * @file c294.c
  * @author Jason3e7
  * @algorithm triangle
  * @date 201710131103
  */

#include <stdio.h>

void swap(int *a, int *b){
   int temp;
   temp = *b;
   *b = *a;
   *a = temp;   
}

int main() {
	int a, b, c;
	while(scanf("%d %d %d", &a, &b, &c) != EOF) {
		if(a > b) {
			swap(&a, &b); 
		} 
		if(b > c) {
			swap(&b, &c); 
		} 
		if(a > b) {
			swap(&a, &b); 
		} 
		
		printf("%d %d %d\n", a, b, c);
		if(a + b <= c) {
			printf("No\n");
			continue;
		}
		int out = a * a + b * b - c * c;
		if(out == 0) {
			printf("Right\n");
		} else if(out > 0) {
			printf("Acute\n");
		} else if(out < 0) {
			printf("Obtuse\n");
		}
	}
	return 0;
}



