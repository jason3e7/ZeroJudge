 /*
  * @file d364.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512011025
  */

#include <stdio.h>
#include <sys/time.h>

struct timeval stop, start;

long timevaldiff(struct timeval *starttime, struct timeval *finishtime) {
	long msec;
	msec=(finishtime->tv_sec-starttime->tv_sec)*1000;
	msec+=(finishtime->tv_usec-starttime->tv_usec)/1000;
	return msec;
}


int s, t, isUse[25], num[31];
int prime[25] = {
2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
73, 79, 83, 89, 97
};

int checkUse(int n) {
	int i;
	for (i = 0; i < 25; i++) {
		if (isUse[i] == 1 && n % prime[i] == 0)
			return 1;
		if (prime[i] > n)
			break;
	}
	return 0;
}

void setFlag(int n, int flag) {
	int i;
	if (n == 1)
		return;
	for (i = 0; i < 25; i++) { 
		if (n % prime[i] == 0)
			isUse[i] = flag;
		if (prime[i] > n)
			break;
	}
	return;
}

void DFS(int begin, int numCount, int sum) {
	int i, j;
	if (numCount == t) {
		if (sum == s) {
			for (i = 0; i < numCount; i++) {
				if ((i + 1) < numCount)
					printf("%d ", num[i]);
				else
					printf("%d\n", num[i]);
			}
		}
		return;
	}
	for (i = begin; i <= (s - sum); i++) {
		if (checkUse(i) == 0) {
			num[numCount] = i;
			setFlag(i, 1);
			DFS(i, numCount + 1, sum + i);
			setFlag(i, 0);
			num[numCount] = 0;
		}
	}	
}

int main() {	
	int i, j, n;
	while (scanf("%d", &n) != EOF) {
		for (i = 1; i <= n; i++) {
			for (j = 0; j < 25; j++) 
				isUse[j] = 0;
			for (j = 0; j < 31; j++)
				num[j] = 0;
			printf("Case %d:\n", i);
			scanf("%d %d", &s, &t);
			gettimeofday(&start, NULL);
			DFS(1, 0, 0);
			gettimeofday(&stop, NULL);
			long msec = timevaldiff(&start, &stop);
			printf("Elapsed time for sleep(1) is: %d milliseconds.\n", msec);
		}
	}
	return 0;
}

// test case
// 1 60 8
// 1 100 30
