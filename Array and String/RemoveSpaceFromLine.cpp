// C++ program to evaluate a given expression
#include <iostream>
using namespace std;

char *removeSpaces(char *str)
{
	int i = 0, j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	return str;
}

void removeExtraSpace(char *str) {
	char newstr[100];
	char c;
	int index = 0;
	int i = 0, check = 0;

	while (str[i]) {
		c = str[i];
		if (isspace(c) && check == 0) {
			newstr[index++] = str[i];
			check = 1;
		} else if (isalnum(c)) {
			newstr[index++] = str[i];
			check = 0;
		}
		i++;
	}
	cout << newstr;
}

// Driver program to test above function
int main()
{
	char str1[] = "anagh      kumar      is      talented as     fuck";
	cout << removeSpaces(str1) << endl;

	char str2[] = " g e e k ";
	cout << removeSpaces(str2) << endl;
	removeExtraSpace(str1);
	return 0;
}