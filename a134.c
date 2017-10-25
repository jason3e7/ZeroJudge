 /*
  * @file a134.c
  * @author Jason3e7
  * @algorithm basic
  * @UVa 948
  * @date 201710251434
  * @note f(40) = 102334155
  */

#include <stdio.h>

int main() {
	int n, temp, f[41], i, first; 
	char fib[41];
	f[0] = 1;
	f[1] = 1;
	for(i = 2; i < 41; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%d", &temp);
			printf("%d = ", temp);
			first = -1;
			for(i = 40; i >= 0; i--) {
				if(temp >= f[i]) {
					temp -= f[i];
					fib[i] = '1';
					if(first == -1) {
						first = i;
					}
				} else {
					fib[i] = '0';
				}
			}
			for(i = first; i >= 1; i--) {
				printf("%c", fib[i]);
			}
			printf(" (fib)\n");
		}
	}
	return 0;
}

