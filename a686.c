 /*
  * @file a686.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201802140954
  */

#include <stdio.h>

int main() {
	int n, x, y, z, day;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%d %d %d", &x, &y, &z);
			x -= y;
			day = 1;
			if(x <= 0) {
				printf("1\n");
			} else if(y <= z) {
				printf("Poor Snail\n");
			} else {
				day += (x / (y - z));
				if(x % (y - z) != 0) {
					day++;
				} 
				printf("%d\n", day);
			}
		}
	}
	return 0;
}
