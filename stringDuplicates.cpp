// Recursive Program to remove Duplicates from a String

#include <iostream>
using namespace std;

string removeDuplicates(string s)
{
	if(s.length() == 0)
		return "";
	
	char ch = s[0];
	string res = removeDuplicates(s.substr(1));
	if(ch == res[0])
		return res;
	
	return ch + res ;
}

int main() {
	cout << removeDuplicates("aabbbee") << endl;
	return 0;
}
