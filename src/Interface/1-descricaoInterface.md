Objetivo:

Fazer a interação direta com o usuário via terminal: mostrar menus, ler opções, ler valores, exibir resultados.
Não conter lógica de negócio (essa fica nos Use Cases) nem detalhes de persistência (essa fica na camada de repositório).

Contém:

main.cpp e classes auxiliares, responsável por:
    Exibir um menu de opções (ex.: criar carteira, editar carteira, registrar compra, listar carteiras, gerar relatórios, sair).

Ler entrada do usuário (opção selecionada, dados para criar/editar, datas etc.).

Chamar o método apropriado do UseCase correspondente (por exemplo, UseCasecriarCarteira()).

Exibir resultados formatados (ex: lista de carteiras, histórico de transações, valor de saldo).

