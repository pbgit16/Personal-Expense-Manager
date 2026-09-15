#include <iostream>
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

        return total;
    }

    
    void showExpenses()
    {
        if (count == 0)
        {
            cout << "\nNo expenses available.\n";
            return;
        }

        cout << "\n ALL EXPENSES :\n";

        for (int i = 0; i < count; i++)
        {
            cout << "\nExpense " << i + 1 << endl;
            cout << "Category    : " << category[i] << endl;
            cout << "Description : " << description[i] << endl;
            cout << "Amount      : Rs. "
                 << fixed << setprecision(2)
                 << expense[i] << endl;
        }
    }

   
    void showSummary()
    {
        double total = totalExpense();
        double balance = income - total;

        cout << "\n WALLET SUMMARY :\n";

        cout << "Total Income  : Rs. "
             << income << endl;

        cout << "Total Expense : Rs. "
             << total << endl;

        cout << "Balance       : Rs. "
             << balance << endl;

        if (income > 0)
        {
            double saving = (balance / income) * 100;

            cout << "Savings       : "
                 << saving << "%\n";
        }
    }

    void highestExpense()
    {
        if (count == 0)
        {
            cout << "\nNo expenses available.\n";
            return;
        }

        int index = 0;

        for (int i = 1; i < count; i++)
        {
            if (expense[i] > expense[index])
            {
                index = i;
            }
        }

        cout << "\n HIGHEST EXPENSE \n";

        cout << "Category    : " << category[index] << endl;
        cout << "Description : " << description[index] << endl;
        cout << "Amount      : Rs. "
             << expense[index] << endl;
    }

    
    void searchCategory()
    {
        string search;

        cout << "\nEnter category to search: ";
        cin >> search;

        bool found = false;

        cout << "\n SEARCH RESULT \n";

        for (int i = 0; i < count; i++)
        {
            if (category[i] == search)
            {
                cout << "Description : "
                     << description[i] << endl;

                cout << "Amount      : Rs. "
                     << expense[i] << endl;

                cout <<"-\n";

                found = true;
            }
        }

        if (!found)
        {
            cout << "No expense found in this category.\n";
        }
    }

    
    void deleteExpense()
    {
        if (count == 0)
        {
            cout << "\nNo expenses available.\n";
            return;
        }

        int number;

        showExpenses();

        cout << "\nEnter expense number to delete: ";
        cin >> number;

        if (number < 1 || number > count)
        {
            cout << "Invalid expense number!\n";
            return;
        }

        for (int i = number - 1; i < count - 1; i++)
        {
            expense[i] = expense[i + 1];
            category[i] = category[i + 1];
            description[i] = description[i + 1];
        }

        count--;

        cout << "Expense deleted successfully!\n";
    }

    
    void checkBudget()
    {
        if (budget == 0)
            return;

        double total = totalExpense();

        cout << "\nBudget: Rs. " << budget << endl;
        cout << "Spent : Rs. " << total << endl;

        if (total > budget)
        {
            cout << "WARNING: You have exceeded your budget!\n";
        }
        else if (total >= budget * 0.8)
        {
            cout << "WARNING: You have used more than 80% of your budget.\n";
        }
        else
        {
            cout << "You are within your budget.\n";
        }
    }

    
    void advice()
    {
        double total = totalExpense();

        cout << "\n PERSONALIZED ADVICE :: \n";

        if (income == 0)
        {
            cout << "Please add your income first.\n";
            return;
        }

        double balance = income - total;
        double saving = (balance / income) * 100;

        if (saving >= 30)
        {
            cout << "Excellent! You are saving more than 30% of your income.\n";
        }
        else if (saving >= 20)
        {
            cout << "Good! Try to maintain your saving habit.\n";
        }
        else if (saving >= 10)
        {
            cout << "Your savings are low. Try reducing unnecessary expenses.\n";
        }
        else
        {
            cout << "Be careful! Most of your income is being spent.\n";
        }

        if (budget > 0 && total > budget)
        {
            cout << "You should reduce your monthly expenses.\n";
        }
    }
};


int main()
{
    ExpenseManager manager;

    int choice;

    do
    {
      
        cout << "       PERSONAL EXPENSE MANAGER ::\n";
       

        cout << "1. Add Income\n";
        cout << "2. Set Monthly Budget\n";
        cout << "3. Add Expense\n";
        cout << "4. View All Expenses\n";
        cout << "5. Wallet Summary\n";
        cout << "6. Find Highest Expense\n";
        cout << "7. Search Expense by Category\n";
        cout << "8. Delete Expense\n";
        cout << "9. Check Budget\n";
        cout << "10. Personalized Advice\n";
        cout << "11. Exit\n";

        

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addIncome();
            break;

        case 2:
            manager.setBudget();
            break;

        case 3:
            manager.addExpense();
            break;

        case 4:
            manager.showExpenses();
            break;

        case 5:
            manager.showSummary();
            break;

        case 6:
            manager.highestExpense();
            break;

        case 7:
            manager.searchCategory();
            break;

        case 8:
            manager.deleteExpense();
            break;

        case 9:
            manager.checkBudget();
            break;

        case 10:
            manager.advice();
            break;

        case 11:
            cout << "\nThank you for using Personal Expense Manager!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 11);

    return 0;
}
