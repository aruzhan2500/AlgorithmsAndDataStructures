#include <iostream>
using namespace std;

int findIndex(int* a, int n, int x) {
	int l = 0;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (x < a[mid]) r = mid - 1;
		if (x > a[mid]) l = mid + 1;
		if (x == a[mid]) 
	}
}

int main()
{
    
}