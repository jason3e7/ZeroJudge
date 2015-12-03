 /*
  * @file c074.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512021806
  */

#include <stdio.h>
#define lottoSize 6
#define lottoNum 50

int k, num[lottoNum], ans[lottoSize];

void DFS(int begin, int count) {
	int i;
	if (count == lottoSize) {
		for(i = 0; i < lottoSize; i++) {
			if (i != 5) {
				printf("%d ", ans[i]);
			} else {
				printf("%d\n", ans[i]);
			}
		}
		return;
	}
	for (i = begin; i < lottoNum; i++) {
		if (num[i] == 1) {
			num[i]--;
			ans[count] = i;
			DFS(i + 1, count + 1);
			num[i]++;
		}
	}	
}

int main() {
	int i, temp, flag = 0;
	while(scanf("%d", &k) != EOF) {
		if (k == 0)
			break;
		if (flag == 1)
			printf("\n");
		for (i = 1; i < lottoNum; i++) 
			num[i] = 0;
		for (i = 1; i < lottoSize; i++)  
			ans[i] = 0;
		
		for (i = 0; i < k; i++) {
			scanf("%d", &temp);
			num[temp] = 1;
		}
		DFS(1, 0);
		flag = 1;
	}
	return 0;
}
