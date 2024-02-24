#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fileA;
    FILE *fileB;

    fileA = fopen("fileA.dat", "rw");
    fileB = fopen("fileB.dat", "w");

    return 0;
}