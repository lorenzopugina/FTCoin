class Oraculo {
public:
  // Pode ser uma interface, para futura implementação REST ou simulação
  virtual double getPriceUSD(const std::string& currency) const = 0;
};
