#include <iostream>

using namespace std;
//function to perform selection_sort
void selection_sort(int Blood_Pressure[],int patients){
    int i,j,min; 
    for(i=0;i<patients;i++){
        min=i; 
        for(int j=i+1;j<patients;j++){
            if(Blood_Pressure[j]<Blood_Pressure[min]){
                min=j;  //assigning minimum index
            }
        }
        //if min is not equal to i then swap with it
        if(min!=i){
            int temp=Blood_Pressure[i]; 
            Blood_Pressure[i]=Blood_Pressure[min]; 
            Blood_Pressure[min]=temp;
        }
    }
}
//printing the result of patients
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
    selection_sort(Blood_Pressure,patients);
    cout << "Result of Sorted Blood Pressure: \n";
    print_result(Blood_Pressure, patients);
    return 0;
}
