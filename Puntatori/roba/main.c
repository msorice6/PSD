# include <stdio.h>
# include "vettore.h"
char* input_array_dyn();
int main()
{
    char number[] = "23 32";
    int num[1];
    sscanf(number, "%d%d", &num[0],&num[1]);
//    sscanf(number, "%d", &num[1]);

    printf("%d\n", num[0]);

    char *p = number;

    printf("%d\n", &p);
    printf("%d\n", &number);

    helloWorld();

    char *sazio;
    sazio = input_array_dyn();
    printf("%c\n", sazio[1]);


    return 0;
}