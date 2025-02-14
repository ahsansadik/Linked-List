#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *ptr = (int *)malloc(3*sizeof(int));

    if (ptr == NULL) {
        printf("Memory Allocation Failed\n");
        return 0;
    }
    else
    {
        printf("Memory Allocation Successful\n");
    }

    *ptr = 42;
    *(ptr + 1) = 32;
    *(ptr + 2) = 22;

    printf("Value: %d\n", *ptr);
    printf("Value: %d\n", *(ptr+1));
    printf("Value: %d\n", *(ptr+2));

    free(ptr);

    return 0;
}

// malloc(5) >> address
// calloc(5,5) >> address

