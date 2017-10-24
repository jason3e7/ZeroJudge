 /*
  * @file d693.c
  * @author Jason3e7
  * @algorithm LCM
  * @date 201710241247
  */

#include <stdio.h>

long int GCD(long int a, long int b) {
	if(b) while((a %= b) && (b %= a)); 
	return a + b;
}

long int LCM(long int a, long int b) {
	return (a * b) / GCD(a, b);
}

int main() {
	int n, i; 
	long int out, num[11];
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		for(i = 0; i < n; i++) {
			scanf("%ld", &num[i]);
		}
		out = LCM(num[0], num[1]);
		for(i = 2; i < n; i++) {
			out = LCM(out, num[i]);
		}
		printf("%ld\n", out);
	}
	return 0;
}

