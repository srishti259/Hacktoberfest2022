
#include <bits/stdc++.h>
using namespace std;

int lcs( char *A, char *B, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (A[m-1] == B[n-1])
		return 1 + lcs(A, B, m-1, n-1);
	else
		return max(lcs(A, B, m, n-1), lcs(A, B, m-1, n));
}


int main()
{
	char X[] = "NUISVEN";
	char Y[] = "UNIVERSE";
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
	
	return 0;
}

