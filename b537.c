 /*
  * @file b537.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710191043
  */

#include <stdio.h>

int main() {
	int a, b, i, swap, operator[1000], point;
	unsigned long long int out;
	while(scanf("%d %d", &a, &b) != EOF) {
		point = 0;
		while(a != b) {
			if(a > b) {
				a -= b;
				operator[point] = 2;
			} else if(a < b) {
				swap = a;
				a = b;
				b = swap;
				operator[point] = 1;
			}
			point++;
		}
		out = 1;
		for(i = point - 1; i >= 0; i--) {
			if(operator[i] == 2) {
				out *= 2;
			} else if(operator[i] == 1) {
				out += 1;
			}
		}
		printf("%llu\n", out);
	}
	return 0;
}

