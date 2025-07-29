#include "person.h"

int personCount = 0;

void PrintContactInfo(const ContactInfo *const info)
{
    if (info->PhoneNumber[0] != '\0')
        printf("Phone number: %s\n", info->PhoneNumber);
    if (info->Email[0] != '\0')
        printf("Email: %s\n", info->Email);
    if (info->Link[0] != '\0')
        printf("Link: %s\n", info->Link);
}

void PrintPerson(const Person *const person)
{
    printf("\n");
    if (person->LastName[0] != '\0')
        printf("Last name: %s\n", person->LastName);
    if (person->FirstName[0] != '\0')
        printf("First name: %s\n", person->FirstName);
    if (person->Patronymic[0] != '\0')
        printf("Patronymic: %s\n", person->Patronymic);
    if (person->WorkPlace[0] != '\0')
        printf("Work place: %s\n", person->WorkPlace);
    if (person->Post[0] != '\0')
        printf("Position: %s\n", person->Post);

    PrintContactInfo(&person->contactInfo);
    printf("\n");
}

void PersonInit(Person *person, const char *LastName, const char *FirstName, const char *Patronymic, const char *WorkPlace, const char *Post)
{
    if (LastName != NULL && LastName[0] != '\0')
        strncpy(person->LastName, LastName, MAX_LEN);
    else
        person->LastName[0] = '\0';

    if (FirstName != NULL && FirstName[0] != '\0')
        strncpy(person->FirstName, FirstName, MAX_LEN);
    else
        person->FirstName[0] = '\0';

    if (Patronymic != NULL && Patronymic[0] != '\0')
        strncpy(person->Patronymic, Patronymic, MAX_LEN);
    else
        person->Patronymic[0] = '\0';

    if (WorkPlace != NULL && WorkPlace[0] != '\0')
        strncpy(person->WorkPlace, WorkPlace, MAX_LEN);
    else
        person->WorkPlace[0] = '\0';

    if (Post != NULL && Post[0] != '\0')
        strncpy(person->Post, Post, MAX_LEN);
    else
        person->Post[0] = '\0';

    person->contactInfo.PhoneNumber[0] = '\0';
    person->contactInfo.Email[0] = '\0';
    person->contactInfo.Link[0] = '\0';
}

void remove_newline(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
}

void Input(Person *person)
{
    char lastName[MAX_LEN];
    char firstName[MAX_LEN];
    char patronymic[MAX_LEN];
    char workPlace[MAX_LEN];
    char post[MAX_LEN];

    do
    {
        printf("Enter last name: ");
        fgets(lastName, MAX_LEN, stdin);
        remove_newline(lastName);
        if (lastName[0] == '\0')
        {
            printf("Last name cannot be empty! Please try again.\n");
        }
    } while (lastName[0] == '\0');

    do
    {
        printf("Enter first name: ");
        fgets(firstName, MAX_LEN, stdin);
        remove_newline(firstName);
        if (firstName[0] == '\0')
        {
            printf("First name cannot be empty! Please try again.\n");
        }
    } while (firstName[0] == '\0');

    printf("Enter patronymic: ");
    fgets(patronymic, MAX_LEN, stdin);
    remove_newline(patronymic);

    printf("Enter work place: ");
    fgets(workPlace, MAX_LEN, stdin);
    remove_newline(workPlace);

    printf("Enter position: ");
    fgets(post, MAX_LEN, stdin);
    remove_newline(post);

    PersonInit(person, lastName, firstName, patronymic, workPlace, post);

    printf("Enter phone number: ");
    fgets(person->contactInfo.PhoneNumber, MAX_LEN, stdin);
    remove_newline(person->contactInfo.PhoneNumber);

    printf("Enter email: ");
    fgets(person->contactInfo.Email, MAX_LEN, stdin);
    remove_newline(person->contactInfo.Email);

    printf("Enter link: ");
    fgets(person->contactInfo.Link, MAX_LEN, stdin);
    remove_newline(person->contactInfo.Link);
}
