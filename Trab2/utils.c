#include "utils.h"
#include <string.h>

struct dupla_char{
    char code;
    char sem_acento;
};

typedef struct dupla_char dupla_char;

dupla_char conversao[] = {
    {80, 'a'},
    {81, 'a'},
    {82, 'a'},
    {83, 'a'},
    {84, 'a'},
    {85, 'a'},
    {88, 'e'},
    {89, 'e'}
};


BOOL newNormalizeWord(unsigned char* word){
    BOOL result = TRUE;
    char c;
    int i;

    char *newword = malloc(MAX_WORD_SIZE * sizeof * newword);
    if(!newword)
        return FALSE;

    for (i =0 ; i < strlen(word); i++){
        c = word[i];
        if (c == 0xc3){
            i++;
            c = word[i]; 
            for (int j = 0; j < CONVERSION_TABLE_SIZE; j++){
                if (conversao[j].code == c)
                    c = conversao.sem_acento;
            }
        }

        newword[i] = c;
    }

    newword[i+1] = '\0';

    strcpy(word, newword);
    free(newword);

} 


BOOL normalizeWord(unsigned char* word){
    BOOL result = TRUE;

    for(int i = 0; i < strlen(word); i++){
        
        if(IsSpecialCaracter(word[i])){
            result = 0;
        }

        if (IsUpperCase(word[i]))
            word[i] = LowerCase(word[i]);

    }


    return result;
}

unsigned int GetLineCount(FILE* src){
    unsigned int LineCount = 0;
    char line[MAX_WORD_SIZE];

    while(fgets(line, MAX_WORD_SIZE, src)){
        LineCount++;
    }

    rewind(src);
    return LineCount;
}


char* GetWord(FILE** src){
    char* word = malloc(MAX_WORD_SIZE * sizeof * word);
    if (!word)
        return NULL;

    memset(word, 0, MAX_WORD_SIZE * sizeof * word);

    word = fgets(word, MAX_WORD_SIZE, *src);
    if (!word)
        return NULL;

    word[strlen(word) - 1] = '\0';


    return  word;
}

char* Normalized(char **word, char** copy){

    if(!*word)
        return NULL;

    strcpy(*copy, *word);

    if (!normalizeWord(*word)){
        free(*word);
        *word = NULL;
    }

    return *word;
}


char* GetNormalizedWord(FILE** src, char** copy){

    char* word = GetWord(src);
    if(!word)
        return NULL;

    strcpy(*copy, word);

    if (!normalizeWord(word)){
        free(word);
        word = NULL;
    }

    return word;
}
