#include<stdio.h>

struct college {
    int roll;
    char name[20];
    char department[30];

};
int main(){
 struct college students[3] = {
        {101, "superman", "Computer Science"},
        {102, "batman", "Electrical Engineering"},
        {103, "spiderman", "Mechanical Engineering"}
    };
    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Department: %s\n", students[i].department);
        printf("\n");
    }


    return 0;
}