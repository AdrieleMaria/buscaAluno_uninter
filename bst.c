#include <stdio.h>
#include "bst.h"

struct no{
  struct aluno dados;

  struct no *esquerda;
  struct no *direita;
};



arvore buscar(arvore *raiz, struct aluno al){
  int ru = al.ru;

  if(raiz != NULL){
    struct no* atual = *raiz;

    if(ru < atual->dados.ru){
      buscar(&atual->esquerda, al);
    }else{
      if(ru > atual->dados.ru){
        buscar(&atual->direita, al);
      }else{
        if(ru == atual->dados.ru){
          return atual;
        }
      }
    }
  }
  return 0;
}