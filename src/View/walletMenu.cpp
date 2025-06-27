#include "walletMenu.h"
#include "Menu.h"
#include "../Utils/Message.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void walletMenu(shared_ptr<WalletController> walletController) {
    vector<string> items = {
        "Create Wallet",
        "Find Wallet",
        "Update Wallet",
        "Delete Wallet",
        "Back"
    };

    bool running = true;
    do {
        Menu menu(items, "Wallet Menu", "Choose an option:");
        int choice = menu.getChoice();

        switch (choice) {
            case 0: { // Create
                string holder, broker;
                cout << "Holder: ";
                getline(cin, holder);
                cout << "Broker: ";
                getline(cin, broker);

                // convert to uppercase
                holder = toUpper(holder);
                broker = toUpper(broker);

                if (walletController->createWallet(holder, broker))
                    Message::showSuccess("Wallet successfully created!");
                else
                    Message::showError("Error creating wallet.");
                break;
            }
            case 1: { // Find
                int id;
                cout << "Wallet ID: ";
                cin >> id; cin.ignore();

                auto wallet = walletController->findWallet(id);
                if (wallet) {
                    cout << "ID: " << wallet->getId() << "\n";
                    cout << "Holder: " << wallet->getHolder() << "\n";
                    cout << "Broker: " << wallet->getBrokerage() << "\n";
                } else 
                    Message::showError("Wallet not found.");
                break;
            }
            case 2: { // Update
                int id;
                string holder, broker;
                cout << "Wallet ID: ";
                cin >> id; cin.ignore();

                cout << "New Holder: ";
                getline(cin, holder);
                cout << "New Broker: ";
                getline(cin, broker);

                holder = toUpper(holder);
                broker = toUpper(broker);

                if (walletController->updateWallet(id, holder, broker))
                    Message::showSuccess("Wallet updated!");	
                else
                    Message::showError("Wallet not found.");
                break;
            }
            case 3: { // Delete
                int id;
                cout << "Wallet ID: ";
                cin >> id; cin.ignore();

                if (walletController->deleteWallet(id))
                    Message::showSuccess("Wallet deleted.");
                else
                    Message::showError("Wallet not found.");	
                break;
            }
            case 4:
                running = false;
                break;
        }
    } while (running);
}

//convert a string to uppercase
string toUpper(const string& str) {
    string upperStr = str;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(),
              [](unsigned char c){ return toupper(c); });
    return upperStr;
}