
// tipo de dado armazenado na arvore
struct aluno{
  char nome[50];
  char email[100];
  int ru;
};

typedef struct no *arvore;

// prototipos das funçoes

arvore* criar_arvore(void);

void libera_arvore(arvore* raiz);

int inserir(arvore *raiz, struct aluno al);

int buscar(arvore *raiz, int ru);

void Em_ordem(arvore *raiz);