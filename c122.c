 /*
  * @file c122.c
  * @author Jason3e7
  * @algorithm basic 
  * @UVa 443
  * @date 201711010942
  */

#include <stdio.h>

int prime[5843] = {2, 3, 5, 7};

int check(int n) {
	int i;
	if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0) {
		return 0;
	}
	for(i = 0; i < 4; i++) {
		while(n % prime[i] == 0) {
			n /= prime[i];
		}
	}
	if(n == 1) {
		return 1;
	} 
	return 0;
}

int main() {
	int num[5843], point, count, n;
	num[0] = 0;
	num[1] = 1;
	count = 2;
	point = 2;
	while(point < 1000) {
		if(check(count) == 1) {
			num[point] = count;
			point++;
		}
		count++;
	}
	while(scanf("%d", &n) != EOF) {
		if(n == 0) {
			break;
		}
		if(n / 10 == 1) {
			printf("The %dth humble number is %d.\n", n, num[n]);
		} else if(n % 10 == 1) {
			printf("The %dst humble number is %d.\n", n, num[n]);
		} else if(n % 10 == 2) {
			printf("The %dnd humble number is %d.\n", n, num[n]);
		} else if(n % 10 == 3) {
			printf("The %drd humble number is %d.\n", n, num[n]);
		} else {
			printf("The %dth humble number is %d.\n", n, num[n]);
		}
	}
	return 0;
}

