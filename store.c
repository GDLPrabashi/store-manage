
#include <stdio.h>
#include <string.h>

// Define the structure for the store item
struct StoreItem {
    int quantity;
    float price;
    char brandName[50];
    int brandCode;
};

// Function to add an item to the store
void addItem(struct StoreItem store[], int *numItems) {
    if (*numItems >= 100) {
        printf("Store capacity reached. Cannot add more items.\n");
        return;
    }

    struct StoreItem newItem;
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    printf("Enter price: ");
    scanf("%f", &newItem.price);

    printf("Enter brand name: ");
    scanf(" %[^\n]", newItem.brandName);

    printf("Enter brand code: ");
    scanf("%d", &newItem.brandCode);

    store[*numItems] = newItem;
    (*numItems)++;
    printf("Item added to the store.\n");
}

// Function to find the index of an item by brand code
int findItemIndex(struct StoreItem store[], int numItems, int brandCode) {
    for (int i = 0; i < numItems; i++) {
        if (store[i].brandCode == brandCode) {
            return i;
        }
    }
    return -1; // Item not found
}

// Function to delete an item from the store by brand code
void deleteItem(struct StoreItem store[], int *numItems) {
    int brandCode;
    printf("Enter the brand code of the item to delete: ");
    scanf("%d", &brandCode);

    int itemIndex = findItemIndex(store, *numItems, brandCode);
    if (itemIndex == -1) {
        printf("Item not found in the store.\n");
        return;
    }

    // Shift items to overwrite the deleted item
    for (int i = itemIndex; i < *numItems - 1; i++) {
        store[i] = store[i + 1];
    }
    (*numItems)--;
    printf("Item deleted from the store.\n");
}

// Function to update an item in the store by brand code
void updateItem(struct StoreItem store[], int numItems) {
    int brandCode;
    printf("Enter the brand code of the item to update: ");
    scanf("%d", &brandCode);

    int itemIndex = findItemIndex(store, numItems, brandCode);
    if (itemIndex == -1) {
        printf("Item not found in the store.\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &store[itemIndex].quantity);

    printf("Enter new price: ");
    scanf("%f", &store[itemIndex].price);

    printf("Enter new brand name: ");
    scanf(" %[^\n]", store[itemIndex].brandName);

    printf("Item updated in the store.\n");
}

// Function to display the current database in the store
void displayDatabase(struct StoreItem store[], int numItems) {
    if (numItems == 0) {
        printf("Store is empty.\n");
        return;
    }

    printf("Current database in the store:\n");
    printf("----------------------------\n");
    printf("Brand Code\tBrand Name\tQuantity\tPrice\n");
    printf("---------------------------------------------------\n");

    for (int i = 0; i < numItems; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", store[i].brandCode, store[i].brandName, store[i].quantity, store[i].price);
    }
    printf("---------------------------------------------------\n");
}

int main() {
    struct StoreItem store[100];
    int numItems = 0;
    int choice;

    do {
        printf("\n1. Add item\n");
        printf("2. Delete item\n");
        printf("3. Update item\n");
        printf("4. Display current database\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(store, &numItems);
                break;
            case 2:
                deleteItem(store, &numItems);
                break;
            case 3:
                updateItem(store, numItems);
                break;
            case 4:
                displayDatabase(store, numItems);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
