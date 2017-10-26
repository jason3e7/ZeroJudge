 /*
  * @file d244.c
  * @author Jason3e7
  * @algorithm array
  * @date 201710261942
  * @note if((count[i] % 3) != 0) not work
  */

#include <stdio.h>
#include <string.h>

char * fix_fgets(char * str, int n) {
	char * ret_val;
	int i;
	ret_val = fgets(str, n, stdin);
	if(ret_val) {
		for(i = 0; i < n; i++) {
			if(str[i] == '\n' || str[i] == '\r') {
				str[i] = '\0';
				break;
			}
		} 
	}
	return ret_val;
}
 
int num[10001], count[10001], point;

int insertNum(int n) {
	int i;
	for(i = 0; i < point; i++) {
		if(num[i] == n) {
			count[i]++;
			return 0;
		} 
	}
	num[point] = n;
	count[point] = 1;
	point++;
	return 0;
}
	
int main() {
	char line[100001];
	int i, length, numFlag, temp;
	while(fix_fgets(line, 100001) != NULL) {
		for(i = 0; i < 10001; i++) {
			num[i] = -1;
			count[i] = 0;
		}
		length = strlen(line);
		numFlag = 0;
		temp = 0;
		point = 0;
		for(i = 0; i < length; i++) {
			if('0' <= line[i] && line[i] <= '9') {
				temp *= 10;
				temp += (line[i] - '0');
				numFlag = 1;
				if(i == (length - 1)) {
					insertNum(temp);
				}
			} else {
				if(numFlag == 1) {
					numFlag = 0;
					insertNum(temp);
					temp = 0;
				}
			}
		}
		for(i = 0; i < 10001; i++) {
			if(count[i] % 3 == 2) {
				printf("%d\n", num[i]);
				break;
			}
		}
	}
	return 0;
}
