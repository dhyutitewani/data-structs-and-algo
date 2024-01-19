/*
 * 8. Find the largest sum of contiguous subarray from a single array. 
 *
 * Process: Solve using kadane's algorithm.	   
 * 	    
 *	    Initialize: max_Sum & curr_sum
 *
 *	    - Iterate through the array using a for loop &
 * 	      add the current element of the arr to curr_sum.
 *	    - If max_sum < curr_sum then set max_sum as
 *	      curr_sum, this records the max_sum of arr.
 *	    - If the curr_sum < 0 then set curr_sum as 0. In
 *	      next ieration val of arr assigned to curr_sum.
 *	      
 * 	    Time complexity : theta(n)
 * 	    Space complexity: theta(1)
 */

#include<bits/stdc++.h>
using namespace std;

int maxSum(int*, int);

int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);
	
	cout << "max sum: " << maxSum(a, n) << "\n";
	cout << "start index: " << maxSum(a, n) << "\n";
	cout << "end index: " << maxSum(a, n) << "\n";
	
	return 0;
}

int maxSum(int *a, int n)
{
	int max_sum = 0, curr_sum = 0;
	int s = 0, e = 0; // start and end index of sub arr

	for (int i = 0; i < n; i++)
	{
		curr_sum += a[i];
	
		if (max_sum < curr_sum)
		{
			max_sum = curr_sum;
			s = 1;
			e = i;
		}	
		
		if (curr_sum < 0)
		{
			curr_sum = 0;
			s = i + 1;
		}
	}

	return max_sum;		
}

// c++ can not return multiple values.
// Start & end index code for ref.
