#include <stdio.h>
#include <string.h>




struct Student {
	int id;
	char name[50]; // Limit name length to prevent buffer overflow
	float marks[5]; // Assuming 5 subjects (adjust as needed)
	float totalMarks; // To store the calculated total
};






void Get_input(struct Student student[], int *numstudents) {

	printf("enter the number of students(max 10 students): ");

	if (scanf_s("%d", numstudents) != 1 || *numstudents < 0 || *numstudents > 10) {
		printf("Invalid ammount of students must be within the number of 0 - 10");
		
	}

	for (int i = 0; i < *numstudents; i++) {
		printf("please enter student ID", i + 1);
		scanf_s("%d", &student[i].id);
		
		printf("please enter student %d name", i + 1);
		fgets(student[i].name, 50, stdin);
		student[i].name[strcspn(student[i].name, "\n")] = '\0';
		
		
		printf("please enter Marks(space-seperated): ");
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
	struct Student student[10];
	int numstudents = 0;

	Get_input(student,&numstudents);
	HighestClassMark(student,numstudents);
	
	
	
	return 0;
}