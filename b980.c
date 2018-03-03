 /*
  * @file b980.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803031447
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)b - *(int*)a );
}

int main() {
	int n, tmp, point, nums[10001], i;
	while(scanf("%d", &n) != EOF) {
		point = 0;
		while(scanf("%d", &tmp)) {
			if(tmp == -1) {
				break;
			}
			nums[point] = tmp;
			point++;
		}		
		qsort(nums, point, sizeof(int), cmpfunc);
		tmp = 0;
		for(i = 0; i < point && i < n; i++) {
			tmp += nums[i];
		}
		printf("%d\n", tmp);
	}
	return 0;
}
