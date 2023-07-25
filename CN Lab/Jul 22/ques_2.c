#include <stdio.h>
#include <string.h>

struct dob{
	int day;
	int month;
	int year;
};

struct student_info{
	int roll_no;
	char name[50];
	float CGPA;
	struct dob age;
};

void call_value(struct student_info student){
	printf("Call by value:\n");
	printf("Roll No: %d\n", student.roll_no);
	printf("Name: %s\n", student.name);
	printf("CGPA: %2.2f\n", student.CGPA);
	printf("DOB: %d-%d-%d\n\n", student.age.day, student.age.month, student.age.year);
}

void call_address(struct student_info *ptr){
	printf("Call by address:\n");
	printf("Roll No: %d\n", ptr->roll_no);
	printf("Name: %s\n", ptr->name);
	printf("CGPA: %2.2f\n", ptr->CGPA);
	printf("DOB: %d-%d-%d\n", ptr->age.day, ptr->age.month, ptr->age.year);
}

int main(){
	struct student_info student;
	
	student.roll_no = 101;
	strcpy(student.name, "ABC");
	student.CGPA = 9.5;
	student.age.day = 1;
	student.age.month = 1;
	student.age.year = 2001;
	
	call_value(student);
	call_address(&student);
	
	return 0; 
}	
