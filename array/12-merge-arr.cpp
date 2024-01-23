/* 
 * 12. Merge two sorted arrays w/o extra space.
 *
 * Note: code can be optimized furter.
 */

#include<bits/stdc++.h>
using namespace std;

void merge(long long*,long long*, int, int);

int main()
{
	long long a[] = {1, 4, 8, 10};
	long long b[] = {2, 3, 9};

	int n = sizeof(a)/sizeof(a[0]);
	int m = sizeof(b)/sizeof(b[0]);

	merge(a, b, n, m);

	return 0;
}

void merge(long long *a, long long *b,int n,int m)
{
	int left = n - 1;
	int right = 0;

	while (left >= 0 && right < m)
	{
		if (a[left] > b[right])
		{
			swap(a[left], b[right]);
			left--;
			right++;
		}
		else
			break;
	}

	sort(a, a + n);
	sort(b, b + m);
	
	// display arr a
	cout << "a: ";
    for (int i = 0; i < n; i++)
	   	cout << *(a + i) << " ";
    cout << "\n";
 
    // display arr b
    cout << "b: ";
    for (int j = 0; j < m; j++)
	   	cout << *(b + j) << " ";
    cout << "\n";
}
