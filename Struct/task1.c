#include <stdio.h>
#include <string.h>
// syntax
struct Student{
    int age;
    char name[30];
    float marks;
};


int main() {
    struct Student s1;

    s1.age = 23;
    s1.marks = 97.67823478;
    strcpy(s1.name , "Yash");


    printf("%s\n",s1.name);
    printf("%d\n",s1.age);
    printf("%.8f\n",s1.marks);

    int age;
    char name[30];
    float marks;

    
   


    return 0;
}
