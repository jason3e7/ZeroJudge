 /*
  * @file d375.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511271017
  */

#include <stdio.h>
#define max 10001

int m, lines[max], maxLine, length, find, ans[4];

void DFS(int numCount, int lineCount) {
	int i;
	if (ans[lineCount] > length || find == 1) 
		return;
	if (ans[lineCount] == length)
		lineCount++;
	if (numCount == m && lineCount == 4) {
		find = 1;	
		return;
	}
	for (i = maxLine; i >= 1; i--) {
		if (lines[i] > 0) {
			lines[i]--;
			ans[lineCount] += i;
			DFS(numCount + 1, lineCount);
			ans[lineCount] -= i;
			lines[i]++;
		}
	}
	return;
}

int main() {
	int n, i, temp, sum;
	scanf("%d", &n);
	while(n--) {
		sum = 0;
		maxLine = 0;
		for (i = 0; i < max; i++)
			lines[i] = 0;
		for (i = 0; i < 4; i++)
			ans[i] = 0;
		find = 0;

		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d", &temp);
			lines[temp]++;
			sum += temp;
			if (temp > maxLine) 
				maxLine = temp;
		}	
		length = sum / 4;
		printf("length: %d  ", length);
		printf("can mod 4: %d\n", sum % 4);
		if ((sum % 4) == 0 && length >= maxLine)
			DFS(0, 0);

		if (find == 1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
