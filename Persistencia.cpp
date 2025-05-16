template<typename T>
class Repository {
public:
  virtual void save(const T& obj) = 0;
  virtual std::optional<T> findById(int id) = 0;
  virtual void remove(int id) = 0;
  virtual std::vector<T> findAll() = 0;
};

using WalletRepository      = Repository<Wallet>;
using TransactionRepository = Repository<Transaction>;
