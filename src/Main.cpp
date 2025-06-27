#include <iostream>
#include <memory>
#include <vector>

#include "./DAO/inMemory/WalletDAOMemory.h"
#include "./DAO/inMemory/transactionDAOmemory.h"
#include "./DAO/inMemory/OracleDAOMemory.h"

#include "./Controller/WalletController.h"
#include "./Controller/TransactionController.h"
#include "./Controller/ReportController.h"

#include "./View/Help.h"
#include "./View/walletMenu.h"
#include "./View/transactionMenu.h"
#include "./View/reportMenu.h"
#include "./View/Menu.h"

using namespace std;

int main() {
    // Instantiate DAOs (In-memory database)
    auto walletDAO = make_shared<WalletDAOMemory>();
    auto transactionDAO = make_shared<TransactionDAOMemory>();
    auto oracleDAO = make_shared<OracleDAOMemory>();

    // Instantiate Controllers
    auto walletController = make_shared<WalletController>(walletDAO);
    auto transactionController = make_shared<TransactionController>(transactionDAO, oracleDAO); 
    auto reportController = make_shared<ReportController>(walletDAO, transactionDAO, oracleDAO);

    // Main Menu
    vector<string> menuOptions = {
        "Wallet",
        "Transaction",
        "Reports",
        "Help",
        "Exit"
    };

    bool running = true;
    do {
        Menu menu(menuOptions, "Main Menu", "Choose an option:");

        int choice = menu.getChoice();

        switch (choice) {
            case 0: // Wallet Menu
                walletMenu(walletController);
                break;
            case 1: // Transaction Menu
                transactionMenu(transactionController);
                break;
            case 2: // Reports Menu
                reportMenu(reportController);
                break;
            case 3: { // Help
                Help help("help.txt");
                help.display();
                break;
            }
            case 4: // Exit
                running = false;
                cout << "Exiting the system...\n";
                break;
        }
    } while (running);

    return 0;
}
