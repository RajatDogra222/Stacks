#include<bits/stdc++.h>
using namespace std;

// void smallNum(string s) {
// 	stack<int> st;
// 	stack<int> st2;
// 	int count = 1;
// 	for (int i = 0; i < s.size(); i++) {
// 		if (st.empty() && s[i] == 'd') {
// 			st.push(count++);
// 			st.push(count++);
// 		}
// 		else if (st.empty() && s[i] == 'i') {
// 			st.push(count + 1);
// 			st.push(count);
// 			count += 2;
// 		}

// 		else if (s[i] == 'd') {
// 			while (!st.empty() && st.top() != count - 1) {
// 				st2.push(st.top());
// 				st.pop();
// 			}
// 			st.push(count++);
// 			while (!st2.empty()) {
// 				st.push(st2.top());
// 				st2.pop();
// 			}
// 		}
// 		else if (s[i] == 'i') {
// 			while (!st.empty()) {
// 				st2.push(st.top());
// 				st.pop();
// 			}
// 			st.push(count++);
// 			while (!st2.empty()) {
// 				st.push(st2.top());
// 				st2.pop();
// 			}
// 		}

// 	}

// 	while (!st.empty()) {
// 		cout << st.top();
// 		st.pop();
// 	}

// }


void smallNum(string s) {
	stack<int> st;
	int num = 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'd') {
			st.push(num);
			num++;
		}
		else {
			st.push(num);
			num++;
			while (!st.empty()) {
				cout << st.top();
				st.pop();
			}
		}
	}

	st.push(num);
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
int main() {
	string s = "ddddiiii";
	smallNum(s);
	return 0;
}