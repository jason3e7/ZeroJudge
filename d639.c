 /*
  * @file d639.c
  * @author Jason3e7
  * @algorithm math(Fast Power)
  * @date 201710261149
  * @note find mod10007 loop not work

ex: 1 1 2 3 
1 1  1 1
1 0  1 0

2 1  1 1
1 1  1 0

3 2
2 1

    | an     |   | an + 1 |
A *	| an - 1 | = | an     |
    | an - 2 |   | an - 1 |
    
    | 1 1 1 |
A = | 1 0 0 |
    | 0 1 0 |

 n   |a3|   | an + 3 |
A  * |a2| = | an + 2 |
     |a1|   | an + 1 |

1 1 1  1 1 1 
1 0 0  1 0 0
0 1 0  0 1 0

2 2 1  1     5
1 1 1  1  => 3
1 0 0  1     1

  */

#include <stdio.h>
#include <string.h>
 
int out[3][3], base[3][3];

int baseDouble() {
	int i, j, temp[3][3];
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			temp[i][j] = (base[i][0] * base[0][j]) % 10007;
			temp[i][j] += (base[i][1] * base[1][j]) % 10007;
			temp[i][j] += (base[i][2] * base[2][j]) % 10007;
			temp[i][j] = temp[i][j] % 10007;
		}
	}
	memcpy(base, temp, sizeof(temp));
	return 0;
}

int matrixMuti() {
	int i, j, temp[3][3];
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			temp[i][j] = (out[i][0] * base[0][j]) % 10007;
			temp[i][j] += (out[i][1] * base[1][j]) % 10007;
			temp[i][j] += (out[i][2] * base[2][j]) % 10007;
			temp[i][j] = temp[i][j] % 10007;
		}
	}
	memcpy(out, temp, sizeof(temp));
	return 0;
}

int main() {
	int n, point, bit[32], i, first, j;
	while(scanf("%d", &n) != EOF) {
		if(n <= 3) {
			printf("1\n");
			continue;
		}
		n--;
		base[0][0] = 1;
		base[0][1] = 1;
		base[0][2] = 1;
		base[1][0] = 1;
		base[1][1] = 0;
		base[1][2] = 0;
		base[2][0] = 0;
		base[2][1] = 1;
		base[2][2] = 0;
		point = 0;
		do {
			bit[point] = n%2;
			point++;
		} while(n/=2);
		first = 1;
		for(i = 0; i < point; i++) {
			if(bit[i] == 1) {
				if(first == 1) {
					memcpy(out, base, sizeof(base));
					first = 0;
				} else {
					matrixMuti();
				}
			}
			baseDouble();
		}
		printf("%d\n", (out[2][0] + out[2][1] + out[2][2]) % 10007);
	}
	return 0;
}

