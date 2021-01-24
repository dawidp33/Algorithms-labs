
#include <cstdlib>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


int partition (vector<int>&arr, int low, int high)
{
    int pivot = arr[high];  
    int i = low;  

    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {  
            swap(arr[i], arr[j]);
	    i++; 
        }
    }
    swap(arr[i], arr[high]);
    return (i);
}


void quickSort(vector<int>&arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



void printArray(vector<int> const& v)
{
	int i;
	for (i = 0; i < v.size(); i++)
		cout << v[i] <<endl;

}

int main(int argc, char* argv[])
{
	vector<int> input;
	int value;
	while (cin >> value) {
		input.push_back(value);
	}
	int n=input.size();
	auto start = std::chrono::high_resolution_clock::now();
	quickSort(input,0,n-1);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << "quickSort time:= " << elapsed.count() << endl;
	//printArray(input);
	return 0;
}
