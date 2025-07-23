#include <stdio.h>
#include <locale.h>
#include "contact.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    Person persons[MAX_PERSONS];
    int choice, index;
    Person temp;

    while (1)
    {
        printf("\n����:\n");
        printf("1. �������� �������\n");
        printf("2. ������������� �������\n");
        printf("3. ������� �������\n");
        printf("4. �������� ��� ��������\n");
        printf("0. �����\n");
        printf("�������� ��������: ");
        if (scanf("%d", &choice) != 1)
        {
            printf("������ �����!\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        switch (choice)
        {
        case 1:
            AddPersons(persons, &temp);
            break;
        case 2:
            if (personCount == 0)
            {
                printf("��� ���������!\n");
                break;
            }
            printf("������� ����� �������� ��� �������������� (�� 1 �� %d): ", personCount);
            if (scanf("%d", &index) != 1 || index < 1 || index > personCount)
            {
                printf("������������ �����!\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            while (getchar() != '\n')
                ;
            EditPersons(persons, index - 1);
            break;
        case 3:
            if (personCount == 0)
            {
                printf("��� ���������!\n");
                break;
            }
            printf("������� ����� �������� ��� �������� (�� 1 �� %d): ", personCount);
            if (scanf("%d", &index) != 1 || index < 1 || index > personCount)
            {
                printf("������������ �����!\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            while (getchar() != '\n')
                ;
            DeletePersons(persons, index - 1);
            break;
        case 4:
            if (personCount == 0)
            {
                printf("��� ���������!\n");
                break;
            }
            PrintAllPersons(persons);
            break;
        case 0:
            printf("����� �� ���������.\n");
            return 0;
        default:
            printf("������������ �����!\n");
        }
    }
}