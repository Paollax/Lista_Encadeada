#include <stdio.h>
#include <stdlib.h> // Necessário para as funções malloc() e free()

// Define a estrutura de cada nó da lista
struct Node{
	int num;            // O campo de dados (onde o número inteiro será armazenado)
	struct Node *prox;  // O ponteiro para o próximo nó da lista
}; 
typedef struct Node node; // Cria um apelido 'node' para 'struct Node' para simplificar o código

// Funções de Gerenciamento Básico
void inicia(node *LISTA);           // Inicializa a lista (reseta LISTA->prox para NULL)
int vazia(node *LISTA);             // Verifica se a lista está vazia
void libera(node *LISTA);           // Libera toda a memória alocada dinamicamente

// Funções de Menu e Interação
int menu(void);                     // Exibe o menu de opções
void opcao(node *LISTA, int op);    // Executa a opção escolhida pelo usuário

// Funções de Inserção (CRIAR)
void insereFim(node *LISTA);        // Insere um elemento no final da lista
void insereInicio(node *LISTA);     // Insere um elemento no início da lista

// Funções de Leitura e Busca (LER)
void exibe(node *LISTA);            // Exibe todos os elementos da lista
node *busca(node *LISTA, int valor); // Busca um nó pelo valor e retorna seu endereço

// Funções de Remoção (DELETAR)
void removeInicio(node *LISTA);     // Remove o primeiro elemento da lista
void removeFim(node *LISTA);        // Remove o último elemento da lista
void removeElemento(node *LISTA, int valor); // Remove um nó específico pelo seu valor


int main(void){
    // Aloca memória para o nó CABEÇA da lista
	node *LISTA = (node *) malloc(sizeof(node)); 

LISTA ->prox = NULL;
inicia(LISTA);
    
	if(!LISTA){
		printf("Sem memoria disponivel!\n");
		exit(1); // Encerra o programa se a alocação de memória falhar
	}
    
	inicia(LISTA); // Inicializa a lista (LISTA->prox = NULL)
	int opt;
		
	do{
		opt = menu();       // Chama o menu e pega a opção do usuário
		opcao(LISTA, opt);  // Executa a opção
	} while(opt); // O loop continua enquanto a opção não for 0 (Sair)

	// A função libera() é chamada no case 0. Aqui, liberamos apenas a memória do nó CABEÇA.
	free(LISTA); 
	return 0;
}

// Inicializa a lista e limpa a memória se houver nós
void inicia(node *LISTA){
    libera(LISTA); // Chama libera para garantir que a memória anterior seja limpa (útil no "Zerar lista")
	LISTA->prox = NULL; // Faz o nó cabeça apontar para NULL (lista vazia)
}

// Verifica se a lista está vazia
int vazia(node *LISTA){
	if(LISTA->prox == NULL)
		return 1; // 1 = Vazia
	else
		return 0; // 0 = Contém elementos
}

int menu(void){
    int opt;

    printf("\n\n");
    printf("--- MENU PRINCIPAL ---\n");
    
    // INSERÇÃO
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no final\n");
    
    // REMOÇÃO
    printf("3. Remover do inicio\n");
    printf("4. Remover do final\n");
    printf("5. Remover por valor\n");
    printf("6. Zerar lista\n");
    
    // VISUALIZAÇÃO E BUSCA
    printf("7. Exibir lista completa\n");
    printf("8. Buscar elemento\n");
    
    printf("0. Sair\n");
    printf("Opcao: ");

    if (scanf("%d", &opt) != 1) {
        while (getchar() != '\n' && !feof(stdin));
        return -1;
    }
    while (getchar() != '\n' && !feof(stdin)); 

    return opt;
}

// Executa a opção escolhida pelo usuário
void opcao(node *LISTA, int op){
    int valor;
    node *no_encontrado;

    switch(op){
        case 0:
            libera(LISTA);
            break;

        case 1:
            insereInicio(LISTA);
            break;
        case 2:
            insereFim(LISTA);
            break;

        case 3:
            removeInicio(LISTA);
            break;
        case 4:
            removeFim(LISTA);
            break;
        case 5: // Remover por valor
            printf("Qual elemento deseja remover? ");
            if (scanf("%d", &valor) != 1) {
                printf("Entrada invalida.\n");
                while (getchar() != '\n' && !feof(stdin));
                break;
            }
            while (getchar() != '\n' && !feof(stdin));
            removeElemento(LISTA, valor);
            break;
        case 6:
            inicia(LISTA); // Zerar lista
            printf("Lista zerada com sucesso.\n");
            break;

        case 7:
            exibe(LISTA);
            break;
        case 8: // Buscar
            printf("Qual elemento deseja buscar? ");
            if (scanf("%d", &valor) != 1) {
                printf("Entrada invalida.\n");
                while (getchar() != '\n' && !feof(stdin));
                break;
            }
            while (getchar() != '\n' && !feof(stdin));
            
            no_encontrado = busca(LISTA, valor);
            if (no_encontrado != NULL) {
                printf("\nElemento %d encontrado no endereco %p.\n\n", valor, no_encontrado);
            } else {
                printf("\nElemento %d NAO encontrado na lista.\n\n", valor);
            }
            break;

        default:
            printf("Comando invalido\n\n");
    }
}


