/*
 * 11. Find the duplicate elements in an array,
 */

#include<bits/stdc++.h>
using namespace std;

void findDuplicate(int*, int);

int main()
{
	int a[] = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1, 1, 2, 2, 2};
	int n = sizeof(a)/sizeof(a[0]);

	findDuplicate(a, n);
		
	return 0;
}

void findDuplicate(int *a, int n)
{		
	int c = 0;
	
	sort(a, a + n);		
	 
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			if (a[i] == a[i - 1])
				continue;
			cout << a[i] << "\n";	
		}
	}
}
