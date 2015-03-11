// Manacher's algorithm, O(n)
//

#include <iostream>
#include <algorithm>
using namespace std;

string longestPalindrome(string s);

int main(void)
{
	string s = "abcbe";

	string a = longestPalindrome(s);

	return 0;
}

string longestPalindrome(string s) {
	const size_t n = s.size();
	string str;
	const size_t m = 2 * n + 1;
	str.reserve(m);

	if (n == 0)
		return str = "";

	str += '^';
	for (int i = 0; i < n - 1; i++){
		str += s[i];
		str += '#';
	}
	str += s[n - 1];
	str += '$';
	str += '\0';

	std::cout << str.c_str() << endl;

	int *rad = new int[m];
	rad[0] = 0;

	int mirror = 0, rightBorder = 0;
	for (int i = 1; i < m; i++){
		int ii = 2 * mirror - i;
		if (i < rightBorder)
			rad[i] = std::min(rad[ii], rightBorder - i);
		else
			rad[i] = 0;

		while (str[i + rad[i] + 1] == str[i - rad[i] - 1]){
			rad[i]++;
		}

		if (i + rad[i] > rightBorder){
			mirror = i;
			rightBorder = i + rad[i];
		}
	}

	//print rad
	for (int j = 0; j < m; j++)
		cout << rad[j] << '\t';
	cout << endl;

	int begin = 1, len = 1, max_begin = 1, max_len = 1;
	char beginChar = str[begin];
	for (int ii = 0; ii < m; ii++){
		begin = ii - rad[ii];
		beginChar = str[begin];
		if (beginChar != '#')
			len = 2 * rad[ii] + 2;
		else
			len = 2 * rad[ii] + 1;
		if (len > max_len){
			max_len = len;
			max_begin = begin;
		}
	}

	max_begin /= 2;
	max_len /= 2;

	delete[]rad;
	return s.substr(max_begin, max_len);
}