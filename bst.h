
// tipo de dado armazenado na arvore
struct aluno{
  char nome[50];
  char email[100];
  int ru;
};


typedef struct no *arvore;


// prototipos das funçoes

int inserir(arvore *raiz, struct aluno);

int buscar(arvore *raiz, int ru);

void visualizar_ordem(arvore *raiz);

void visualizar_preordem(arvore *raiz);

void visualizar_posordem(arvore *raiz);
