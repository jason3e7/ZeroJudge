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

int main() {
	int n,  f[1001], i, j;
	f[0] = 0, f[1] = 1, f[2] = 1, f[3] = 1;
	for(i = 4; i < 1001; i++) {
		f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % 10007;
	}
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", f[n]);
	}
	return 0;
}

