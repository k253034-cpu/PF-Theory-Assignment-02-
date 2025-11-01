#include <stdio.h>

#define ROWS 3   
#define COLS 3   


#define POWER_ON           0  
#define OVERLOAD_WARNING   1 
#define MAINTENANCE_REQ    2  


void updateSector(int grid[ROWS][COLS], int row, int col, int bit, int value);
void querySector(int grid[ROWS][COLS], int row, int col);
void runDiagnostic(int grid[ROWS][COLS]);
void displayMenu();

int main() {
    int grid[ROWS][COLS] = {0};  
    int choice, row, col, bit, value;
   
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter sector coordinates (row and col): ");
                scanf("%d %d", &row, &col);

                if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                    printf("Select flag to update:\n");
                    printf("0 - Power Status\n1 - Overload Warning\n2 - Maintenance Required\n");
                    scanf("%d", &bit);

                    printf("Enter value (1 to set / 0 to clear): ");
                    scanf("%d", &value);

                    updateSector(grid, row, col, bit, value);
                } else {
                    printf("Invalid coordinates!\n");
                }
                break;

            case 2:
                printf("\nEnter sector coordinates (row and col): ");
                scanf("%d %d", &row, &col);
                if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
                    querySector(grid, row, col);
                } else {
                    printf("Invalid coordinates!\n");
                }
                break;

            case 3:
                runDiagnostic(grid);
                break;

            case 0:
                printf("Exiting system...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

        printf("\n");

    } while (choice != 0);

    return 0;
}


void displayMenu() {
    printf("=== IESCO Power Grid Monitoring System ===\n");
    printf("1. Update Sector Status\n");
    printf("2. Query Sector Status\n");
    printf("3. Run System Diagnostic\n");
    printf("0. Exit\n");
}


void updateSector(int grid[ROWS][COLS], int row, int col, int bit, int value) {
    if (value == 1)
        grid[row][col] |= (1 << bit);   
    else
        grid[row][col] &= ~(1 << bit);  

    printf("Sector (%d,%d) updated successfully.\n", row, col);
}


void querySector(int grid[ROWS][COLS], int row, int col) {
    int status = grid[row][col];

    printf("\nStatus of Sector (%d,%d):\n", row, col);
    printf("Power: %s\n", (status & (1 << POWER_ON)) ? "ON" : "OFF");
    printf("Overload Warning: %s\n", (status & (1 << OVERLOAD_WARNING)) ? "YES" : "NO");
    printf("Maintenance Required: %s\n", (status & (1 << MAINTENANCE_REQ)) ? "YES" : "NO");
}


void runDiagnostic(int grid[ROWS][COLS]) {
    int overloaded = 0, maintenance = 0;
    int i, j;

    for ( i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] & (1 << OVERLOAD_WARNING))
                overloaded++;
            if (grid[i][j] & (1 << MAINTENANCE_REQ))
                maintenance++;
        }
    }

    printf("\n=== System Diagnostic Report ===\n");
    printf("Total Sectors Overloaded: %d\n", overloaded);
    printf("Total Sectors Requiring Maintenance: %d\n", maintenance);
}

