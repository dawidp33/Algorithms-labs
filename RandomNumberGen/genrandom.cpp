#include <iostream>
#include <ctime>
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
        cout<<A[i]<<endl;;
	}
	delete[] A;
    return 0;
}
