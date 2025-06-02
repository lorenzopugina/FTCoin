Objetivo:

Isolar totalmente a forma como os dados são guardados e recuperados.

deve:

Definir interfaces (abstracts) para cada entidade (por exemplo: IRepositorioCarteira, IRepositorioTransacao, IRepositorioOraculo).

Essas interfaces listam apenas os métodos de CRUD ou consultas específicas necessárias (inserir, atualizar, remover, buscarPorId, listarTodas, buscarPorData, etc.).

Cada interface não conhece implementação; trata-se apenas de “o que” deve ser feito, por isso são abstracts.

Criar implementação inMemory de cada interface.
    Tudo fica em memória até o encerramento do programa.

No futuro, criar uma implementação Database que também cumpra a mesma interface.
    Padrão DAO

    Essa abstração garante que o restante do sistema (camada de serviços e de interface) depende apenas de IRepositorio…, não de classes concretas.