#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *head;

void Print_Linked_List()
{
    if(head == NULL) return;
    struct node *temp = head;
    while(temp != NULL){
        printf("%d -> ", &temp->data);
        temp = temp->next;
    }
    printf("\n");
}

/// Function to insert a node at the beginning
void Insert_At_First(int number)
{
    struct node *newItem = (struct node*) malloc(sizeof(struct node));
    /// Creating Node
    newItem->data = number;
    newItem->next = head;
    head = newItem; /// Updating the head pointer
}

/// Function to insert a node at the end
void Insert_At_Tail(int number)
{
    struct node *newItem = (struct node*) malloc(sizeof(struct node));
    /// Creating Node
    newItem->data = number;
    newItem->next = NULL;

    /// If the list is empty
    if (head == NULL) {
        head = newItem;
        return;
    }

    struct node *temp = head; /// Temp is a pointer, not a node. We don't need to dynamically store its value in the heap memory

    /// Traversing the LinkedList
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    /// Temp is now the last element
    temp->next = newItem; /// temp->next = NULL updated to temp->next = newItem
}


void Insert_At_Position(int number, int position)
{
    struct node *newItem = (struct node*) malloc(sizeof(struct node));
    newItem->data = number;
    newItem->next = NULL;
    ///Setting prev var for traverse
    struct node *prev = head;

    for(int i = 0; i < position-1; i++)
    {
        prev = prev->next;
    }
    ///Now Temp var is in desired position
    newItem->next = prev->next;
    prev->next = newItem;
}

void Insert_Before_Value(int value, int assign_data) {
    struct node *newItem = (struct node*) malloc(sizeof(struct node));
    newItem->data = assign_data; // Assigning data
    newItem->next = NULL;

    /// If the list is empty
    if (head == NULL) {
        printf("List is empty.\n");
        free(newItem);
        return;
    }

    /// If the head node contains the value
    if (head->data == value) {
        newItem->next = head;
        head = newItem;
        return;
    }

    struct node *temp = head;

    /// Finding the node before the one containing the specified value
    while (temp->next != NULL && temp->next->data != value) {
        temp = temp->next;
    }

    /// If the value was not found in the list
    if (temp->next == NULL) {
        printf("Value not found in the list.\n");
        free(newItem);
        return;
    }

    /// Inserting the new node before the specified value
    newItem->next = temp->next;
    temp->next = newItem;
}void printFunc()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d-> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    while(1)
    {
        int ch, num, pos, val;
        printf("\n\n1.Insert First\n2.Insert Last\n3.Insert Middle (Any other pos)\n4.Insert before a Target Val\n5.Print\n");
        scanf("%d", &ch);

        if(ch==1)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            Insert_At_First(num);
        }
        else if (ch==2)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            Insert_At_Tail(num);
        }
        else if (ch==3)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Position to insert: ");
            scanf("%d", &pos);
            Insert_At_Position(num, pos);
        }

        else if(ch==4)
        {
            printf("\nEnter val to insert: ");
            scanf("%d", &num);
            printf("\nEnter Value to insert before: ");
            scanf("%d", &val);
            Insert_Before_Value(num, val);
        }
        else if(ch == 5)
        {
            printFunc();
        }

        else
        {
            printf("\n\n\t\tProgram Terminated\n\n");
            break;
        }
    }
    return 0;
}
