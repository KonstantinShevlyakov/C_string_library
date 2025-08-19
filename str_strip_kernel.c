#include <stdio.h>
#include <string.h> //тут походу ваще не нужен
char *strstrip(char *s);

int main() {
    char s[] = "   test ";
    printf
}
char *strstrip(char *s)
{
        size_t size; //ок, определяем размер
        char *end; // устанавливаем указатель на end 

        size = strlen(s);

        if (!size)
                return s;

        end = s + size - 1;
        while (end >= s && isspace(*end)) //isspace это что?
                end--;
        *(end + 1) = '\0';

        while (*s && isspace(*s))
                s++;

        return s;
}