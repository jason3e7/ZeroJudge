 /*
  * @file a158.c
  * @author Jason3e7
  * @algorithm GCD 
  * @UVa 11827
  * @date 201710281014
  */

#include <stdio.h>
#include <string.h>

void clean_stdin(void) {
    char c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

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

int getLineNumber(char line[], int number[], int* point) {
	int length = strlen(line), flag = 0, count = 0, i;
	for(i = 0; i < length; i++) {
		if('0' <= line[i] && line[i] <= '9') {
			count *= 10;
			count += (line[i] - '0');
			flag = 1;
			if(i == length - 1) {
				number[*point] = count;
				(*point)++;
			}
		} else {
			if(flag == 1) {
				number[*point] = count;
				(*point)++;
				count = 0;
				flag = 0;
			}
		}
	}
	return 0;
}

int GCD(int a, int b) {
	if(b) while((a %= b) && (b %= a)); 
	return a + b;
}

int main() {
	int i, j, n, max, num[101], point, gcd;
	char line[10001];
	while(scanf("%d", &n) != EOF) {
		clean_stdin();
		while(n--) {
			fix_fgets(line, 100001);
			point = 0;
			max = 1;
			getLineNumber(line, num, &point);
			for(i = 0; i < point; i++) {
				for(j = i + 1; j < point; j++) {
					gcd = GCD(num[i], num[j]);
					if(gcd > max) {
						max = gcd;
					}
				}
			}
			printf("%d\n", max);
		}
	}
	return 0;
}

