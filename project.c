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
    headMessage("ADD NEW BOOKS");
}
void search ()
{
    int id;
    ListNodePtr current = startPtr;
     headMessage("SEARCH");
    if(startPtr == NULL)
    {
        printf("\n\t\t\tList is Empty\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("\n\t\t\tEnter Id :");
        scanf("%d",&id);
        system("cls");
         headMessage("SEARCH");
        while (current != NULL)
        {
            if (current->l.id == id)
            {
                printf ("\n\t\t\tbook_Name: %s\n", current->l.bookname);
                printf ("\t\t\tID Number: %d\n", current->l.id);
                printf ("\t\t\tauthor_name: %s\n", current->l.author);
                printf ("\t\t\tprice: %.2f\n", current->l.price);
                system("pause");
                system("cls");
                return;
            }
            current = current->nextPtr;
        }
        if(current==NULL)
        {
            printf("\n\t\t\tId Not found\n");
            system("pause");
            system("cls");
        }

    }
}
void exitMessage()
{
    headMessage("faculty of engineering  shoubra banha");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WITH                      =");
    printf("\n\t\t\t        =                  OUR                      =");
    printf("\n\t\t\t        =                  BEST                     =");
    printf("\n\t\t\t        =                 WISHES                    =");
    printf("\n\t\t\t        =                GOOD LUCK                  =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n                          ");
}
