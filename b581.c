/*
 * @file d581.c
 * @author Jason3e7
 * @date 201510051627
 */

#include <stdio.h>

int main() {
	int t, Itemp, sum, flag;
	char Ctemp;
	scanf("%d", &t);
	getchar();
	while (t--) {
		Itemp = 0;
		sum = 0;
		flag = 0;
		while (1) {
			Ctemp = getchar();
			if (Ctemp == '\n' || Ctemp == EOF)
				break;
			if ('0' <= Ctemp && Ctemp <= '9') {
				flag = 1;
				Itemp = Itemp * 10;
				Itemp += Ctemp - '0';
			} else {
				if (flag == 1) {
					flag = 0;
					sum += Itemp;
					Itemp = 0;
				}
			}
		}
		sum += Itemp;
		printf("%d\n", sum);
	}
	
	return 0;
}

//printf("%d %d\n", Itemp, Ctemp);
