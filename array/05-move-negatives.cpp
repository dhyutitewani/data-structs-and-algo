/*
 * 5. Move all the elements to one side of the array.
 *
 * Process: Solve using the dutch flag algorithm.
 *
 * 	    Two pointer aproach is taken, the pointers being
 * 	    low & high.
 *		
 *	    Check the value at the low & high position.
 * 	     
 *	    If low < 0, inctiment low.  
 *	    If high > 0, decriment high.
 *	    Else swap low with high.
 *
 *	    Time complexity : O(n)
 *	    Space complexity: O(1)
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {-10, 20, 11, -12, -13, 14, -12, 16, 18};
	int n = sizeof(a)/sizeof(a[0]);
	
	int l = 0, h = n-1; // low & high
	while (l < h)
	{
		if (a[l] < 0)
			l++;
		
		if (a[h] > 0)
			h--;
		else
			swap(a[l], a[h]);
            				
	}

	for (int i = 0; i < n; i++)
        	cout << *(a+i) << " ";
    	cout << "\n";

    return 0;
}