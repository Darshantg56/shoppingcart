#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;
Item* addItem(Item* head, char name[], int quantity, float price);
Item* removeItem(Item* head, char name[]);
void updateQuantity(Item* head, char name[], int quantity);
void displayCart(Item* head);
void generateBill(Item* head);
int main() {
    Item* cart = NULL;
    int choice;
    char name[50];
    int quantity;
    float price;
    while (1) {
        printf("\n--- Shopping Cart Menu ---\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Update Quantity\n");
        printf("4. Display Cart\n");
        printf("5. Generate Bill\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter item name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);
            cart = addItem(cart, name, quantity, price);
            break;
        case 2:
            printf("Enter the name of the item to remove: ");
            scanf("%s", name);
            cart = removeItem(cart, name);
            break;
        case 3:
            printf("Enter the name of the item to update: ");
            scanf("%s", name);
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            updateQuantity(cart, name, quantity);
            break;
       case 4:
            displayCart(cart);
            break;
       case 5:
            generateBill(cart);
            break;
       case 6:
            printf("Exiting...\n");
            return 0;
       default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
    Item* addItem(Item* head, char name[], int quantity, float price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = NULL;
    if (head == NULL) {
        return newItem;
    }
    Item* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newItem;
    printf("Item added to cart successfully.\n");
    return head;
}
  Item* removeItem(Item* head, char name[]) {
    if (head == NULL) {
        printf("Cart is empty. No items to remove.\n");
        return NULL;
    }
    Item* temp = head;
    Item* prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Item not found in cart.\n");
        return head;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Item removed from cart successfully.\n");
    return head;
}
void updateQuantity(Item* head, char name[], int quantity) {
    Item* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            temp->quantity = quantity;
            printf("Item quantity updated successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Item not found in cart.\n");
}
void displayCart(Item* head) {
    if (head == NULL) {
        printf("Cart is empty.\n");
        return;
    }
    printf("\n--- Shopping Cart Contents ---\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("--------------------------------------\n");
    Item* temp = head;
    while (temp != NULL) {
        printf("%-20s %-10d $%-10.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}
void generateBill(Item* head) {
    if (head == NULL) {
        printf("Cart is empty. No bill to generate.\n");
        return;
    }
    float total = 0;
    printf("\n--- Bill ---\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "Quantity", "Price", "Subto-tal");
    printf("--------------------------------------------------------\n");
    Item* temp = head;
    while (temp != NULL) {
        float subtotal = temp->quantity * temp->price;
        total += subtotal;
        printf("%-20s %-10d $%-10.2f $%-10.2f\n", temp->name, temp->quantity, temp->price, subtotal);
        temp = temp->next;
    }
    printf("--------------------------------------------------------\n");
    printf("Total: $%.2f\n", total);
}

 
