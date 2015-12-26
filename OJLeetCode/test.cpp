#include <iostream>
#include <cstdio>

int main()
{
    float a, b, c;
    char s1[100], s2[100];

    printf("to test scanf\n");

    FILE *pFile;
    pFile = fopen("test_in.txt", "w");
    fprintf(pFile, "yosen 06075008 10.51 200.39 181.32\n");
    fclose(pFile);

    pFile = fopen("test_in.txt", "r");
    fscanf(pFile, "%s %s", s1, s2);
    fscanf(pFile, "%f", &a);
    fscanf(pFile, "%f", &b);
    fscanf(pFile, "%f", &c);
    
    printf("s1(%s), s2(%s), a(%.2f), b(%.2f), c(%.2f)\n", s1, s2, a, b, c);

    return 0;
}
