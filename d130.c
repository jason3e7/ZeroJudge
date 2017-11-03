 /*
  * @file d130.c
  * @author Jason3e7
  * @algorithm  
  * @UVa 138
  * @date 201711041003
  */

#include <stdio.h>

int main() {
	int n[10] = {0}, k[10] = {0}, point = 0, i;
	int leftSum = 1, mid = 2, rightSum = 0, right;
	while(1) {
		right = mid + 1;
		rightSum = 0;
		while(leftSum > rightSum) {
			rightSum += right;
			if (leftSum == rightSum) {
				n[point] = right;
				k[point] = mid;
				point++;
			}
			right++;
		}
		leftSum += mid;
		mid++;
		if(point == 6) {
			break;
		}
	}
	for(i = 0; i < 10; i++) {
		printf("%10d%10d\n", k[i], n[i]);
	}
	return 0;
}

