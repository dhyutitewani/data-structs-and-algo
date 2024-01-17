#include<bits/stdc++.h>
using namespace std;

void reverse(int*, int);

int main() 
{
	int a[] = {1, 2, 3, 4, 12};
	int asize = sizeof(a)/sizeof(a[0]);
	reverse (a, asize);

	for (int i = 0; i < asize; i++)
		cout << *(a+i) << " "; 
	return 0;
}

void reverse(int *a, int n) 
{
	int f = 0, l = n-1;
	while (f<=l) 
	{
		swap(a[f], a[l]);
		f++;
		l--;
	}
}




