#include <stdio.h>
#include <locale.h>
#include "contact.h"



int main() {
    setlocale(LC_ALL, "Russian");
    Person persons[MAX_PERSONS];
    int choice, index;
    Person temp;

    while (1) {
        printf("\nМеню:\n");
        printf("1. Добавить контакт\n");
        printf("2. Редактировать контакт\n");
        printf("3. Удалить контакт\n");
        printf("4. Показать все контакты\n");
        printf("0. Выход\n");
        printf("Выберите действие: ");
        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода!\n");
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                AddPersons(persons, &temp);
                break;
            case 2:
                if(personCount==0){
                    printf("Нет контактов!\n");
                    break;
                }
                printf("Введите номер контакта для редактирования (от 1 до %d): ", personCount);
                if (scanf("%d", &index) != 1 || index < 1 || index > personCount) {
                    printf("Некорректный номер!\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');
                EditPersons(persons, index - 1);
                break;
            case 3:
                if(personCount==0){
                    printf("Нет контактов!\n");
                    break;
                }
                printf("Введите номер контакта для удаления (от 1 до %d): ", personCount);
                if (scanf("%d", &index) != 1 || index < 1 || index > personCount) {
                    printf("Некорректный номер!\n");
                    while (getchar() != '\n');
                    break;
                }
                while (getchar() != '\n');
                DeletePersons(persons, index - 1);
                break;
            case 4:
                if(personCount==0){
                    printf("Нет контактов!\n");
                    break;
                }
                PrintAllPersons(persons);
                break;
            case 0:
                printf("Выход из программы.\n");
                return 0;
            default:
                printf("Некорректный выбор!\n");
        }
    }
}