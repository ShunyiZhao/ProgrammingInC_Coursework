#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>

int pwdok(char *s);

void test();

int main(void)
{
    assert(pwdok("Ab1") == 1);
    assert(pwdok("Ab#") == 1);
    assert(pwdok("Ab") == 0);
    assert(pwdok("#abndsjksd2434") == 0);

    return 0;
}

int pwdok(char *s)
{
    int nLength, nMark_NonAlpha = 0, nMark_Upper = 0, nMark_Lower = 0, i;

    nLength = strlen(s);
    for(i = 0; i < nLength; i++){
        if( !isalpha(s[i]) ){
            nMark_NonAlpha = 1;
        }
        if( islower(s[i]) ){
            nMark_Lower = 1;
        }
        if( isupper(s[i]) ){
            nMark_Upper = 1;
        }
    }
    if( nMark_NonAlpha == 0 || nMark_Upper == 0 || nMark_Lower == 0){
        return 0;
    }

    return 1;
}

void test()
{
    assert(pwdok("xya123#abc") == 0);
    assert(pwdok("Xya#") == 1);
    assert(pwdok("xya1abc") == 0);
    assert(pwdok("xya1AbcM") == 1);
    assert(pwdok("XY123#") == 0);
    assert(pwdok("abcdf") == 0);
}