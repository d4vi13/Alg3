#include <string.h>
#include "consulta.h"


/*
 *  Ler do src uma linha e retornar a palavra para e distância de edição 
 * */

void LerUmaConsulta(FILE* src, char** word, int* dist){
   	 
	char *space, *line = malloc(MAX_WORD_SIZE * 2 * sizeof * word);
	if(!line){
		printf("buffer allocation failed");
		return;
	}

    *word = malloc(MAX_WORD_SIZE * sizeof **word);
  	if (!*word){
		free(line);	
		printf("buffer allocation failed");
		return;
	} 
    
    memset(line, 0, 2*MAX_WORD_SIZE * sizeof * word);
    memset(word, 0, MAX_WORD_SIZE * sizeof * word);
    
    line = fgets(word, MAX_WORD_SIZE, *src);
    if (!line)
        return;

	space = strchr(line, ' ');
	*space = '\0';
	
	strcpy(word, line);
	
	*dist = atoi(space+1);

	free(line);
	free(word);
    return  word; 
     
}

/*
 * Calcula a distancia de edicao entre a e b
 * */
static inline void DistanciaDeEdicao(char * a, char* b){
	int coluna, linha, coluna_atual, linha_atual;
	coluna = strlen(a);
	linha = strlen(b);

	int distancias[coluna][linha];

	for (coluna_atual = 0; coluna_atual <= coluna; ++coluna_atual) distancias[0][coluna_atual] = coluna_atual;
	for (linha_atual = 0; linha_atual <= linha; ++linha_atual) distancias[linha_atual][0] = linha_atual;

	for (coluna_atual = 1; coluna_atual <= coluna; ++coluna_atual) {
		for (linha_atual = 1; linha_atual <= linha; ++linha_atual) {
			if (a[coluna_atual - 1] == b[linha_atuali - 1]) distancias[coluna_atual][linha_atual] = distancias[coluna_atual - 1][linha_atual - 1];
			else distancias[coluna_atual][linha_atual] = (min(distancias[coluna_atual-1][linha_atual-1], min(distancias[coluna_atual-1][linha_atual],distancias[coluna_atual][linha_atual-1]))) + 1;
		}
	}
	return distancias[coluna_atual][linha_atual];
}

/*
 * Passear na arvore até ter inserir 20 chaves no vetor ou ter acabado as palavras 
 * */
static inline void ProcurarPalavarasComDistN(TRIE_TREE tree, char* word, int dist, int VetorDeChaves[20]){

}


static inline void EscreverResultado(FILE* out, char* palavrasDaConsulta, int* VetorDeChaves){

}


void Consulta(FILE* in, FILE* out, PTRIE_TREE trie, PDICT dict){
	/*
    int chaves[20], max_dist ,lines = GetLineCount(in);
    char* word;


    for(int i = 0; i < lines; i++){
        LerUmaConsulta(out, &word, &max_dist);
        ProcurarPalavrasComDistN(trie, word, max_dist, chaves);
        EscreverResultado(out, word, chaves);
    }
	*/
}
