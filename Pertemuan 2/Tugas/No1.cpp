#include<iostream>
#include<string>
using namespace std;

void merge(string arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;
	
	string L[100], R[100];
	
	for(int i=0; i<n1; i++) L[i] = arr[l + i];
	for(int j=0; j<n2; j++) R[j] = arr[m + 1 + j];
	
	int i=0, j=0, k=l;
	
	while(i<n1 && j<n2) {
		if(L[i] <= R[j]) arr[k++] = L[i++];
		else arr[k++] = R[j++];
	}
	
	while(i<n1) arr[k++] = L[i++];
	while(j<n2) arr[k++] = R[j++];
}

void mergeSort(string arr[], int l, int r) {
	if(l<r) {
		int m = (l + r) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int main() {
	string data_barang[] = {"Pallet", "Kardus", "Forklift", "Rak", "Meja", "Troli", "Helm"};
	int n = 7;
	
	mergeSort(data_barang, 0, n-1);
	
	cout << "Hasil Sorting:" << endl;
	for(int i=0; i<n; i++) {
		cout << data_barang[i] << endl;
	}
	
	return 0;
}
