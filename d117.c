/*
 * @file d117.c
 * @author Jason3e7
 * @date 201605231019
 */

#include <stdio.h>
#include <string.h>

int main() {
	int i, wordLen, count, flag;
	char word[20];
	while(scanf("%s", &word) != EOF) {
		flag = 1;
		wordLen = strlen(word);
		count = 0;
		for (i = 0; i < wordLen; i++) {
			if (122 >= word[i] && word[i] >= 97)
				count += word[i] - 96;
			if (90 >= word[i] && word[i] >= 65) 
				count += word[i] - 38;
		}
		for (i = 2; i <= count / 2; i++) {
			if (count % i == 0) {
				flag = 0;
				break;
			}
			if (i > 2)
				i++;
		}
		if (flag == 1) {
			printf("It is a prime word.\n");
		} else {
			printf("It is not a prime word.\n");
		}
	}
	return 0;
}

