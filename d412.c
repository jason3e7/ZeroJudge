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
	//if (vis[locate][sum + 32000] == 1)
	//	return;
	
	vis[locate][sum] = 1;
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
	while(n--) {
		find = 0;
		scanf("%d", &p);
		for (i = 0; i <= p; i++) 
			scanf("%d", &num[i]);

		for (i = 0; i < 102; i++) 
			for (j = 0; j < 64005; j++) 
				vis[i][j] = 0;

		gettimeofday(&start, NULL);
		DFS(1, num[0]);
		if (find == 0)
			printf("NO EXPRESSION\n");
		gettimeofday(&stop, NULL);
		printf("took %lu\n", stop.tv_usec - start.tv_usec);
	}
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
// 50 14689 8723 19743 17017 7852 18951 7233 16784 9135 4509 13395 31991 22632 11185 30577 15256 4264 14108 3544 4474 14957 31961 10654 12605 28145 5030 24694 320 26873 25410 6970 9561 2133 26712 26577 9984 18015 6162 31119 31501 10670 16865 31491 5653 28049 2419 20909 4664 16526 28804 -9138
