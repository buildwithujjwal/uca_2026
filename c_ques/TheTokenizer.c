#include <stdio.h>
#include <string.h>

int main() {
    char languages[] = "C,C++,Java,Python,Rust";
    char *ptr;

    ptr = strtok(languages, ",");

    while (ptr != NULL) {
        printf("%s\n", ptr);
	ptr = strtok(NULL, ",");
    }

    return 0;
}
