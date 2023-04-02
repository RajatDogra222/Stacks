#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n;  i++) {
		cin.ignore();
		string s;
		getline(cin, s);
		cin.ignore();
		int j = 0;
		string num1 = "";
		string num2 = "";
		while (s[j] != ' ') {

			num1 += s[j];
			j++;
		}
		v[i].first = stoi(num1);
		j++;
		while (j < s.size()) {

			num2 += s[j];
			j++;
		}
		v[i].second = stoi(num2);

	}

	for (auto val : v) {
		cout << val.first << " " << val.second << endl;
	}
	return 0;
}