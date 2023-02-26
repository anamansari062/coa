#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int ans[32], decNum;
	float dec, decFract;
	//Assigning element of ans array as 0
	for(int b=0; b<32; b++)
		ans[b]=0;
	
	cout<<"Enter a decimal number: ";
	cin>>dec;

	//If number is negative then sign bit will be 1 else 0
	if(dec>0)
		ans[0]= 0;
	else{
		ans[0]= 1;
		dec = dec * (-1);
	}

	//Separating dec into decNum and decFract
	decNum= (int) dec;
	decFract= dec- decNum;

	//Calculating the position from where decFract starts in array[32] as len 
	int len= log2(decNum) + 9;

	//i is the last position of decNum, e will be used to calculate exp
	int i=len-1, e=127 + len-9;

	//Now converting decFract into binary and assigning them to the correct position in ans
	while(decFract!=0){
		ans[len]= (int) (decFract * 2);
		if(decFract*2 >=1)
			decFract= 1- (decFract*2);
		else
			decFract= (decFract*2);
		len++;
	}

	//Converting decNum into binary and assigning in ans
	while(decNum>0){
		ans[i]= decNum%2;
		decNum= decNum/2;
		i--;
	}

	//Converting e to binary to assign as exp
	int m=8;
	while(e>0){
		ans[m]= e%2;
		e= e/2;
		m--;
	}

	//Printing part by part : sign, exp, mantissa
	cout<<"The IEEE 754 format for single precision is: ";
	cout<<ans[0]<<" ";
	for(int q=1; q<9; q++)
		cout<<ans[q];
	cout<<" ";
	for(int q=9; q<32; q++)
		cout<<ans[q];
	cout<<endl;
	return 0;
}