//binary search ....the array should be sorted
#include<iostream>
int binarysearch(int arr[],int n,int key){
    int s=0;
    int e=n; 
    while(s<=e){
        int mid=(s+e)/2; 
        if(arr[mid]==key){
            return mid ; 
        }
        else if (arr[mid]>key){   //this will check if key is greater then mid element then e will shift by 1 left
            e=mid-1; 
    }
    else {
        s=mid+1; 
    }
    }
    return -1; 
}
using namespace std;
int main()
{
    int n,key;
    cout<<"Enter the size of array: "<<endl; 
    cin>>n; 
    int arr[n]; 
    cout<<"Enter array"<<endl; 
    for(int i=0; i<n;i++){
        cin>>arr[i]; 
    }
    cout<<"\nPrint the key"<<endl;
    cin>>key; 
   cout<<"Index is "<<endl;
 cout<<binarysearch(arr,n,key)<<endl;
 return 0;
}
