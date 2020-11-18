//Prime Test Implementation

//Main Function for finding Prime no are test_prime and isPrimeee

// Daniel's Algorithms Implementation

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool test_prime(unsigned int n) {
	if (n % 2 == 0) return false;
	unsigned sqrtn = sqrt((double)n);
	for (unsigned int i = 3; i <= sqrtn; i += 2) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int power(int x, unsigned int y, int p)
{
	int res = 1;
	x = x % p;
	while (y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}


bool miillerTest(int d, int n)
{
	int a = 2 + rand() % (n - 4);
	int x = power(a, d, n);

	if (x == 1  || x == n - 1)
		return true;

	while (d != n - 1)
	{
		x = (x * x) % n;
		d *= 2;

		if (x == 1)      return false;
		if (x == n - 1)    return true;
	}

	return false;
}


bool isPrime(int n, int k)
{
	if (n <= 1 || n == 4)  return false;
	if (n <= 3) return true;

	int d = n - 1;
	while (d % 2 == 0)
		d /= 2;

	for (int i = 0; i < k; i++)
		if (!miillerTest(d, n))
			return false;

	return true;
}

void isPrimee(int n, int k) {
	int flag;
	for (int i = k + 1; i < n; i++) {
		flag = 0;
		for (int j = 2; j < i / 2; j++) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << i << " ";
	}

}

bool isPrimeee(int n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	// for (int i = 2; i <n; i++) {	for O(n) complexity
	for (int i = 2; i < sqrt(double(n)); i++) { //for O(sqrt(n)) complexity
		if (n % i == 0)
			return false;
	}

	return true;
}

int main() {
	string s = "Prime\n";
	string p = "Not prime\n";
	int x = 3;
	int y = test_prime(x);
	string max = (y == 1) ?  s :  p;
	cout << max << " ";
	int k = 4;

	cout << "All primes smaller than 100: \n";
	// for (int n = 1; n < 100; n++)
	// if (isPrime(n, k))
	// cout << n << " ";
	int n = 100;
	// isPrimee(n, k);
	for (int i = 4; i < 100; i++) {
		if (isPrimeee(i)) {
			cout << i << " ";
		}
	}

	return 0;
}