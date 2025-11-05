# Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

#include <stdio.h>
#include <string.h>

int isUnique(char *str, int start, int end) {
    int freq[256] = {0}; 

    for(int i = start; i <= end; i++) {
        if(freq[(unsigned char)str[i]] == 1)
            return 0;
        freq[(unsigned char)str[i]] = 1;
    }
    return 1;
}

int main() {
    char s[100];
    int maxLen = 0;

    printf("Enter a string: ");
    scanf("%s", s);

    int n = strlen(s);

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(isUnique(s, i, j)) {
                int len = j - i + 1;
                if(len > maxLen)
                    maxLen = len;
            }
        }
    }

    printf("Length of longest substring without repeating characters: %d\n", maxLen);
    return 0;
}
