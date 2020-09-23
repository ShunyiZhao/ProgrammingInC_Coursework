#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<ctype.h>

char *pwdextend(char *a);

void test();

int main(void)
{
    char *p2, *p1;

    test();
    p1 = pwdextend("password");
    p2 = pwdextend("hackable");

    assert(strcmp(p1, "password808") == 0);
    assert(strcmp(p2, "hackable808") == 0);
    free(p1);
    free(p2);
    return 0;
}

char *pwdextend(char *a)
{
    char *c;
    int nLength, i;

    nLength = strlen(a);
    c = (char *)malloc(sizeof(char) * (nLength + 4));
    strcpy(c, a);
    i = nLength;
    c[i++] = '8';
    c[i++] = '0';
    c[i++] = '8';
    c[i] = '\0';

    return c;
}

void test()
{
    char *p1;
    p1 = pwdextend("abc");
    assert(strcmp(p1, "abc808") == 0);
    free(p1);
    p1 = pwdextend("AkkK252:::");
    assert(strcmp(p1, "AkkK252:::808") == 0);
    free(p1);
    p1 = pwdextend("abcdEFGhi#jkl");
    assert(strcmp(p1, "abcdEFGhi#jkl808") == 0);
    free(p1);
    p1 = pwdextend("oui");
    assert(strcmp(p1, "oui808") == 0);
    free(p1);

}