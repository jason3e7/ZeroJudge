 /*
  * @file d244.c
  * @author Jason3e7
  * @algorithm array
  * @date 201710261942
  * @note 
  *	   if((count[i] % 3) != 0) not work
  *    get number to EOF
  */

#include <stdio.h>

int getNum() {
	char cha;
	int n;
	while(1) {
		cha = getchar();
		if(('0' <= cha && cha <= '9') || cha == EOF) {
			break;
		}
	} 
	if(cha == EOF) {
		return -1;
	}
	n = cha - '0';
	while(1) {
		cha = getchar();
		if('0' <= cha && cha <= '9') {
			n *= 10;
			n += (cha - '0');
		} else {
			break;
		}
	}
	return n;

}
 
int num[100001], count[100001], point;

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
	int n, i;
	while(1) {
		n = getNum();
		if(n == -1) {
			break;
		}
		insertNum(n);
	}
	for(i = 0; i < 100001; i++) {
		if(count[i] % 3 == 2) {
			printf("%d\n", num[i]);
			break;
		}
	}
	return 0;
}
