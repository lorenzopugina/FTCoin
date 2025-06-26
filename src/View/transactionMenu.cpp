#include "transactionMenu.h"
#include "Menu.h"
#include "../Utils/Date.h"
#include "../Utils/Message.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void transactionMenu(shared_ptr<TransactionController> transactionController) {
    vector<string> items = {
        "Create Transaction",
        "Find Transaction",
        "Update Transaction",
        "Delete Transaction",
        "Back"
    };

    bool running = true;
    do {
        Menu menu(items, "Transaction Menu", "Choose an option:");
        int choice = menu.getChoice();

        switch (choice) 
        {
            case 0: { // Create
                int walletId;
                int day, month, year;
                char option;
                char type;
                double quantity;
                Date date;

                cout << "Wallet ID: ";
                cin >> walletId;

                cout << "Create transaction with today's date? Y/N: ";
                cin >> option;

                if (option == 'N' || option == 'n') {
                    cout << "Enter the date separated by spaces (day month year): ";
                    cin >> day >> month >> year;
                    date.setDate(day, month, year);
                }

                cout << "Type (B - Buy, S - Sell): ";
                cin >> type;
                cout << "Quantity: ";
                cin >> quantity;

                if (transactionController->createTransaction(walletId, date, type, quantity))
                    Message::showSuccess("Transaction created!");
                else
                    Message::showError("Error creating transaction.");
                break;
            }
            case 1: { // Find
                int id;
                cout << "Transaction ID: ";
                cin >> id; cin.ignore();

                auto tx = transactionController->findTransaction(id);
                if (tx) {
                    cout << "Transaction ID: " << tx->getTransactionId() << "\n";
                    cout << "Wallet ID: " << tx->getWalletId() << "\n";
                    cout << "Date: " << tx->getOperationDate() << "\n";
                    cout << "Type: " << tx->getOperationType() << "\n";
                    cout << "Quantity: " << tx->getQuantity() << "\n";
                } else 
                    Message::showError("Transaction not found.\n");
                break;
            }
            case 2: { // Update
                int id;
                int day, month, year;
                char type;
                double quantity;

                cout << "Transaction ID: ";
                cin >> id;

                cout << "Enter the date separated by spaces (day month year): ";
                cin >> day >> month >> year;

                cout << "New Type (B/S): ";
                cin >> type;

                cout << "New Quantity: ";
                cin >> quantity;

                Date date(day, month, year);

                if (transactionController->updateTransaction(id, date, type, quantity))
                    Message::showSuccess("Transaction updated!\n");
                else
                    Message::showError("Transaction not found.\n");
                break;
            }

            case 3: { // Delete
                int id;
                cout << "Transaction ID: ";
                cin >> id; cin.ignore();

                if (transactionController->deleteTransaction(id))
                    Message::showSuccess("Transaction deleted!\n");
                else
                    Message::showError("Transaction not found.\n");
                break;
            }
            case 4:
                running = false;
                break;
        }
    } while (running);
}
