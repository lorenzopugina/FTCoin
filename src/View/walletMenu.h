#ifndef WALLET_MENU_H
#define WALLET_MENU_H

#include <memory>
#include "../Controller/WalletController.h"

void walletMenu(std::shared_ptr<WalletController> walletController);
string toUpper(const string& str);

#endif
