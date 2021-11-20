// Aaliyan Khan
// 2019A7PS0025U

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;
void NewAccount();
// void ExistingAccount();

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
public:
    string customer_name, pin;
    int account_no, account_type;
    float account_balance;

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
        int temp = rand() % 1000000;
        account_balance = 0.0;
    }

    // for existing Account
    Account(string cust_name, int acc_no, string pin_no, int acc_type, float balance, string name)
    {
        customer_name = cust_name;
        account_no = acc_no;
        account_type = acc_type;
        account_balance = balance;
        customer_name = name;
        if (pin_no.length() == 4)
        {
            pin = pin_no;
        }
        else
        {
            cout << "PIN must be of 4 digits \n";
            // ExistingAccount();
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
    fout << '{' << name << '}';
}

// void ExistingAccount()
// {
//     string name;
//     string pin;
//     string details;
//     int accNo, type;
//     cout << "WELCOME \n";
//     cout << "Enter name \n";
//     cin >> name;
//     cout << "Enter Account Number \n";
//     cin >> accNo;
//     cout << "Enter pin \n";
//     cin >> pin;
//     cout << "Enter 1 for Current account 2 for Savings Account \n";
//     cin >> type;
//     Account acc(name, accNo, pin, type);
//     typeChecker(type);
// }

void tokenize(string s, string del, string temp[])
{
    int start = 0;
    int end = s.find(del);
    int i = 0;
    while (end != -1)
    {
        temp[i] = s.substr(start, end - start);
        // cout << s.substr(start, end - start) << endl;
        start = end + del.size();
        end = s.find(del, start);
        i++;
    }
    // cout << s.substr(start, end - start);
}

int main()
{
    // Account acc[100];
    Account *acc = (Account *)malloc(sizeof(Account) * 100);
    int i = 0;
    string temp[100];
    // file handling
    string line, data;
    ifstream fin;
    ofstream fout;
    fin.open("account.txt");
    if (fin)
    {
        cout << "file exists \n";
        while (getline(fin, data))
        {
            cout << data<<endl;
            tokenize(data, "-", temp);
            acc[i] = Account(temp[4], stoi(temp[0]), temp[1], stoi(temp[3]), stof(temp[2]), temp[4]);
            i++;
        }
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
        // ExistingAccount();
    }

    // new account
    else if (acc_status == 2)
    {
        NewAccount();
    }

    return 0;
}
