#include <iostream>
#include <math.h>
#include <string>
using namespace std;

string addBinary(string number1, string number2, int len)
{
    int re, carry=0;
    string sum="";
    for(int i=len-1; i>=0; i--)
   {
      re = carry;
      if(number1[i] == '1')
         re = re+1;
      else
         re = re+0;
      if(number2[i] == '1')
         re = re+1;
      else
         re = re+0;
      if(re%2==1)
         sum = '1' + sum;
      else
         sum = '0' + sum;
      if(re<2)
         carry = 0;
      else
         carry = 1;
   }
   return sum;
}

string convertTwosComplement(string binary){
	int n= binary.size();
	for(int j=0; j<n; j++){    
        if(binary[j]=='0'){
            binary[j]='1';
        }
        else{
            binary[j]='0';
        }
    }
    
    for(int k=n; k>=0; k--){      
        if(binary[k]=='0'){
            binary[k]='1';
            break;
        }
        else
            binary[k]='0';
    }
	return binary;
}

void printStatement(int n, string a, string q, string operation){
	if(n==0){
		cout<<"\t"<<a<<"\t"<<q<<"\t"<<operation<<"\n";
		return;
	}
	cout<<"--------------------------------------------\n";
	cout<<n<<"\t"<<a<<"\t"<<q<<"\t"<<operation<<"\n";
    return;
}


string convertBinary(int number){
	int n= log2(number)+1;  
	string binary;
    int i=0;

    while(number){            
        binary= to_string(number%2) + binary;
        number = number/2;
        i++;
    } 
    return binary;
}

int convertDecimal(string binary, int len){
	int number=0;
	for(int i=len-1, j=0; i>=0; i--, j++){
		int n= (binary[i]=='0')? 0:1;
		number= number + (n * pow(2.0, j));
	}
	return number;
}


int main(){
	int n1, n2;
	string m, q;
	cout<<"Divident : ";
	cin>>n1;
	cout<<"Divisor: ";
	cin>>n2;
	q = convertBinary(n1);
	m = convertBinary(n2);
	m = string(q.size()-m.size()+ 1, '0') + m;
	string a= string(m.size(), '0');
	string mC= convertTwosComplement(m);
	int n= q.size();
	cout<<"Here M= "<<m<<" and M''= "<<mC<<endl;
	cout<<"N\t"<<"A\t"<<"Q\t"<<" Operation\t"<<endl;
	printStatement(n, a, q, "Initial");
	int len1= a.size();
	int len2= q.size();
	while(n--){
		a= a.substr(1, len1) + q[0];
	   q= q.substr(1, len2-1);
	   printStatement(n+1, a, q, "Left Shift");
		string restoring= a;
		a= addBinary(a, mC, len1);
		printStatement(0, a, q, "A= A-M");
		
		if(a[0]=='1'){
			a= restoring;
			q= q+ '0';
			printStatement(0, a, q, "Q[0]=0 Restoring A");		
		}
		else{
			q= q+ '1'; 
			printStatement(0, a, q, "Q[0]=1");		}
	}
	cout<<"Quotient= "<<q<<" = "<<convertDecimal(q, len2)<<endl<<"Remainder= "<<a<<" = "<<convertDecimal(a, len1)<<endl;
	return 0;
}