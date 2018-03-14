 /*
  * @file a270.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803141035
  */
 
#include <stdio.h>

int main() {
	int n, i, t[4], cur, next, flag, begin, end, sum;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < 4; i++) {
			scanf("%d", &t[i]);
		}
		cur = 0;
		next = 0;
		flag = 0;
		for(i = 0; i < 8; i++) {
			scanf("%d", &cur);
			if(flag != 0) {
				continue;
			} 
			if(next == 0) {
				next = cur;
				continue;
			}
			if(next > cur) {
				begin = cur;
				end = next;
			} else {
				begin = next;
				end = cur;
			}
			sum = 0;
			for(; begin < end; begin++) {
				sum += t[begin - 1];
			}
			if(sum > n) {
				flag = 1;
			}
			next = cur;
		}
		if(flag == 1) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
	}
	return 0;
}
