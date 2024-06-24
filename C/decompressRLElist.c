// Below is the "sketch"
// so never mind

#include <stdio.h>
#include <stdlib.h>

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
