#include <stdio.h> // Инпут-аутпут (нужен? -- нужен для принтф)
#include <string.h> // Для строчных функций
char* str_strip(char*);

int main(void) {
    char text[] = "  KOMTYA  "; // хранится в стеке, изначально писалось в read-only память (почитать)
    printf("%s", str_strip(text)); //не компилировалось когда сюда писал текст вместо переменной
    return 0;
}

char* str_strip(char* string) {
    if (string == NULL) {
        return NULL; // Если пустая
    }

    size_t len = strlen(string); //Длина строки
    size_t start = 0; //Начало строки, size_t == unsigned long (ну в ошибках так)
    while (start < len && string[start] == ' ') {
        start++; //Ищем начало строки уже без пробелов, повышая каунтер
    }
    size_t end = len; // Конец строки == длина всей строки со всеми символами, надо убрать пробелы
    while (end > start && string[end - 1] == ' ') { // -1 потому что нуль-терминатор
        end--; // Снижаем каунтер, получаем строку без пробелов
    }

    if (start > 0) { //Если в начале пробелы были, то надо сдвигать строку
        size_t counter = 0; //Ставлю каунтер для движения влево
        while (start + counter < end) { // Двигаем всю строку посимвольно, пока не дойдем до end
            string[counter] = string[start + counter];
            counter++;
        }
    }

    string[end - start] = '\0'; // обрезаем нулем-терминатором нашу строку (иначе получается "KOMTYAYA  ")


    return string;
}