#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int key_generator() {
    srand(time(0));
    int key = rand() % 26;
    return key;
}

char* caesar_encoder(char* plaintext, int key) {
    int n = strlen(plaintext);
    for(int i = 0; i < n; i++) {
        char c = plaintext[i];
        if(c == ' ') {
            continue;
        }
        c += key;
        if(c > 'z' || (c > 'Z' && c < 'a')) {
            c -= 26;
        }
        plaintext[i] = c;
    }
    return plaintext;
}

char* caesar_decoder(char* plaintext, int key) {
    int n = strlen(plaintext);
    for(int i = 0; i < n; i++) {
        char c = plaintext[i];
        if(c == ' ') {
            continue;
        }
        c -= key;
        if(c < 'A' || (c > 'Z' && c < 'a')) {
            c += 26;
        }
        plaintext[i] = c;
    }
    return plaintext;
}

int main() {
    char str[] = "geeZ is coming";
    int k = key_generator();
    printf("%d\n", k);
    char* coded = caesar_encoder(str, k);
    printf("%s\n", coded);
    char* decoded = caesar_decoder(coded, k);
    printf("%s\n", decoded);
    return 0;
}