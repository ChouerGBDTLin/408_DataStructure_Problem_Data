#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int* a, int x, int n);

int main(void)
{
	int a[10] = { 1, 3, 6, 8, 9, 19, 35, 50 };
	cout << "元素8在数组中的第" << BinarySearch(a, 8, 8) << "个位置！" << endl; 
	int pos = BinarySearch(a, 10, 8);
	if (pos == -1)
		cout << "不存在 ！" << endl;
	else
		cout << "元素10在第" << pos << "的位置！" << endl;
	
	
	return 0;
}
int BinarySearch(int* a, int x, int n) {
	int low = 0, high = n - 1;
	
	while (low <= high) {
		int mid = (low + high) / 2;
		if (a[mid] == x)
			return mid + 1;
		else if (a[mid] > x)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}