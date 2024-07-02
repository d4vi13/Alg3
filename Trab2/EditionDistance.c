#include "EditionDistance.h"

int min (int x, int y) {
    return (x < y ? x : y);
}

int EditionDistance (char *string1, char *string2) {
    int col, lin, i, j;
    col = strlen(string1);
    lin = strlen(string2);
    int check[col][lin];

    for (i = 0; i <= col; i++) check[0][i] = i;
    for (j = 0; j <= lin; j++) check[j][0] = j;

    for (i = 1; i <= col; i++) {
        for (j = 1; j <= lin; j++) {
            if (string1[i - 1] == string2[j - 1]) check[i][j] = check[i - 1][j - 1];
            else check[i][j] = (min(check[i - 1][j - 1], min(check[i - 1][j], check[i][j - 1]))) + 1;
        }
    }
    return check[col][lin];
}