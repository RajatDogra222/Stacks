#include<bits/stdc++.h>
using namespace std;

void celebrity(vector<vector<int>> v, int n) {

	stack<int> st;
	for (int i = 0; i < n; i++) st.push(i);

	while (st.size() > 1) {
		int i = st.top();
		st.pop();
		int j = st.top();
		st.pop();

		if (v[i][j] == 0) st.push(i);
		else st.push(j);
	}

	for (int i = 0; i < n; i++) {
		if (i != st.top() && v[i][st.top()] == 0) {
			cout << "none";
			return;
		}

		if (v[st.top()][i] == 1) {
			cout << "none";
			return;
		}
	}

	cout << st.top();

}


int main() {
	int n;
	cin >> n;
	vector<vector<int>> v;

	for (int i = 0; i < n; i++) {
		string line;
		cin >> line;
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			temp.push_back(line[j] - '0');
		}
		v.push_back(temp);
	}

	celebrity(v, n);
	return 0;
}