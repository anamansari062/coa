#include<iostream>
using namespace std;

int main(){
	int a, b;
	cout<<"Enter first number: ";
	cin>>a;
	cout<<"Enter second number: ";
	cin>>b;
	while(b==0){
		cout<<"\nInterrupt detected: division by zero";
		cout<<"\nEnter second number again: ";
		cin>>b;
	}
	cout<<"The division is: "<<a/b;
	return 0;
}