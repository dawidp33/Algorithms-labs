#include <iostream>
#include <ctime>
#include <bits/stdc++.h>
#include<cstdlib>

using namespace std;

int main(int argc , char *argv[])
{
    srand (time(NULL));
	const int n = atoi(argv[1]);
	int max = atoi(argv[2]);
	int* A = new int[n];
	max++;
	for(int i=0;i<n;i++){
        A[i]=rand() % max;
	}
	for(int i=0;i<n;i++)
		for(int j=1;j<n-i;j++) //p�tla wewn�trzna
		if(A[j-1]>A[j])
			//zamiana miejscami
			swap(A[j-1], A[j]);


	for(int i=0;i<n;i++){
        cout <<A[i]<<endl;
	}
	delete[] A;
    return 0;
}
