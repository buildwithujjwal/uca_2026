#include<stdio.h>
#include<stdlib.h>

#define MAX 1000000

int main() {

    char *code = (char*) malloc(MAX * sizeof(char));
    int n = 0;
    int ch;

    while ((ch = getchar()) != EOF && n < MAX - 1) {
        code[n++] = (char) ch;
    }
    code[n] = '\0';

    char *result = (char*) malloc(MAX * sizeof(char));
    int r = 0;

    int i = 0;
    int inString = 0;
    int inChar = 0;
    int inLineComment = 0;
    int inBlockComment = 0;

    while (i < n) {

        if (inLineComment) {
            if (code[i] == '\n') {
                inLineComment = 0;
                result[r++] = code[i];
            }
            i++;
            continue;
        }

        if (inBlockComment) {
            if (code[i] == '*' && i + 1 < n && code[i+1] == '/') {
                inBlockComment = 0;
                i += 2;
            } else {
                if (code[i] == '\n') result[r++] = code[i];
                i++;
            }
            continue;
        }

        if (inString) {
            result[r++] = code[i];
            if (code[i] == '\\' && i + 1 < n) {
                result[r++] = code[i+1];
                i += 2;
                continue;
            }
            if (code[i] == '"') inString = 0;
            i++;
            continue;
        }

        if (inChar) {
            result[r++] = code[i];
            if (code[i] == '\\' && i + 1 < n) {
                result[r++] = code[i+1];
                i += 2;
                continue;
            }
            if (code[i] == '\'') inChar = 0;
            i++;
            continue;
        }

        if (code[i] == '"') {
            inString = 1;
            result[r++] = code[i];
            i++;
            continue;
        }

        if (code[i] == '\'') {
            inChar = 1;
            result[r++] = code[i];
            i++;
            continue;
        }

        if (code[i] == '/' && i + 1 < n && code[i+1] == '/') {
            inLineComment = 1;
            i += 2;
            continue;
        }

        if (code[i] == '/' && i + 1 < n && code[i+1] == '*') {
            inBlockComment = 1;
            i += 2;
            continue;
        }

        result[r++] = code[i];
        i++;
    }

    result[r] = '\0';

    printf("%s", result);

    free(code);
    free(result);

    return 0;
}