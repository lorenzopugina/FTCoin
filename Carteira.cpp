class Carteira {
public:
  using Id = int;
  Carteira(Id id, std::string ownerName);
  Id       getId() const;
  const std::string& getOwnerName() const;
  double   getBalance(const std::string& currency) const;
  void     deposit(const std::string& currency, double amount);
  void     withdraw(const std::string& currency, double amount);
private:
  Id                          id_;
  std::string                 ownerName_;
  std::map<std::string,double> balances_; // "BTC" → quantidade
};
