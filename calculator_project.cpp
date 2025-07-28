//calculator using function loop and switch case

#include<iostream>
using namespace std;
void calculator();

void calculator(){
  	int choice;
    float no1,no2;
	
	       cout<<"-----------Welcome to the Calculator-----------\n";
  do{
  
  cout<<" press 1 for +\n press 2 for -\n press 3 for *\n press 4 for /\n press 5 for %\n press 0 to exit\n";
  cout<<endl;
	cout<<"enter your choice: ";
	cin>>choice;
	cout<<endl;
	
	
	if(choice==0) break;
	
	cout<<"enter first number: ";
	cin>>no1;
	cout<<"enter second number: ";
	cin>>no2;
	
	cout<<endl;
	switch(choice){
		case 1:
		cout<<"the sum of "<<no1<<" and "<<no2<<" is "<<no1+no2<<endl;
		break;
		
		case 2:
		cout<<"the subtraction of "<<no1<<" and "<<no2<<" is "<<no1-no2<<endl;
		break;
		
		case 3:
		cout<<"the multiplicaton of "<<no1<<" and "<<no2<<" is "<<no1*no2<<endl;
		break;
		
		case 4:
		cout<<"the division of "<<no1<<" and "<<no2<<" is "<<no1/no2<<endl;	
		break;
		
		case 5:
		cout<<"the modulus of "<<no1<<" and "<<no2<<" is "<<(int)no1 % (int)no2<<endl;	
		break;
		
		default:
			cout<<"invalid choice";
	}
	    cout<<endl;
	
	} while(choice!=0);
	
	    cout<<"The Program has been Terminated.\n";
	
	 }


int main() {
	calculator();
   	
	return 0;
}