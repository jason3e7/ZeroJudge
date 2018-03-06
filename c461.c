 /*
  * @file c461.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803070915
  */

#include <stdio.h>

int main() {
	int a, b, c, flag;
	while(scanf("%d %d %d", &a, &b, &c) != EOF) {
		if(a != 0) {
			a = 1;
		}
		if(b != 0) {
			b = 1;
		}
		flag = 0;
		if((a & b) == c) {
			printf("AND\n");
			flag = 1;
		}
		if((a | b) == c) {
			printf("OR\n");
			flag = 1;
		}
		if((a ^ b) == c) {
			printf("XOR\n");
			flag = 1;
		}
		if(flag == 0) {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
