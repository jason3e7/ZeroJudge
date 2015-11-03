/*
 * @file b540.c
 * @author Jason3e7
 * @date 201511031233
 */

#include <stdio.h>

int l[6], line, num;

void checkShape() {
	int i;
	line = 0;
	for (i = 0; i < 6; i++) {
		if (l[i] != 0) {
			line++;
			num = l[i];
		}
	}
}

int getSum() {
	checkShape();
	int i, sum = 0;
	printf("line : %d\n", line);
	for (i = 0; i < 6; i++) 
		printf(" %d ", l[i]);
	if (line <= 2) {
		return 0;
	}
	if (line == 3) {
		for (i = 1; i <= num; i++) {
			sum += (i * 2 - 1);
		}
		return sum;
	}
	if (line == 4) {
		int mutiOne = 0;
		for (i = 0; i < 6; i++) 
			if (l[i] == 1) 
				mutiOne++;
		if (mutiOne >= 2) {
			for (i = 0; i < 6; i++) {
				if (l[i] != 0) {
					sum += l[i];
					l[i]--;
				}
			}
			sum -= 2;
		} else {
			for (i = 0; i < 6; i++) {
				if (l[i] != 0) {
					sum += (l[i] * 2 - 1);
					l[i]--;
				}
			}
			sum -= 4;
		}
		return sum + getSum();
	}
	if (line == 5) {	
		for (i = 0; i < 6; i++) {
			if (l[i] != 0) {
				sum += (l[i] * 2 - 1);
				l[i]--;
			}
		}
		sum -= 2;
		return sum + getSum();
	}
	if (line == 6) {	
		for (i = 0; i < 6; i++) {
			sum += (l[i] * 2 - 1);
			l[i]--;
		}
		return sum + getSum();
	}
}

int main() {
	while(scanf("%d %d %d %d %d %d", &l[0], &l[1], &l[2], &l[3], &l[4], &l[5]) != EOF) {
		printf("%d\n", getSum());
	}
	return 0;
}
