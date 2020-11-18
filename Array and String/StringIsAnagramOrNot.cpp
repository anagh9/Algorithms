//Anagram are those words which are formed through rearranging the same word
//Like Silent and listen are anagram by rearranging s and l we get anagrams.



#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isAnagram(string s, string t) {
	if (s == "" || t == "") return false;
	sort(&s[0], &s[0] + s.length());
	sort(&t[0], &t[0] + t.length());
	if (s == t) return true;
	else return false;
} //Time Complexity = O(n)

bool isAnagram1(string s, string t) {
	if (s == "" || t == "") return false;
	if (s.length() != t.length()) return false;

	int len = s.length();
	int c[256];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < len; ++i) {
		++c[(int)s[i]];
		--c[(int)t[i]];
	}

	for (int i = 0; i < 256; ++i)
		if (c[i] != 0)
			return false;
	return true;
}

int main() {
	string s = "listen";
	string p = "silent";
	string r = "kuchvfd";
	isAnagram1(s, p) ? cout << "True" : cout << "False ";
	isAnagram(s, r) ? cout << "True" : cout << "False ";



	return 0;
}