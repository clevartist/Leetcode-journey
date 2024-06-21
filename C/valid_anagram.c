#include <stdio.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) {
        return false;
    }

    int letterCount[26] = {0}; // 26 letters in alphabet
    int i;

    // count for s
    for(i = 0; s[i] != '\0'; i++) {

        //increment current position
        letterCount[s[i] - 'a']++;
        /*
        -EXPLANATION-
        'a' has ASCII value 97 
        
        1. let's say i is at 'a'. s[i]-'a' in our case means 97 - 97 = index 0
        2. if i is at 'b' then 98 - 97 = index 1
        and so on.

        This way we found the index of the letters in `letterCount` array :)
        */
    }

    // opposite for t to return back to 0 if it's an anagram
    for(i = 0; t[i] != '\0'; i++) {
        letterCount[t[i] - 'a']--;
    }

    for(i = 0; i < 26; i++) {
        if(letterCount[i] != 0) {
            return false;
        }
    }

    return true;
}
