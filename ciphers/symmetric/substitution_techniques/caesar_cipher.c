#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// Random Key Generator
int key_generator() {
    srand(time(0));
    int key = rand() % 26; // Random key generator within limits 0 to 26
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
        c += key;
        // Check for limits
        if(c > 'z' || (c > 'Z' && c < 'a')) {
            c -= 26;
        }
        plaintext[i] = c;
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
            c += 26;
        }
        text[i] = c;
    }
    return text;
}

// Testing
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