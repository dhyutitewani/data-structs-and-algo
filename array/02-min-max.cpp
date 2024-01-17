#include<iostream>
using namespace std;

int main() 
{
	int a[] = {10, 20, 15, 18};
	int min = a[0], max = a[0];
	int n = sizeof(a)/sizeof(a[0]);
	
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		   min = a[i];

		if (a[i] > max)
		   max = a[i];
	}

	cout << "min element is: " << min << endl;
	cout << "max element is: " << max << endl; //do not use endl, reason?
}