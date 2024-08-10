#include "dict.h"
#include <string.h>
#include "utils.h"

static inline BOOL DictInit(FILE* src, PDICT dict){
    memset(dict, 0, sizeof * dict);

    dict->MaxSize = GetLineCount(src);
    dict->words = malloc(dict->MaxSize * sizeof *dict->words);
    if (!dict->words)
        return FALSE;

    dict->unnormalized_words = malloc(dict->MaxSize * sizeof *dict->words);
    if (!dict->unnormalized_words)
        return FALSE;

    return TRUE;
}

static inline void AddWord(FILE** src, PDICT dict){ 

    dict->unnormalized_words[dict->entryCount] = malloc(MAX_WORD_SIZE * sizeof(char));
    memset( dict->unnormalized_words[dict->entryCount] ,0, MAX_WORD_SIZE * sizeof(char));


    char* newEntry = GetNormalizedWord(src,&dict->unnormalized_words[dict->entryCount]);

    // will push word even its null
    PushEntry(dict, newEntry);

    return ;
}

BOOL MountDict(FILE* src, PDICT dict){

    if (!DictInit(src, dict))
        return FALSE;

    for (int i = 0; i < dict->MaxSize; i++)
       AddWord(&src, dict);

    return TRUE;
}

void DismountDict(PDICT dict){
    for (int i = 0; i < dict->MaxSize; i++){
        free(dict->words[i]);
        free(dict->unnormalized_words[i]);
    }
    free(dict->words);
    free(dict->unnormalized_words);
}
