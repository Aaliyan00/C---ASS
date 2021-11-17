/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include<stdlib.h>

using namespace std;
void NewAccount();
void ExistingAccount();
void typeChecker(int acc_type)
{
    if (acc_type == '1' || acc_type == 1)
    {
        cout << "inside curr_acct";
        char a = getchar();
    }
    else if (acc_type == '2' || acc_type == 2)
    {
        cout << "inside sav_acct";
        char a = getchar();
    }
    else
    {
        cout << "invalid";
        char a = getchar();
    }
}

class Account
{
    string customer_name, pin;
    int account_no, account_type;

public:
    // for new Account
    Account(string cust_name, int acc_type, string pin_no)
    {
        customer_name = cust_name;
        account_type = acc_type;
        if (pin_no.length() == 4)
        {
            pin = pin_no;
        }
        else
        {
            cout << "PIN must be of 4 digits \n";
            NewAccount();
        }
        int temp=rand()%1000000;
        
    }

    // for existing Account
    Account(string cust_name, int acc_no, string pin_no, int acc_type)
    {
        customer_name = cust_name;
        account_no = acc_no;
        account_type = acc_type;
        if (pin_no.length() == 4)
        {
            pin = pin_no;
        }
        else
        {
            cout << "PIN must be of 4 digits \n";
            ExistingAccount();
        }
    }
};

void NewAccount()
{
    string name;
    string pin;
    int type;
    cout << "WELCOME \n";
    cout << "Enter name \n";
    cin >> name;
    cout << "Enter 1 for Current account 2 for Savings Account \n";
    cin >> type;
    cout << "Enter pin \n";
    cin >> pin;
    Account acc(name, type, pin);
    typeChecker(type);

    // adding to txt file
    ofstream fout;
    fout.open("account.txt");
    fout << { << name << };
}

void ExistingAccount()
{
    string name;
    string pin;
    int accNo, type;
    cout << "WELCOME \n";
    cout << "Enter name \n";
    cin >> name;
    cout << "Enter Account Number \n";
    cin >> accNo;
    cout << "Enter 1 for Current account 2 for Savings Account \n";
    cin >> type;
    cout << "Enter pin \n";
    cin >> pin;
    Account acc(name, accNo, pin, type);
    typeChecker(type);

    accountChecker();
}

Account accountChecker(Account inAcc)
{
}

int main()
{
    // file handling
    string line;
    ifstream fin;
    ofstream fout;
    fin.open("account.txt");
    if (fin)
    {
        cout << "file exists \n";
    }
    else
    {
        fout.open("account.txt");
    }

    cout << "If you are an existing account holder Enter 1 else enter 2\n";
    int acc_status;
    cin >> acc_status;

    // existing account
    if (acc_status == 1)
    {
        ExistingAccount();
    }

    // new account
    else if (acc_status == 2)
    {
        NewAccount();
    }

    return 0;
}
