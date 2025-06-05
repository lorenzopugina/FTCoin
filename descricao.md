
Estamos usando o padrão MVC - Model View Controller, veja nas pastas a descrição doq cada uma faz.

Resumo de como vai funcionar:

exemplo: registrar compra de moeda

-View mostra o menu: 1. Registrar Compra
-Usuário escolhe a opção e insere os dados
-View chama o Controller MovimentacaoController.registrarCompra(...)

-Controller processa: Recupera a Carteira pelo CarteiraDAO
-Model (Carteira): Recebe a nova Movimentacao criada
-Atualiza seu estado interno (ex: adiciona a movimentação, recalcula saldo, etc.)
-DAO (MovimentacaoDAO): Guarda a movimentação no armazenamento (memória ou banco MariaDB)
-Controller finaliza: Envia uma mensagem de sucesso ou erro para a View
-View: Exibe o resultado da operação para o usuário


Usuário → View → Controller → Model → DAO → Banco de Dados
                                ↓        ↑
                              Utils (suporte)
