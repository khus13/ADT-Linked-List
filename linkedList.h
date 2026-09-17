#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char FName[20];
    char LName[16];
    char MI;
}Name;

typedef struct{
    Name studName;
    int studID;
    int year;
    float GPA;
    char course[20];
    char program[20];
}Student;

typedef struct node{
    Student data;
    struct node *link;
}StudentNode, *StudentPtr;

void initList(StudentPtr *stud); //Initializes List
void displayList(StudentPtr stud); //Displays List

//Sorting
void sortList(StudentPtr* stud);//Sort Student Based on Last Name

//Insertion
int insertStudentAtFirst(StudentPtr *stud, Student s); //Inserts passed student at the first Index of the List
int insertStudentAtPosition(StudentPtr *stud, Student s, int idx); //Inserts student to the position given/passed
int insertStudentAtLast(StudentPtr *stud, Student s);//Inserts student at the Last

//Deletion
int deleteStudentAtFirst(StudentPtr *stud, Student s); //Deletes student at the beginning of the List
int deleteStudentAtPosition(StudentPtr *stud, Student s, int idx); //Deletes Student at the Specified Position
int deleteStudentAtEnd(StudentPtr *stud, Student s); //Deletes Student at the End

//Returning a Structure
StudentNode ReturnDeleted(StudentPtr *stud, Student s);
StudentNode ReturnFound(StudentPtr *stud, Student s);

//Checking (True or False)
bool isFull(StudentPtr stud);
bool isEmpty(StudentPtr stud);
#endif
