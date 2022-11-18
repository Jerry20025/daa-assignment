// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <iostream>
using namespace std;

int search(int arr[], int N, int x)
{
	int i;
	for (i = 0; i < N; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Driver's code
int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x ; 
	int N = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nGiven Array is : "<<endl; 
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl; 
    cout<<"Enter no to be search in Array: "<<endl; 
	cin>>x; 
    cout<<endl;
    
	// Function call
	int result = search(arr, N, x);
	 if(result==1){
	      cout << "Element is present at index " << result;
	 }
	 else{
	      cout << "Element is not present in array ";
	 }
	return 0;
}
