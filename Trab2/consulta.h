#ifndef CONSULTA_H
#define CONSULTA_H

#include "common.h"
#include "trie.h"
#include "utils.h"
#include "dict.h"

int DistanciaDeEdicao(char * a, char* b);

void ProcurarPalavarasComDistN(PTRIE_TREE tree, PDICT dict, char* word, int dist);

extern void Consulta(FILE* in, PTRIE_TREE trie, PDICT dict);


#endif
