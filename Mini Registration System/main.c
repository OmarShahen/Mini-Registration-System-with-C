#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    struct Address
    {
        char country[20];
        char city[20];
    };
    struct Birthdate
    {
        int day;
        int month;
        int year;
    };
    struct Student
    {
        int id;
        char name[50];
        double gpa;
        char gender[7];
        struct Address address;
        struct Birthdate birthdate;
    };
    struct Statistics
    {
        int max,min,number_of_males,number_of_females;
        double average;
    };

void pint_all_students(struct Student student[],int size);
void print_student(struct Student student[],int id);
void display_Statistics(struct Student student[],int number_of_males,int number_of_females);
void display_Range(double max_range,double min_range,struct Student student[]);
void Student_ascending_sort(struct Student student[]);
int delete_Student(struct Student student[],int id);


int main()
{
     struct Student student[15];
     struct Statistics statistics = {0,0,0,0,0};
     int number_of_males = 0,number_of_females = 0;
     int size = 4;

     for(int i=0;i<size;i++){
    printf("Student No.%d\n\n",i+1);
    printf("Student ID:");
    scanf("%d",&student[i].id);
    printf("Student Name:");
    scanf("%s",&student[i].name);
    gender:
    printf("Student Gender:");
    scanf("%s",&student[i].gender);
    if(strcmp(student[i].gender,"male") == 0|| strcmp(student[i].gender,"MALE") == 0 || strcmp(student[i].gender,"Male") == 0)
    {
        number_of_males++;
    }
    else if(strcmp(student[i].gender,"female") == 0 || strcmp(student[i].gender,"FEMALE") == 0|| strcmp(student[i].gender,"Female") == 0)
    {
        number_of_females++;
    }
    else{

        printf("Enter the gender correctly.(Male or Female)\n");
        goto gender;
    }
    gpa:
    printf("Student GPA:");
    scanf("%lf",&student[i].gpa);
    if(student[i].gpa > 4.00 || student[i].gpa < 0.00)
    {
        printf("Enter The GPA correctly.(0.00 -> 4.00)\n");
        goto gpa;

    }
    printf("Student Address(Country):");
    scanf("%s",&student[i].address.country);
    printf("Student Address(City):");
    scanf("%s",&student[i].address.city);
    printf("Student BirthDate(day):");
    scanf("%d",&student[i].birthdate.day);
    printf("Student BirthDate(month):");
    scanf("%d",&student[i].birthdate.month);
    printf("Student BirthDate(Year):");
    scanf("%d",&student[i].birthdate.year);
    printf("\n======================================================\n");
     }
     while(1){
                printf("\n======================================================\n");

     printf("1.Print all students.\n");
     printf("2.Search specific student.\n");
     printf("3.Calculate Statistics.\n");
     printf("4.Range GPA of students.\n");
     printf("5.Sort Students GPA in Ascending Order.\n");
     printf("6.Delete Student.\n");
     printf("7.QUIT.\n");
     printf("Enter the number of the option:");
     int choose;
     scanf("%d",&choose);
     if(choose == 1){

        pint_all_students(student,size);
     }
     if(choose == 2)
     {
         printf("Enter the ID of the Student:");
         int target;
         scanf("%d",&target);
         print_student(student,target);
     }
     if(choose == 3)
     {
           display_Statistics(student,number_of_males,number_of_females);

     }
     if(choose == 4)
     {
         double max_range,min_range;
         printf("Enter the Maximum range:");
         scanf("%lf",&max_range);
         printf("Enter the Minimum range:");
         scanf("%lf",&min_range);
         display_Range(max_range,min_range,student);
     }
     if(choose == 5)
     {
         Student_ascending_sort(student);
     }
     if(choose == 6)
     {
         int id;
         printf("Enter Student ID:");
         scanf("%d",&id);
          size = delete_Student(student,id);
     }
     if(choose == 7)
     {
         break;
     }
}

    return 0;
}

void pint_all_students(struct Student student[],int size)
{
                printf("\n======================================================\n");

    for(int i=0;i<size;i++)
    {
        printf("%d\t\t",student[i].id);
        printf("%s\t\t",student[i].name);
        printf("%s\t\t",student[i].gender);
        printf("%.2lf\t\t",student[i].gpa);
        printf("%s\t\t",student[i].address.country);
        printf("%s\t\t",student[i].address.city);
        printf("%d\t\t",student[i].birthdate.day);
        printf("%d\t\t",student[i].birthdate.month);
        printf("%d\t\t",student[i].birthdate.year);
        printf("\n");

    }
                printf("\n======================================================\n");

}
void print_student(struct Student student[],int id)
{
                printf("\n======================================================\n");



    for(int i=0;i<7;i++)
    {
        if(student[i].id == id)
        {
            printf("\nID:%d\n",student[i].id);
            printf("Name:%s\n",student[i].name);
            printf("Gender:%s\n",student[i].gender);
            printf("GPA:%.2lf\n",student[i].gpa);
            printf("Address:(%s,%s)\n",student[i].address.country,student[i].address.city);
            printf("BirthDate:%d/%d/%d\n",student[i].birthdate.day,student[i].birthdate.month,student[i].birthdate.year);
            printf("\n=============================================\n");
        }
    }
}
void display_Statistics(struct Student student[],int number_of_males,int number_of_females)
{
    double sum = 0,max_GPA,min_GPA,average;
    max_GPA = student[0].gpa;
    min_GPA = student[0].gpa;
    for(int i=0;i<4;i++)
    {
        sum = sum + student[i].gpa;

        if(max_GPA < student[i].gpa)
        {
            max_GPA = student[i].gpa;
        }
        if(min_GPA > student[i].gpa)
        {
            min_GPA = student[i].gpa;
        }
    }
    average = sum/4;

    printf("\n================================\n");
    printf("The Highest GPA:%.2lf\n",max_GPA);
    printf("The Lowest GPA:%.2lf\n",min_GPA);
    printf("The Average:%.2lf\n",average);
    printf("The Number of Males:%d\n",number_of_males);
    printf("The Number of Females:%d\n",number_of_females);
    printf("\n=================================\n");

}
void display_Range(double max_range,double min_range,struct Student student[])
{

    if(max_range <= 4.00  && min_range >= 0.00)
    {
        printf("\n=============================================\n");

        for(int i=0;i<4;i++)
        {
            if(max_range >= student[i].gpa && student[i].gpa >= min_range)
            {
             printf("GPA:%.2lf\tName:%s\n",student[i].gpa,student[i].name);
            }
        }
                    printf("\n======================================================\n");


    }

}
void Student_ascending_sort(struct Student student[]) {
    int n = 4;
    int i = 0, j = 0;
    double tmp;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (student[j].gpa > student[j + 1].gpa) {
                tmp = student[j].gpa;
                student[j].gpa = student[j + 1].gpa;
                student[j + 1].gpa = tmp;
            }
        }
    }
            printf("\n======================================================\n");
    for(int i=0;i<n;i++)
    {
        printf("GPA:%.2lf\n",student[i].gpa);

    }
                printf("\n======================================================\n");

}
int delete_Student(struct Student student[],int id)
{
    int n =4,position;
 for(int i=0;i<n;i++)
 {
     if(student[i].id == id)
     {
         position = i;
         for(int j = position;j<n-1;j++)
         {
             student[j] = student[j+1];
         }
         n--;

      }
 }
      return n;
}






