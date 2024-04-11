/*
FIle: StudentmarkUploader.cpp
Project or Assignment:  Personal Project
Programmer: Joshua Harvey 


Description: The funtions in this file allow the user to enter their class followed by entering students info
Name,Student number,Marks then it will be sorted and the student with the best mark will be displayed at the end witha congrats message.
*/






#include <stdio.h>
#include <string.h>




struct Student { // Struc for Student information for user to enter 
	int id;
	char name[50]; // Limit name length to prevent buffer overflow
	float marks[5]; // Assuming 5 subjects (adjust as needed)
	float totalMarks; // To store the calculated total
};





// Get input function gets user input for name Id mark NOTE: Assuming their are at least 5 subjects so 5 marks will be entered.
void Get_input(struct Student student[], int *numstudents) {

	printf("enter the number of students(max 10 students): ");

	if (scanf_s("%d", numstudents) != 1 || *numstudents < 0 || *numstudents > 10) {
		printf("Invalid ammount of students must be within the number of 0 - 10");
		
	}

	for (int i = 0; i < *numstudents; i++) {
		printf("please enter student ID\n", i + 1);
		scanf_s("%d", &student[i].id);
		
		printf("please enter student %d name\n", i + 1);
		fgets(student[i].name, 50, stdin);
		student[i].name[strcspn(student[i].name, "\n")] = '\0';
		
		
		printf("please enter Marks(space-seperated)\n ");
		for (int j = 0; j < 5; j++) {
			scanf_s("%f", &student[i].marks[j]);
		}
	}

	for (int i = 0; i < *numstudents; i++) {
		float total_marks = 0.0;
		for (int j = 0; j < 5; j++)
		{
			total_marks += student[i].marks[j];
		}
		student[i].totalMarks = total_marks;
	}
}

// Highestclassmark function stores all students marks and finds the highest mark displays the student info with the highest mark and congratulates them.
void HighestClassMark(struct Student student[], int numstudents) {

	float highest_mark = -1.0;
	int highest_marks_index = -1;
	
	
	for (int j = 0; j < numstudents; j++) {
		if (student[j].totalMarks > highest_mark) {
			highest_mark = student[j].totalMarks;
			highest_marks_index = j;
			
		}
		
	}
	if (highest_marks_index != -1) {
		printf("Student with Highest Mark:\n");
		printf("ID: %d\n",student[highest_marks_index].id);
		printf("Name: %s\n",student[highest_marks_index].name);
		printf("Total marks: %.2f\n",student[highest_marks_index].totalMarks);
		printf("Congarats %s You did an amazing Job\n", student[highest_marks_index].name);
	}
	else {
		printf("No students found in the provided data");
	}


}



int main() {
	struct Student student[10]; // size of class is 10 
	int numstudents = 0; // set number of students to 0 as user enters class size

	Get_input(student,&numstudents); // function call getinput
	HighestClassMark(student,numstudents);// function call highestclassmark
	
	
	
	return 0;
}