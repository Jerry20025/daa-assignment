#include <iostream>

using namespace std;
//function for insertion sort
void insertion_sort(int Blood_Pressure[], int patients){
    int max; 
    int i,j; 
    for(int i=1;i<patients;i++){
        max=Blood_Pressure[i]; //initializing max element
        j=i-1; 
        while(j>=0 && Blood_Pressure[j]>max){
            Blood_Pressure[j+1]=Blood_Pressure[j]; 
            j=j-1; 
        }
        Blood_Pressure[j+1]=max; 
    }
}
//funciton to print the result of patients
void print_result(int Blood_Pressure[], int patients){
    for(int i=0;i<patients;i++){
        cout<<Blood_Pressure[i]<<" "; 
    }
}
int main()
{
   int Blood_Pressure[] = { 180, 70, 98, 90, 120, 80 }; //Blood Pressure in unit of mmHg
    int patients = sizeof(Blood_Pressure) / sizeof(Blood_Pressure[0]);
    cout<<"Given List of Blood Pressure is: "<<endl; 
    print_result(Blood_Pressure,patients);
    cout<<endl;
    insertion_sort(Blood_Pressure,patients);
    cout << "Result of Sorted Blood Pressure: \n";
    print_result(Blood_Pressure, patients);
    return 0;
}
