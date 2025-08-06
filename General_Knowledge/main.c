# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "strutils.h"


int main()
{
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
 
    if (str[strlen(str)-1] == '\n') {
        str[strlen(str)-1] = '\0';
    }
    
    char *result = str_trim(str);
    
    printf("%s\n", result);
    
    free(result);
 
    return 0;
}