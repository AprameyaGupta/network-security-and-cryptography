#include<stdio.h>
#include <string.h>

char* hill_encoder(char plaintext[], int** key) {
    int n = strlen(plaintext);
    int key_size = sizeof(key[0])/sizeof(key[0][0]);
    char encodedtext[n];
    for(int i = 0, j = 0; i < n; i++) {
        
    }
    return encodedtext;
}

int main() {
    char str[] = "hi";
    int k = 1;
    char* ans = caesar_encoder(str, k);
    printf("%s\n", ans);
    return 0;
}