#include "levenshtein.h"
#include <stdio.h>

int compute(char *fstStr, char *secStr) {

    // 获取字符长度
    size_t fstLen = strlen(fstStr);
    size_t secLen = strlen(secStr);
    char fstChar, secChar;
    char *secBegin;
    int i, j, x, y, left, top, leftTop, maxLen;

    // 初始化二维表
    fstLen++;
    secLen++;
    unsigned int charTable[fstLen][secLen];

    charTable[0][0] = 0;

    for (i = 0; i < fstLen; i++) {
        charTable[i][0] = i;
    }

    for (i = 0; i < secLen; i++) {
        charTable[0][i] = i;
    }

    fstLen--;
    secLen--;

    secBegin = secStr;
    for (i = 1; i <= fstLen; i++) {

        x = i - 1;
        fstChar = *fstStr;
        fstStr++;

        secStr = secBegin;
        for (j = 1; j <= secLen; j++) {
            y = j - 1;
            secChar = *secStr;
            secStr++;

            left = charTable[x][j] + 1;
            top = charTable[i][y] + 1;
            leftTop = fstChar == secChar ? charTable[x][y] : charTable[x][y] + 1;

            charTable[i][j] = left < top ? (left < leftTop ? left : leftTop) : (top < leftTop ? top : leftTop);
        }
    }

    maxLen = fstLen > secLen ? fstLen : secLen;

    maxLen = (int)((1 - ((float)charTable[fstLen][secLen] / (float)maxLen)) * 100);

    return maxLen;
}
