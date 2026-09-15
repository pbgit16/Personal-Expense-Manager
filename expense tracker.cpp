
#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

class ExpenseManager
{
private:
    double income;
    double expense[50];
    string category[50];
    string description[50];
    int count;
    double budget;

public:

   
    ExpenseManager()
    {
        income = 0;
        count = 0;
        budget = 0;
    }

    
    void addIncome()
    {
        double amount;

        cout << "\nEnter income: Rs. ";
        cin >> amount;

        if (amount > 0)
        {
            income += amount;
            cout << "Income added successfully!\n";
        }
        else
        {
            cout << "Invalid amount!\n";
        }
    }

    
    void setBudget()
    {
        cout << "\nEnter your monthly budget: Rs. ";
        cin >> budget;

        cout << "Budget set successfully!\n";
    }

    
    void addExpense()
    {
        if (count >= 50)
        {
            cout << "Expense limit reached!\n";
            return;
        }

        cout << "\nEnter expense category:\n";
        cout << "1. Food\n";
        cout << "2. Travel\n";
        cout << "3. Shopping\n";
        cout << "4. Education\n";
        cout << "5. Entertainment\n";
        cout << "6. Bills\n";
        cout << "7. Other\n";

        int choice;
        cout << "Choose category: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            category[count] = "Food";
            break;

        case 2:
            category[count] = "Travel";
            break;

        case 3:
            category[count] = "Shopping";
            break;

        case 4:
            category[count] = "Education";
            break;

        case 5:
            category[count] = "Entertainment";
            break;

        case 6:
            category[count] = "Bills";
            break;

        case 7:
            category[count] = "Other";
            break;

        default:
            cout << "Invalid category!\n";
            return;
        }

        cout << "Enter description: ";
        cin.ignore();
        getline(cin, description[count]);

        cout << "Enter amount: Rs. ";
        cin >> expense[count];

        if (expense[count] <= 0)
        {
            cout << "Invalid amount!\n";
            return;
        }

        count++;

        cout << "Expense added successfully!\n";

        checkBudget();
    }

    
    double totalExpense()
    {
        double total = 0;

        for (int i = 0; i < count; i++)
        {
            total += expense[i];
        }