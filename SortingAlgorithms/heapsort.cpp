#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>

using namespace std;

/*
[ 9 | 7 2 | 4 3 2 0 ]
*/

void dropDown(int* tab, int size, int idx) {
	int left = idx * 2 + 1;
	int right = left + 1;
	int greater; // indeks dziecka o wiekszej wartosci
	while (true) {
		if (left < size) {
			if (right < size) {
				if (tab[left] > tab[right])
					greater = left;
				else
					greater = right;
			}
			else {
				greater = left;
			}
		}
		else {
			break;
		}
		if (tab[greater] > tab[idx]) {
			swap(tab[idx], tab[greater]);
			idx = greater;
			left = idx * 2 + 1;
			right = left + 1;
		}
		else {
			break;
		}
	}
}

void buildHeap(int* tab, int size) {
	for (int i = size / 2 - 1; i >= 0; --i) {
		dropDown(tab, size, i);
	}
}

void heapSort(int* tab, int size) {
	buildHeap(tab, size);
	int heapSize = size;
	while (heapSize > 0) {
		swap(tab[heapSize - 1], tab[0]);
		--heapSize;
		dropDown(tab, heapSize, 0);
	}
}

void printArray(vector<int> const& v)
{
	int i;
	for (i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int main(int argc, char* argv[])
{
	vector<int> input;
	int value;
	while (cin >> value) {
		input.push_back(value);
	}
	auto start = std::chrono::high_resolution_clock::now();
	heapSort(input.data(), input.size());
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << "bubbleSort time:= " << elapsed.count() << endl;
	return 0;
}
