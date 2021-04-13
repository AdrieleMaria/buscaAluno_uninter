#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

struct no{
  struct aluno dados;

  struct no *esquerda;
  struct no *direita;
};

arvore* criar_arvore(void){
  printf("\nArvore Criada!");
  arvore* raiz = (arvore*)malloc(sizeof(arvore));

  if(raiz!=NULL)
    *raiz = NULL;
  return raiz;
  printf("arvore criada!");
}

void libera_NO(struct no* aux){
  if(aux == NULL)
    return;
  libera_NO(aux->esquerda);
  libera_NO(aux->direita);
  free(aux);
  aux = NULL;
}

void libera_arvore(arvore* raiz){
  printf("liberou!");
  if(raiz == NULL)
    return;
  libera_NO(*raiz);// libera cada no
  free(raiz);// libera a raiz
}

int inserir(arvore *raiz, struct aluno al){
  //printf("entrou no inserir!");
  if(raiz == NULL)
    return 0;
  struct no* novo;
  novo = (struct no*) malloc(sizeof(struct no));

  if(novo == NULL)
    return 0;

  novo->dados = al;
  novo->direita = NULL;
  novo->esquerda = NULL;

  if(*raiz == NULL)
    *raiz = novo;
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

  if(ru < aux->dados.ru){
    buscar(&aux->esquerda, ru);
  }else{
    if(ru > aux->dados.ru){
      buscar(&aux->direita, ru);
    }else{
      if(ru == aux->dados.ru){
        printf("%-10s %-20s %d",(*raiz)->dados.nome,(*raiz)->dados.email,(*raiz)->dados.ru);
      }
    }
  }
  return 0;
}


void Em_ordem(arvore *raiz){ 
    if(raiz == NULL){
      printf("\nvazia\n\n");// imprime         
    }
    if(*raiz != NULL){
      Em_ordem(&((*raiz)->esquerda));
      printf("\n%-10s %-20s %d",(*raiz)->dados.nome,(*raiz)->dados.email,(*raiz)->dados.ru);
      Em_ordem(&((*raiz)->direita));
    }   
}

