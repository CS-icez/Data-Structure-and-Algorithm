#include <iostream> 
using namespace std; 

const int N = 47;
int a[N][N], n;

int main() {   
	cin >> n;
	n = 2*n-1;
	
	int i = 0, j = n/2;	// index
	a[i][j] = 1;

	for (int k = 2, i1, j1; k <= n*n; ++k){	// the number to be filled
		i1 = (i+n-1)%n, j1 = (j+1)%n;
		if (a[i1][j1]) i1 = i+1, j1 = j;
		a[i1][j1] = k;
		i = i1, j = j1;
	}

	for (int x = 0; x < n; ++x)
		for (int y = 0; y < n; ++y)
			cout << a[x][y] << " \n"[y==n-1];
} 
