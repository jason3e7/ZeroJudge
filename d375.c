 /*
  * @file d375.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511271017
  */

#include <stdio.h>

int m, lines[21], isUse[21], length, find, ans[4];

void DFS(int begin, int lineCount) {

	if (ans[lineCount] > length || find == 1)
		return;
	if (ans[lineCount] == length) {
		lineCount++;
		begin = 1;
	}
	if (lineCount == 3) {
		find = 1;
		return;
	}
	int i;
	for (i = begin; i < m; i++) {
		if (isUse[i] == 0) {
			isUse[i]++;
			ans[lineCount] += lines[i];
			DFS(i + 1, lineCount);
			ans[lineCount] -= lines[i];
			isUse[i]--;
		}
		if (find == 1)
			break;
	}
	return;
}

int main() {
	int n, i, j, temp, sum, maxLocal;
	scanf("%d", &n);
	while(n--) {
		sum = 0;
		maxLocal = 0;
		for (i = 0; i < 21; i++) {
			lines[i] = 0;
			isUse[i] = 0;
		}
		for (i = 0; i < 4; i++)
			ans[i] = 0;

		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d", &lines[i]);
			sum += lines[i];
		}	
		for (i = 0; i < m; i++) {
			for (j = i + 1; j < m; j++) {
				if (lines[i] < lines[j]) {
					temp = lines[i];
					lines[i] = lines[j];
					lines[j] = temp;
				}
			}
		}
		length = sum / 4;
		find = 0;
		if ((sum % 4) == 0 && length >= lines[0]) {
			isUse[0]++;
			ans[0] = lines[0];
			DFS(1, 0);
		}
		if (find == 1)
			printf("yes\n");
		else 
			printf("no\n");
	}
	return 0;
}

// 1 18 89 33 63 97 45 3 43 99 15 53 85 79 51 25 1 21 7 3 
// yes
