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


void prefixEval(string s) {

    stack<int> st;
    stack<string> inf;
    stack<string> post;
    for (int i = s.size() - 1; i >= 0; i--) {

        if (s[i] >= '0' && s[i] <= '9') {
            st.push(s[i] - '0');
            string word = "";
            word = s[i];
            inf.push(word);
            post.push(word);
        }
        else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            int res = operation(s[i], op1, op2);
            st.push(res);

            string s1 = inf.top();
            inf.pop();
            string s2 = inf.top();
            inf.pop();
            inf.push("(" + s1 + s[i] + s2 + ")");

            string s3 = post.top();
            post.pop();
            string s4 = post.top();
            post.pop();
            post.push( s3 + s4 + s[i]);

        }
    }

    cout << st.top() << endl;
    cout << inf.top() << endl;
    cout << post.top() << endl;
}

int main() {
    string s = "-+7*45+20";
    prefixEval(s);
    return 0;
}