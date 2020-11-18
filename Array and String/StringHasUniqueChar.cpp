// Implement an algorithm to determine if a string has all unique characters. What if you can not use additional data structures?

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isUnique1(string s) {
	bool a[256];
	memset(a, 0, sizeof(a));
	int len = s.length();
	for (int i = 0; i < len; i++) {
		int v = (int)s[i];
		if (a[v]) return false;
		// if(a[v]) meaning  if(varName == true) || if(a[v] == 1) || a[v] == true
		// if(!a[v]) meaning if(varName == false) || a[v] == 0 || a[v] == false
		a[v] = true;
	}
	return true;
}//For Reducing Space Complexity

bool isUnique2(string s) {
	int a[8];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < s.length(); i++) {
		int v = (int)s[i];
		int idx = v / 32, shift = v % 32;
		if (a[idx] & (1 << shift)) return false;
		a[idx] |= ( 1 << shift);
	}
	return true;
}


// It will only work for string ranging a-z and A-Z
bool isUnique3(string s) {
	int check = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		int v = (int)(s[i] - 'a');
		if (check & (1 << v)) return false;
		check |= (1 << v);
	}
	return true;
}

int main() {
	string s = "abcdefghijklmnopqrstuvwxyz";
	string s1 = "abcdefghijklmnopqrstuvwxyzABCD1234567890";
	// isUnique1(s) ? cout << "Unique " : cout << "Not Unique ";
	isUnique2(s) ? cout << "Unique " : cout << "Not Unique ";
	isUnique2(s1) ? cout << "Unique " : cout << "Not Unique ";
	isUnique3(s) ? cout << "Unique " : cout << "Not Unique ";


	return 0;
}