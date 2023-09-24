//  Develop a calculator program that performs basic arithmetic operations such as addition, subtraction, multiplication, and
//division. Allow the user to input two numbers and choose an operation to perform.
#include<bits/stdc++.h>
using namespace std;

int main(){
	
		float num1;
		cout<<"Enter first number"<<endl;
		cin>>num1;
		float num2;
		cout<<"enter second number"<<endl;
		cin>>num2;

		char check;
		cout<<"Enter the operation you want to perform "<<endl;
		cin>>check;
		switch(check){

		case '+':
			cout<<"Addition of given number is : "<<num1+num2<<endl;
			break;

		case'-':
            cout<<"Subtraction of given number is : "<<num1-num2<<endl;
            break;

         case'*':
         	cout<<"Multiplication of given number is : "<<num1*num2<<endl;
         	break;
         case'/':
         	cout<<"Division of given number is : "<<num1/num2<<endl;
         	break;

         default:
         	cout<<"Invalid Input!"<<endl;
         	break;
		}

	return 0;
}