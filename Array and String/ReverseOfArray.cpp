//Reverse of Array

/***Iterative Solution

Initialize start  = 0
end = n-1
In loop swap arr[start] and arr[end]
change start = start +1 ,
end = end-1

*/

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void reverseArray(int arr[], int start, int end)
{
	while (start < end)
	{
		swap(arr[start], arr[end]);
		start++;
		end--;
	}
}


/***
Recursive Solution
Initialize start and end indexes as start =0, end = n-1,
Swap arr[start] and arr[end]
Recursively call reverse for rest of the array.

*/

void RreverseArray(int arr[], int start, int end) {
	if (start >= end)
		return;
	swap(arr[start], arr[end]);
	RreverseArray(arr, start + 1, end - 1);
}

void printList(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int n = sizeof(arr) / sizeof(arr[0]);
	// reverseArray(arr, 0, n - 1);
	RreverseArray(arr, 0, n - 1);
	printList(arr, n);
}

//TC = O(n);