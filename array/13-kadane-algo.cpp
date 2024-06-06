/*
 * 13. kadane's algo implimentation.
 */

#include<bits/stdc++.h>
using namespace std;

int algo(int*, int);

int main()
{
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(a)/sizeof(a[0]);

	cout << "max sum: " << algo(a, n) << "\n";

	return 0;	
}

int algo(int *a, int n)
{
	int max_sum = INT_MIN, curr_sum = 0;

	for (int i = 0; i < n; i++)
	{
		curr_sum += a[i];

		if (max_sum < curr_sum)
			max_sum = curr_sum;
		
		if (curr_sum < 0)
			curr_sum = 0;
	}

	return max_sum;
}
