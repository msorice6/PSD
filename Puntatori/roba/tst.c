# include <stdio.h>
// # include "vettore.h"

int main()
{
    char s[] = "cazzo e culo" ;

    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' ')
            i++;
    }

    printf("stringa: %s\n",s);
    printf("dimensioni: %i\n",i);

    return 0;
}