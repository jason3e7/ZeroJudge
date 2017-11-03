 /*
  * @file d130.c
  * @author Jason3e7
  * @algorithm  
  * @UVa 138
  * @date 201711041003
  * @note while(1) Wrong answer Why !?
  */

#include <stdio.h>

int main() {
	int point, i;
	unsigned long long int n[10] = {0}, k[10] = {0};
	unsigned long long int leftSum = 1, mid = 2, rightSum = 3, rightEnd = 4;
	while(point < 10) {
		while(leftSum > rightSum) {
			rightSum += rightEnd;
			if (leftSum == rightSum) {
				n[point] = rightEnd;
				k[point] = mid;
				point++;
			}
			rightEnd++;
		}
		leftSum += mid;
		mid++;
		rightSum -= mid;
	}
	for(i = 0; i < 10; i++) {
		printf("%10llu%10llu\n", k[i], n[i]);
	}
	return 0;
}

