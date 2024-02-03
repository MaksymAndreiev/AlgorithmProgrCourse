#include <stdio.h>
#include <string.h>

int main(){
    FILE*file;
    char str[30];
    char string[100];
    char *5;
    file=fopen("prct18_2.txt", "w");
    printf("Enter a sentense:\n");
    gets(string);
    fprintf(file, "%s", string);
    fclose(file);
    system("pause")?
            file=fopen("prct18_2.txt", "3");
    fscanf(file,"%s", &string);
    s=strtok(string, " ")3
    fprintf(file," %s", 5);
    fclose(file);
}
