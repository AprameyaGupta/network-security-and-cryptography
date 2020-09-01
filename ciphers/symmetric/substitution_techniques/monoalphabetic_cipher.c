#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define ALPHA_SIZE 26

// Key generator inspired by fisher yates shuffle algorithm
int* key_generator() {
    static int cipher_text[ALPHA_SIZE];
    for(int i = 0; i < ALPHA_SIZE; i++) {
        cipher_text[i] = i+1;
    }
    // seed
    srand(time(0));
    int j = ALPHA_SIZE - 1;
    do {
        int r = rand() % j;
        int temp = cipher_text[j];
        cipher_text[j] = cipher_text[r];
        cipher_text[r] = temp;
        j--;
    } while(j > 0);
    return cipher_text;
}

// Monoalphabetic Encoder
char* monoalphabetic_encoder(char* plaintext, int* key) {
    int n = strlen(plaintext);
    for(int i = 0; i < n; i++) {
        char c = plaintext[i];
        if(c >= 'A' && c<='Z') {
            c = key[(int)c-'A'] + 'A' - 1;
        }
        else if (c >= 'a' && c <= 'z') {
            c = key[(int)c-'a'] + 'a' - 1;
        } else {
            continue;
        }
        plaintext[i] = c;
    }
    return plaintext;
}

// Monoalphabetic Decoder
char* monoalphabetic_decoder(char* text, int* key) {
    int n = strlen(text);
    for(int i = 0; i < n; i++) {
        char c = text[i];
        if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            for(int j = 0; j < ALPHA_SIZE; j++) {
                if(c >= 'A' && c<='Z' && (key[j] == (int)(c-'A'+1))) {
                    c = j + 'A';
                    break;
                }
                else if (c >= 'a' && c <= 'z' && (key[j] == ((int)c-96))) {
                    c = j + 'a';
                    break;
                }
            }
        } else {
            continue;
        }
        text[i] = c;
    }
    return text;
}

// Testing
int main(int argc, char const *argv[])
{
    char s[] = "Winter is coming";
    printf("Plain Text: %s \n", s);
    int* k =  key_generator();
    printf("Cipher Literals: \n");
    for(int i = 0; i < ALPHA_SIZE; i++) {
        printf("%c\t%c\t%c\n", i + 65, k[i] + 64, k[i] + 96);
    }
    printf("\n");
    for(int i = 0; i < ALPHA_SIZE; i++) {
        printf("%c ", k[i] + 96);
    }
    printf("\n");
    char* coded = monoalphabetic_encoder(s, k);
    printf("Coded Text: %s\n", coded);
    char* decoded = monoalphabetic_decoder(coded, k);
    printf("Decoded Text: %s\n", decoded);
    return 0;
}
