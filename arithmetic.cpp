#include <iostream>
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
   if(carry!=0)
      sum = '1' + sum;
   return sum;
}

string mulBinary(string number1, string number2){
   string product= (number2[number2.size()-1]=='0')? string(number1.size(), '0'): number1;

   for(int i=number2.size()-2; i>=0; i--){
      if(number2[i]=='0')
      {
         number1=number1+'0';
         product= '0' + product;
      }
      else
      {
         number1= number1+ '0';
         if(product.size()!= number1.size())
            product= '0' + product;
         product= addBinary(product, number1, product.size());
      }
   }
   return product;
}

int main(){
   string number1, number2, sum, product;
   int len1, len2;
   cout<<"Enter First Binary Number: ";
   cin>>number1;
   cout<<"Enter Second Binary Number: ";
   cin>>number2;
   len1= number1.size();
   len2= number2.size();
   if(len1>len2){
      sum= addBinary(number1, string(len1-len2, '0')+ number2, len1);
   }
   else{
      sum= addBinary(string(len2-len1, '0') + number1, number2, len2);
   }

   cout<<"Sum is = "<<sum<<endl;
   
   product= mulBinary(number1, number2);   
   cout<<"Product is= "<<product<<endl;
   return 0;

}