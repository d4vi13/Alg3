#include "utils.h"
#include <string.h>

struct dupla_char{
    char code;
    char sem_acento;
};

typedef struct dupla_char dupla_char;

dupla_char conversao[] = {
    {0x80, 'a'},
    {0x81, 'a'},
    {0x82, 'a'},
    {0x83, 'a'},
    {0x84, 'a'},
    {0x85, 'a'},
    {0x86, 'a'},
    {0x87, 'c'},
    {0x88, 'e'},
    {0x89, 'e'},
    {0x8a, 'e'},
    {0x8b, 'e'},
    {0x8c, 'i'},
    {0x8d, 'i'},
    {0x8e, 'i'},
    {0x8f, 'i'},
    {0x92, 'o'},
    {0x93, 'o'},
    {0x94, 'o'},
    {0x95, 'o'},
    {0x96, 'o'},
    {0x99, 'u'},
    {0x9a, 'u'},
    {0x9b, 'u'},
    {0x9c, 'u'},
    {0xa0, 'a'},
    {0xa1, 'a'},
    {0xa2, 'a'},
    {0xa3, 'a'},
    {0xa4, 'a'},
    {0xa5, 'a'},
    {0xa6, 'a'},
    {0xa7, 'c'},
    {0xa8, 'e'},
    {0xa9, 'e'},
    {0xaa, 'e'},
    {0xab, 'e'},
    {0xac, 'i'},
    {0xad, 'i'},
    {0xae, 'i'},
    {0xaf, 'i'},
    {0xb2, 'o'},
    {0xb3, 'o'},
    {0xb4, 'o'},
    {0xb5, 'o'},
    {0xb6, 'o'},
    {0xb9, 'o'},
    {0xba, 'u'},
    {0xbb, 'u'},
    {0xbc, 'u'}
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
                    c = conversao[j].sem_acento;
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
