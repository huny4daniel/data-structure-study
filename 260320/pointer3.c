#include <stdio.h>
#include <string.h>

int my_strlen(const char *s) {
    int len = 0;

    while (*s != '\0') {
        len++;
        s++;
    }
    
    return len;
}

void my_strcpy(char *dst, const char *src) {
    while (*src != '\0') {
        *dst = *src;

        dst++;
        src++;
    }
    *dst = '\0';
}

int main() {
    char str[] = "Hello World!";
    char str2[2000000];
    char str3[20];

    printf("%s\n", str);
    printf("len %d\n", strlen(str));
    printf("len %d\n", my_strlen(str));

    strcpy(str2, str);
    printf("%s\n", str2);

    my_strcpy(str3, str);
    printf("%s\n", str3);

    return 0;
}