 /*
  * @file d018.c
  * @author Jason3e7
  * @algorithm basic and input
  * @date 201710061614
  */

#include <stdio.h>
int main() {
	int n;
	float m, sum = 0;
	char temp = ' ';
	while(scanf("%d:%f", &n, &m) != EOF) {
		if(n % 2 == 1) {
			sum += m;
		} else {
			sum -= m;
		}
		while(temp != EOF) {
			temp = getchar();
			if('0' <= temp && temp <= '9') {
				ungetc(temp, stdin);
				break;
			}
			if(temp == '\n' || temp == '\r' || temp == EOF) {
				printf("%g\n", sum);
				sum = 0;
				break;
			}
		}
	}
	return 0;
}

