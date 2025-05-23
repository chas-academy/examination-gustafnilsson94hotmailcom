//Write your code in this file
#include <stdio.h>
#include <ctype.h>

struct student 
{
    char name[11];
    int score[13];
    float average;
};

void capitalize(char *name) // Function that makes first letter uppercase
{
    name[0] = toupper(name[0]);
}



int main(){

    struct student students[5]; // Here i create an array with 5 students

    float totalAverage = 0.0;

    // Nested for-loop 
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", students[i].name);
        int sum = 0;
        for (int j = 0; j < 13; j++)
        {
            scanf("%d", &students[i].score[j]);
            sum += students[i].score[j];
        }
        students[i].average = sum / (float)13;
        totalAverage += students[i].average;
    }
    totalAverage /= 5;

    // Finding student with the highest average score
    int bestIndex = 0;
    for (int i = 1; i < 5; i++)
    {
        if (students[i].average > students[bestIndex].average)
        {
            bestIndex = i;
        }
    }
    capitalize(students[bestIndex].name);
    printf("%s\n", students[bestIndex].name);

    // Writes students 
    for (int i = 0; i < 5; i++)
    {
        if (students[i].average < totalAverage)
        {
            capitalize(students[i].name);
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}