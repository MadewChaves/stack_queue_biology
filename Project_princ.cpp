#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct no_da_fila {

char nucleotideos;

struct no_da_fila* prox;

};

struct fila {

struct no_da_fila* primeiro;

struct no_da_fila* ultimo;

};

void inserir_na_fila(struct fila* fila, char nucleotideos) {

struct no_da_fila* no_novo = (struct no_da_fila*)malloc(sizeof(struct no_da_fila));

no_novo->nucleotideos = nucleotideos;

no_novo->prox = NULL;

if (fila->primeiro == NULL) {

fila->primeiro = no_novo;

fila->ultimo = no_novo;

} else {

fila->ultimo->prox = no_novo;

fila->ultimo = no_novo;

}

}

void excluir_na_fila(struct fila* fila) {

if (fila->primeiro == NULL) {

printf("Fila vazia, por favor, inserir novos elementos.\n");

} else {

struct no_da_fila* temp = fila->primeiro;

fila->primeiro = fila->primeiro->prox;

free(temp);

}

}

void imprimir_na_fila(struct fila* fila) {

struct no_da_fila* temp = fila->primeiro;

while (temp != NULL) {

printf("%c", temp->nucleotideos);

temp = temp->prox;

}

printf("\n\n");

}

struct no_da_pilha {

char nucleotideos;

struct no_da_pilha* prox;

};

struct pilha {

struct no_da_pilha* topo;

};

void inserir_na_pilha(struct pilha* pilha, char nucleotideos) {

struct no_da_pilha* no_novo = (struct no_da_pilha*)malloc(sizeof(struct no_da_pilha));

no_novo->nucleotideos = nucleotideos;

no_novo->prox = pilha->topo;

pilha->topo = no_novo;

}

void excluir_na_pilha(struct pilha* pilha) {

if (pilha->topo == NULL) {

printf("Pilha vazia. Por favor, inserir novos elementos.\n");

} else {

struct no_da_pilha* temp = pilha->topo;

pilha->topo = pilha->topo->prox;

free(temp);

}

}

void imprimir_na_pilha(struct pilha* pilha) {

struct no_da_pilha* temp = pilha->topo;

while (temp != NULL) {

printf("%c", temp->nucleotideos);

temp = temp->prox;

}

printf("\n\n");

}

int main() {

struct fila fila;

fila.primeiro = NULL;

fila.ultimo = NULL;

struct pilha pilha;

pilha.topo = NULL;

char seq[100];

printf("Digite a sequencia de nucleotideos para obter o resultado esperado: ");

scanf("%s", seq);

int tamanho = strlen(seq);

for (int i = 0; i < tamanho; i++) {

inserir_na_fila(&fila, seq[i]);

}

while (fila.primeiro != NULL) {

char nucleotideos = fila.primeiro->nucleotideos;

excluir_na_fila(&fila);

switch (nucleotideos) {

case 'A':

inserir_na_pilha(&pilha, 'T');

break;

case 'T':

inserir_na_pilha(&pilha, 'A');

break;

case 'C':

inserir_na_pilha(&pilha, 'G');

break;

case 'G':

inserir_na_pilha(&pilha, 'C');

break;

default:

printf("Nucleotideo não encontrado, por favor, verificar novamente.\n", nucleotideos);

break;

}

}

printf("Fila: %s", seq);

printf("\n");

printf("Pilha: ");

imprimir_na_pilha(&pilha);

return 0;

}
