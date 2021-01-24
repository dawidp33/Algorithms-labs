#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void bubbleSort(vector<int>& arr)
{
	int n = arr.size();
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1]) {
				swap(arr[j],arr[j+1]);
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
	auto start = std::chrono::high_resolution_clock::now();
	bubbleSort(input);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << "bubbleSort time:= " << elapsed.count() << endl;
	return 0;
}
