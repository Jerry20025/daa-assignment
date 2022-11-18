#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Function to sort arr[] of
// size n using bucket sort
void bucketSort(float arr[], int n)
{
	
	// Create dynamic array of  n empty buckets
	vector<float> bucket[n];

	// Put array elements in different buckets
	for (int i = 0; i < n; i++) {
		int bi = n * arr[i]; // Index of bucket
		bucket[bi].push_back(arr[i]);
	}

	// Sort individual buckets using predefined function
	for (int i = 0; i < n; i++)
		sort(bucket[i].begin(), bucket[i].end());

	//add  all buckets into arr[]
	int index = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < bucket[i].size(); j++)
			arr[index++] = bucket[i][j];
}
int main()
{
	float arr[]= { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout<<"Given Array is : "<<endl; 
	for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    } 
	cout<<endl; 
	cout<<"\nSorted array is : "<<endl; 
	bucketSort(arr, n);

	
	for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
	
	return 0;
}
