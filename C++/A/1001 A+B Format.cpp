Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).
Input Specification:

Each input file contains one test case. Each case contains a pair of integers a and b where −10​6​​≤a,b≤10​6​​. The numbers are separated by a space.
Output Specification:

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.
Sample Input:

-1000000 9

Sample Output:

-999,991

----------------------------------------------
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main () {
	int a, b;
	scanf("%d %d", &a, &b);
	string sum = to_string(a + b);
	for (int i = 0; i < sum.length(); i++) {
		cout << sum[i];
		if (sum[i] == '-') {
			continue;
		}
		if ((i + 1) % 3 == sum.length() % 3 && i != sum.length() - 1) {
			cout << ",";
		}
	}
	return 0;
}

---------------------------------------
(i + 1) % 3 == sum.length() % 3
