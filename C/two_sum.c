#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    int *indexes = (int *)malloc(2 * sizeof(int));
    if(indexes == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                indexes[0] = i;
                indexes[1] = j;
                *returnSize = 2;
                return indexes;
            }
        }
    }

    free(indexes);
    *returnSize = 0;
    return NULL;
}
