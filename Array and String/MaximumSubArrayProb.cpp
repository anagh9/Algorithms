//Its also Known as Kadanes Algorithm

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void maxSubarray(int arr[], int n) {
	int subvalue = arr[0];
	int maxValue = arr[0];
	int new_begin;

	for (int i = 1; i < n; i++) {
		if (subvalue > 0) {
			subvalue += arr[i];
		} else {
			subvalue = arr[i];
			new_begin = i;
		}

		if (maxValue < subvalue) {
			maxValue = subvalue;
		}
	}

	cout << maxValue << endl;
}

int main() {
	int test1[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int test2[] = {1, 2, 3, -4, 5, -16, 7, 8, 9, 0, -11, 2};
	int n = sizeof(test1) / sizeof(test1[0]);
	int m = sizeof(test2) / sizeof(test2[0]);
	maxSubarray(test1, n);
	maxSubarray(test2, n);



	return 0;
}
