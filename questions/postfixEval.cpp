#include<bits/stdc++.h>
using namespace std;

int operation(char ch, int op1, int op2) {
	int res;
	switch (ch)
	{
	case '+': res = op1 + op2;
		break;
	case '-': res = op1 - op2;
		break;
	case '/': res = op1 / op2;
		break;
	case '*': res = op1 * op2;
		break;
	case '^': res = pow(op1, op2);
		break;

	}
	return res;
}

void postfixEval(string s) {

	stack<int> st;
	stack<string> inf;
	stack<string> pre;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
			st.push(s[i] - '0');
			string word = "";
			word = s[i];
			inf.push(word);
			pre.push(word);
		}
		else {
			int op2 = st.top();
			st.pop();
			int op1 = st.top();
			st.pop();
			int res = operation(s[i], op1, op2);
			st.push(res);

			string s2 = inf.top();
			inf.pop();
			string s1 = inf.top();
			inf.pop();
			inf.push("(" + s1 + s[i] + s2 + ")");

			string s4 = pre.top();
			pre.pop();
			string s3 = pre.top();
			pre.pop();
			pre.push(s[i] + s3 + s4);
		}
	}
	cout << st.top() << endl;
	cout << inf.top() << endl;
	cout << pre.top() << endl;
}
int main() {
	string s = "264*8/+3-";
	postfixEval(s);
	return 0;
}