#include "reportMenu.h"
#include "Menu.h"

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

void reportMenu(shared_ptr<ReportController> reportController) {
    vector<string> items = {
        "List Wallets by ID",
        "List Wallets by Holder",
        "View Wallet Balance",
        "View Wallet History",
        "View Wallet Gain/Loss",
        "Back"
    };

    bool running = true;
    do {
        Menu menu(items, "Report Menu", "Choose an option:");
        int choice = menu.getChoice();

        switch (choice) {
            case 0: { // List by ID
                auto list = reportController->listWalletsById();
                if (list.empty()) {
                    cout << "No wallets found.\n";
                } else {
                    for (const auto& w : list) {
                        cout << "ID: " << w.getId()
                             << " | Holder: " << w.getHolder()
                             << " | Broker: " << w.getBrokerage() << "\n";
                    }
                }
                break;
            }
            case 1: { // List by Holder
                auto list = reportController->listWalletsByHolder();
                if (list.empty()) {
                    cout << "No wallets found.\n";
                } else {
                    for (const auto& w : list) {
                        cout << "ID: " << w.getId()
                             << " | Holder: " << w.getHolder()
                             << " | Broker: " << w.getBrokerage() << "\n";
                    }
                }
                break;
            }
            case 2: { // View Balance
                int id;
                cout << "Wallet ID: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.\n";
                    break;
                }
                cin.ignore();
                double balance = reportController->calculateWalletBalance(id);
                cout << "Current balance: " << balance << "\n";
                break;
            }
            case 3: { // History
                int id;
                cout << "Wallet ID: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.\n";
                    break;
                }
                cin.ignore();
                auto history = reportController->getWalletHistory(id);
                if (history.empty()) {
                    cout << "No transactions found.\n";
                } else {
                    for (const auto& t : history) {
                        cout << "Transaction ID: " << t.getTransactionId()
                             << " | Date: " << t.getOperationDate()
                             << " | Type: " << t.getOperationType()
                             << " | Quantity: " << t.getQuantity() << "\n";
                    }
                }
                break;
            }
            case 4: { // Gain/Loss
                int id;
                cout << "Wallet ID: ";
                if (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input.\n";
                    break;
                }
                cin.ignore();
                double gain = reportController->calculateGainLoss(id);
                cout << "Current Gain/Loss: " << gain << "\n";
                break;
            }
            case 5:
                running = false;
                break;
        }
    } while (running);
}
