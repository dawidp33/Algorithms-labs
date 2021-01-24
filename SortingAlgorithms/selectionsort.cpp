#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
using namespace std;

	void selectionSort(vector<int>& arr)
	{
		int i, j, min_idx;
        int n=arr.size();
		for (i = 0; i < n - 1; i++)
		{
			min_idx = i;
			for (j = i + 1; j < n; j++)
				if (arr[j] < arr[min_idx])
					min_idx = j;
			swap(arr[min_idx], arr[i]);
		}
	}

	void printArray(vector<int> const& arr)
	{
		int i;
		for (i = 0; i < arr.size(); i++)
			cout << arr[i] <<endl;

	}

int main(int argc, char* argv[])
{
	vector<int> input;
	int value;
	while (cin >> value) {
		input.push_back(value);
	}
	auto start = std::chrono::high_resolution_clock::now();
	selectionSort(input);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << "selectionSort time:= " << elapsed.count() << endl;
	return 0;
}


