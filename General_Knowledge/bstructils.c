# include <string.h>
# include <stdlib.h>

char* str_resever(char * str){
    
    int size = strlen(str);
    
    char * ret = (char*)malloc((size +1)*sizeof(char)) ;
    
    for(int i = 0; i < size; i++){
        ret[size-1-i] = str[i];
    }
    
    ret[size] = '\0';
    
    return ret;
}
 
char* str_trim(char* str){
    
    int size = strlen(str);
    
    int bPos = 0;
    int ePos = size -1;
    
    while (str[bPos] == ' ' && bPos != size){
        bPos++;
    }
    if(bPos == size){
        return "";
    }
    
    while (str[ePos] == ' ' && ePos != -1){
        ePos--;
    }
    
    int sizeOfRetStr = ePos - bPos + 1;
    char *ret = (char*)malloc((sizeOfRetStr + 1) * sizeof(char));
    
    for(int i = bPos; i <= ePos; i++){
        ret[i-bPos] = str[i];
    }
    ret[sizeOfRetStr] = '\0';
    
    return ret;
}