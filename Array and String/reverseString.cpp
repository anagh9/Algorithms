#include<bits/stdc++.h>
#define ll long long
using namespace std;

void swap(char &a, char &b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void reverse(char *s) {
	int n = strlen(s);
	for (int i = 0; i < n / 2; ++i)
		swap(s[i], s[n - i - 1]);
}



int main() {
	char s[] = "Anagh Is A Good Boy";
	char p[] = "1234567890";
	reverse(s);
	reverse(p);
	cout << s << "\n" << p;


	return 0;
}