#include <iostream>
using namespace std;
 
// Merging  two subarrays sub_arr1 and sub_arr2 into sorted
void merge(int Blood_Pressure[], int start, int mid, int end) {
  
 // Create sub_arr1 ← A[start..mid] and sub_arr2 ← A[mid+1..end]
  int m1 = mid - start + 1;
  int m2 = end - mid;
 
  int sub_arr1[m1], sub_arr2[m2];
 
  for (int i = 0; i < m1; i++)
    sub_arr1[i] = Blood_Pressure[start + i];
  for (int j = 0; j < m2; j++)
    sub_arr2[j] = Blood_Pressure[mid + 1 + j];
 
  // Maintain current index of subarrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = start;
 
// Until we reach the end of either arr1 or arr2, pick larger among
// elements sub_arr1 and sub_arr2 and place them in the correct position at sorted[start..end]
  while (i < m1 && j < m2) {
    if (sub_arr1[i] <= sub_arr2[j]) {
      Blood_Pressure[k] = sub_arr1[i];
      i++;
    } else {
      Blood_Pressure[k] = sub_arr2[j];
      j++;
    }
    k++;
  }
 
// When all elements are traverse in either sub_arr1 or sub_arr2,
// pick up the remaining elements and put in sorted[start..end]
  while (i < m1) {
    Blood_Pressure[k] = sub_arr1[i];
    i++;
    k++;
  }
 
  while (j < m2) {
    Blood_Pressure[k] = sub_arr2[j];
    j++;
    k++;
  }
}
 
// Divide the array into two subarrays, sort them and merge them
void mergeSort(int Blood_Pressure[], int start, int end) {
  if (start < end) {
    // middle  is the point where the array is divided into two sub arrays
    int mid = start + (end - start) / 2;
 
    mergeSort(Blood_Pressure, start, mid);
    mergeSort(Blood_Pressure, mid + 1, end);
 
    // this will merge the two sorted array
    merge(Blood_Pressure, start, mid, end);
  }
}
//function to print_result of patients
void print_result(int Blood_Pressure[],int patients){
    for(int i=0;i<patients;i++){
        cout<<Blood_Pressure[i]<<" "; 
    }
}
 
int main() {
 int Blood_Pressure[] = { 180, 70, 98, 90, 120, 80 }; //Blood Pressure in unit of mmHg
    int patients = sizeof(Blood_Pressure) / sizeof(Blood_Pressure[0]);
    cout<<"Given List of Blood Pressure is: "<<endl; 
    print_result(Blood_Pressure,patients);
    cout<<endl;
    mergeSort(Blood_Pressure,0,patients);
    cout << "Result of Sorted Blood Pressure: \n";
    print_result(Blood_Pressure, patients);
    return 0;
}
