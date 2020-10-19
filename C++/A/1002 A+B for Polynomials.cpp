This time, you are supposed to find A+B where A and B are two polynomials.
Input Specification:

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N​1​​ a​N​1​​​​ N​2​​ a​N​2​​​​ ... N​K​​ a​N​K​​​​

where K is the number of nonzero terms in the polynomial, N​i​​ and a​N​i​​​​ (i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤N​K​​<⋯<N​2​​<N​1​​≤1000.
Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.
Sample Input:

2 1 2.4 0 3.2
2 2 1.5 1 0.5

Sample Output:

3 2 1.5 1 2.9 0 3.2

--------------------------------------------
#include<iostream>
#include<set>
#include<cmath>
#include<vector>
using namespace std;
int main () {
	int k, n, cnt = 0;
	double a, b[1005] = {0};
	for (int i = 0; i < 2; i++) {
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			scanf("%d %lf", &n, &a);
			b[n] += a;
		}
	}
	for (int i = 0; i <= 1000; i++) {
		if (b[i] != 0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	for (int i = 1000; i >= 0; i--) {
		if (b[i] != 0) {
			printf(" %d %.1lf", i, b[i]);
		}
	} 
	return 0;
} 
