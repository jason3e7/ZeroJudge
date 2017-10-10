 /*
  * @file d555_2.c
  * @author Jason3e7
  * @algorithm algorithm
  * @date 201710111040
  */

#include <stdio.h>
int main() {
	int n, map[100001], i, x, y, max, point, c = 1, temp;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < 100001; i++) {
			map[i] = -1;
		}
		max = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			if(y > map[x]) {
				map[x] = y;
			}
			if(x > max) {
				max = x;
			}
		}
		temp = map[max];
		point = 1;
		for(i = max - 1; i >= 0; i--) {
			if(temp >= map[i]) {
				map[i] = -1;
			} else {
				temp = map[i];
				point++;
			}
		}
		printf("Case %d:\n", c);
		printf("Dominate Point: %d\n", point);
		for(i = 0; i <= max; i++) {
			if(map[i] != -1) {
				printf("(%d,%d)\n", i, map[i]);
			}
		}
		c++;
	}
	return 0;
}


