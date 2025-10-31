#include <stdio.h>

#define MAX_BOOKS 100

// Function prototypes
int addBook(int isbns[], char titles[][50], float prices[], int quantities[], int count);
int processSale(int isbns[], int quantities[], int count);
int lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count);

int main() {
    int isbns[MAX_BOOKS];
    char titles[MAX_BOOKS][50];
    float prices[MAX_BOOKS];
    int quantities[MAX_BOOKS];
    int count = 0;   // number of books currently stored

    int choice;

    do {
        printf("\n=== LIBERTY BOOKS INVENTORY SYSTEM ===\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                count = addBook(isbns, titles, prices, quantities, count);
                break;
            case 2:
                processSale(isbns, quantities, count);
                break;
            case 3:
                lowStockReport(isbns, titles, prices, quantities, count);
                break;
            case 4:
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

// Function to add a new book
int addBook(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    if (count >= MAX_BOOKS) {
        printf("Inventory is full!\n");
        return count;
    }

    int newISBN;
    printf("Enter ISBN: ");
    scanf("%d", &newISBN);

    // Check duplicate ISBN manually (no string.h used)
    int i;
    for (i = 0; i < count; i++) {
        if (isbns[i] == newISBN) {
            printf("Error: Book with this ISBN already exists!\n");
            return count;
        }
    }

    isbns[count] = newISBN;
    printf("Enter Title: ");
    getchar(); // clear input buffer
    gets(titles[count]); // use gets for simple input (OK for small programs)
    printf("Enter Price: ");
    scanf("%f", &prices[count]);
    printf("Enter Quantity: ");
    scanf("%d", &quantities[count]);

    printf("Book added successfully!\n");
    count++;
    return count;
}

// Function to process a sale
int processSale(int isbns[], int quantities[], int count) {
    int searchISBN, copies;
    printf("Enter ISBN of the book sold: ");
    scanf("%d", &searchISBN);

    int i;
    for (i = 0; i < count; i++) {
        if (isbns[i] == searchISBN) {
            printf("Enter number of copies sold: ");
            scanf("%d", &copies);

            if (copies > quantities[i]) {
                printf("Error: Not enough stock available!\n");
            } else {
                quantities[i] -= copies;
                printf("Sale processed successfully! Remaining stock: %d\n", quantities[i]);
            }
            return 0;
        }
    }

    printf("Error: Book with given ISBN not found!\n");
    return 0;
}

// Function to show low stock books
int lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int count) {
    int found = 0;
    int i;
    printf("\n--- LOW STOCK REPORT (Quantity < 5) ---\n");
    for (i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("ISBN: %d | Title: %s | Price: %.2f | Quantity: %d\n",
                   isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }
    if (!found)
        printf("All books are sufficiently stocked.\n");

    return 0;
}

