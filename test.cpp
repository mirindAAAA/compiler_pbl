#include <stdio.h>

int main()
{
    char buf[5];

    gets(buf);

    printf("%s", buf);

    return 0;
}
