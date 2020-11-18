#include<bits/stdc++.h>
#define ll long long
using namespace std;


// It return x^y
int power(int x, int y) {
	int res = 1;
	while (y > 0) {
		if (y & 1)
			res = (res * x);
		y = y >> 1;
		x = (x * x);
	}
	return res;
}

int main() {
	int x = 5;
	int y = 5;
	cout << power(x, y);
	return 0;
}