// Counting sort in C++ programming
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void countSort(vector<int>& array)
{
  int n=array.size();
  int* output = new int[n];
  int max = array[0];

  //szukamy najwiêkszej wartosci w tablicy
  for (int i = 1; i < array.size(); i++)
  {
    if (array[i] > max)
      max = array[i];
  }
  int* count=new int[max];
    //zliczanie liczb
  for(int i=0;i<max;i++){
    count[i]=0;
  }
  for (int i = 0; i < array.size(); i++)
  {
    count[array[i]]++;
  }

  //dodajemy zliczone liczby do siebie
  for (int i = 1; i <= max; i++)
  {
    count[i] += count[i - 1];
  }


  for (int i = array.size() - 1; i >= 0; i--)
  {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
  for (int i = 0; i < array.size(); i++)
  {
    array[i] = output[i];
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
	countSort(input);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << "countingSort time:= " << elapsed.count() << endl;
	return 0;
}
