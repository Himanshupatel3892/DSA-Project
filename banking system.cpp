/*banking system*/
#include<iostream>
using namespace std;

//------ BankAccount----

class BankAccount {

protected:
    long long accountNumber;
    string accountHolderName;
    double balance;

public:
							 //get account information
    void get_info() {
        cout<<"Enter name: ";
        cin>>accountHolderName;
        cout<<"Enter account number: ";
        cin>>accountNumber;
        cout<<endl;
        balance = 0;
    }
						
    void deposit() {
        double amount;
        cout<<"Enter amount deposit: ";
        cin>>amount;
         if(amount>0){				
         
         	 balance += amount;        // balance=balance+amount
        cout<<"Your balance is " << balance << " rs" <<endl;
		 } else{
		 	cout<<"invalid amount enter"<<endl;
		 }
       
    }
    
							// method to withdraw amount from balance
    void withdraw() {
        double amount;
        cout<<"Enter amount withdraw: ";
        cin>>amount;
        if(amount>0){
		
        if (amount < balance) {          			
            balance -= amount;
            cout<<"You withdraw: " << amount << " rs" <<endl;
            cout<<"Your  balance: " << balance << " rs" <<endl;
        } else {
            cout<<"Insufficient balance! Available: " << balance << " rs" <<endl;
        }
    }
    else{
    	cout<<"enter valid amount";
	}
}
						
    void getBalance() {
        cout<<"Your Current Balance is: " << balance << " rs" <<endl;
    }

						
    void displayAccountInfo() {
        cout<<"Account holder name is: " << accountHolderName <<endl;
        cout<<"Account number : " << accountNumber <<endl;
        cout<<"Current balance is: " << balance << " rs" <<endl;
    }
};

	//--SavingAccount 
	
class SavingAccount : public BankAccount {
public:
	
			// calculate interest
			
    void calculateInterest(double interestRate) {
        double interest = balance * interestRate;     
        balance += interest; 
        cout<<"Interest added: Rs. " << interest <<endl;
        cout<<"New balance after interest: Rs. " << balance <<endl;
    }
};
	// ---Fixed Deposit Account

class FixedDepositAccount : public BankAccount {

protected:
    int term;
    double interestRate;

public:
	
         // method to calculate interest for Fixed Diposit Account
         
    void calculateInterest() {
        double amount;
        int term;
        double interestRate = 0.06;  // 6% interest
 			
 		
		
        cout<<"Enter amount  fixed deposit: ";
        cin>>amount;
        if(amount>0){
        cout<<"Enter duration time (in months) for fixed deposit: ";
        cin>>term;

        double interest = amount * interestRate * (term / 12.0);
        amount += interest;

        cout<<"Interest added (Fixed Deposit): Rs." << interest <<endl;
        cout<<"New balance after interest: Rs." << amount <<endl;
    }  else{
    	cout<<"enter valid amount";
	}
     }	
};

      // --- Main function start ------    
	    
int main() {
    int accChoice1;
    cout<<"Press 1 for Saving Account"<<endl;
    cout<<"Press 2 for Fixed Deposit"<<endl<<endl;
    cout<<"select Account Type: ";
    cin>>accChoice1;
    cout<<endl;
    

    switch (accChoice1) {

    case 1: {
        SavingAccount saving;       //  Account object
        saving.get_info();

			//switch case  selecting Banking Operation
			
        int choice;
        do {
            cout<<"\n----Menu----\n" <<endl;
            cout<<"Press 1 for Deposit" <<endl;
            cout<<"Press 2 for Withdraw" <<endl;
            cout<<"Press 3 for Get Balance" <<endl;
            cout<<"Press 4 for Display Account Info" <<endl;
            cout<<"Press 0 for Exit\n" <<endl;
            cout<<"please select your choice: ";
            cin>>choice;
            cout<<endl;

            switch (choice) {
            case 1:
                saving.deposit();
                break;
            case 2:
                saving.withdraw();
                break;
            case 3:
                saving.getBalance();
                break;
            case 4:
                saving.displayAccountInfo();
                break;
            case 0:
                cout<<"Exiting." <<endl;
                break;
            default:
                cout<<"Invalid choice" <<endl;
                break;
            }

        } while (choice != 0);

        saving.calculateInterest(0.02); // 2% interest
        cout<<"\nProgram has been terminated successfully." <<endl;
        break;
    }

    case 2: {
        FixedDepositAccount fd;	// Fixed Diposit Account object
        fd.get_info();
        fd.calculateInterest();
        cout<<"\nProgram has been terminated successfully." << endl;
        break;
    }

    default:
        cout<<"Invalid account type" <<endl;
        break;
    }

    return 0;
    
}
