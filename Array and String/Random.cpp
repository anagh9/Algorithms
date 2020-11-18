#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		int x = rand() % (11); // It will Generate random no from 0 to 11;
		int min = -25;
		int max = 25;
		int y = min + rand() % (max - min + 1); //For generating b/w any range
		cout << y << " ";
	}



	return 0;
}