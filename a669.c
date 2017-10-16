 /*
  * @file a669.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710161913
  */

#include <stdio.h>

int main() {
	int n, m, out;
	while(scanf("%d %d", &n, &m) != EOF) {
		n--;
		if(n == 0 || m == 0) {
			printf("0\n");
			continue;
		}
		out = n / m;
		if(n % m > 0) {
			out++;
		}
		printf("%d\n", out);
	}
	return 0;
}



