/*
 * 7. Cyclically (clock-wise) rotate an array by one. 
 *
 * Process: Solve using reverse approach.
 *
 * 	    Reverse from n-d to n-1
 * 	    Reverse from 0 to n-d-1
 *	    Reverse from 0 to n-1
 *	    
 *	    Time complexity : theta(n)
 *	    Space complexity: theta(1)
 *
 */

#include<bits/stdc++.h>
using namespace std;

void reverse(int*, int, int);

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int d = 1;
	int n = sizeof(a)/sizeof(a[0]);
	
	reverse(a, n-d, n-1);
	reverse(a, 0, n-d-1);
	reverse(a, 0, n-1);

	for (int i = 0; i < n; i++)
		cout << *(a+i) << " ";
	cout << "\n";	

	return 0;
}

void reverse(int *a, int l, int h) // low & high
{
	while (l <= h)
	{
		swap(a[l], a[h]);
		l++;
		h--;
	}
}