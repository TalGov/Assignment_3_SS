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
    s->head= NULL;
    s->size= 0;
    return s;
}

node* Node_alloc(char data[MAX_STRING_SIZE],node* next)
{
    node* n= (node*)malloc(sizeof(node));
    n->string = data;
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
    node* n1= StrList->head;
    node* n2;

    while(n1)
    {
        n2 = n1;
        n1= n1->next;
        Node_free(n2);
    }
    free(StrList);
}

void Node_free(node* n)
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
    node* next = NULL;
    node* n = Node_alloc(temp_data, next);

    if(StrList->head->string == NULL)
    {
        StrList->head = n;
        StrList-> size++;
    }
    else
    {
        node* last_Node = StrList->head;

        //last node's next address will be NULL
        while(last_Node->next != NULL)
        {
            last_Node = last_Node->next;
        }

        //add the newNode at the end of the linked list
        last_Node->next = n;
    }

    Node_free(n);
}

//Inserts an element at given index
void StrList_insertAt(StrList* StrList,const char* data,int index)
{

}

//Returns the StrList first data.
char* StrList_firstData(const StrList* StrList)
{
    return StrList->head->string;
}

//Prints the StrList to the standard output.
void StrList_print(const StrList* StrList)
{

}

//Prints the word at the given index to the standard output.
void StrList_printAt(const StrList* Strlist,int index)
{

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
    return 0;
}

/*
 * Clones the given StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_clone(const StrList* StrList)
{
    return 0;
}

//Reverces the given StrList.
void StrList_reverse( StrList* StrList)
{

}

//Sort the given list in lexicographical order
void StrList_sort( StrList* StrList)
{

}

/*
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StrList)
{
    return 0;
}
