#include <iostream>
#include <unordered_map>
using namespace std;

int isomorph(string a, string b) {
	unordered_map<char, char> hmap;

	for (int i = 0; i < a.length(); i++) {
		char c1 = a[i];
		char c2 = b[i];

		if (hmap.find(c1) != hmap.end()) {
			if (hmap[c1] != c2) {
				return false;
			}	
		} else {
			hmap[c1] = c2;	
		}
	}
	return true;
}

int main() {
	string a = "aab", b = "xxy";

	if (a.length() != b.length()) return false; 
	
	if(isomorph(a, b)) 
		cout << "true" << endl;
	else 
		cout << "false" << endl;

	return 0;
}
