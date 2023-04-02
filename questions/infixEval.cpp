#include<bits/stdc++.h>
using namespace std;

int prec(char ch) {
  if (ch == '^') return 3;
  else if (ch == '/' || ch == '*') return 2;
  else if (ch == '+' || ch == '-') return 1;
  else return -1;
}


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



int infixEval(string s) {
  stack<int> s1;
  stack<char> s2;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ' ') continue;
    if (s[i] - '0' >= 0 && s[i] - '0' <= 9) s1.push(s[i] - '0');
    else if (s[i] == '(') s2.push(s[i]);
    else {

      while (!s2.empty() &&  s2.top() != '(' && prec(s[i]) <= prec(s2.top())) {
        int op2 = s1.top();
        s1.pop();
        int op1 = s1.top();
        s1.pop();
        int res = operation(s2.top(), op1, op2);
        s2.pop();
        s1.push(res);
      }
      if (s[i] == ')' && !s2.empty() && s2.top() == '(') s2.pop();
      else s2.push(s[i]);
    }
  }

  while (!s2.empty()) {
    int op2 = s1.top();
    s1.pop();
    int op1 = s1.top();
    s1.pop();
    int res = operation(s2.top(), op1, op2);
    s2.pop();
    s1.push(res);
  }

  return s1.top();
}



int main() {
  string s;
  getline(cin, s);
  int ans = infixEval(s);
  cout << ans;
  return 0;
}