#include <stdio.h>
#include "random.h"

int main()
{
    std::random_device rd;
    pcg rand(rd);
    std::uniform_int_distribution<> u(1, 6);

    for (int i = 0; i < 10; ++i)
        printf("%d\n", u(rand));
}
