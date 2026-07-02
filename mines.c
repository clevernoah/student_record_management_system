#include <stdio.h>
#include <string.h>
#define max_students 100





struct student{
 char name[50];
    int marks[2];
};

    struct student s[max_students];
    int count = 0; 

    void add_student_record();
void search_student();
 void update_student_records();
 void delete_student();
 void display_student_records();
 void save_to_file();
 void load_from_file();

int main(){
load_from_file();
    printf("****STUDENT RECORD MANAGEMENT SYSTEM****\n");

    int choice;
    do{
        printf("\n1. Add Student Records\n");
        printf("2. Search Student Records\n");
        printf("3. Update Student Records\n");
        printf("4. Delete Student Records\n");
        printf("5. Display Student Records\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                add_student_record();
                break;
            case 2:
                search_student();
                break;
            case 3:
                update_student_records();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                 display_student_records();
                break;
                case 6:
printf("Exiting the program.\n");
break;
            default:
                printf("Invalid choice. Please try again.\n");
        }



    }while(choice != 6);
    
    return 0;
}


void add_student_record() {
    int total = 0;
    printf("How many student records do you want to add?");
    scanf("%d", &total);

    if (total < 0 || total+count > max_students){
        printf("Invalid number,%d slots are available\n",max_students-count);
    }

    while (getchar() != '\n');
    for (int i = 0; i < total; i++) {
        
        printf("Enter the name for student %d: ", i + 1);
        fgets(s[count+i].name,sizeof(s[count+i].name),stdin);
        s[count+i].name[strcspn(s[count+i].name,"\n")] = '\0';

        for (int j = 0; j < 2; j++) {
            printf("Enter the mark%d for student %d: ", j + 1, i + 1);
            scanf("%d", &s[count+i].marks[j]);
            printf("\n");
            while(getchar() != '\n');
        }
    }
    count += total;
    save_to_file();
    printf("Student records added successfully.\n");
}




void search_student() {
    char name1[50];
    printf("Enter the name of the student to search:\n");
    while (getchar() != '\n');
fgets(name1, sizeof(name1), stdin);
name1[strcspn(name1, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].name, name1) == 0) {
            printf("Student found: %s\n", s[i].name);
            for(int j = 0; j < 2; j++) {
                printf("Mark %d: %d\n", j + 1, s[i].marks[j]);
            }
            return;
        }
    }
    printf("Student not found.\n");
}


void update_student_records() {
    char name1[50];
    int choice;
    while (getchar() != '\n');
    printf("Enter the name of the student to update:\n ");
    fgets(name1,sizeof(name1),stdin);
    name1[strcspn(name1,"\n")] = '\0';
    printf("Do you wish to update the name or marks? (1 for name, 2 for name and marks,3 for marks):\n "); 
    scanf("%d", &choice);
    while (getchar() != '\n');

    if (choice == 1) {
        for (int i=0; i < count; i++) {
            if (strcmp(s[i].name, name1) == 0) {
                printf("Student found: %s\n", s[i].name);
                printf("Enter the new name for student %s: ", s[i].name);
                fgets(s[i].name,sizeof(s[i].name),stdin);
                s[i].name[strcspn(s[i].name,"\n")] = '\0';
                printf("Name updated successfully.\n");
                return;
            }
        }
        printf("Student not found.\n");
        // Update name
    } 
    
    else if (choice == 2) {
        while (getchar() != '\n');
        for (int i=0; i < count; i++) {
            if (strcmp(s[i].name,name1) == 0) {
                printf("Student found: %s\n", s[i].name);
                printf("Enter the new name for student %s: ", s[i].name);
                fgets(s[i].name,sizeof(s[i].name),stdin);
                s[i].name[strcspn(s[i].name,"\n")] = '\0';
                for (int j = 0; j < 2; j++) {
                    printf("Enter the new mark%d for student %s: ", j + 1,s[i].name);
                    scanf("%d",&s[i].marks[j]);
                    while (getchar() != '\n');
                }
                printf("Name and marks updated successfully.\n");
                return;
            }
        }

printf("Student not found.\n");
        // Update name and marks
    }
    else if (choice == 3) {
        for(int i=0; i < count; i++) {
            if (strcmp(s[i].name, name1) == 0) {
                printf("Student found: %s\n",s[i].name);
                for (int j = 0; j < 2; j++) {
                    printf("Enter the new mark%d for student %s: ", j + 1, s[i].name);
                    scanf("%d", &s[i].marks[j]);
                }
                printf("Marks updated successfully.\n");
                return;
            }
        }
        printf("Student not found.\n");
        // Update marks
    }
else {
        printf("Invalid choice. Please enter 1, 2, or 3.\n");
        return;
    }
}

void delete_student() {
    char name1[50];
    printf("Enter the name of the student to delete: ");
    while (getchar() != '\n');
fgets(name1, sizeof(name1), stdin);
name1[strcspn(name1, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(s[i].name, name1) == 0) {
            printf("Student found: %s\n", s[i].name);
            for (int j = i; j < count - 1; j++) {
                s[j] = s[j + 1];
            }
            count--;
            save_to_file();
            printf("Student record deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void display_student_records() {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("Student Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", s[i].name);
        for (int j = 0; j < 2; j++) {
            printf("Mark %d: %d\n", j + 1, s[i].marks[j]);
        }
        printf("\n");
    }
    printf("Total number of student records: %d\n", count);
}

void save_to_file(){
    FILE *fp = fopen("student_records.txt", "w");
    if (fp == NULL) {
        printf("Error opening file for writing.\n");
        return;
}
fprintf(fp, "%d\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s\n", s[i].name);
        for (int j = 0; j < 2; j++) {
            fprintf(fp, "%d\n", s[i].marks[j]);
        }
    }
    fclose(fp);
}

void load_from_file(){
    FILE *fp = fopen("student_records.txt", "r");
    if (fp == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }
    fscanf(fp, "%d", &count);
    fgetc(fp); // consume newline

    for (int i = 0; i < count; i++) {
         fgets(s[i].name, sizeof(s[i].name), fp);
    s[i].name[strcspn(s[i].name, "\n")] = '\0';

        for (int j = 0; j < 2; j++) {
            fscanf(fp, "%d", &s[i].marks[j]);
        }fgetc(fp); // consume newline
    }
    fclose(fp);
}