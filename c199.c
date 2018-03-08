 /*
  * @file c199.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803090903
  */

#include <stdio.h>

int main() {
	int n, temp, sum, flag, high;
	while(scanf("%d", &n) != EOF) {
		sum = 0;
		high = 0;
		flag = 0;
		while(n--) {
			scanf("%d", &temp);
			if(high == 0) {
				high = temp;
				continue;
			} 
			if(temp > high) {
				flag = 1;
			}
			if(temp < high && flag == 1) {
				sum++;
				flag = 0;
			}
			high = temp;
		}
		printf("%d\n", sum);
	}
	return 0;
}
