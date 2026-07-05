#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
int a[6] = {2, 8, 5, 3, 9, 4};
int j;


    // Calculate the number of elements in the array
    int size = sizeof(a) / sizeof(a[0]);
    int key;

    for (int i = 1; i < size; i++) {
        key = a[i];
        j = i - 1;
        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;


    }


    for (int i = 0; i < size; i++)
        printf("a[%d]: %d\n", i, a[i]);


    return 0;
}