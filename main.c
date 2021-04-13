#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "bst.h"

int main(void) {

  // utilização da biblioteca locale
  setlocale(LC_ALL, "");    

  arvore *raiz; // raiz é um ponteiro para ponteiro para a struct no 

  raiz = criar_arvore();

  char nome[50];
  char email[100];
  int ru;


  struct aluno al;

  struct aluno alun[10]={{"Maria","m@email.com",3154987},{"Ana","a@email.com",3265789},{"Adriele","adriele@email.com",3314980},{"Bia","b@email.com",3465987},{"Charles", "charles@email.com",3565982},{"Neuza","neuza@email.com",3645982},{"Pedro","pedrinho@email.com",3756982},{"Luiz","luiz@email.com",3798523},{"Marina","mari@email.com",3845980},{"Laura","laurinha@email.com",3945670}};  

  int opcao;

  do{
     printf("\n\n----------MENU---------- \n1. Utilizar array alun  |\n2. Inserir aluno manual |\n3. Buscar aluno por RU  |");
     printf("\n4. Exibir todos Alunos  |\n5. liberar a Arvore     |\n6. Sair                 |");
     printf("\n------------------------\nOpção Escolhida: ");

        scanf("%d", &opcao);

    switch(opcao){
      case 1:         
        //array alun
        for(int i=0;i<10;i++){
          inserir(raiz, alun[i]);
        }        
        break;
      case 2: 
        //Inserir manualmente
        printf("\nNome do aluno: ");
        setbuf(stdin, NULL); 
        fgets( nome, sizeof(nome), stdin);
        strcpy(al.nome, nome);

        printf("\nEmail do Aluno: ");
        setbuf(stdin, NULL);
        fgets( email, sizeof(email), stdin);
        strcpy(al.email, email); 

        printf("\nRU do Aluno: ");
        setbuf(stdin, NULL);
        scanf("%d", &ru);
        al.ru = ru;

        inserir(raiz, al);        
        break;        
      case 3:
        //buscar
        printf("digite o ru do aluno: ");   
        scanf("%d", &ru);
        
        printf("%-10s %-20s\n", "Nome", "email");
        buscar(raiz, ru);
        break;
      case 4:
        printf("%-10s %-20s %s", "Nome", "email", "RU");
        Em_ordem(raiz);
        break;
      case 5:
        libera_arvore(raiz);
        break;
      case 6:
        break;
      default:
        printf("numero incorreto!");
        break;
    }
  }while(opcao != 6);  

  return 0;
}