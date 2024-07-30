#include "consulta.h"


/*
 *  Ler do src uma linha e retornar a palavra para e distância de edição 
 * */

static inline void LerUmaConsulta(FILE* src, char** word, int* dist){

}

/*
 * Calcula a distancia de edicao entre a e b
 * */
static inline void DistanciaDeEdicao(char * a, char* b){

}

/*
 * Passear na arvore até ter inserir 20 chaves no vetor ou ter acabado as palavras 
 * */
static inline void ProcurarPalavarasComDistN(TRIE_TREE tree, char* word, int dist, int VetorDeChaves[20]){

}


static inline void EscreverResultado(FILE* out, char* palavrasDaConsulta, int* VetorDeChaves){

}


void Consulta(FILE* in, FILE* out, PTRIE_TREE trie, PDICT dict){
    int chaves[20], max_dist ,lines = GetLineCount(in);
    char* word;


    for(int i = 0; i < lines; i++){
        LerUmaConsulta(out, &word, &max_dist);
        ProcurarPalavrasComDistN(trie, word, max_dist, chaves);
        EscreverResultado(out, word, chaves);
    }
}

