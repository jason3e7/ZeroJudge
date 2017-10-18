 /*
  * @file c297.c
  * @author Jason3e7
  * @algorithm simulation
  * @date 201710181225
  */

#include <stdio.h>
#include <string.h>

int base[4] = {0};

int run(int n) {
	int i, out = 0;
	for(i = 3; i >= 1; i--) {
		if(base[i] == 1) {
			base[i] = 0;
			if ((i + n) >= 4) {
				out++; 
			} else {
				base[i + n] = 1;
			}
		}
	}
	if(n == 4) {
		out++;
	} else {
		base[n] = 1;
	}
	return out;
}

int clearBase() {
	int i;
	for(i = 0; i < 4; i++) {
		base[i] = 0;
	}
	return 0;
}

int printBase() {
	int i;
	for(i = 1; i <= 3; i++) {
		printf("base %d : is %d\n", i, base[i]);
	}
	return 0;
}

int main() {
	int out[27], play[9][5], temp, i, j, outCount, score;
	char line[1000];
	while(scanf("%d", &temp) != EOF) {
		// init
		for(i = 0; i < 27; i++) {
			out[i] = 0;
		}
		for(i = 0; i < 9; i++) {
			for(j = 0; j < 5; j++) {
				play[i][j] = -1;
			}
		}
		// input
		for(i = 0; i < 9; i++) {
			if(i > 0) {
				scanf("%d", &temp);
			}
			for(j = 0; j < temp; j++) {
				scanf("%s", line);
				if(strstr(line, "FO") != NULL || strstr(line, "GO") != NULL || strstr(line, "SO") != NULL) {
					play[i][j] = 0;
				} else if(strstr(line, "1B") != NULL) {
					play[i][j] = 1;
				} else if(strstr(line, "2B") != NULL) {
					play[i][j] = 2;
				} else if(strstr(line, "3B") != NULL) {
					play[i][j] = 3;
				} else if(strstr(line, "HR") != NULL) {
					play[i][j] = 4;
				}
			}
		}
		for(i = 0; i < 5; i++) {
			for(j = 0; j < 9; j++) {
				printf("%d ", play[j][i]);
			}
			printf("\n");
		}
		
		// simulation
		clearBase();
		score = 0;
		outCount = 0;
		for(i = 0; i < 5; i++) {
			for(j = 0; j < 9; j++) {
				if(play[j][i] == 0) {
					out[outCount] = score;
					outCount++;
					if(outCount % 3 == 0) {
						clearBase();
					}
				} else if(play[j][i] > 0) {
					score += run(play[j][i]);
				} else if(play[j][i] < 0) {
					break;
				}
				printf("======================\n");
				printf("play : %d %d\n", j, i);
				printf("score : %d\n", score);
				printf("out : %d\n", outCount);
				printBase();
			}
		}
		scanf("%d", &temp);
		printf("%d\n", temp);
	}
	return 0;
}




