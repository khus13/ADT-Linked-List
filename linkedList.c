#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"


void initList(StudentPtr *stud){
    *stud = NULL;
}

void displayList(StudentPtr stud){
    printf("These are the Students logged to the Student Record:\n");
    while(stud != NULL){
        printf("Student Name:\n");
        printf("%s %s %c\n", stud->data.studName.FName, stud->data.studName.LName, stud->data.studName.MI);
        printf("Student ID Number: %d\n", stud->data.studID);
        printf("Year: %d\n", stud->data.year);
        printf("GPA: %.2f\n", stud->data.GPA);
        printf("Course: %s\n", stud->data.course);
        printf("Program: %s\n", stud->data.program);

        stud = stud->link;
    }
}

//Sorting
void sortList(StudentPtr* stud){

}//Sort Student Based on Last Name


//Checking (True or False)
bool isFull(StudentPtr stud){
    // printf("khugo will be under miss pena for algo and become an artist");
    //Linked Lists Never Becomes Full
}

bool isEmpty(StudentPtr stud){
    return(stud == NULL);
}


//Insertion
int insertStudentAtFirst(StudentPtr *stud, Student s){
    StudentPtr newNode= malloc(sizeof(StudentNode));
    if(newNode == NULL) return 0;

    newNode->data = s;
    newNode->link = *stud;
    *stud = newNode;
    return 1;

} //Inserts passed student at the first Index of the List

int insertStudentAtPosition(StudentPtr *stud, Student s, int idx){
    if(isEmpty(*stud)) return 0;

    int count = 1;

    StudentPtr *ptr;
    for(ptr = stud; *ptr != NULL && count != idx; ptr = &(*ptr)->link, ++count){}

    StudentPtr newNode = malloc(sizeof(StudentNode));
    if(newNode != NULL){
        newNode->data = s;
        newNode->link = *ptr;
        *ptr = newNode;

        return 1;
    }

} //Inserts student to the position given/passed


int insertStudentAtLast(StudentPtr *stud, Student s){
    if(isEmpty(*stud)) return 0;

    StudentPtr *ptr;
    for(ptr = stud; *ptr != NULL; ptr = &(*ptr)->link){}

    StudentPtr newNode = malloc(sizeof(StudentNode));
    if(!isEmpty(*stud)){
        newNode->data = s;
        newNode->link = NULL;
    }

    return 1;
}//Inserts student at the Last

//Deletion
int deleteStudentAtFirst(StudentPtr *stud, Student s){
    if(isEmpty(*stud)) return 0;

    StudentPtr temp = *stud;
    *stud = temp->link;
    free(temp);


    return 1;
} //Deletes student at the beginning of the List

int deleteStudentAtPosition(StudentPtr *stud, Student s, int idx){
    if(isEmpty(*stud)) return 0;

    StudentPtr *ptr;
    int count = 1;
    for(ptr = stud; *ptr != NULL && count < idx; ptr = &(*ptr)->link, count++){}

    StudentPtr temp = *ptr;
    *ptr = (*ptr)->link;
    free(temp);

    return 1;

} //Deletes Student at the Specified Position


int deleteStudentAtEnd(StudentPtr *stud, Student s){
    if(isEmpty(*stud)) return 0;

    StudentPtr *trav;
    for(trav = stud; (*trav)->link != NULL; trav = &(*trav)->link){}

    free(*trav);
    *trav = NULL;

    return 1;


} //Deletes Student at the End

//Returning a Structure
StudentNode ReturnDeleted(StudentPtr *stud, Student s){

}

StudentNode ReturnFound(StudentPtr *stud, Student s){

}

