#include<bits/stdc++.h>
#define ll long long
using namespace std;

int max(int &a, int&b) {
	return (a > b) ? a : b;
}

int LCS(char first[], char second[], int len1, int len2) {
	int L[len1 + 1][len2 + 1];
	for (int i = 0; i <= len1; i++) {
		for (int j = 0; j <= len2; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (first[i - 1] == second[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	return L[len1][len2];
}


int main() {
	char first[] = "AACGTABG";
	char second[] = "GECAAFRABG";
	int len1 = strlen(first);
	int len2 = strlen(second);

	cout << "Maximum length of LCS is" << LCS(first, second, len1, len2);
}