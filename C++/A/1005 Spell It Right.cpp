Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.
Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (≤10​100​​).
Output Specification:

For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.
Sample Input:

12345

Sample Output:

one five

-----------------------------------------------
#include<iostream>
using namespace std;
string eng[10] = {"zero", "one", "two", "three", "four", 
				"five", "six", "seven", "eight", "nine"};
int main () {
	string n, ans;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i < n.length(); i++) {
		sum += n[i] - '0'; 
	}
	ans = to_string(sum);
	for (int i = 0; i < ans.length(); i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%s", eng[ans[i] - '0'].c_str());
	}
	return 0;
}
