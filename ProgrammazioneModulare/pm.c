
//Pointers introduction: https://scrappedscript.com/a-basic-guide-to-pointers-in-c-programming

#include <stdio.h>
void swap(int *a, int *b); // Function prototype
int main(){
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int b[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

    int i , j = 0;

    for(int i = 0; i < 10; i++){
        printf("a[%d] = %d\n",i, a[i]);
        printf("a[%d] = %d\n",j, a[j]);
   }

    swap(&a[0], &b[0]);
    return 0;
}


void swap(int *a, int *b) {
    int temp = *a; // Store the value at address a in a temporary variable
    *a = *b;       // Copy the value at address b into the address a
    *b = temp;     // Copy the temporary value into the address b
}