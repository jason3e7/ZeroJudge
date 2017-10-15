 /*
  * @file b911.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710161008
  */

#include <stdio.h>

int main() {
	unsigned long long int n;
	int out;
	while(scanf("%llu", &n) != EOF) {
		out = 0;
		while(n > 0) {
			n /= 2;
			out++;
		}
		printf("%d\n", out);
	}
	return 0;
}



