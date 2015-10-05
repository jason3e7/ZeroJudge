/*
 * @file d575.c
 * @author Jason3e7
 * @date 201510051646
 */

#include <stdio.h>
#include <string.h>

int main() {
	int n, k, i, j, l, Iflag, outFlag, sum, ntemp;
	char memory[4][21][21], room[21][21];
	while(scanf("%d %d", &n, &k) != EOF) {
		for(i = 0; i < n; i++) 
			scanf("%s", memory[0][i]);
		for(l = 0; l < 3; l++) 
			for(i = 0; i < n; i++) 
				for(j = 0; j < n; j++) 
					memory[l + 1][(n - 1) - j][i] = memory[l][i][j];
		sum = 0;
		ntemp = n - 1;
		while(ntemp--) {
			for(i = 0; i < n; i++) { 
				scanf("%s", room[i]);
				if (strlen(room[i]) == 0) {
					i--;
				}
			}
			outFlag = 0;
			for(l = 0; l <= 3; l++) {
				Iflag = 1;
				for(i = 0; i < n; i++) {
					for(j = 0; j < n; j++) {
						if (memory[l][i][j] != room[i][j]) {
							Iflag = 0;
							break;
						}
					}
					if (Iflag == 0)
						break;
				}
				if (Iflag == 1)
					outFlag = 1;
			}
			if (outFlag == 1) 
				sum++;
		}
		printf("%d\n", sum);
	}
	return 0;
}

//printf("%d %d : %c => %d %d : %c\n", i, j, memory[l][i][j], (n - 1) -j, i, memory[l + 1][(n - 1) - j][i]);
/*
			printf("%s\n", memory[0][i]);
			for(j = 0; j < n; j++) {
				printf("%d %d : %c\n", i, j, memory[l][i][j]);
			}
*/
