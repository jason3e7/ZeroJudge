 /*
  * @file b541.c
  * @author Jason3e7
  * @algorithm simulation 
  * @date 201712301709
  */

#include <stdio.h>

int main() {
	char num[100000], temp[100000];
	int n, point, i, save, count, tempP;
	while(scanf("%d", &n) != EOF) {
		num[0] = '1';
		point = 1;
		n--;
		while(n--) {
			save = num[0];
			tempP = 0;
			count = 1;
			for(i = 1; i < point; i++) {
				if(save == num[i]) {
					count++;
				} else {
					temp[tempP] = count + '0';
					temp[tempP + 1] = save;
					tempP += 2;
					save = num[i];
					count = 1;
				}
			}
			temp[tempP] = count + '0';
			temp[tempP + 1] = save;
			tempP += 2;
			for(i = 0; i < tempP; i++) {
				num[i] = temp[i];
			}
			point = tempP;
		}
		for(i = 0; i < point; i++) {
			printf("%c", num[i]);
		}
		printf("\n");
	}
	return 0;
}
