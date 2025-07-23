#define MAX_LEN 20
#define MAX_PERSONS 20
typedef struct {
    char PhoneNumber[MAX_LEN];
    char Email[MAX_LEN];
    char Link[MAX_LEN];
} ContactInfo;


typedef struct {
    char LastName[MAX_LEN];
    char FirstName[MAX_LEN];
    char Patronymic[MAX_LEN];
    char WorkPlace[MAX_LEN];
    char Post[MAX_LEN];
    ContactInfo contactInfo;
} Person;

extern int personCount;


void PrintPerson(const Person* const person);
void PrintContactInfo(const ContactInfo* const info);
void PersonInit(Person* person,const char *LastName, const char *FirstName, const char *Patronymic, const char *WorkPlace, const char *Post);
void Input(Person* person);
void AddPersons(Person* persons, Person *newPerson); //
void EditPersons(Person* persons, const int index); // 
void DeletePersons(Person* persons, const int index); // 
void PrintAllPersons(const Person* persons);


