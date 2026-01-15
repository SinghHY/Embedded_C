#include <stdio.h>
#include <string.h>

// ===== STRUCTURES =====
// Structure: Collection of different data types
struct Student {
    int rollNo;
    char name[50];
    float gpa;
    char grade;
};

// Nested structure
struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int empId;
    char empName[50];
    struct Date joinDate;
    float salary;
};

// ===== UNIONS =====
// Union: All members share the same memory location
union Data {
    int intValue;
    float floatValue;
    char charValue;
};

// Union with structure
union StudentInfo {
    struct {
        int id;
        char name[30];
    } details;
    struct {
        int marks;
        float percentage;
    } performance;
};

int main() {
    printf("===== STRUCTURES =====\n\n");
    
    // Structure example 1
    struct Student student1 = {101, "John Doe", 3.8, 'A'};
    printf("Student Details:\n");
    printf("Roll No: %d\n", student1.rollNo);
    printf("Name: %s\n", student1.name);
    printf("GPA: %.2f\n", student1.gpa);
    printf("Grade: %c\n\n", student1.grade);
    
    // Nested structure example
    struct Employee emp1;
    emp1.empId = 202;
    strcpy(emp1.empName, "Jane Smith");
    emp1.joinDate.day = 15;
    emp1.joinDate.month = 3;
    emp1.joinDate.year = 2023;
    emp1.salary = 75000.50;
    
    printf("Employee Details:\n");
    printf("ID: %d\n", emp1.empId);
    printf("Name: %s\n", emp1.empName);
    printf("Join Date: %d/%d/%d\n", emp1.joinDate.day, emp1.joinDate.month, emp1.joinDate.year);
    printf("Salary: %.2f\n\n", emp1.salary);
    
    // Structure size
    printf("Size of struct Student: %zu bytes\n", sizeof(struct Student));
    printf("Size of struct Employee: %zu bytes\n\n", sizeof(struct Employee));
    
    // ===== UNIONS =====
    printf("===== UNIONS =====\n\n");
    
    union Data data;
    printf("Size of union Data: %zu bytes\n\n", sizeof(union Data));
    
    // Only one member can hold value at a time
    data.intValue = 100;
    printf("intValue: %d\n", data.intValue);
    
    data.floatValue = 3.14;  // This overwrites intValue
    printf("After assigning floatValue: %.2f\n", data.floatValue);
    printf("intValue now: %d (overwritten)\n\n", data.intValue);
    
    // Union with structure example
    union StudentInfo info;
    info.details.id = 505;
    strcpy(info.details.name, "Alice");
    printf("Student ID: %d, Name: %s\n", info.details.id, info.details.name);
    
    info.performance.marks = 95;  // Overwrites previous data
    info.performance.percentage = 98.5;
    printf("After updating performance - Marks: %d, Percentage: %.1f\n", 
           info.performance.marks, info.performance.percentage);
    
    return 0;
}