#include<stdio.h>

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 256; i++) {
        printf("%d %c \n", i, i);
    }
    return 0;
}
