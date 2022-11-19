#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char start, char end, char refrence)  //here n is total no. of disk
{
	if (n == 0) {
		return;
	}
	towerOfHanoi(n - 1, start, refrence, end);
	cout << "Move disk " << n << " from rod " << start
		<< " to rod " << end<< endl;
	towerOfHanoi(n - 1, refrence, end, start);
}
int main()
{
	int N = 3;

	// A, B and C are names of rods
	towerOfHanoi(N, 'A', 'C', 'B');
	return 0;
}

