class Movimentacao {
public:
  enum class Type { Buy, Sell };
  Movimentacao(int id,
              Wallet::Id walletId,
              Type type,
              std::string currency,
              double amount,
              double unitPriceUSD,
              std::chrono::system_clock::time_point timestamp);
  // getters...
private:
  int    id_;
  Wallet::Id walletId_;
  Type   type_;
  std::string currency_;
  double amount_;
  double unitPriceUSD_; // cotação no momento
  std::chrono::system_clock::time_point timestamp_;
};
