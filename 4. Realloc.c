#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(3 * sizeof(int));

    if (arr == NULL) {
        printf("Initial memory allocation failed\n");
        return 0;
    }

    for (int i = 0; i < 3; i++) {
        arr[i] = i + 1;
    }

    printf("Initial array:\n");
    for (int i = 0; i < 3; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    arr = (int *)realloc(arr, 5 * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed\n");
        return 0;
    }

    for (int i = 3; i < 5; i++) {
        arr[i] = i + 1;
    }

    printf("\nResized array:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}

