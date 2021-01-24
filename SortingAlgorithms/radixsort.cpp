#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <chrono>
#include <math.h>
using namespace std;


class Queue
{
	int* data;
	int front;
	int size;
	int capacity;

	void realloc() {
		if (capacity == 0) {
			capacity = 10;
			data = new int[capacity];
			return;
		}
		int newsize = capacity * 2;
		int* newdata = new int[newsize];

		for (int i = 0; i < front; ++i) {
			newdata[i] = data[i];
		}
		int newfront = newsize - (size - front);
		int newi = newfront;
		for (int i = front; i < size; ++i) {
			newdata[newi] = data[i]; //nowa tablica przyjmuje wartoœci startej
			++newi;
		}
		//_data moze byc nullptr, ale delete na nullptr jest dozwolone
		delete[] data;
		data = newdata;
		capacity = newsize;
		front = newfront;
	}

public:
	Queue() {
		data = nullptr;
		front = 0;
		size = 0;
		capacity = 0;
	}

	void push(int value) {
		if (size == capacity)
			realloc();
		data[(front + size) % capacity] = value;
		++size;
	}

	int pop() {
		int value = data[front];
		front = (front + 1) % capacity;
		--size;
		return value;
	}

	bool empty() {
		return size == 0;
	}
};


void printArray(vector<int> const& v)
{
	int i;
	for (i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

int getMax(vector<int> const& v)
{
	int mx = v[0];
	for (int i = 1; i < v.size(); i++)
		if (v[i] > mx)
			mx = v[i];
	return mx;
}

int countDigits(int n) {
	int res = 1;
	while ((n /= 10) > 0)
		res++;
	return res;
}

void radixSort(vector<int>& v) {
	int max = getMax(v);
	int maxDigits = countDigits(max);
	Queue bins[10];

	int currentDigit = 0;
	while (currentDigit < maxDigits) {
		int divisor = pow(10, currentDigit);
		for (int i = 0; i < v.size(); i++) {
			int num = v[i];
			int digitValue = (num / divisor) % 10;
			bins[digitValue].push(num);
		}
		int i = 0;
		for (int k = 0; k < 10; k++) {
			while (!bins[k].empty()) {
				v[i] = bins[k].pop();
				i++;
			}
		}
		currentDigit++;
	}
}

int main(int argc, char* argv[]) {
	vector<int> input;
	int value;
	while (cin >> value) {
		input.push_back(value);
	}
    auto start = std::chrono::high_resolution_clock::now();
	radixSort(input);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << "radixSort time:= " << elapsed.count() << endl;
	return 0;
}

