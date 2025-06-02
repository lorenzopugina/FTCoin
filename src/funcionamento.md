
Vamos usar arquitetura em camadas:
    organiza a aplicação e separa em diferentes camadas, cada uma com sua função, e só conversam com as camadas adjacentes.
    
 Camadas da nossa aplicação:

    Interface = interage com o usuário (Menus) e chama os casos de uso apropriados
    Use Case = Quem faz as operações, combina chamadas a vários repositórios e entidades com lógica par ter um resultado.
    Repository = Implementa os acessos e a persistência dos dados, possui os abstracts que definem a implementação dos BDs
    Entities = Classes que representam dados
 

Resumo:
    Interface chama → Use Case (faz a regra, usa entidades, chama repositórios) → Repository (Interfaces e implementações) manipula entidades → Entities são os objetos de dados que trafegam por todas as camadas.