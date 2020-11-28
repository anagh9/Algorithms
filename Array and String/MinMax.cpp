#include<bits/stdc++.h>
#define ll long long
using namespace std;


void getMinMax(int arr[], int n) {
	int min = 0, max = 0;
	if (n == 1) {
		min = arr[0];
		max = arr[0];
	}

	if (arr[0] > arr[1]) {
		max = arr[0];
		min = arr[1];
	}

	else {
		max = arr[1];
		min = arr[0];
	}

	for (int i = 2; i < n; i++) {
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}


	cout << "Max :" << max << endl;
	cout << "Min :" << min << endl;
}

// TC = O(N)



//Kth Min and Max element
void KthMinMax(int arr[], int n, int k) {
	sort(arr, arr + n);
	cout << k << "th Min " << arr[k - 1] << endl;
	cout << k << "th Max " << arr[n - k] << endl;

}

int main() {
	int arr[] = {1, 2, 3, 4, 5, 900, 6, 1000};
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int x : arr)
		cout << x << " ";
	cout << endl;
	getMinMax(arr, n);
	KthMinMax(arr, n, 5);

	return 0;
}