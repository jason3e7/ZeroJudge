 /*
  * @file d835.c
  * @author Jason3e7
  * @algorithm string
  * @date 201803141043
  */
 
#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;
	int i, s11[10001][2], s21[10001][2], s11p = 0, s21p = 0;
	for(i = 0; i < 10001; i++) {
		s11[i][0] = 0;
		s11[i][1] = 0;
		s21[i][0] = 0;
		s21[i][1] = 0;
	}
	while((c = getchar()) != EOF) {
		if(c == 'E') {
			break;
		}
		if(c == 'W') {
			s11[s11p][0]++;
			s21[s21p][0]++;
		}
		if(c == 'L') {
			s11[s11p][1]++;
			s21[s21p][1]++;
		}
		if((s11[s11p][0] >= 11 || s11[s11p][1] >= 11) && abs(s11[s11p][0] - s11[s11p][1]) >= 2) {
			s11p++;
		}
		if((s21[s21p][0] >= 21 || s21[s21p][1] >= 21) && abs(s21[s21p][0] - s21[s21p][1]) >= 2) {
			s21p++;
		}
	}
	for(i = 0; i <= s11p; i++) {
		printf("%d:%d\n", s11[i][0], s11[i][1]);
	}
	printf("\n");
	for(i = 0; i <= s21p; i++) {
		printf("%d:%d\n", s21[i][0], s21[i][1]);
	}
	return 0;
}
