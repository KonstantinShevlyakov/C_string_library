#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h>

// main видит функции объявленные над ним
void get_word(char* str);
char* str_strip(const char* string);


int main(void){
    char text[100];

    get_word(text);
    str_strip(text);

    printf("Result: '%s'\n", text);

    return 0;
}


char* str_strip(const char* string) { //Указатель на строку -- для индексации. Если не ставить будет ошибка
    if (string == NULL) {
        return NULL; // Если пустая -- NULL
    }

    size_t len = strlen(string); // Длина строки (strlen до \0)
    size_t start = 0; // Начало строки после пробела
    while (start < len && string[start] == ' ') {
        start++; 
    } // Увеличиваю старт пока не пройду пробелы
    size_t end = len; // Конец строки вместе со всеми символами
    while (end > start && (string[end - 1] == ' ')) {
        end--; // Ищем конец строки уже без пробелов
    }
    size_t new_len = end - start; // Полученная строка на выход

    char* stripped = (char*) malloc(new_len + 1); //для нуля-терминатора +1

    strncpy(stripped, string + start, new_len); // strncopy(destination, frist symbol, last symbol)
    stripped[new_len] = '\0'; // закрыл строку

    return stripped;
}

void get_word(char* str) {
    printf("Enter word: ");
    scanf("%s", str);
}