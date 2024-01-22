/*
 * 10. Min no of jumps to reach the end of the array.
 *
 * Process: Solve using greedy algorithm.
 *
 *		Intialize: maxReach, step & jump 
 *
 *		Traverse array and find the max reachable index
 *		from curr pos (maxReach).
 *		- If maxReach > len of arr then jump++ and stop
 *		  the end of the array reached.
 *		- Otherwise more jumps need to be made.
 *		- Steps is the no of steps to move forward at curr
 *		  pos, initially declared as value of elem.
 *
 *	 	Step decrimented each time the pos moves forward.
 *		
 *		Time complexity : ? // to be calcualted
 *		Space complexity: ? // to be calculated
 */

#include<bits/stdc++.h>
using namespace std;

int minJumps(int*, int);

int main()
{
	int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "min jumps: " << minJumps(a, n) << "\n";

	return 0;
}

int minJumps(int *a, int n)
{
	if (n <= 1)
		return 0;				// already at end or no elem
	
	if (n - 1 <= a[0])
		return 1;				// only 1 jump needed	

	if (a[0] == 0)
		return -1;				// no jump possible

	int maxReach = a[0], step = a[0], jump = 1;

	for (int i = 1; i < n; i++)
	{
		if (i == n - 1)
			return jump;			// if on last elem

		if ((n - 1) - i <= a[i])		// check if curr elem garuntees 
			return jump + 1;	 	// jump to last elem
		
		maxReach = max(maxReach, i + a[i]);
		
		step--;
		
		if (step == 0)
		{
			jump++;

			if (maxReach <= i)
				return -1;

			step = maxReach - i;
		}
	}

	return -1;
}
