#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ALPHA_SIZE 26

// Random Key Generator
int key_generator() {
    srand(time(0));
    int key = rand() % ALPHA_SIZE; // Random key generator within limits 0 to 26
    return key;
}

// Caesar Encoder
char* caesar_encoder(char* plaintext, int key) {
    int n = strlen(plaintext);
    for(int i = 0; i < n; i++) {
        char c = plaintext[i];
        // Check for spaces
        if(c == ' ') {
            continue;
        }
        // Encryption
        char temp = c + key;
        // Check for limits
        if((c >= 'A' && c <= 'Z' && temp > 'Z') || (c >= 'a' && c <= 'z' && temp > 'z')) {
            temp -= ALPHA_SIZE;
        }
        plaintext[i] = temp;
    }
    return plaintext;
}

// Caesar Decoder
char* caesar_decoder(char* text, int key) {
    int n = strlen(text);
    for(int i = 0; i < n; i++) {
        char c = text[i];
        // Check for spaces
        if(c == ' ') {
            continue;
        }
        // Decryption
        c -= key;
        // Check for limits
        if(c < 'A' || (c > 'Z' && c < 'a')) {
            c += ALPHA_SIZE;
        }
        text[i] = c;
    }
    return text;
}

// Testing
int main() {
    char str[] = "geez is loming";
    // int k = key_generator();
    int k = 20;
    printf("%d\n", k);
    char* coded = caesar_encoder(str, k);
    printf("%s\n", coded);
    char* decoded = caesar_decoder(coded, k);
    printf("%s\n", decoded);
    return 0;
}