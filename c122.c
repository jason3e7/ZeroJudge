 /*
  * @file c122.c
  * @author Jason3e7
  * @algorithm DP 
  * @UVa 443
  * @date 201711010942
  * @note 111
  */

#include <stdio.h>

int min(int a, int b) {
	if(a < b) {
		return a;
	}
	return b;
}

int main() {
	int i, n, num[5842], point[4] = {0, 0, 0, 0}, minNum;
	num[0] = 1;
	for(i = 1; i < 5842; i++) {
		minNum = min(min(2 * num[point[0]], 3 * num[point[1]]) , min(5 * num[point[2]], 7 * num[point[3]]));
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
		if(minNum == 7 * num[point[3]]) {
			point[3]++;
		}
	}
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		if((n / 10) % 10 == 1) {
			printf("The %dth humble number is %d.\n", n, num[n - 1]);
		} else if(n % 10 == 1) {
			printf("The %dst humble number is %d.\n", n, num[n - 1]);
		} else if(n % 10 == 2) {
			printf("The %dnd humble number is %d.\n", n, num[n - 1]);
		} else if(n % 10 == 3) {
			printf("The %drd humble number is %d.\n", n, num[n - 1]);
		} else {
			printf("The %dth humble number is %d.\n", n, num[n - 1]);
		}
	}
	return 0;
}

