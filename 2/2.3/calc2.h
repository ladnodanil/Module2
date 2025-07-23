#define SIZE 4

typedef struct
{
    int id;
    char name[20];
} Operation;
extern Operation operations[SIZE];
float add(int a, int b);
float subtract(int a, int b);
float multiply(int a, int b);
float divide(int a, int b);
float (*select(int choice))(int, int);