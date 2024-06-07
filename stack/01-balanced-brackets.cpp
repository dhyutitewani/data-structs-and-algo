/*
 *	1. Balanced brackets
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<char> s;
	string exp = "[()]{}{[()()]()}";
	
	s.push(exp[0]);
	for (int i = 1; i < exp.length(); i++) {
		if (s.empty()) { 
			s.push(exp[i]);
		} else if ((s.top() == '(' && exp[i] == ')') || (s.top() == '[' && exp[i] == ']') || (s.top() == '{' && exp[i] == '}')) {
			s.pop();
		} else {
			s.push(exp[i]);
		}
	}

	if (s.empty()) cout << "balanced" << endl;
	else cout << "not balanced" << endl;
	return 0;
}
