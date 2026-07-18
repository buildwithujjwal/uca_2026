#include <stdio.h>

int find_substring(const char *h, const char *n) {
    if (!n[0]) return 0;
    for (int i = 0; h[i]; i++) {
        int j = 0;
        while (h[i+j] && n[j] && h[i+j] == n[j]) j++;
        if (!n[j]) return i;
    }
    return -1;
}

int main() {
    char h[100], n[100];

    printf("Haystack: "); fgets(h, 100, stdin);
    printf("Needle: ");   fgets(n, 100, stdin);

    // strip newline from both
    for (int i = 0; h[i]; i++) if (h[i] == '\n') { h[i] = '\0'; break; }
    for (int i = 0; n[i]; i++) if (n[i] == '\n') { n[i] = '\0'; break; }

    printf("Index: %d\n", find_substring(h, n));
}
