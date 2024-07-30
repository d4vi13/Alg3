#include "dict.h"
#include <string.h>
#include "../utils.h"

static inline BOOL DictInit(FILE* src, PDICT dict){
    memset(dict, 0, sizeof * dict);
    
    dict->MaxSize = GetLineCount(src);
    dict->words = malloc(dict->MaxSize * sizeof *dict->words);
    if (!dict->words)
        return FALSE;


    return TRUE;
}

static inline void AddWord(FILE** src, PDICT dict){
    
    char* newEntry = GetNormalizedWord(src);        


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
    }
    free(dict->words);

} 

