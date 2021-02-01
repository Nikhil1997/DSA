#include <iostream>
#include<stack>

using namespace std;

void reverseWords(string s) {
    
    int n = s.length();
    stack<string> st;

    for(int i=0;i<n;i++)
    {
        string word = "";
        while(s[i] != ' ' && i < n)
        {
            word += s[i];
            i++;
        }
        st.push(word);
    }

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main() {
	
    string s = "How are you Nikhil?";
    reverseWords(s);
	return 0;
}