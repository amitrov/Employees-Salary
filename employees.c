#include <stdio.h>
#include <string.h>

#define MAX_ENTRIES 10
#define NAME_LIMIT 10

// Function to truncate names longer than 10 characters
void truncate(char *str, int limit) {
    if (strlen(str) > limit) {
        str[limit] = '\0';
    }
}

int main() {
    char name[50], surname[50];
    int age;
    double salary, yearly_salary;
    int precision;
    double total_salary = 0;
    int counter = 1;
    int i;

    printf("Enter precision for salary display (e.g., 2 for 2 decimal places): ");
    scanf("%d", &precision);

    // Column headers
    printf("\n%-4s %-12s %-12s %-4s %*s %*s\n", "No.", "Name", "Surname", "Age", precision + 10, "Monthly Salary", precision + 10, "Yearly Salary");

    for (i = 0; i < MAX_ENTRIES; i++) {
        printf("\nEnter employee details:\n");

        // Clear the input buffer to handle any leftover newlines or spaces
        while (getchar() != '\n');

        // Prompt for Name
        printf("Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // Remove newline
        truncate(name, NAME_LIMIT);

        // Prompt for Surname
        printf("Surname: ");
        fgets(surname, sizeof(surname), stdin);
        surname[strcspn(surname, "\n")] = '\0'; // Remove newline
        truncate(surname, NAME_LIMIT);

        // Prompt for Age
        printf("Age: ");
        scanf("%d", &age);

        // Prompt for Monthly Salary
        printf("Monthly Salary: ");
        scanf("%lf", &salary);

        // Calculate yearly salary with 13 months
        yearly_salary = salary * 13;
        total_salary += yearly_salary;

        // Display the entry in table format
        printf("%-4d %-12s %-12s %-4d %*.*f %*.*f\n", counter++, name, surname, age, precision + 10, precision, salary, precision + 10, precision, yearly_salary);

        // Display table after every 5 entries
        if ((i + 1) % 5 == 0 && i != MAX_ENTRIES - 1) {
            printf("\n--- Displaying next set of entries ---\n");
        }
    }

    // Calculate and display average salary
    double average_salary = total_salary / MAX_ENTRIES;
    printf("\nAverage yearly salary: %.*f\n", precision, average_salary);

    return 0;
}
