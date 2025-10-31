#include <stdio.h>

#define MAX_ITEMS 100


int getCustomerInfo(char name[], char cnic[]);
void displayInventory(int productCodes[], int stock[], int price[], int size);
void addToCart(int productCodes[], int stock[], int price[], int cartCodes[], int cartQty[], int *cartCount, int size);
float displayBill(int cartCodes[], int cartQty[], int price[], int cartCount);
float applyPromo(float total);
void showInvoice(char name[], char cnic[], float total, float discounted);

int main() {
    
    int productCodes[4] = {1, 2, 3, 4};
    int stock[4] = {50, 10, 20, 8};
    int price[4] = {100, 200, 300, 150};

    
    int cartCodes[MAX_ITEMS];
    int cartQty[MAX_ITEMS];
    int cartCount = 0;

    
    char name[50], cnic[20];
    float totalBill = 0, discountedBill = 0;

    int choice;
    do {
        printf("\n=== SUPERMARKET BILLING SYSTEM ===\n");
        printf("1. Enter Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add Item to Cart\n");
        printf("4. Display Total Bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                getCustomerInfo(name, cnic);
                break;
            case 2:
                displayInventory(productCodes, stock, price, 4);
                break;
            case 3:
                addToCart(productCodes, stock, price, cartCodes, cartQty, &cartCount, 4);
                break;
            case 4:
                totalBill = displayBill(cartCodes, cartQty, price, cartCount);
                discountedBill = applyPromo(totalBill);
                break;
            case 5:
                showInvoice(name, cnic, totalBill, discountedBill);
                break;
            case 6:
                printf("Exiting system... Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }

    } while(choice != 6);

    return 0;
}


int getCustomerInfo(char name[], char cnic[]) {
    printf("Enter Customer Name: ");
    getchar(); 
    gets(name);
    printf("Enter CNIC Number: ");
    gets(cnic);
    printf("Customer information saved successfully!\n");
    return 0;
}


void displayInventory(int productCodes[], int stock[], int price[], int size) {
    int i;
    printf("\n--- INVENTORY LIST ---\n");
    printf("Code\tStock\tPrice\n");
    for (i = 0; i < size; i++) {
        printf("00%d\t%d\t%d\n", productCodes[i], stock[i], price[i]);
    }
}


void addToCart(int productCodes[], int stock[], int price[], int cartCodes[], int cartQty[], int *cartCount, int size) {
    int code, qty, i, found = 0;
    printf("Enter product code to add: ");
    scanf("%d", &code);
    printf("Enter quantity: ");
    scanf("%d", &qty);

    for (i = 0; i < size; i++) {
        if (productCodes[i] == code) {
            found = 1;
            if (qty <= stock[i]) {
                cartCodes[*cartCount] = code;
                cartQty[*cartCount] = qty;
                (*cartCount)++;
                stock[i] -= qty; 
                printf("Item added to cart successfully!\n");
            } else {
                printf("Error: Not enough stock available!\n");
            }
        }
    }

    if (!found)
        printf("Invalid product code!\n");
}


float displayBill(int cartCodes[], int cartQty[], int price[], int cartCount) {
    float total = 0;
    int i;
    printf("\n--- BILL DETAILS ---\n");
    printf("Code\tQty\tPrice\tTotal\n");
    for (i = 0; i < cartCount; i++) {
        int index = cartCodes[i] - 1; 
        float itemTotal = price[index] * cartQty[i];
        printf("00%d\t%d\t%d\t%.2f\n", cartCodes[i], cartQty[i], price[index], itemTotal);
        total += itemTotal;
    }
    printf("----------------------------\n");
    printf("Total Bill (without discount): %.2f\n", total);
    return total;
}


float applyPromo(float total) {
    char code[20];
    char correct[] = "Eid2025";
    int i, match = 1;

    printf("Enter promocode (or press Enter to skip): ");
    getchar(); 
    gets(code);

    
    for (i = 0; correct[i] != '\0' || code[i] != '\0'; i++) {
        if (correct[i] != code[i]) {
            match = 0;
            break;
        }
    }

    if (match) {
        float discount = total * 0.25;
        float newTotal = total - discount;
        printf("Promocode applied! 25%% discount given.\n");
        printf("New Total Bill: %.2f\n", newTotal);
        return newTotal;
    } else if (code[0] != '\0') {
        printf("Invalid promocode entered.\n");
    }

    return total;
}


void showInvoice(char name[], char cnic[], float total, float discounted) {
    printf("\n====== CUSTOMER INVOICE ======\n");
    printf("Customer Name: %s\n", name);
    printf("CNIC: %s\n", cnic);
    printf("-----------------------------\n");
    printf("Total (without discount): %.2f\n", total);
    printf("Total (after discount): %.2f\n", discounted);
    printf("==============================\n");
}