// Insere um nó no final da lista
void insereFim(node *LISTA){
	node *novo = (node *) malloc(sizeof(node));
    
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
    
	printf("Novo elemento: "); 
    // Leitura do dado e limpeza de buffer
    if (scanf("%d", &novo->num) != 1) {
        printf("Erro de leitura ou valor invalido!\n"); free(novo); return;
    }
    while (getchar() != '\n' && !feof(stdin));
    
	novo->prox = NULL; // O nó do final sempre aponta para NULL

	if(vazia(LISTA))
		LISTA->prox=novo; // Se vazia, a cabeça aponta diretamente para o novo
	else{
		node *tmp = LISTA->prox;
		
        // Percorre até o último nó (aquele cujo 'prox' é NULL)
		while(tmp->prox != NULL)
			tmp = tmp->prox;
            
		tmp->prox = novo; // O último nó antigo aponta para o novo nó
	}
}

// Insere um nó no início da lista (após o nó cabeça)
void insereInicio(node *LISTA){
	node *novo = (node *) malloc(sizeof(node));
    
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
    
	printf("Novo elemento: "); 
    // Leitura do dado e limpeza de buffer
    if (scanf("%d", &novo->num) != 1) {
        printf("Erro de leitura ou valor invalido!\n"); free(novo); return;
    }
    while (getchar() != '\n' && !feof(stdin));

	// 1. O novo nó aponta para o nó que era o primeiro
	novo->prox = LISTA->prox; 

	// 2. O nó cabeça passa a apontar para o novo nó
	LISTA->prox = novo; 
}

// Exibe todos os elementos da lista
void exibe(node *LISTA){
    if(vazia(LISTA)){
		printf("Lista vazia!\n\n");
		return;
	}

	node *tmp = LISTA->prox; // Começa no primeiro nó real

	printf("\nLista: ");
	while(tmp != NULL){
		printf("%d ", tmp->num);
		tmp = tmp->prox; // Avança para o próximo nó
	}
	printf("\n\n");
}

// Busca um elemento na lista e retorna seu endereço
node *busca(node *LISTA, int valor) {
    if (vazia(LISTA)) {
        return NULL;
    }

    node *tmp = LISTA->prox; // Começa a busca no primeiro nó real

    while (tmp != NULL) {
        if (tmp->num == valor) {
            return tmp; // Retorna o ponteiro para o nó encontrado
        }
        tmp = tmp->prox;
    }

    return NULL; // Elemento não encontrado
}



// Libera a memória de todos os nós (exceto o cabeça)
void libera(node *LISTA){
	if(!vazia(LISTA)){
		node *proxNode,
			  *atual;
				
		atual = LISTA->prox; // Começa no primeiro elemento

		while(atual != NULL){
			proxNode = atual->prox; // Salva o endereço do próximo nó
			free(atual);            // Libera a memória do nó atual
			atual = proxNode;       // Avança para o próximo nó
		}
	}
}

// Remove o nó do início da lista
void removeInicio(node *LISTA) {
    if(vazia(LISTA)) {
        printf("Lista vazia. Nao ha o que remover.\n\n");
        return;
    }

    node *lixo = LISTA->prox; // 'lixo' aponta para o nó a ser removido (o primeiro)
    
    // O nó cabeça passa a apontar para o segundo nó da lista
    LISTA->prox = lixo->prox; 

    free(lixo); // Libera a memória do nó removido

    printf("Elemento removido do inicio da lista.\n\n");
}

// Remove o nó do final da lista
void removeFim(node *LISTA) {
    if (vazia(LISTA)) {
        printf("Lista vazia. Nao ha o que remover.\n\n");
        return;
    }

    // Caso 1: Lista com APENAS 1 elemento
    if (LISTA->prox->prox == NULL) {
        node *lixo = LISTA->prox;
        LISTA->prox = NULL;
        free(lixo);
        printf("Elemento removido do final da lista (Lista ficou vazia).\n\n");
        return;
    }

    // Caso 2: Lista com 2 ou mais elementos
    node *anterior = LISTA->prox; // Começa no primeiro nó
    node *atual = anterior->prox;  // Começa no segundo nó

    // O loop para quando 'atual' for o último nó (seu 'prox' é NULL)
    while (atual->prox != NULL) { 
        anterior = atual; // 'Anterior' segue 'atual'
        atual = atual->prox;  
    }

    // 'anterior' é o penúltimo, 'atual' é o último (o lixo)
    anterior->prox = NULL; // O penúltimo agora é o novo fim
    free(atual);           // Libera o antigo último nó

    printf("Elemento removido do final da lista.\n\n");
}

// Remove um elemento em qualquer posição pelo seu valor
void removeElemento(node *LISTA, int valor) {
    if (vazia(LISTA)) {
        printf("Lista vazia. Impossivel remover.\n\n");
        return;
    }

    node *anterior = LISTA;        // Começa na CABEÇA (necessário para religar)
    node *atual = LISTA->prox;     // Começa no primeiro nó real

    // Percorre até encontrar o valor OU até o fim
    while (atual != NULL && atual->num != valor) {
        anterior = atual;   
        atual = atual->prox;    
    }

    if (atual == NULL) {
        // Elemento não encontrado
        printf("Elemento %d NAO encontrado na lista.\n\n", valor);
    } else {
        // Elemento encontrado (em 'atual')
        
        // RELIGAÇÃO: O nó anterior aponta para o nó seguinte do removido
        anterior->prox = atual->prox;
        
        // Libera a memória do nó removido
        free(atual);
        
        printf("Elemento %d removido da lista.\n\n", valor);
    }
}


