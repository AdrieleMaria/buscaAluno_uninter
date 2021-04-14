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

  if(*raiz == NULL) // raiz vazia?
    *raiz = novo; // insere novo
  else{
    struct no* atual = *raiz;
    struct no* antes = NULL;
    while(atual != NULL){
      antes = atual;
      if(al.ru == atual->dados.ru){
        free(novo);
        return 0;
      }
      if(al.ru > atual->dados.ru){
        atual = atual->direita;
      }else{
        atual = atual->esquerda;
      }
    }
    if(al.ru > antes->dados.ru){
      antes->direita = novo;      
    }else{
      antes->esquerda = novo;
    }  
    printf("\n%s foi inserido", novo->dados.nome);
  }
  
  return 1;
}



int buscar(arvore *raiz, int ru){
  //printf("chegou no buscar!");  

  if(raiz == NULL)
    return 0;
  
  struct no* aux = *raiz;

  if(ru!= aux->dados.ru){
    printf("\nRU nao encontrado");
  }else if(ru < aux->dados.ru){
    buscar(&aux->esquerda, ru);
    printf("esquerda");
  }else{
    if(ru > aux->dados.ru){
      buscar(&aux->direita, ru);
      printf("direita");
    }else{      
      if(ru == aux->dados.ru){
        printf("%-10s %-20s",(*raiz)->dados.nome,(*raiz)->dados.email);
      }      
    }
    
  }
  
  return 0;
}


void Em_ordem(arvore *raiz){ 
    if(*raiz == NULL){
      printf("\narvore vazia\n\n");// imprime         
    }
    if(*raiz != NULL){
      Em_ordem(&((*raiz)->esquerda));
      printf("\n%-10s %-20s %d",(*raiz)->dados.nome,(*raiz)->dados.email,(*raiz)->dados.ru);
      Em_ordem(&((*raiz)->direita));
    }   
}

