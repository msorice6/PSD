#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindroma(char *s){
    int i =0 ,j = strlen(s)-1;
    for(;i<j;i++,j--){
        if(s[i]==' ') i++;
        if(s[j]==' ')j--;
        if(s[i]!=s[j]) 
            return 0;
    }
    return 1;
}


int palindromaRecursive(char *s, int len){
    if(len<=1) 
        return 1;
    else if(s[0]!=s[len-1])
        return 0;
    else 
        return palindromaRecursive(s+1,len-2);
}

int palindromaRec(char *s){
    return palindromaRecursive(s,strlen(s));
}

int main(int argc, char *argv[]){
    if(argc!=2){
        fprintf(stderr, "Numero di parametri errato!\n");
        exit(EXIT_FAILURE);
    }
    
    if(palindromaRec(argv[1]))
        printf("palindroma\n");
    else    
        printf("non palindroma\n");
    return 0;
}