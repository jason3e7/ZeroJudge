 /*
  * @file d375.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201511271017
  */

#include <stdio.h>
#define max 10001

int m, lines[max], maxLine, length, flag;

void DFS(int lineSum) {
	if (flag == 1)
		return;
	if (lineSum == length) {
		flag = 1;
		return;
	}

	int i = length - lineSum;
	if (i > maxLine)
		i = maxLine;

	for (; i >= 1; i--) {
		if (lines[i] > 0) {
			lines[i]--;
			DFS(lineSum + i);	
			break;
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

		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			scanf("%d", &temp);
			lines[temp]++;
			sum += temp;
			if (temp > maxLine) 
				maxLine = temp;
		}	

		length = sum / 4;
		flag = 0;
		if ((sum % 4) == 0 && length >= maxLine) {
			for (i = 0; i < 4; i++) {
				flag = 0;
				DFS(0);
				if (flag == 0)
					break;
			}	
		}

		if (flag == 1)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
