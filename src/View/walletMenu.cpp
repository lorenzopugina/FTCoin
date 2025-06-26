#include "walletMenu.h"
#include "Menu.h"

#include <iostream>
#include <vector>
#include <string>

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

                if (walletController->createWallet(holder, broker))
                    cout << "Wallet successfully created!\n";
                else
                    cout << "Error creating wallet.\n";
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
                } else {
                    cout << "Wallet not found.\n";
                }
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

                if (walletController->updateWallet(id, holder, broker))
                    cout << "Wallet updated!\n";
                else
                    cout << "Wallet not found.\n";
                break;
            }
            case 3: { // Delete
                int id;
                cout << "Wallet ID: ";
                cin >> id; cin.ignore();

                if (walletController->deleteWallet(id))
                    cout << "Wallet deleted.\n";
                else
                    cout << "Wallet not found.\n";
                break;
            }
            case 4:
                running = false;
                break;
        }
    } while (running);
}
