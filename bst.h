
// tipo de dado armazenado na arvore
struct aluno{
  char nome[50];
  char email[100];
  int ru;
};

typedef struct no *arvore;

// prototipos das funçoes

arvore buscar(arvore *raiz,struct aluno al);


