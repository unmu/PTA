As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.
Input Specification:

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C​1​​ and C​2​​ - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c​1​​, c​2​​ and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C​1​​ to C​2​​.
Output Specification:

For each test case, print in one line two numbers: the number of different shortest paths between C​1​​ and C​2​​, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.
Sample Input:

5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

Sample Output:

2 4

-----------------------------------------------------------------------
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main () {
	int n, m, c1, c2, t1, t2, l, maxr = 0;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	vector<int> dis(n, INT_MAX), num(n), w(n), book(n), res(n);
	vector<vector<int> > e(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		scanf("%d", &w[i]);
		
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				e[i][j] = 0;
			} else {
				e[i][j] = INT_MAX;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &t1, &t2, &l);
		e[t1][t2] = l;
		e[t2][t1] = l;
	}
	dis[c1] = 0;
	res[c1] = w[c1];
	num[c1] = 1;
	int minn, f;
	for (int i = 1; i < n; i++) {
		minn = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (book[j] == 0 && dis[j] < minn) {
				minn = dis[j];
				f = j;
			}
		}
		if (minn == INT_MAX) {
			break;
		}
		book[f] = 1;
		for (int t = 0; t < n; t++) {
			if (e[f][t] < INT_MAX && book[t] == 0) {
				if (dis[t] == dis[f] + e[f][t]) {
					num[t] += num[f];
					if (res[t] < res[f] + w[t]) {
						res[t] = res[f] + w[t];
					}
				} else if (dis[t] > dis[f] + e[f][t]) {
					dis[t] = dis[f] + e[f][t];
					num[t] = num[f];
					res[t] = res[f] + w[t];
				}
			}
		}
	}
	printf("%d %d\n", num[c2], res[c2]);
	return 0;
}
