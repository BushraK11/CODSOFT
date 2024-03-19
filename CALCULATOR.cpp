#include<iostream>
using namespace std;
int main (){
	int choice;
	cout<<"Enter your choice"<<endl;
	cout<<"1.Addition"<<endl;
	cout<<"2.Subtraction"<<endl;
	cout<<"3.Multiplication"<<endl;
	cout<<"4.Division"<<endl;
	cout<<"Choice: " ;
	cin>>choice;
	int a,b;
	switch(choice){
		case 1: {
			cout<<"Enter your first number: ";
			cin>>a;
			cout<<"Enter your second number: ";
			cin>>b;
			cout<<"Sum : " << a+b <<endl;
			break;
		}
		case 2:{
			cout<<"Enter your first number: ";
			cin>>a;
			cout<<"Enter your second number: ";
			cin>>b;
			cout<<"Difference : " << a-b <<endl;
			break;
		}
		case 3:{
			cout<<"Enter your first number: ";
			cin>>a;
			cout<<"Enter your second number: ";
			cin>>b;
			cout<<"Product : " << a*b <<endl;
			break;
		}
		case 4:{
			cout<<"Enter your first number: ";
			cin>>a;
			cout<<"Enter your second number: ";
			cin>>b;
			cout<<"Quotient : " << a/b <<endl;
			break;
		}
	}
}