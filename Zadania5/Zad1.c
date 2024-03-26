#include <stdlib.h>
#include <stdio.h>

typedef struct node 
{
    int val;
    struct node * next;
} node_t;

void add_first(node_t ** head, int value);
void pop(node_t ** head);
void remove_last(node_t * head);
void remove_by_index(node_t ** head, int index);
void remove_by_value(node_t ** head, int value);
void add_by_index(node_t ** head, int index, int value);
void print_list(node_t * head);

int main()
{
    node_t * head = NULL;
    head = (node_t *) malloc(sizeof(node_t));
    if (head == NULL) 
    {
        return 1;
    }
    head->val = 2;
    head->next = NULL;

    add_first(&head, 4);
    add_first(&head, 22);
    add_first(&head, 5);
    add_first(&head, 11);
    add_first(&head, 7);
    add_first(&head, 8);
    pop(&head);
    remove_by_index(&head, 1);
    remove_by_value(&head, 22);
    add_by_index(&head, 1, 15);
    remove_last(head);
    print_list(head);
} 

// zad1
void add_first(node_t ** head, int value)
{
    node_t * newElem = (node_t *) malloc(sizeof(node_t));
    newElem->val = value;
    newElem->next = * head;
    * head = newElem;
}

//zad2
void pop(node_t ** head)
{
    if (head == NULL) 
    {
        return;
    }
    node_t * tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

//zad3
void remove_last(node_t * head)
{
    node_t * current = head;

    while (current->next->next != NULL) 
    {
        current = current->next;
    }
    
    free(current->next->next);
    current->next = NULL;
}

//zad4
void remove_by_index(node_t ** head, int index)
{
    node_t * current = *head;
    node_t * tmp = NULL;

    if (index == 0) // dla pierwszego elementu
    {
        *head = (*head)->next;
        free(current);
        return;
    }

    int n = 0;
    while (current != NULL && n < index) 
    {
        tmp = current;
        current = current->next;
        n++;
    }

    if (current == NULL) 
    {
        return;
    }

    tmp->next = current->next;
    free(current);
}

//zad5
void remove_by_value(node_t ** head, int value)
{
    node_t * current = *head;
    node_t * tmp = NULL;

    if (current->val == value ) // dla pierwszego elementu
    {
        *head = (*head)->next;
        free(current);
        return;
    }

    while (current->val != value) 
    {
        if (current->next == NULL)
        {
            return;
        }
        tmp = current;
        current = current->next;
    }
    
    tmp->next = current->next;   
    free(current);
}

//zad6
void add_by_index(node_t ** head, int index, int value)
{
    node_t * current = *head;
    node_t * tmp = NULL;

    if (index == 0 || current == NULL) // dla pierwszego elementu
    {
        add_first(head, value);
        return;
    }

    int n = 0;
    while (current != NULL && n < index) 
    {
        tmp = current;
        current = current->next;
        n++;
    }

    if (current == NULL) 
    {
        return;
    }

    node_t * newElem = (node_t *) malloc(sizeof(node_t));
    newElem->val = value;
    newElem->next = current;
    
    tmp->next = newElem;
}

void print_list(node_t * head) 
{
    node_t * current = head;

    while (current != NULL) 
    {
        printf("%d\n", current->val);
        current = current->next;
    }
}

