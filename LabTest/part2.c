#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>

void passswp(char *a, char *b);

char SingleSwap(char cInput);

void test();

int main(void )
{
    char b[100];

    test();

    passswp("ABCdefghijklmnopqrstuvwxyz", b);
    printf("B: %s\n", b);
    /*printf("B length: %d\n", strlen(b));*/
    assert(strcmp(b, "@BCdefghijklmn0pqr5tuvwxyz") == 0);
    passswp("aBCdefghijklmnOpqrstuvwxyz", b);
    assert(strcmp(b, "@BCdefghijklmn0pqr5tuvwxyz") == 0);

    
    
    
    return 0;
}

void passswp(char *a, char *b)
{
    int nLength, i;

    strcpy(b, a);
    nLength = strlen(b);
    for(i = 0; i < nLength; i++){
        b[i] = SingleSwap(b[i]);
    }
}

char SingleSwap(char cInput)
{
    char cTem;
    cTem = toupper(cInput);
    switch(cTem){
        case 'A':
            return '@';
        case 'O':
            return '0';
        case 'S':
            return '5';
    }
    
    return cInput;
}

void test()
{
    char b[100];
    passswp("aAoOsS", b);
    printf("%s\n", b);
    assert(strcmp(b, "@@0055") == 0);
    assert(strcmp(b, "@@0O55") != 0);

    passswp("abcdefghijklmnopqrstuvwxyz", b);
    assert(strcmp(b, "@bcdefghijklmn0pqr5tuvwxyz") == 0);
    passswp("Abc",b);
    assert(strcmp(b, "@bc") == 0);

    passswp("abcdefghijklmnOpqrstuvwxys", b);
    assert(strcmp(b, "@bcdefghijklmn0pqr5tuvwxy5") == 0);

}