Objetivo:

Centralizar toda a lógica de negócio, validações e regras de cálculo (por exemplo, como registrar uma compra, calcular ganho/perda usando cotações, ordenar carteiras, gerar histórico, etc.), Orquestrar chamadas. 

Como organizar:

Criar uma classe de serviço para cada responsabilidade maior:

    useCaseCarteira: criar, editar, excluir e recuperar carteiras; listar ordenações por ID ou nome.

    useCaseMovimentacao: registrar compra e venda, validando existência de carteira, consultando cotação daquele dia e salvando transação.

    useCaseRelatorio: calcular saldo atual, histórico de movimentações e ganho/perda total usando cotações.


Injeção de Dependências:
    Cada serviço recebe, via construtor ou setter, ponteiros/shared_ptr para as interfaces de repositório de que precisa.


Exemplo conceitual: useCaseMovimentacao recebe IRepositorioCarteira + IRepositorioTransacao + IRepositorioOraculo.
    Isso segue o princípio de Dependency Inversion (SOLID), pois a classe de serviço depende de abstrações, não de implementações concretas.


Regras de Cálculo e Validação:
T   udo que envolva “como calcular saldo”, “como gerar relatório de ganhos/perdas” ou “ordenar listas” fica aqui.

A camada de serviços não se preocupa com detalhes de I/O ou de interface (console): apenas executa ações lógicas e retorna resultados (objetos ou valores).

