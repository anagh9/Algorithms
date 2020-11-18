#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
void shuffle(T *list , int len) {
	srand(time(NULL));
	T temp;
	int i = len, j;
	if (i == 0) return;
	while (i--) {
		j = rand() % (i + 1);
		temp = list[i];
		list[i] = list[j];
		list[j] = temp;
	}

	for (int i = 0; i < len; i++) {
		cout << list[i] << " ";
	}
	cout << "\n";
}

int main() {

	//Test case 1

	string s[] = {"anagh", "boy", "dj snake", "abhi", "raj", "simran", "puja"};
	int n = sizeof(s) / sizeof(s[0]);
	shuffle(s, n);


	//Test case 2

	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int m = sizeof(arr) / sizeof(arr[0]);
	shuffle(arr, m);


	//Test case 3

	char str[] = {'a', 'b', 'c', 'd', 'f', 'g', 'k', 'o'};
	int len = sizeof(str) / sizeof(str[0]);
	shuffle(str, len);

	return 0;
}