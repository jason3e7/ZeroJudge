 /*
  * @file a738.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710201107
  */

#include <stdio.h>

int GCD(int a, int b) {
	if(b) while((a %= b) && (b %= a)); 
	return a + b;
}

int main() {
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", GCD(a, b));
	}
	return 0;
}

