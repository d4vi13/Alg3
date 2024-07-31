#ifndef CONSULTA_H
#define CONSULTA_H

#include "common.h"
#include "trie/trie.h"
#include "utils.h"

int DistanciaDeEdicao(char * a, char* b);

void LerUmaConsulta(FILE** src, char** word, int* dist);

//extern void Consulta(FILE* in, FILE* out, PTRIE_TREE trie, PDICT dict);


#endif
