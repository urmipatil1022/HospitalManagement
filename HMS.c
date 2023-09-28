#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

// Define a structure to represent a patient
struct Patient {
    int id;
    char name[50];
    int age;
};

// Function to add a new patient to the system
int addPatient(struct Patient patients[], int count, int id, const char name[], int age) {
    if (count >= MAX_PATIENTS) {
        printf("Hospital database is full.\n");
        return count;
    }

    struct Patient newPatient;
    newPatient.id = id;
    strncpy(newPatient.name, name, sizeof(newPatient.name));
    newPatient.age = age;

    patients[count] = newPatient;

    return count + 1;
}

// Function to display the list of patients
void displayPatients(struct Patient patients[], int count) {
    printf("Patient List:\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", patients[i].id, patients[i].name, patients[i].age);
    }
}

int main() {
    struct Patient patients[MAX_PATIENTS];
    int patientCount = 0;

    while (1) {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (patientCount < MAX_PATIENTS) {
                    int id, age;
                    char name[50];
                    printf("Enter patient ID: ");
                    scanf("%d", &id);
                    printf("Enter patient name: ");
                    scanf("%s", name);
                    printf("Enter patient age: ");
                    scanf("%d", &age);
                    patientCount = addPatient(patients, patientCount, id, name, age);
                    printf("Patient added successfully.\n");
                } else {
                    printf("Hospital database is full. Cannot add more patients.\n");
                }
                break;

            case 2:
                displayPatients(patients, patientCount);
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

