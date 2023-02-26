#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }
}

int main(){
    int number;
    cout<<"Enter a number: ";
    cin>>number;
    int n= log2(number)+1;  //calculate length of array
    int binary[n];
    int i=0;

    while(number){            //convert to binary
        binary[i]= number%2;
        number = number/2;
        i++;
    }

    reverse(binary, binary+n);  //reverse the binary array

    cout<<"The binary is: ";
    printArray(binary, n);
    
    for(int j=0; j<n; j++){    //calculate one's complement
        if(binary[j]==0){
            binary[j]=1;
        }
        else{
            binary[j]=0;
        }
    }

    cout<<endl<<"The ones complement is: ";
    printArray(binary, n);

    
    for(int k=n; k>=0; k--){      //calculate two's complement
        if(binary[k]==0){
            binary[k]=1;
            break;
        }
        else{
            binary[k]=0;
        }
    }

    cout<<endl<<"The twos complement is: ";
    printArray(binary, n);
    cout<<endl;

    return 0;
}
