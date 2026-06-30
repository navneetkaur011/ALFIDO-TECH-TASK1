#include <stdio.h>
#include <stdlib.h>

// Defining the structure for a single node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the very beginning
void insertHead(struct Node** head_ref, int new_data) {
    // Dynamically allocate memory for the new node
    struct Node* new_node = malloc(sizeof(struct Node));

    if (new_node == NULL) {
        printf("Error: Memory allocation failed!\n");
        return;
    }
    
    new_node->data = new_data;// Assign data to the node
    new_node->next = *head_ref;// Point new node's next to the old head
    *head_ref = new_node;// Move the head pointer to our new node
    
    printf("Successfully inserted %d at the head.\n", new_data);
}

// Function to search for a specific value and return its position (1-indexed)
int searchList(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == key) {
            return position;// Found the key, return where it is
        }
        current = current->next;// Move to the next node
        position++;
    }
    return -1;// Return -1 if the key doesn't exist
}

// Function to delete the first occurrence of a specific key
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // Case 1: If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;// Change head to the next node
        free(temp);// Free the memory of the old head
        printf("Deleted %d from the list.\n", key);
        return;
    }

    // Case 2: Search for the key while keeping track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Case 3: Key was not found in the list
    if (temp == NULL) {
        printf("Element %d not found. Deletion skipped.\n", key);
        return;
    }

    // Case 4: Unlink the node from the linked list and free it
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", key);
}

// Function to traverse and print the whole list
void printList(struct Node* node) {
    printf("Current List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, target, pos;

    while (1) {
        printf("\n===== LINKED LIST MENU =====\n");
        printf("1. Insert at Head\n");
        printf("2. Search Element\n");
        printf("3. Delete Element\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting program.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter integer value to insert: ");
                while (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter an integer: ");
                    while (getchar() != '\n');
                }
                insertHead(&head, value);
                break;
                
            case 2:
                printf("Enter value to search: ");
                while (scanf("%d", &target) != 1) {
                    printf("Invalid input. Please enter an integer: ");
                    while (getchar() != '\n');
                }
                pos = searchList(head, target);
                if (pos != -1)
                    printf("Element %d found at position %d.\n", target, pos);
                else
                    printf("Element %d not found in the list.\n", target);
                break;
                
            case 3:
                printf("Enter value to delete: ");
                while (scanf("%d", &target) != 1) {
                    printf("Invalid input. Please enter an integer: ");
                    while (getchar() != '\n');
                }
                deleteNode(&head, target);
                break;
                
            case 4:
                printList(head);
                break;
                
            case 5:
                printf("Exiting program. Tata Bye Bye!\n");
                return 0;
                
            default:
                printf("Invalid choice! Select between 1 and 5.\n");
        }
    }
    return 0;
}