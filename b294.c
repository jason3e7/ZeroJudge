 /*
  * @file b294.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710031013
  */

#include <stdio.h>
int main() {
	int n, m, out, i;
	while(scanf("%d", &n) != EOF) {
		out = 0;
		for(i = 1; i <= n; i++) {
			scanf("%d", &m);
			out += (m * i);
		}
		printf("%d\n", out);
	}
	return 0;
}

