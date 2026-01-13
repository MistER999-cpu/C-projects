#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct{

    int id;
    char name[50];
    float grade;

}Student;

void addStudent(Student student[], int *count);
void displayStudents(Student students[], int count);
int findIndexById(Student students[], int count, int id);
void searchbyID(Student students[], int count);
void updatestudentgrade(Student students[], int count);
void deletestudentbyID(Student students[], int *count);
float computeaveragegarde(Student students[], int count);



int main(){

    Student students[50];
    int count = 0;

    int choice = 0;


    printf("*** Student Management System ***\n\n");

  do{
    printf("MENU\n\n");
    printf("1. Add student\n");
    printf("2. Display students\n");
    printf("3. Search by ID\n");
    printf("4. Update student by ID\n");
    printf("5. Delet student by ID\n");
    printf("6. Compute average grade\n");
    printf("7. Exit\n");

    printf("Enter your commande :");
    scanf("%d", &choice);

    if(choice < 0 || 10 < choice){
        printf("no commande associated with tis number!!");
        return 0;
    }

    switch(choice){
        case 1 :
        addStudent(students, &count);
        break;

        case 2 :
        displayStudents(students, count);
        break;

        case 3 :
        searchbyID(students, count);
        break;

        case 4 :
        updatestudentgrade(students, count);
        break;

        case 5 :
        deletestudentbyID(students, &count);
        break;

       case 6: {
    float avg = computeaveragegarde(students, count);
    if (avg < 0) {
        printf("No students to compute average.\n");
    } else {
        printf("Average grade: %.2f\n", avg);
    }
    break;
}

    }
    
  }while(choice != 7);




    return 0;
}

void addStudent(Student students[], int *count){
    
    if(*count >= 50){
        printf("List is full\n");
        return ;

    }

    printf("\nEnter ID :");
    scanf("%d", &students[*count].id);

    printf("\nEnter name :");
    scanf("%s", &students[*count].name);

    printf("\nEnter grade :");
    scanf("%f", &students[*count].grade);

    (*count)++;

    printf("\nStudent added.\n");


}    

void displayStudents(Student students[], int count){


    if(count == 0){

        printf("No students found.\n");
    }

   for(int i = 0; i < count; i++){

     printf("\nID : %d | Name : %s | Grade : %.2f\n", 
    students[i].id, students[i].name, students[i].grade);
   }


}

int findIndexById(Student students[], int count, int id){

 for(int i = 0; i < count; i++){
      
    if(students[i].id == id) 
    return i;
    
 }
 return -1;

}

void searchbyID(Student students[], int count){
  
    int id;

    printf("Enter ID to search :");
    scanf("%d", &id);

    int idx = findIndexById(students, count, id);

    if(idx == -1 ){
        printf("Student not found!!");
    
    }
    else{printf("Found -> ID: %d | Name : %s | grade : %.2f\n",
    students[idx].id, students[idx].name, students[idx].grade);
}


}

void updatestudentgrade(Student students[], int count){

    int id;
    float newgrade;

    if(count == 0){

      printf("No students in the list\n");
      return;
    }

    printf("Enter ID to update");
    scanf("%d", &id);

    int idx = findIndexById(students, count, id);

    if(idx == -1){
     
        printf("Student not found!!\n");
        return;

    }

    printf("Current grade : %.2f\n", students[idx].grade);
    printf("Enter new grade :");
    scanf("%f", &newgrade);

    if (newgrade < 0 || newgrade > 20){

        printf("Invalide grade\n");
        return;
    }

    students[idx].grade = newgrade;

    printf("grade updated to successfully .\n");
}

void deletestudentbyID(Student students[], int *count){

  if(*count == 0){

    printf("No dtudent to delete \n");
    return;
  }

   int id;
   printf("Enter ID to delete :");
   scanf("%d", &id);

   int idx = findIndexById(students, *count, id);

   if(idx == -1){

    printf("Student not found\n");
    return; 
   }

   for(int i = idx; i < *count -1; i++){

    students[i] = students[i+1];
   }

   (*count)--;

   printf("Student deleted successfully\n");


}
float computeaveragegarde(Student students[], int count) {
    if (count == 0) {
        return -1.0f;  
    }

    float sum = 0.0f;

    for (int i = 0; i < count; i++) {
        sum += students[i].grade;
    }

    return sum / count;
}
