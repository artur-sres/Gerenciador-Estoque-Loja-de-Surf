//Header guard para evitar inclusoes duplicadas
#ifndef LOJA_H
#define LOJA_H

//Bibliotecas utilizadas
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Definicao das capacidaddes das caixas para cada tipo de produto
#define CAPACIDADE_CAIXA_PARAFINA 50
#define CAPACIDADE_CAIXA_LEASH 25
#define CAPACIDADE_CAIXA_QUILHA 10
#define CAPACIDADE_CAIXA_DECK 5

//Structs utilizadas 
typedef struct no_produto{ 
    char* codigo;
    char* tipo;
    char* descricao;
    float preco;
    struct no_produto* prox;
    struct no_produto* ant;
}no_produto;

typedef struct no_caixa{ 
    char* codigo;
    int capacidade;
    int qntd_itens;
    no_produto* inicio;
    no_produto* final;
    struct no_caixa* prox;
}no_caixa;

typedef struct no_pilha_de_caixas{ 
    char* tipo;
    no_caixa* topo;
    int qntd_caixas;
    int qntd_itens;
    struct no_pilha_de_caixas* prox;
    struct no_pilha_de_caixas* ant;
}no_pilha_de_caixas;

typedef struct no_pp{ 
    no_produto* produto; 
    struct no_pp* prox;
    struct no_pp* ant;
}no_pp;

typedef struct no_pedido_entrega{
    no_produto* produto_entregue; 
    char* nome_cliente;
    char* cpf;
    char* cep;
    char* rua;
    char* numero_casa;
    char* complemento;
    struct no_pedido_entrega* prox; 
}no_pedido_entrega;

//Prototipos das funcoes
no_pilha_de_caixas* achar_tipo(no_pilha_de_caixas* inicio_pilha, char* tipo); //Funcao para encontrar um tipo de pilha de caixas
char* gerar_codigo(const char* prefixo); //Funcao para gerar um codigo de identicacao para produtos e para caixas
no_caixa* criar_nova_caixa(no_produto* novo_produto, const char* tipo); //Funcao para criar nova caixa
void inserir_produto_ordenado_na_caixa(no_produto* novo_produto, no_produto** inicio_caixa, no_produto** final_caixa); //Funcao para inserir no_produto ordenado por preco dentro de uma caixas
void inserir_produto_ordenado_na_lista_de_vendas(no_produto* novo_produto); //Funcao para inserir no_produto ordenado por preco dentro da lista de venda
void add(char* tipo, char* descricao, float preco); //Funcao para adicionar um produto ao estoque
void imprimir_estoque_completo(); //Funcao para imprimir todos os produtos disponiveis no estoque (Por caixas)
void imprimir_lista_venda(); //Funcao para imprimir todos os produtos disponiveis para venda 
void imprimir_por_tipo(char* tipo); //Funcao para visualizar produtos de uma categoria especifica
void imprimir_por_preco(float min, float max); //Funcao para visualizar produtos dentro de um intervalo de preço
char* identificar_tipo_pelo_codigo(char* codigo_produto); //Funcao para identificar o tipo de produto pelo codigo
no_produto* remover_produto(char* codigo);//Funcao para remover um produto do estoque e retornar o endereço do removido
void adicionar_na_fila_de_entrega(no_produto* produto, char* nome, char* cpf, char* cep, char* rua, char* numero, char* complemento); //Funcao para criar o pedido e adiciona-lo na fila de entrega
void preparar_pedido(no_produto* produto_comprado); //Funcao para pedir os dados do cliente ao usuario
void processar_entrega(); //Funcao para remover o primeiro item da fila e simular a saida para entrega
void imprimir_fila_de_entregas(); //Funcao para imprimir a fila de entregas

#endif

