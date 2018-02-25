 /*
  * @file d892.c
  * @author Jason3e7
  * @algorithm basic
  * @date 2018022609598
  */

#include <stdio.h>

int main() {
	int m, n, w[101], point, count, i, temp, flag, r;
	while(scanf("%d %d", &m, &n) != EOF) {
		point = 0, count = 0, r = 0;
		while(n--) {
			scanf("%d", &temp);
			flag = 0;
			for(i = 0; i < count; i++) {
				if(temp == w[i]) {
					flag = 1;
					break;
				}
			}
			if(flag == 1) {
				continue;
			}

			r++;
			w[point] = temp;
			point++;
			if(point == m) {
				point = 0;
			}
			if(count < m) {
				count++;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}
