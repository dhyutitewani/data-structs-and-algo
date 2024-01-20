/*
 * 9. Minimize the max dist between heights. 
 *
 * Process: Solve by subtracting or adding k to all the vals.	   
 * 	    
 *	    Sort the array and find the difference b/w the 
 *	    heights of smallest and the largest towers.
 * 
 *	    - Find the min height after adding k to the 1st 
 * 	      and subtracting the other values by k.
 *	    - Find the max height by subtracting k from 
 *	      last elem and add k to the other elements.
 *	    
 *	    To find the min height, find the min value of
 * 	    original dist and new dist = max - min height
 *
 * 	    Time complexity : theta(n) ?
 * 	    Space complexity: theta(1) ?
 */

#include<bits/stdc++.h>
using namespace std;

int getMinHeight(int*, int, int);

int main()
{
	int k = 6;
	int a[] = { 7, 4, 8, 8, 8, 9};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "min distance: " << getMinHeight(a, n, k) << "\n";

	return 0;
}

int getMinHeight(int *a, int n, int k)
{
	sort(a, a + n);
	
	int min_h = 0, max_h = 0;
	int fin = a[n - 1] - a[0];
	
	for (int i = 1; i < n; i++)
	{
		if (a[i] - k < 0)
			continue;
		
		min_h = min(a[0] + k, a[n - i] - k);
		max_h = max(a[n - 1] - k, a[i - 1] + k);
	
		fin = min(fin, max_h - min_h);
	}
	
	return fin;	
}
