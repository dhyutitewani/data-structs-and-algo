/*
 * 4. Sort an aray of only 0, 1 and 2 witout using 
 *    any sorting algo.
 *
 * Process: Solve using the dutch flag algorithm.
 *
 * 	    Three pointer aproach is taken, the pointers being
 * 	    low, mid and high.
 *		
 *	    Check the value at the mid position.
 * 	     
 *	    If mid = 0, swap low and min, & inctiment low and mid.  
 *	    If mid = 1, incriment mid.
 *	    If mid = 2, swap mid and high, & decriment mid and high.
 *
 * Time complexity : O(n)
 * Space complexity: O(1)
 */

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a[] = {0, 1, 1, 0, 0, 2, 1, 2, 2, 1, 0};
	int n = sizeof(a)/sizeof(a[0]);
	
	int l = 0, m = 0, h = n-1; // low, mid and high
	while (m <= h)
	{
		if (a[m] == 0)
		{
			swap(a[l], a[m]);
			l++;
			m++;
		}
		else if (a[m] == 1)
			m++;
		else
		{
			swap(a[m], a[h]);
            		h--;		
		}
	}

	for (int i = 0; i < n; i++)
        	cout << *(a+i) << " ";
    	cout << "\n";

    return 0;
}