#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void merge(vector<int>&arr, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1; //Rozmiar pierwszej tablicy 
	int n2 =  r - m; //Rozmiar drugiej 

	int L[n1], R[n2];// tablice pomocnicze

	//Kopiuje wartosci z tablicy do tablic pomocniczych
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    //Lacze tablice pomocniczne w tablice [l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //Kopiuje pozostale elementy z L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

	//Kopiuje pozostale elementy z P[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

int min(int x, int y){
	if (x < y){return x;}
	else{return y;}
}

void mergeSort(vector<int>& tablica, int n)
{
   int curr_size; // Aktualny rozmiar podtablic (1..2/n)
   int left; //Indeks poczatkowy lewej tablicy

   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   {
       for (left=0; left<n-1; left += 2*curr_size) {
           int mid = min(left + curr_size - 1, n-1);
           int right = min(left + 2*curr_size - 1, n-1);
           merge(tablica, left, mid, right);
       }
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
	mergeSort(input,n);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = end - start;
	std::cerr << "bubbleSort time:= " << elapsed.count() << endl;
	//printArray(input);
	return 0;
}

