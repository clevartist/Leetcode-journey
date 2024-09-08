#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenA > lenB ? lenA : lenB;
    char* result = (char*)malloc(maxLen + 2);
    result[maxLen+1] = '\0';
    int carry = 0;

    int i = lenA-1;
    int j = lenB-1;
    int k = maxLen;

    while(i>=0||j>=0||carry){
        if(i>=0){
            carry+=a[i]-'0';
            i--;
        }
        if(j>=0){
            carry+=b[j]-'0';
            j--;
        }
        result[k]=(carry%2)+'0';
        carry/=2;
        k--;
    }

    if(k==0){
        memmove(result,result+1,maxLen+1);
    }
    return result;
}
