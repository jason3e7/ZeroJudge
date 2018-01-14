 /*
  * @file b882.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201801141557
  */

#include <stdio.h>

int main() {
	unsigned long long int h, m, s;
	while(scanf("%d %d %d", &h, &m, &s) != EOF) {
		m += (s / 60); 
		s %= 60;

		h += (m / 60);
		m %= 60;

		h %= 24;
		printf("%02d:%02d:%02d\n", h, m, s);		
	}
	return 0;
}

