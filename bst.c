#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct no{
  struct aluno dados; // dados que serão armazenados 

  struct no *esquerda; //ponteiro para filho a esquerda
  struct no *direita; // ponteiro para filho a direita
};

// função criar arvore
arvore* criar_arvore(void){
  printf("\nArvore Criada!");
  // criar a raiz e aloca espaço na memória para ela
  arvore* raiz = (arvore*)malloc(sizeof(arvore));

  // se deu certo, árvore criada
  if(raiz!=NULL)
    // raiz recebe nulo
    *raiz = NULL;
  // retorna a raiz
  return raiz;
}

// função libera no
void libera_NO(struct no* aux){
  if(aux == NULL) // no aux é nulo?
    return;
  libera_NO(aux->esquerda); // percorrer recursivamente o no da esquerda
  libera_NO(aux->direita); // percorrer recursivamente o no da direita
  free(aux); // na volta da recursão, libera no aux
  aux = NULL; // colocar Null para evitar erro de verificação posterior
}

void libera_arvore(arvore* raiz){
  printf("liberou!");
  if(raiz == NULL) // raiz é nula?
    return;
  libera_NO(*raiz);// libera cada no
  free(raiz);// libera a raiz
}

int inserir(arvore *raiz, struct aluno al){
  //printf("entrou no inserir!");
  if(raiz == NULL) // raiz existe?
    return 0;
  
  struct no* novo; // criar no novo
  novo = (struct no*) malloc(sizeof(struct no)); // alocar espaço na menmória para novo

  if(novo == NULL) // novo existe?
    return 0;

  //copia os dados que eu quero inserir para o no novo
  novo->dados = al;
  novo->direita = NULL; // o próximo a direita será nulo
  novo->esquerda = NULL; // o próximo a esquerda será nulo

  if(*raiz == NULL) // arvore vazia?
    *raiz = novo; // insere novo
  else{ // se não...
    struct no* atual = *raiz; // criar nó atual recebendo a raiz
    struct no* antes = NULL; // criar um nó anterior guardando null
    while(atual != NULL){ // percorrer os nós até chegar em um nó folha
      antes = atual; // o nó anterior recebe o atual
      if(al.ru == atual->dados.ru){ // comparar o ru se é igual a informação que está no nó atual 
        free(novo); // não vai guardar valores repetidos, então libera o nó novo
        return 0; // elemento já existe
      }
      if(al.ru > atual->dados.ru){ // se o valor for maior...
        atual = atual->direita; // atual recebe o nó da direita
      }else{
        atual = atual->esquerda; // se for menor, o da esquerda
      }
    } // ao final do while, quer dizer que chegou a uma folha

    // inicia a inserção escolhendo onde inserir
    if(al.ru > antes->dados.ru){// se o valor for maior insere na direita
      antes->direita = novo;      
    }else{ // se o valor for menor, insere na esquerda
      antes->esquerda = novo;
    }  
    printf("\n%s foi inserido", novo->dados.nome); // mostrar o nome do que foi inserido, para verificação
  }
  
  return 1; // deu certo a inserção
}



int buscar(arvore *raiz, int ru){  
  if(raiz == NULL) // raiz existe?
    return 0;  
  struct no* aux = *raiz; //cria um nó auxiliar recebendo a raiz

  if(ru < aux->dados.ru){ // se ru digitado for menor...
    buscar(&aux->esquerda, ru); // buscar recursivamente pela esquerda   
  }else{
    if(ru > aux->dados.ru){ // se for maior...
      buscar(&aux->direita, ru); // buscar recursivamente pela direita  
    }else{      
      if(ru == aux->dados.ru){ // se for igual..
        printf("%-10s %-20s",(*raiz)->dados.nome,(*raiz)->dados.email); // imprima o nome e o email do aluno encontrado
      }else if(ru != aux->dados.ru){ // se não encontrar...
        printf(" RU não existe!"); // imprima mensagem de erro
      }
    }    
  }
  
  return 0;
}


void Em_ordem(arvore *raiz){ 
    if(*raiz == NULL){
      printf("\narvore vazia\n\n");// imprime         
    }
    if(*raiz != NULL){ // se arvore existir imprima em ordem começando pela raiz
      Em_ordem(&((*raiz)->esquerda)); 
      printf("\n%-10s %-20s %d",(*raiz)->dados.nome,(*raiz)->dados.email,(*raiz)->dados.ru);
      Em_ordem(&((*raiz)->direita));
    }   
}

