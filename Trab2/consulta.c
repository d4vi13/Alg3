#include <string.h>
#include "consulta.h"
#include "dict.h"

/*
 *  Ler do src uma linha e retornar a palavra para e distância de edição 
 * */

int LerUmaConsulta(FILE** src, char** word, int* dist){
   	 
	char *space, *line = malloc(MAX_WORD_SIZE * 2 * sizeof * word);
	if(!line){
		printf("buffer allocation failed");
		return 0;
	}

    *word = malloc(MAX_WORD_SIZE * sizeof **word);
  	if (!*word){
		free(line);	
		printf("buffer allocation failed");
		return 0;
	} 
    
    memset(line, 0, 2*MAX_WORD_SIZE * sizeof * line);
    memset(*word, 0, MAX_WORD_SIZE * sizeof ** word);
    
    line = fgets(line, MAX_WORD_SIZE, *src);
    if (!line || (line[0] == '\n')) {
		free(line);
		free(*word);
        return 0;
	}
	space = strchr(line, ' ');
	*space = '\0';
	
	strcpy(*word, line);
	
	*dist = atoi(space+1);

	free(line);
    return 1; 
     
}

/*
 * Calcula a distancia de edicao entre a e b
 * */
int DistanciaDeEdicao(char * a, char* b){
	int coluna, linha, i, j;
	coluna = strlen(a);
	linha = strlen(b);

	int distancias[coluna+1][linha+1];

	for (i = 0; i <= coluna; ++i) distancias[i][0] = i;
	for (j = 0; j <= linha; ++j) distancias[0][j] = j;

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
	int qtd_keys = 0, n = 0, j = 0;

	RetrieveAllKeys(tree, keys, &qtd_keys);
	for (int i = 0; i < qtd_keys && j < 20 ; ++i) {
		if (DistanciaDeEdicao(word, dict->words[keys[i]]) <= dist) {
			if (n != 0) {
				printf(",");
			}
			printf("%s", FetchUnWord(dict, keys[i]));
			n = 1;
			j++;
		}		
	}

	printf("\n");

    free(keys);

}

void Consulta(FILE* in, PTRIE_TREE trie, PDICT dict){
    char* word, *copy = malloc(1024 * sizeof * copy);
	int dist;

    int tam = GetLineCount(in);
	for(int i = 0; i < tam; i++){
		if (LerUmaConsulta(&in, &word, &dist)) {
			Normalized(&word, &copy);
			if (word){
				printf("%s:", copy);
				ProcurarPalavarasComDistN(trie, dict, word, dist);
				free(word);
			}
		}
	}
	free(copy);
	return;
}
