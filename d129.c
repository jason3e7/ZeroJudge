 /*
  * @file d129.c
  * @author Jason3e7
  * @algorithm DP 
  * @UVa 136
  * @date 201711031045
  * @note c122
  */

#include <stdio.h>

int min(int a, int b) {
	if(a < b) {
		return a;
	}
	return b;
}

int main() {
	int i, n, num[1500], point[3] = {0, 0, 0}, minNum;
	num[0] = 1;
	for(i = 1; i < 1500; i++) {
		minNum = min(min(2 * num[point[0]], 3 * num[point[1]]) , 5 * num[point[2]]);
		num[i] = minNum;
		if(minNum == 2 * num[point[0]]) {
			point[0]++;
		}
		if(minNum == 3 * num[point[1]]) {
			point[1]++;
		}
		if(minNum == 5 * num[point[2]]) {
			point[2]++;
		}
	}
	printf("The 1500'th ugly number is %d.\n", num[1499]);
	return 0;
}

