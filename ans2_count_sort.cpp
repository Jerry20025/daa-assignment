#include <iostream>

using namespace std;
//funtion to find maximum element
int max_element(int arr_to_sort[], int n){
    int max=arr_to_sort[0];  //assuming maximum element as first element of array 
    for(int i=1;i<n;i++){
        if(arr_to_sort[i]>max){
            max=arr_to_sort[i];
        }
    }
    return max; //returning max_element
}
void count_sort(int arr_to_sort[], int n){
    int max=max_element(arr_to_sort,n); 
    int count[max+1]={0}; //creating new count array of size max+1
    for(int i=0;i<n;i++){
        count[arr_to_sort[i]]++;  //coutning the frequencies
    }
    
    int index=0;   //for reducing the space complexity we use the same array to store the sorted array  
    for(int i=0;i<=max;i++){
        while(count[i]--){
            arr_to_sort[index++]=i;
        }
        
    }
}
//funtion to print the array
void print(int arr_to_sort[], int n){
    for(int i=0;i<n;i++){
        cout<<arr_to_sort[i]<<" ";
    }
}

int main()
{
    int arr_to_sort[]={1,2,3,4,4,3,4,5,3,2,3,3,3,3,4}; 
    int n=sizeof(arr_to_sort)/sizeof(arr_to_sort[0]); 
    cout<<"Given Array is : "<<endl; 
    print(arr_to_sort,n);
    cout<<endl;
    cout<<"\nAfter performing the Operation : "<<endl; 
    count_sort(arr_to_sort,n); 
    print(arr_to_sort,n);

    return 0;
}
