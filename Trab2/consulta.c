#include <string.h>
#include "consulta.h"

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

	int distancias[coluna][linha];

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
static inline void ProcurarPalavarasComDistN(TRIE_TREE tree, char* word, int dist, int VetorDeChaves[20]){
/*	int *todasAsChaves = malloc;
	PassearNaTrieEPegarAsChaves(todasAsChaves);

	iterar sobre todasAsChaves 
		if Distancia de dict[chave] de word < dist
			add to VetorDeChaves
*/


}


static inline void EscreverResultado(FILE* out, char* palavrasDaConsulta, int* VetorDeChaves){

}


	/*
void Consulta(FILE* in, FILE* out, PTRIE_TREE trie, PDICT dict){
    int chaves[20], max_dist ,lines = GetLineCount(in);
    char* word;


    for(int i = 0; i < lines; i++){
        LerUmaConsulta(out, &word, &max_dist);
        ProcurarPalavrasComDistN(trie, word, max_dist, chaves);
        EscreverResultado(out, word, chaves);
    }
}
	*/
