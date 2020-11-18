#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main() {

	// int a[10] = {0}; //in 10 blocks of array 0 is stored
	// cout << a[5];

	/*
		Problem 1:
		int b[10] = {21}; //wrong method only valid for only 0
		cout << b[5]; //0

		Problem 2:
		int n; cin>>n;
		int a[n] = {0}; //error variable size not initialized
		cout<<a[5]<<endl;
	*/

	//Solution to these Problem is memset :

	int n = 10;	// cin>>n; cout<<n;
	int a[n];
	memset(a, -1, sizeof(a)); //value -> 0 & -1
	//It will initialize all block with 0 or -1
	// memset(value,-1,sizeof(val))
	for (int i : a)
		cout << i << " ";

	return 0;
}