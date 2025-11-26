# 🔗 Gerenciador de Lista Encadeada em C
## 💻 Sobre o projeto

Este projeto é uma implementação completa de uma **Lista Simplesmente Encadeada (Singly Linked List)** utilizando a linguagem C. 

O objetivo é demonstrar o funcionamento dinâmico da memória (`malloc` e `free`) e a lógica de manipulação de ponteiros. O projeto utiliza a estratégia de **Nó Cabeça (Head Node)**, onde o primeiro nó serve apenas como referência inicial, facilitando as operações de inserção e remoção.

O programa conta com um menu interativo no terminal para gerenciar os dados.

## ⚙️ Funcionalidades

O sistema permite realizar as seguintes operações:

* **Inserção:**
    * Inserir elemento no início da lista.
    * Inserir elemento no final da lista.
* **Remoção:**
    * Remover do início.
    * Remover do final.
    * Remover um elemento específico (busca por valor).
    * Zerar toda a lista (limpar memória).
* **Visualização e Busca:**
    * Exibir a lista completa.
    * Buscar o endereço de memória de um valor específico.

## 🛠 Estrutura do Código

O código baseia-se na seguinte `struct`:

```c
struct Node {
    int num;            // Dado armazenado
    struct Node *prox;  // Ponteiro para o próximo nó
};

## 🚀 Como executar o projeto

## Opção 1: Compilador Online (Recomendado para testes rápidos)

* Acesse o OnlineGDB.
* Selecione a linguagem C.
* Copie o código do arquivo main.c e cole no editor.
* Clique em Run.

### Opção 2: Rodando localmente (Linux/Mac ou Windows com GCC)
Pré-requisitos: Ter o compilador GCC instalado.

```bash
# 1. Clone este repositório
$ git clone https://github.com/Paollax/Lista_Encadeada

# 2. Acesse a pasta do projeto
$ cd nome-do-repositorio

# 3. Compile o código
$ gcc main.c -o lista_encadeada

# 4. Execute o programa
# No Linux/Mac:
$ ./lista_encadeada

# No Windows:
$ lista_encadeada.exe



🧠 Exemplo de Uso
Ao rodar o programa, você verá o seguinte menu:

--- MENU PRINCIPAL ---
1. Inserir no inicio
2. Inserir no final
3. Remover do inicio
4. Remover do final
5. Remover por valor
6. Zerar lista
7. Exibir lista completa
8. Buscar elemento
0. Sair
Opcao:
