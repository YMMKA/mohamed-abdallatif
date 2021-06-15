#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
typedef struct list
{
    char bookname[100];
    int id;
    char author[100];
    float price;
} List;
struct listNode
{
    List l;
    struct listNode *nextPtr;
};
typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;
ListNodePtr startPtr = NULL; // initially there are no nodes

// insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, char *bookname,int id,char *author,float price)
{
    ListNode* newPtr =(ListNode*) malloc(sizeof(ListNode)); // create node

    if (newPtr != NULL)   // is space available?
    {
        strcpy(newPtr->l.bookname,bookname);
        newPtr->l.id=id;
        strcpy(newPtr->l.author,author);
        newPtr->l.price=price;
        newPtr->nextPtr = NULL; // node does not link to another node

        ListNodePtr previousPtr = NULL;
        ListNodePtr currentPtr = *sPtr;
// loop to find the correct location in the list
        while (currentPtr != NULL && id > currentPtr->l.id)
        {
            previousPtr = currentPtr; // walk to ...
            currentPtr = currentPtr->nextPtr; // ... next node
        }
// insert new node at beginning of list
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else   // insert new node between previousPtr and currentPtr
        {
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        }
    }
    else
    {
        printf("%d not inserted. No memory available.\n", id);
    }
    system("cls");
    headMessage("MAIN MENU");
}
void search ()
{
    int id;
    ListNodePtr current = startPtr;
    if(startPtr == NULL)
    {
        printf("\n\t\t\tList is Empty\n") ;
    }
    else
    {
        printf("\n\t\t\tEnter Id :");
        scanf("%d",&id);
        while (current != NULL)
        {
            if (current->l.id == id)
            {
                printf ("\n\t\t\tbook_Name: %s\n", current->l.bookname);
                printf ("\n\t\t\tID Number: %d\n", current->l.id);
                printf ("\n\t\t\tauthor_name: %s\n", current->l.author);
                printf ("\n\t\t\tprice: %f\n", current->l.price);
                return;
            }
            current = current->nextPtr;
        }
        if(current==NULL)
        {
            printf("\n\t\t\tId Not found\n");
        }

    }
}
