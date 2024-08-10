#include <string.h>
#include "consulta.h"
#include "dict/dict.h"

/*
 *  Ler do src uma linha e retornar a palavra para e distância de edição 
 * */

void LerUmaConsulta(FILE** src, char** word, int* dist){
   	 
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
    
    memset(line, 0, 2*MAX_WORD_SIZE * sizeof * line);
    memset(*word, 0, MAX_WORD_SIZE * sizeof ** word);
    
    line = fgets(line, MAX_WORD_SIZE, *src);
    if (!line)
        return;

	space = strchr(line, ' ');
	*space = '\0';
	
	strcpy(*word, line);
	
	*dist = atoi(space+1);

	free(line);
    return; 
     
}

/*
 * Calcula a distancia de edicao entre a e b
 * */
int DistanciaDeEdicao(char * a, char* b){
	int coluna, linha, i, j;
	coluna = strlen(a);
	linha = strlen(b);

	int distancias[coluna+1][linha+1];

	for (i = 0; i <= coluna; ++i) distancias[0][i] = i;
	for (j = 0; j <= linha; ++j) distancias[j][0] = j;

	for (i = 1; i <= coluna; ++i) {
		for (j = 1; j <= linha; ++j) {
			if (a[i - 1] == b[j - 1]) distancias[i][j] = distancias[i - 1][j - 1];
			else distancias[i][j] = (min(distancias[i-1][j-1], min(distancias[i-1][j],distancias[i][j-1]))) + 1;
		}
	}
	return distancias[coluna][linha];
}

/*
 * Passear na arvore até ter inserir 20 chaves no vetor ou ter acabado as palavras 
 * */
void ProcurarPalavarasComDistN(PTRIE_TREE tree, PDICT dict, char* word, int dist){
    int *keys = malloc(8192 * sizeof * keys);
	int qtd_keys = 0, n = 0;

/*	int *todasAsChaves = malloc;
	PassearNaTrieEPegarAsChaves(todasAsChaves);

	iterar sobre todasAsChaves 
		if Distancia de dict[chave] de word < dist
			add to VetorDeChaves
*/
	RetrieveAllKeys(tree, keys, &qtd_keys);
	printf("%s:\n", word);
	for (int i = 0; i < qtd_keys && i < 20 ; ++i) {
        //printf("%d\n", DistanciaDeEdicao(word, dict->words[keys[i]]) );
		if (DistanciaDeEdicao(word, dict->words[keys[i]]) <= dist) {
			if (n != 0) {
				printf(",");
			}
			printf("%s", FetchWord(dict, keys[i]));
			n = 1;
		}		
	}
	printf("\n");

    free(keys);

}


// static inline void EscreverResultado(FILE* out, char* palavrasDaConsulta, int* VetorDeChaves){
	
// }

/*
void Consulta(FILE* in, FILE* out, PTRIE_TREE trie, PDICT dict){
    int max_dist ,lines = GetLineCount(in);
    char* word;

    for(int i = 0; i < lines; i++){
        LerUmaConsulta(out, &word, &max_dist);
        ProcurarPalavrasComDistN(trie, dict, word, max_dist);
        // EscreverResultado(out, word, chaves);
    }
}

*/
