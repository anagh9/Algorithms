//Naive Pattern search Algorithms
//KMP Algorithm Pattern Matching


#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool naiveSearch(string pat, string txt) {
	int m = txt.size();
	int n = pat.size();

	for (int i = 0; i <= (m - n); i++) {
		bool isBool = true;
		for (int j = 0; j < n; j++) {
			if (pat[j] != txt[j + i]) {
				isBool = false;
				break;
			}
		}

		if (isBool) {
			return true;
		}
	}

	return false;
} //Time Complexity = O(n*m)


//Kmp Algorithms Starting

void computeLpsArray(string pat, int m, int lps[]) {
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

bool kmp(string pat, string txt) {
	int m = pat.size();
	int n = txt.size();
	int lps[m];

	computeLpsArray(pat, m, lps);
	int i = 0, j = 0;
	while (i < n) {
		if (pat[j] == txt[i]) {
			i++;
			j++;
		}

		if (j == m) {
			return true;
			// cout<<"Found pattern at "<<i-j;
			j = lps[j - 1];
		}

		else if (i < n && pat[j] != txt[i]) {
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}

	return false;
}//Time Complexity = O(m+n)


int main() {

	string s = "AnaghIsGoodBoy";
	string p = "Good";
	// cout << naiveSearch(p, s);

	naiveSearch(p, s) ? cout << " Found " : cout << "Not Found" ;
	// kmp(p, s) ? cout << " Found " : cout << "Not Found" ;
	//condition  ? true statement : false statement

	return 0;
}