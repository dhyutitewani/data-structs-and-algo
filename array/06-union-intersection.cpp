/*
 * 6. Find union and intersection of two arrays.
 *
 * Process: Solve using vector insert and find fnc. 
 *
 *	    Define three vectors a, b and c.
 * 	    
 *	    Find union	     : Use insert to add the values of
 *			       a and b to c. 
 *	    Find intersection: Use find to identify same elements.
 *	    
 *	    For union of vectors:
 *	    - Time complexity : O(m+n) // Will it be O(2n) or O(m+n)? 
 *	    - Space complexity: O(m+n) // To be checked
 *
 *	    For intersection of vectors:
 *	    - Time complexity : theta(n^2) // To be checked
 *	    - Space complexity: O(m+n) // To be checked
 * 
 * Use STL for sort.
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a = {1, 2, 3, 4, 5};
	vector<int> b = {4, 5, 6, 7, 8};

	vector<int> c(a.begin(), a.end());
	vector<int> d = {};

	int n = a.size();
	
	// sort a & b
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	// union
	c.insert(c.end(), b.begin(), b.end());
	for (int i : c)
        	cout << i << " ";
    	cout << "\n";
	
	// intersection
	for (const int &j : a)
		if (find(b.begin(), b.end(), j) != b.end())
			d.push_back(j);
	
	for (int i : d)
        	cout << i << " ";
    	cout << "\n";

    return 0;
}
