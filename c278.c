 /*
  * @file c278.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710111023
  */

#include <stdio.h>
int main() {
	int n, m[100001], i, j, out, swap;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &m[i]);
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < (n - 1 - i); j++) {
				if(m[j] > m[j + 1]) {
					swap = m[j];
					m[j] = m[j + 1];
					m[j + 1] = swap;
				}
			}
		}
		out = 0;
		for(i = 0; i < n; i+=2) {
			out += (m[i + 1] - m[i]);
		}
		printf("%d\n", out);
		
	}
	return 0;
}

