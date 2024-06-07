/*
 *	2. Pallindrom
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<char> s;
	string n = "";
	string exp = "abc";
	
	for (int i = 0; i < exp.length(); i++) {
		s.push(exp[i]);
	}
	
	for (int i = 0; i < exp.length(); i++) {
		n += s.top();
		s.pop();
	}
	
	if (n == exp) cout << "pallin" << endl;
	else cout << "not" << endl;
	
	return 0;
}
