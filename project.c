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
ListNode *Query()
{
    ListNodePtr current = startPtr;

    int id;
    if (startPtr == NULL)
    {
        printf("\t\t\tlinked list is empty.\n");
        printf("\t\t\tPlz Enter Data first into linked list\n");
    }
    else{
 printf("\n\n\t\t\tEnter BOOK ID to search for: ");
    scanf("%u",&id);
        while (current->l.id != id)
        {
            current = current->nextPtr;
            if (current == NULL)
            {
                printf("\t\t\tPlz insert correct ID NO\n");
                return 0;
            }
        }
        return current;
    }
}

int displayQuery()
{
    ListNode *ptr;
    ptr = malloc(sizeof(ListNode));
    ptr = Query();
    printf("\n\t\t\tBook ID NO: %s", ptr->l.bookname);
    printf("\n\t\t\tBOOK Price: %d", ptr->l.id);
    printf("\n\t\t\tBook Name: %s", ptr->l.author);
    printf("\n\t\t\tAuthor Name: %f", ptr->l.price);
    printf("\n\t\t\t_______________________________ BOOK DATA END _______________________________");
    puts("\n");
    return 0;
}
