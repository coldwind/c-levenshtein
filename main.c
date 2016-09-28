#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]) {

    if (argc != 3) {
        exit(1);
    }

    int res;
    res = compute(argv[1], argv[2]);
    printf("similarity:%d\n", res);

    return 0;
}
