#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char str[1024];

    file = fopen("prct18_1.txt", "r+");
    fscanf(file, "%s", &str);
    fprintf(file, "%s", str);
    fclose(file);

    return 0;
}
