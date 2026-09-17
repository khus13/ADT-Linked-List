#include <stdio.h>
#include <string.h>
#include "linkedList.h"

// Helper just for this test file: builds a Student struct from raw values
Student makeStudent(const char *fname, const char *lname, char mi,
                     int id, int year, float gpa,
                     const char *course, const char *program) {
    Student s;
    strcpy(s.studName.FName, fname);
    strcpy(s.studName.LName, lname);
    s.studName.MI = mi;
    s.studID = id;
    s.year = year;
    s.GPA = gpa;
    strcpy(s.course, course);
    strcpy(s.program, program);
    return s;
}

int main(void) {
    StudentPtr list;
    initList(&list);

    printf("Is list empty? %s\n\n", isEmpty(list) ? "Yes" : "No");

    // --- Insert at first ---
    Student s1 = makeStudent("Juan", "Dela Cruz", 'S', 2024001, 1, 1.50,
                              "BSCS", "Computer Science");
    insertStudentAtFirst(&list, s1);

    Student s2 = makeStudent("Maria", "Santos", 'B', 2024002, 2, 1.75,
                              "BSIT", "Information Tech");
    insertStudentAtFirst(&list, s2);

    printf("Is list empty? %s\n\n", isEmpty(list) ? "Yes" : "No");

    printf("--- After insertStudentAtFirst ---\n");
    displayList(list);
    printf("\n");

    // --- Insert at a specific position ---
    Student s3 = makeStudent("Pedro", "Reyes", 'M', 2024003, 3, 1.25,
                              "BSCE", "Civil Engineering");
    insertStudentAtPosition(&list, s3, 2);

    printf("--- After insertStudentAtPosition (idx 2) ---\n");
    displayList(list);
    printf("\n");

    // --- Insert at the last position ---
    Student s4 = makeStudent("Ana", "Lopez", 'C', 2024004, 4, 1.10,
                              "BSN", "Nursing");
    insertStudentAtLast(&list, s4);

    printf("--- After insertStudentAtLast ---\n");
    displayList(list);
    printf("\n");

    // --- Delete at first ---
    deleteStudentAtFirst(&list, s1);

    printf("--- After deleteStudentAtFirst ---\n");
    displayList(list);
    printf("\n");

    // --- Delete at a specific position ---
    deleteStudentAtPosition(&list, s3, 2);

    printf("--- After deleteStudentAtPosition (idx 2) ---\n");
    displayList(list);
    printf("\n");

    // --- Delete at the end ---
    deleteStudentAtEnd(&list, s4);

    printf("--- After deleteStudentAtEnd ---\n");
    displayList(list);
    printf("\n");

    // NOTE: sortList, isFull, ReturnDeleted, and ReturnFound are not called
    // here because they have no working implementation yet (empty bodies /
    // missing return statements).

    return 0;
}
