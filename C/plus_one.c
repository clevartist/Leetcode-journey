#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    // converting digits to integer
    int w = 0;
    for(int i = 0; i < digitsSize; i++) {
        w = 10 * w + digits[i];
    }

    w += 1;

    // find out the new length of w
    int c = 0;
    int temp = w;

    while(temp != 0) {
        temp /= 10;
        c++;
    }

    // allocate memory for the result array
    int* arr = (int*)malloc(c * sizeof(int));
    if (arr == NULL) {
        // Handle malloc failure
        *returnSize = 0;
        return NULL;
    }

    // store each of w's digit into the new array 'arr'
    for(int i = c - 1; i >= 0; i--) {
        arr[i] = w % 10;
        w /= 10;
    }

    
    *returnSize = c;
    return arr;
}
