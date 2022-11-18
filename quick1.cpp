#include<iostream>
using namespace std; 
void swap(int *a, int *b){  //swap function for swaping two numbers
    int temp=*a; 
         *a=*b;
         *b=temp; 
}
//function to find a refrence element to perform quickshort
int partition(int Blood_Pressure[], int low, int high)
{
    int pivot = Blood_Pressure[high];
    int i= (low - 1); 
                
  
    for (int j = low; j <= high - 1; j++) {
        
        if (Blood_Pressure[j] < pivot) {
            i++;
            swap(&Blood_Pressure[i], &Blood_Pressure[j]);
        }
    }
    swap(&Blood_Pressure[i + 1], &Blood_Pressure[high]);
    return (i + 1);
}
//rescursive solution for quickSort 
void quickSort(int Blood_Pressure[], int low, int high)
{
    if (low < high) {
        int pi = partition(Blood_Pressure, low, high);
        quickSort(Blood_Pressure, low, pi - 1);
        quickSort(Blood_Pressure, pi + 1, high);
    }
}
  
//function to print the sorted blood pressure
void print_result(int Blood_Pressure[], int patients)
{
    int i;
    for (i = 0; i < patients; i++)
        cout << Blood_Pressure[i] << " ";
    cout << endl;
}
  

int main()
{
    int Blood_Pressure[] = { 180, 70, 98, 90, 120, 80 }; //Blood Pressure in unit of mmHg
    int patients = sizeof(Blood_Pressure) / sizeof(Blood_Pressure[0]);
    cout<<"Given List of Blood Pressure is: "<<endl; 
    print_result(Blood_Pressure,patients);
    cout<<endl;
    quickSort(Blood_Pressure, 0,patients - 1);
    cout << "Result of Sorted Blood Pressure: \n";
    print_result(Blood_Pressure, patients);
    return 0;
}
