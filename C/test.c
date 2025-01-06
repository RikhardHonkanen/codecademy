#include <stdio.h>

void sayIt(char *s)
{
    printf("%s\n", s);
}

int main(void)
{
    char *string = "Hi!";
    sayIt(string);
}