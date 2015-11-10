 /*
  * @file a054.c
  * @author Jason3e7
  * @date 201511101421
  */

#include <stdio.h>

int main() {
	int i, total, ini, totalTemp;
	int num[27], temp = 10;
	num[8] = 34;
	num[14] = 35;
	num[22] = 32;
	num[25] = 33;
	for (i = 0; i < 25; i++, temp++) {
		if (temp == 18 || temp == 23 || temp == 30) 
			i++;
		num[i] = temp;
	}
	while(scanf("%d", &ini)!= EOF){
		total = ini % 10;
		ini /= 10;
		for(i = 1; i <= 8; i++) {
			total += (ini % 10) * i;
			ini /= 10;
		}
		for(i = 0; i < 26; i++) {
			totalTemp = total + (num[i] % 10) * 9 + (num[i] / 10);
			if(totalTemp % 10 == 0) 
				printf("%c", i + 'A');
		}
		printf("\n");
	}
	return 0;
}
