#include <stdio.h>

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int total = 0;
    int i;
    int max = 0;
    int curr = 0;

    for(i = 0; i < customersSize; i++) {
        if(grumpy[i] == 0) {
            total += customers[i];
        }
    }

    for(i = 0; i < customersSize; i++){
        
        if(grumpy[i] == 1) {
            curr += customers[i];
        }
        
        if(i >= minutes && grumpy[i - minutes] == 1) {
            curr -= customers[i - minutes];
        }

        if(curr > max) {
            max = curr;
        }
    }

    return total + max;
}
