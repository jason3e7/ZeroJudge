 /*
  * @file d130.c
  * @author Jason3e7
  * @algorithm math 
  * @UVa 138
  * @date 201711041003
  * @note while(1) Wrong answer Why !?
  * (1 + k - 1) * (k - 1) / 2 = (1 + n) * n / 2 - (1 + k - 1) * (k - 1) / 2 - k
  * k * (k - 1)  = (1 + n) * n - k * (k - 1) - 2k 
  * k * k - k = n * n + n - k * k + k - 2k 
  * 2k * k = n * n + n
  * k * k = (n * n + n)/2
  */

#include <stdio.h>
#include <math.h>

int main() {
	int i;
	unsigned long long int k, n = 8, temp;
	for(i = 0; i < 10;) {
		temp = (n * n + n) / 2;
		k = (int)sqrt(temp);
		if (k * k == temp) {
			printf("%10llu%10llu\n", k, n);
			i++;
		}
		n++;
	}
	return 0;
}

