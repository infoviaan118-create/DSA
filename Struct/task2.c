#include <stdio.h>
#include <string.h>

typedef struct Student
{
    int age;
    char name[20];
} Student;

void show(Student *ptr){
    printf("Name is %s & age is %d\n",ptr->name , ptr->age);
}

int main()
{   

    int a = 10;

    Student s1;
    Student *ptr = &s1;

    ptr->age = 23;
    strcpy(ptr->name , "Yash");

    show(&s1);
    // show(ptr);


    return 0;
}