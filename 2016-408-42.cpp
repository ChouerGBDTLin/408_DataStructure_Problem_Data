/*
* 2016-408-43：
* 将集合A划分为两个不相交的子集A1, A2。元素个数分别是n1, n2。A1和A2中元素之和分别为S1, S2。
* 要求：设计一个尽可能高效的算法，满足|n1 - n2|最小且|S1 - S2|最大
*/ 
#include <bits/stdc++.h>
using namespace std;
class Problem {
public:
	void p_2016(); 
	int setPartition(int *a, int n);
};
int main(void)
{
	Problem p;
	p.p_2016(); 
	return 0;
}
void Problem::p_2016() {
	int a[10] = { 4, 1, 12, 18, 7, 13, 18, 16, 5, 15 };
	int difference = setPartition(a, 10);
	cout << difference << endl;
}
int Problem::setPartition(int* a, int n) {
	int pivotkey;
	int low = 0, low0 = 0, high = n - 1, high0 = n - 1, flag = 1, k = n / 2;
	int s1 = 0, s2 = 0;
	while (flag) {
		pivotkey = a[low];
		while (low < high) {
			while (low < high && a[high] >= pivotkey) --high;
			if (low != high) a[low] = a[high];
			while (low < high && a[low] <= pivotkey) ++low;
			if (low != high) a[high] = a[low];
		}
		a[low] = pivotkey;
		if (low == k - 1) flag = 0;
		else {
			if (low < k - 1) { low0 = low++; high = high0; }
			else { high0 = --high; low = low0; }
		}
	}
	for (int i = 0; i < k; ++i) s1 += a[i];
	for (int i = k; i < n; ++i) s2 += a[i];
	return s2 - s1;
} 