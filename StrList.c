#include <stdio.h>
#include <string.h>
#include "StrList.h"

struct Node
{
    char* string;
    struct Node* next;
};

struct _StrList
{
    int size;
    struct Node* head;
};

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc()
{
    StrList* s= (StrList*)malloc(sizeof(StrList));
    if(s == NULL)
    {
        printf("Error StrList alloc!");
        return 0;
    }
    s->head= NULL;
    s->size= 0;
    return s;
}

Node* Node_alloc(char data[MAX_STRING_SIZE], Node* next)
{
    Node* n= (Node*)malloc(sizeof(Node));
    if(n == NULL)
    {
        printf("Error Node alloc!");
        return 0;
    }
    n->string = (char *)malloc(strlen(data)+1);
    n->next= next;
    return n;
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList)
{
    if (StrList == NULL)
    {
        return;
    }
    Node* n1= StrList->head;
    Node* n2;

    while(n1)
    {
        n2 = n1;
        n1= n1->next;
        Node_free(n2);
    }
    free(StrList);
}

void Node_free(Node* n)
{
    free(n);
}

//Returns the number of elements in the StrList.
size_t StrList_size(const StrList* StrList)
{
    return StrList->size;
}

//Inserts an element in the end of the StrList.
void StrList_insertLast(StrList* StrList,const char* data)
{
    ///////////todo////////////

    char* temp_data = strdup(data); //covert const char to char
    Node* n = Node_alloc(temp_data, NULL);

    if(StrList->head == NULL)
    {
        StrList->head = n;
    }
    else
    {
        Node* last_Node = StrList->head;

        //last Node's next address will be NULL
        while(last_Node->next != NULL)
        {
            last_Node = last_Node->next;
        }

        //add the newNode at the end of the linked list
        last_Node->next = n;
    }

    StrList-> size++;
}

//Inserts an element at given index
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    Node* current = StrList->head;
    Node* next_node = NULL;
    // reach the wanted index - 1
    for (int i = 0; i < index; i++)
    {
        next_node = current->next;
        current = next_node;
    }
    // store the wanted index
    next_node = current->next;

    // create a new node containing the data
    char* temp_data = strdup(data); //covert const char to char
    Node* new_node = Node_alloc(temp_data, NULL);

    // put the new node as child to the node index -1
    current->next = new_node;
    // put the child of the new node to be the node at index
    new_node->next = next_node;
}

//Returns the StrList first data.
char* StrList_firstData(const StrList* StrList)
{
    return StrList->head->string;
}

//Prints the StrList to the standard output.
void StrList_print(const StrList* StrList)
{
    const Node* p= StrList->head;

    while(p)
    {
        printf("%s->",p->string);
        p = p->next;
    }
    printf("size:%d\n ",StrList->size);
}

//Prints the word at the given index to the standard output.
void StrList_printAt(const StrList* Strlist,int index)
{
    Node* n = Strlist->head;
    int i = 0;

    while (n != NULL)
    {
        if (i == index)
        {
            printf("The string in index %d is : %s",index, n->string);
        }
        i++;
        n = n->next;
    }
}

//Return the amount of chars in the list.
int StrList_printLen(const StrList* Strlist)
{
    return 0;
}

//Given a string, return the number of times it exists in the list.
int StrList_count(StrList* StrList, const char* data)
{
    return 0;
}

//Given a string and a list, remove all the appearences of this string in the list.
void StrList_remove(StrList* StrList, const char* data)
{


}

//Given an index and a list, remove the string at that index.
void StrList_removeAt(StrList* StrList, int index)
{

}

/*
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    const int _equal= 1;
    const int _notequal= 0;

    const Node* h1= StrList1->head;
    const Node* h2= StrList2->head;

    while(h1)
    {
        if (h2==NULL || h1-> string != h2->string)
        {
            return _notequal;
        }
        h1= h1->next;
        h2= h2->next;
    }
    if (h2 != NULL)
    {
        return _notequal;
    }

    return _equal;
}

/*
 * Clones the given StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StList)
{
    StrList* copyS= StrList_alloc();
    const Node* old= StList->head;
    Node** copy= &(copyS->head);

    copyS->size= StList->size;

    while(old)
    {
        *copy= Node_alloc(old->string,NULL);
        old= old->next;
        copy= &((*copy)->next);
    }
    return copyS;
}

//Reverses the given StrList.
void StrList_reverse( StrList* StrList)
{
    Node* prev = NULL;
    Node* current = StrList->head;
    Node* next = current->next;

    while(next != NULL)
    {
        // we put the previous node to be the pointer to the current
        current->next = prev;

        // we move all the pointer to the next node
        prev = current;
        current = next;
        next = current->next;
    }

    // we reached the last node
    current->next = prev;
    StrList->head = current;
}

//Sort the given list in lexicographical order
void StrList_sort( StrList* StrList)
{

}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StList)
{
    StrList* s = StrList_clone(StList);
    StrList_sort(s);

    if(StrList_isEqual(StList,s ))
    {
        return 1;
    }
    return 0;
}
