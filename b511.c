 /*
  * @file b511.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710211249
  */

#include <stdio.h>

int coin[5] = {0}, sum = 0, n;
int ans[100][5] = {0}, ansPoint = 0, temp[5] = {0}, tempSum = 0;

int arrayCopy(int a[], int b[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		a[i] = b[i];
	}
	return 0;
}

int findNext(int point) {
	if(point == n) {
		return 0;
	}
	int max, i; 
	max = sum / coin[point];
	for(i = max; i >= 0; i--) {
		int j = point;
		tempSum += (coin[point] * i);
		if(tempSum > sum) {
			tempSum -= (coin[point] * i);
			continue;
		}
		temp[point] = i;
		if(tempSum == sum) {
			arrayCopy(ans[ansPoint], temp, n);
			ansPoint++;
		}
		if(tempSum < sum) {
			findNext(point + 1);
		}
		tempSum -= (coin[point] * i);
		temp[point] = 0;
	}
	return 0;
}

int main() {
	int i, j;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &coin[i]);
		}
		scanf("%d", &sum);
		for(i = 0; i < n; i++) {
			temp[i] = 0;
		}
		ansPoint = 0;
		tempSum = 0;
		findNext(0);	
		for(i = ansPoint - 1; i >= 0; i--) {
			for(j = 0; j < n; j++) {
				if(j == 0) {
					printf("(%d", ans[i][j]);
				} else {
					printf(",%d", ans[i][j]);
				}
			}
			printf(")\n");
		}
	}
	return 0;
}

