 /*
  * @file d412.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511301030
  */

#include <stdio.h>
#include <sys/time.h>

struct timeval stop, start;

char operator[100];
int p, num[102], find, vis[102][64005];

void DFS(int locate, int sum) {
	int i;
	if (find == 1)
		return;
	
	if (locate == p) {
		if (sum == num[p]) {
			find = 1;
			printf("%d", num[0]);
			for(i = 1; i < p; i++) {
				printf("%c%d", operator[i], num[i]);
			}
			printf("=%d\n", num[p]);
		}
		return;
	}

	if (!(32000 >= sum && sum >= -32000)) 
		return;
	if (vis[locate][sum + 32000] == 1)
		return;
	
	vis[locate][sum + 32000] = 1;
	operator[locate] = '+';
	DFS(locate + 1, sum + num[locate]);	
	operator[locate] = '-';
	DFS(locate + 1, sum - num[locate]);			
	operator[locate] = '*';
	DFS(locate + 1, sum * num[locate]);			
	if (sum % num[locate] == 0) {
		operator[locate] = '/';
		DFS(locate + 1, sum / num[locate]);
	}
}

int main() {
	int i, j, n;
	scanf("%d", &n);
	gettimeofday(&start, NULL);
	while(n--) {
		find = 0;
		scanf("%d", &p);
		for (i = 0; i <= p; i++) 
			scanf("%d", &num[i]);

		for (i = 0; i < 102; i++) 
			for (j = 0; j < 64005; j++) 
				vis[i][j] = 0;

		DFS(1, num[0]);
		if (find == 0)
			printf("NO EXPRESSION\n");
	}
	gettimeofday(&stop, NULL);
	printf("took %lu\n", stop.tv_usec - start.tv_usec);
	/*
	for (i = 0; i < 102; i++) {
		for (j = 0; j < 64005; j++) {
			if (vis[i][j] == 1) {
				printf("%d : %d\n", i, j + 32000);
			}
		}
	}
	*/
	return 0;
}

// test case
// 1 93 20541 12372 26460 8844 26376 3402 3743 16201 10406 18682 23805 10468 1173 14050 18140 13499 7059 13304 26112 510 16810 30787 4728 3764 7543 7128 4693 9875 13293 22817 2920 6185 7540 29379 15029 1915 5132 23123 18116 19889 9804 14272 30356 15328 673 20847 1179 7731 6503 27290 8241 27664 30428 17320 31427 5970 28799 4119 20197 10091 31288 23116 20627 6827 24846 8007 8742 2329 31129 31209 22217 8933 17832 24925 24260 18505 13771 25438 30587 24625 25080 11179 20288 27859 28498 24066 1829 29648 28185 26377 7738 31824 17492 717
