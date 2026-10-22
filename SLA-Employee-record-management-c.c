#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// Defining structure to hold employee details
struct Employee {
    int id;
    char name[50];
    char department[30];
    float salary;
};

// Global array and counter
struct Employee empList[MAX_EMPLOYEES];
int count = 0;

// Function declarations
void addEmployee();
void displayEmployees();
void searchEmployee();
int readInt(const char *prompt, int *value);
int readFloat(const char *prompt, float *value);
int readText(const char *prompt, char *value, size_t size);

int main() {
    int choice;

    while (1) {
        printf("\n=========================================");
        printf("\n    EMPLOYEE RECORD MANAGEMENT SYSTEM    ");
        printf("\n=========================================");
        printf("\n1. Add New Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Exit");
        printf("\n-----------------------------------------");
        if (!readInt("Enter your choice (1-4): ", &choice)) {
            printf("\nInput ended. Exiting program...\n");
            return 0;
        }

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                printf("\nExiting program... Thank you!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to add an employee record
void addEmployee() {
    if (count >= MAX_EMPLOYEES) {
        printf("\nError: Record memory full!\n");
        return;
    }

    printf("\n--- Add Employee Details ---\n");
    if (!readInt("Enter Employee ID: ", &empList[count].id) ||
        !readText("Enter Name: ", empList[count].name,
                  sizeof(empList[count].name)) ||
        !readText("Enter Department: ", empList[count].department,
                  sizeof(empList[count].department)) ||
        !readFloat("Enter Salary: ", &empList[count].salary)) {
        printf("\nInput ended. Employee was not added.\n");
        return;
    }

    count++;
    printf("\nEmployee record added successfully!\n");
}

// Function to display all employee records
void displayEmployees() {
    if (count == 0) {
        printf("\nNo employee records found!\n");
        return;
    }

    printf("\n------------------------------------------------------------------");
    printf("\n%-10s %-20s %-20s %-10s", "ID", "Name", "Department", "Salary");
    printf("\n------------------------------------------------------------------");

    for (int i = 0; i < count; i++) {
        printf("\n%-10d %-20s %-20s %-10.2f",
               empList[i].id,
               empList[i].name,
               empList[i].department,
               empList[i].salary);
    }
    printf("\n------------------------------------------------------------------\n");
}

// Function to search an employee by ID
void searchEmployee() {
    if (count == 0) {
        printf("\nNo employee records found!\n");
        return;
    }

    int searchId, found = 0;
    if (!readInt("\nEnter Employee ID to search: ", &searchId)) {
        printf("\nInput ended. Returning to the main menu.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (empList[i].id == searchId) {
            printf("\n--- Record Found ---");
            printf("\nID: %d", empList[i].id);
            printf("\nName: %s", empList[i].name);
            printf("\nDepartment: %s", empList[i].department);
            /* Use ASCII currency text so output is portable across consoles. */
            printf("\nSalary: Rs. %.2f\n", empList[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nEmployee with ID %d not found.\n", searchId);
    }
}

int readInt(const char *prompt, int *value) {
    char line[100];
    char extra;

    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0;
        }
        if (sscanf(line, " %d %c", value, &extra) == 1) {
            return 1;
        }
        printf("Invalid number. Please try again.\n");
    }
}

int readFloat(const char *prompt, float *value) {
    char line[100];
    char extra;

    for (;;) {
        printf("%s", prompt);
        if (fgets(line, sizeof(line), stdin) == NULL) {
            return 0;
        }
        if (sscanf(line, " %f %c", value, &extra) == 1) {
            return 1;
        }
        printf("Invalid salary. Please try again.\n");
    }
}

int readText(const char *prompt, char *value, size_t size) {
    size_t length;

    printf("%s", prompt);
    if (fgets(value, (int)size, stdin) == NULL) {
        return 0;
    }

    length = strcspn(value, "\n");
    if (value[length] != '\n') {
        int character;
        while ((character = getchar()) != '\n' && character != EOF) {
            /* Discard input that does not fit in the destination buffer. */
        }
    }
    value[length] = '\0';

    if (length == 0) {
        printf("Input cannot be empty.\n");
        return readText(prompt, value, size);
    }
    return 1;
}
