#include <bits/stdc++.h>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }


int knapsack(int W, int wt[], int val[], int n)
{


	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapsack(W, wt, val, n - 1);

	else
		return max(
			val[n - 1]
				+ knapsack(W - wt[n - 1],
						wt, val, n - 1),
			knapsack(W, wt, val, n - 1));
}

// Driver code
int main()
{
	int n;
	cout<<"Enter number of elements: ";
	cin>>n;
	
	cout<<"\n";
	int wt[n],val[n];
	cout<<"Enter the weights: ";
	for(int i=0;i<n;i++)
	cin>>wt[i];
	
	cout<<"\nEnter the values: ";
	for(int i=0;i<n;i++)
	cin>>val[i];
	
	int W;
	cout<<"\nEnter the size of knapsack: ";
	cin>>W;
	
	cout << knapsack(W, wt, val, n);
	return 0;
}

