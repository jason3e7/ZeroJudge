 /*
  * @file LCM.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710241309
  */

#include <stdio.h>

int GCD(int a, int b) {
	if(b) while((a %= b) && (b %= a)); 
	return a + b;
}

int LCM(int a, int b) {
	return (a * b) / GCD(a, b);
}

int main() {
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", LCM(a, b));
	}
	return 0;
}

