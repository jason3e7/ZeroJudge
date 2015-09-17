/*
 * @file d574.c
 * @author Jason3e7
 * @date 201509171041
 */

#include <stdio.h>
#include <string.h>

char magic[10000000];

int getDigits(int n) {
	int count = 1;
	while(n / 10) {
		n /= 10;
		count++;
	}
	return count;
}

int main() {
	int n, i, count, tempCount;
	char temp;
	while(scanf("%d", &n) != EOF) {
		scanf("%s", &magic);
		count = 0;
		temp = '0';
		tempCount = 0;
		for (i = 0; i < n; i++) {
			if (temp != magic[i]) {
				count += getDigits(tempCount);

				temp = magic[i];
				tempCount = 1;
				count++;
			} else {
				tempCount++;
			}
		}
		if (count >= n) {
			printf("%s\n", magic);
		} else {
			temp = magic[0];
			tempCount = 1;
			for (i = 1; i < n; i++) {
				if (temp != magic[i]) {
					printf("%d%c", tempCount, temp);
					temp = magic[i];
					tempCount = 1;
				} else {
					tempCount++;
				}
			}
			printf("%d%c\n", tempCount, temp);
		}
	}
	return 0;
}

/*
	printf("%d %d\n", count, n);

*/
// why big array can out main 
// in main is break;
