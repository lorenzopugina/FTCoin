#ifndef AJUDA_H
#define AJUDA_H

#include <string>

class Ajuda {
public:
    Ajuda(const std::string& caminhoArquivo);
    void exibir() const;

private:
    std::string caminho;
};

#endif // AJUDA_H
