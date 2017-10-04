 /*
  * @file b681.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710051026
  */

#include <stdio.h>
int main() {
	long long int n;
	while(scanf("%lli", &n) != EOF) {
		if (n >= 0) {
			n = (n * 2 - 1);
		} else {
			n = (n * -2);
		}
		printf("%lli\n", n);
	}
	return 0;
}

