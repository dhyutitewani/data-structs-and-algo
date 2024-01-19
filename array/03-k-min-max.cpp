/* 
 * 3. Finding the kth max and min element from an array.
 * 
 * Process: Usng quick select to pick the Kth element.
 *
 * 	    Smallest element = k-1. 
 *    	    Largest element  = n-k.
 *
 * 	    Using STL for QuickSelect.
 *
 * 	    Time complexity : O(n) 
 * 	    Space complexity: theta(1)
 */

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main() 
{
	int a[] = {10, 20, 15, 18, 22}; // sorted array(even tho sort is not being used) = {10, 15, 18, 20}
	int n = sizeof(a)/sizeof(a[0]);
	int k = 3; // kth index.
		
	nth_element(a, a + k - 1, a + n);
    	int min = a[k - 1];

    	nth_element(a, a + n - k, a + n);
    	int max = a[n - k];

	cout << k << " min element is: " << min << "\n";
	cout << k << " max element is: " << max << "\n";
}