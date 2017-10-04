 /*
  * @file b682.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710051108
  */

#include <stdio.h>
int main() {
	int h1, m1, h2, m2;
	while(scanf("%d %d", &h1, &m1) != EOF) {
		scanf("%d %d", &h2, &m2);
		if(m1 > m2) {
			m2 += 60;
			h2--;
		}
		if(h1 > h2) {
			h2 += 24;
		}
		printf("%d %d\n", h2-h1, m2-m1);
	}
	return 0;
}

