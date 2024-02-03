#include <stdio.h>

int len(char *a){
    int i;
    for (i = 0; a[i] != '\0'; i++);
    return i;
}

int main(){
    char a[100];
    printf("Enter a string:\n");
    gets(a);
    printf("Length = %d\n", len(a));
    return 0;
}
