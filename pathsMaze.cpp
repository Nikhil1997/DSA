#include <iostream>
using namespace std;

// i,j is starting point in N x N Matrix
int countPaths(int N , int i , int j)
{
    if(i == N-1 && j == N-1)
        return 1;

    if(i >= N || j >= N)
        return 0;

    return countPaths(N , i+1, j) + countPaths(N , i, j+1) ;
}

int main() {
	
    cout << countPaths(3 , 0 , 0) << endl;
	return 0;
}