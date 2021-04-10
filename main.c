#include <stdio.h>
#include <locale.h>

#include "bst.h"

int main(void) {

  // utilização da biblioteca locale
  setlocale(LC_ALL, "");    

  arvore *raiz; // raiz é um ponteiro para ponteiro para a struct no

  struct aluno al;

  char aluno[50];
  char email[100];
  int ru;

  int opcao;

  do{
     printf("\n-------MENU------- \n1. Buscar Aluno  |\n2. Exibir Todos  |\n3. Sair          |");
     printf("\n------------------\nOpção Escolhida: ");

        scanf("%d", &opcao);

    switch(opcao){
      case 1:

        break;
      case 2:

        

        break;
      case 3:
        break;
      default:
        printf("numero incorreto!");
        break;
    }
  }while(opcao != 3);


  return 0;
}