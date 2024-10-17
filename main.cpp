#include "bank.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    Bank myBank("client_info.txt");

    int choice;
    long account_number;
    long double amount;
    string name, ssn;
    Client new_client;

    do {
        cout << "\n--- Welcome to Our Banking System ---" << endl;
        cout << "       ⬇  Menu Choices ⬇     " << endl;
        cout << "1. Show all clients information" << endl;
        cout << "2. Deposit into an account" << endl;
        cout << "3. Withdraw from an account" << endl;
        cout << "4. Find a client by account number" << endl;
        cout << "5. Add a new client" << endl;
        cout << "6. Save changes" << endl;
        cout << "7. Exit" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Display all clients
                for (int i = 0; i < myBank.get_num_clients(); ++i) {
                    Client* clients = myBank.get_clients_info();  // Get the pointer to the clients array
                    cout << "Client Name: " << clients[i].client_Name << endl;
                    cout << "SSN: " << clients[i].ssn << endl;
                    cout << "Account Number: " << clients[i].bank_account_number << endl;
                    cout << "Balance: $" <<fixed << setprecision(2)<< clients[i].balance << endl;
                    cout << "-----------------------------" << endl;
                }
                break;
                
            case 2:
                // Deposit into an account
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                cout << "Updated balance: $" << myBank.deposit(account_number, amount) << endl;
                break;

            case 3:
                // Withdraw from an account
                cout << "Enter account number: ";
                cin >> account_number;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                cout << myBank.withdraw(account_number, amount) << endl;
                break;

            case 4:
                // Find a client by account number
                cout << "Enter account number: ";
                cin >> account_number;
                myBank.find_client(account_number);
                break;

            case 5:
                // Add a new client
                myBank.add_new_client();
                cout << "New client added successfully!✅" << endl;
                break;

            case 6:
                // Save changes to the file
                myBank.saving_info("client_info.txt");
                cout << "Changes saved to file." << endl;
                break;

            case 7:
                // Exit
                cout << "Visit us again. See you later 😄 !" << endl;
                break;

            default:
                cout << "🚩Invalid choice🚩, please try again." << endl;
        }
    } while (choice != 7);  // Exit the loop when user selects 7

    return 0;
}
