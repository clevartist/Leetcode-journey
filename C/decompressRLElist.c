#include <stdio.h>
#include <stdlib.h>

// Final code
int* decompressRLElist(int* nums, int numsSize, int* returnSize) {
    
    int total_size = 0;
    for(int i = 0; i < numsSize; i += 2) {
        total_size += nums[i];
    }

    // allocate memory
    int *alloc = (int *)malloc(total_size * sizeof(int));
    if(alloc == NULL){
        *returnSize = 0;
        return NULL;
    }

    // apply values to the allocated memory
    int current = 0;
    for(int k = 0; k < numsSize; k+=2) {
        int freq = nums[k];
        int val = nums[k + 1];

        for(int p = 0; p < freq; p++) {
            alloc[current++] = val;
        }
    }

    *returnSize = total_size;
    return alloc;
}



// Below is the "sketch"
// so never mind
int main() {
    int nums[] = {1,2,3,4,5,6,7,8,9,10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    
    for (int i = 0; i < numsSize; i += 2) {
        int j = i + 1;
        
        // allocate memory for each pair
        size_t isize = nums[i] * sizeof(int);
        int *freqAlloc = (int *)malloc(isize);
        
        // apply values to the allocated memory blocks
        for(int k = 0; k < nums[i]; k++) {
            freqAlloc[k] = nums[j];
        }
        
        free(freqAlloc);
    }
}
