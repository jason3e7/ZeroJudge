 /*
  * @file c130.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511250950
  */

#include <stdio.h>
#define maxNum 1000
// zerojudge and uva 100 re 101 re why

int t, n, num[maxNum], isUse[maxNum], hasAns;

void DFS(int end, int sum) {
	int i;
	if (sum > t) 
		return;
	if (sum == t) {
		hasAns = 1;
		int flag = 1, count;
		for(i = (maxNum - 1); i >= 1; i--) {
			count = isUse[i];
			while (count--) {
				if (flag == 1) {
					printf("%d", i);
					flag = 0;
				} else {
					printf("+%d", i);
				}
			}
		}
		printf("\n");
		return;
	}
	for (i = end; i >= 1; i--) {
		if (num[i] > 0) {
			num[i]--;
			isUse[i]++;
			DFS(i, sum + i);
			isUse[i]--;
			num[i]++;
		}
	}	
}

int main() {
	int i, temp;
	while(scanf("%d %d", &t, &n) != EOF) {
		if (t == 0 && n == 0)
			break;
		for (i = 0; i < maxNum; i++) {
			num[i] = 0;			
			isUse[i] = 0;			
		}
		printf("Sums of %d:\n", t);
		for (i = 0; i < n; i++) { 
			scanf("%d", &temp);
			num[temp]++;
		}
		hasAns = 0;
		DFS(maxNum - 1, 0);
		if (hasAns == 0) 
			printf("NONE\n");
	}
	return 0;
}
