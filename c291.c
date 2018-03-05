 /*
  * @file c291.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803061133
  */

#include <stdio.h>

int main() {
	int n, i, nums[50001], g, point, tmp;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &nums[i]);
		}
		g = 0;
		for(i = 0; i < n; i++) {
			if(nums[i] != -1) {
				g++;
				point = i;
				while(nums[point] != -1) {
					tmp = nums[point];
					nums[point] = -1;
					point = tmp;
				}
			}
		}
		printf("%d\n", g);
		
	}
	return 0;
}
