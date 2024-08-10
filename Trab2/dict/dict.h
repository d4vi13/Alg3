#ifndef DICT_H
#define DICT_H

#include "../common.h"

#define CommitEntry(dict, word) dict->words[dict->entryCount] = word
#define RaiseEntryCount(dict) dict->entryCount += 1
#define PushEntry(dict, word){\
    CommitEntry(dict,word);\
    RaiseEntryCount(dict);\
}
#define FetchWord(dict, key) (key < (dict)->MaxSize) ? ((dict)->words[key]) : (NULL)
#define FetchUnWord(dict, key) (key < (dict)->MaxSize) ? ((dict)->unnormalized_words[key]) : (NULL)

struct dict{
    char** words;
    char** unnormalized_words;


    char nullword[10];

    unsigned int entryCount;
    unsigned int MaxSize;
};

typedef struct dict DICT, *PDICT;

typedef unsigned int KEY, *PKEY;

extern BOOL MountDict(FILE* src, PDICT dict);

extern void DismountDict(PDICT dict);

#endif
