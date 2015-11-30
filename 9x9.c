#include <stdio.h>

int main() {
	int i, j, k;
	for (i = 1; i <= 7; i += 3) {
		for (j = 1; j <= 9; j++) {
			for (k = i; k <= i + 2; k++) {
				if (k != (i + 2))
					printf("%d * %d = %-5d",  k, j, k * j);
				else
					printf("%d * %d = %d\n",  k, j, k * j);
			}
		}
		printf("\n");
	}
}
