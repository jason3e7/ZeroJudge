 /*
  * @file d396.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511241433
  */

#include <stdio.h>

int prime[32] = {0}, n, isSet[17] = {0}, ans[17];

int checkPrime(int num, int loc) {
	int nextLoc, prevLoc, next, prev;
	nextLoc = (loc + 1 > n) ? 1 : (loc + 1);
	prevLoc = (loc - 1 > 0) ? (loc - 1) : n;
	next = ans[nextLoc];
	prev = ans[prevLoc];
	if (isSet[next] == 1 && prime[next + num] == 0) 
		return 0;
	if (isSet[prev] == 1 && prime[prev + num] == 0) 
		return 0;
	return 1;
}

void DFS(int count) {	
	int i;
	if (count > n) {
		for(i = 1; i <= n; i++) {
			if (i != n)
				printf("%d ", ans[i]);
			else
				printf("%d\n", ans[i]);
		}
		return;
	}
	for (i = 2; i <= n; i++) {
		if (isSet[i] == 0 && checkPrime(i, count)) {
			ans[count] = i;
			isSet[i] = 1;
			DFS(count + 1);
			isSet[i] = 0;
			ans[count] = 0;
		}
	}	
}

int main() {
	prime[2] = 1;
	prime[3] = 1;
	prime[5] = 1;
	prime[7] = 1;
	prime[11] = 1;
	prime[13] = 1;
	prime[17] = 1;
	prime[19] = 1;
	prime[23] = 1;
	prime[29] = 1;
	prime[31] = 1;
	ans[1] = 1;
	isSet[1] = 1;
	int caseNum = 1;
	while(scanf("%d", &n) != EOF) {
		if (caseNum != 1) 
			printf("\n");
		printf("Case %d:\n", caseNum);
		DFS(2);
		caseNum++;
	}
	return 0;
}
