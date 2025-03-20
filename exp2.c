#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct college {
    int roll;
    char name[20];
    char department[30];

};
int main(){
 struct college* st= (struct college*)(malloc(3 * sizeof(struct college)));
    st[0].roll = 102;
    st[0].name= strcpy("Jane Smith");
    st[0].departments= strcpy("Electrical Engineering");
    st[1].roll = 102;
    st[1].name= strcpy("Jane Smith");
    st[1].department=strcpy("Electrical Engineering");
    st[2].roll = 102;
    st[2].name= strcpy("Jane Smith");
    st[2].department=strcpy("Electrical Engineering");
    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", st[i].roll);
        printf("Name: %s\n", st[i].name);
        printf("Department: %s\n", st[i].department);
        printf("\n");
    }
    // st=realloc(st, (4*sizeof(struct college)));
    // st[5].roll=590015171;
    // st[5].name="ironman";
    // st[5].department="Computer Science";
    return 0;
    }