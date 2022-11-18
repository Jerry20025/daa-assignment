#include <iostream>

using namespace std;
void bubble_sort(int Blood_Pressure[],int patients){
    for(int i=0;i<patients-1;i++){
        for(int j=0;j<patients-i-1;j++){
            if(Blood_Pressure[j]>Blood_Pressure[j+1]){
                int temp=Blood_Pressure[j]; 
                Blood_Pressure[j]=Blood_Pressure[j+1]; 
                Blood_Pressure[j+1]=temp; 
            }
        }
    }
}
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
    bubble_sort(Blood_Pressure,patients);
    cout << "Result of Sorted Blood Pressure: \n";
    print_result(Blood_Pressure, patients);
    return 0;
}
