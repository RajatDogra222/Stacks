#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
	if (ch == '^') return 3;
	else if (ch == '/' || ch == '*') return 2;
	else if (ch == '+' || ch == '-') return 1;
	else return -1;
}

void infixConv(string s) {

	stack<string> s1;
	stack<string> s2;
	stack<char> o;

	string word1 = "";
	string word2 = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ')  continue;
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
			string word = "";
			word = s[i];
			s1.push(word);
			s2.push(word);
		}
		else if (s[i] == '(') o.push(s[i]);
		else {

			while (!o.empty() && o.top() != '(' && prec(s[i]) <= prec(o.top())) {
				string op2 = s1.top();
				s1.pop();
				string op1 = s1.top();
				s1.pop();
				string op4 = s2.top();
				s2.pop();
				string op3 = s2.top();
				s2.pop();

				word1 = op1 + op2 + o.top();
				word2 = o.top() + op3 + op4;
				s1.push(word1);
				s2.push(word2);
				o.pop();
			}

			if (s[i] == ')' && !o.empty() && o.top() == '(') o.pop();
			else o.push(s[i]);
		}

	}
	while (!o.empty()) {
		string op2 = s1.top();
		s1.pop();
		string op1 = s1.top();
		s1.pop();
		string op4 = s2.top();
		s2.pop();
		string op3 = s2.top();
		s2.pop();

		word1 = op1 + op2 + o.top();
		word2 = o.top() + op3 + op4;
		s1.push(word1);
		s2.push(word2);
		o.pop();
	}

	cout << s1.top() << endl;
	cout << s2.top() << endl;
}
int main() {

	string s;
	getline(cin, s);

	infixConv(s);
	return 0;
}