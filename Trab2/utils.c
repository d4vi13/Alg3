#include "utils.h"
#include <string.h>

BOOL normalizeWord(unsigned char* word){
    //    wchar_t wide_word
    BOOL result = TRUE;

    for(int i = 0; i < strlen(word); i++){

        if(IsSpecialCaracter(word[i])){
            result = FALSE;
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

char* GetNormalizedWord(FILE** src){
    
    char* word = GetWord(src);
    if(!word)
        return NULL;

    if (!normalizeWord(word)){
        free(word);
        word = NULL;
    }
    
    return word;
}

