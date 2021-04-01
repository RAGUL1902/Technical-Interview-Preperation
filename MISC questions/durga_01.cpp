#include <stdio.h>
struct student
{
    char name[100];
    int scores[100];
    float avg;
    char grade;
};

struct gradebook
{
    char coursename[100];
    int number_of_weights;
    int number_of_students;
    float weights[100];
    student data[100];
};

student input_one_student(int totalscore)
{
    int i;
    student scr;
    printf("enter the name of student:");
    scanf("%s", scr.name);
    for (i = 0; i < totalscore; i++)
    {
        scanf("%d", &scr.scores[i]);
    }
    return scr;
}

gradebook input_n_students()
{
    gradebook a;
    int i;
    printf("enter the course name:");
    scanf("%s", a.coursename);
    printf("enter total no of students:");
    scanf("%d", &a.number_of_students);
    printf("enter total no of score:");
    scanf("%d", &a.number_of_weights);
    for (i = 0; i < a.number_of_weights; i++)
    {
        scanf("%f", &a.weights[i]);
    }

    for (i = 0; i < a.number_of_students; i++)
    {
        a.data[i] = input_one_student(a.number_of_weights);
    }
    return a;
}


student compute_one_student(student d,gradebook b)
{
    float s = 0;
    for (int i = 0; i < b.number_of_weights; i++)
    {
        s += (d.scores[i] * b.weights[i]);
    }
    int sumofweights = 0;
    for (int i = 0; i < b.number_of_weights; i++)
    {
        sumofweights +=  b.weights[i];
    }
    d.avg = (s / sumofweights);

    if (d.avg >= 0 && d.avg < 60)
        d.grade = 'f';
    else if (d.avg >= 60 && d.avg < 70)
        d.grade = 'd';
    else if (d.avg >= 70 && d.avg < 80)
        d.grade = 'c';
    else if (d.avg >= 80 && d.avg < 90)
        d.grade = 'b';
    else if (d.avg >= 90 && d.avg < 100)
        d.grade = 'a';

    return d;
}
gradebook compute_n_students(gradebook b)
{
    for (int i = 0; i < b.number_of_students; i++)
    {
        b.data[i] = compute_one_student(b.data[i],b);
    }
    return b;
}
void print_one_student(student d)
{
printf("%s\t%0.2f%c\n",d.name,d.avg,d.grade);
}
void print_n_student(gradebook b){
    for(int i=0;i<b.number_of_students;i++){
        print_one_student(b.data[i]);
    }
}

int main()
{
    int n;
    printf("enter the total number of grade book\n");
    scanf("%d", &n);
    gradebook g[n];
    for (int i = 0; i < n; i++)
    {
        g[i] = input_n_students();
        g[i] = compute_n_students(g[i]);
       
    }
    for (int i = 0; i < n; i++)
    {
       print_n_student(g[i]);
    }
    
    return 0;
}