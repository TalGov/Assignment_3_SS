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
    size_t size;
    struct Node* head;
};

/*
 * Allocates a new empty StrList.
 * It's the user responsibility to free it with StrList_free.
 */
StrList* StrList_alloc()
{
    // allocating the memory for the Strlist
    StrList* s= (StrList*)malloc(sizeof(StrList));
    if(s == NULL) // if the allocation failed
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
    // allocation for the node struct
    Node* n= (Node*)malloc(sizeof(Node));
    if(n == NULL) // check for failed allocation
    {
        printf("Error Node alloc!");
        return 0;
    }
    // allocating for the String data
    n->string = (char*) malloc(strlen(data) + 1);
    if(n->string == NULL) // checking for failed allocation
    {
        printf("Error Node->String alloc!");
        return 0;
    }
    strcpy(n->string,data); // putting the data
    n->next = next; // the next node of the current node
    return n;
}

/*
 * Frees the memory and resources allocated to StrList.
 * If StrList==NULL does nothing (same as free).
 */
void StrList_free(StrList* StrList)
{
    if(StrList_size(StrList) == 0)
    {
        return;
    }
    while(StrList->head)
    {
        StrList_removeAt(StrList, 0);
    }
}

/**
 * Free the memory of the node
 */
void Node_free(Node* n)
{
    if (n == NULL) // Check if n is NULL
    {
        return;
    }

    free(n->string); // Free the string separately because it was allocated dynamically
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
    char* temp_data = strdup(data); //convert const char to char
    Node* n = Node_alloc(temp_data, NULL);
    free(temp_data);

    if (n == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    // check for failed allocation
    if(StrList->head == NULL)
    {
        StrList->head = n;
    }
    else
    {
        Node* last_Node = StrList->head;

        // last Node's next address will be NULL
        while(last_Node->next != NULL)
        {
            last_Node = last_Node->next;
        }

        // add the node at the end
        last_Node->next = n;
    }
    StrList-> size++; // incrementing the size by one
}

//Inserts an element at given index
void StrList_insertAt(StrList* StrList,const char* data,int index)
{
    Node* current = StrList->head;
    Node* next_node = NULL;
    // reach the wanted index - 1
    for (int i = 0; i < index - 1; i++)
    {
        next_node = current->next;
        current = next_node;
    }
    // store the wanted index
    next_node = current->next;

    // create a new node containing the data
    char* temp_data = strdup(data); //convert const char to char
    Node* new_node = Node_alloc(temp_data, NULL);
    free(temp_data);
    if (new_node == NULL)
    {
        printf("Node allocation failed");
        return;
    }

    // put the new node as child to the node index -1
    current->next = new_node;
    // put the child of the new node to be the node at index
    new_node->next = next_node;

	StrList->size += 1;
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
    // iterating through all the nodes
    while(p)
    {
        // print the stringsoter in the node
        printf("%s", p->string);
        if (p->next)
        {
            printf(" ");
        }
        p = p->next;
    }
	printf("\n");
}

//Prints the word at the given index to the standard output.
void StrList_printAt(const StrList* Strlist,int index)
{
    Node* n = Strlist->head;
    int i = 0;
    while (n) // iterating through the node until we reach NULL (the end of the linked list)
    {
        if (i == index) // if this node is the one wanted
        {
            printf("%s\n", n->string);
            return;
        }
        i++;
        n = n->next;
    }
}

//Return the amount of chars in the list.
int StrList_printLen(const StrList* Strlist)
{
    Node * current = Strlist->head;
	int count = 0; // char counter
	while (current)
	{
		count += (int)strlen(current->string); // using the built-in strlen function
		current = current->next;
	}

	return count;
}

//Given a string, return the number of times it exists in the list.
int StrList_count(StrList* StrList, const char* data)
{
	Node * current = StrList->head;
	int count = 0;
	while (current)
	{
		if (strcmp(current->string, data) == 0) // comparing using the built-in String comparison
		{
			count += 1;
		}
		current = current->next;
	}
	return count;
}

/*
 * Given a string and a list, remove all the appearances of this string in the list.
 */
void StrList_remove(StrList* StrList, const char* data)
{
	// iterating over all the nodes
	Node* current = StrList->head;
	Node* next_node = current->next;
	int index = 0;
	while (current)
	{
		// if the current node data is equal to the deleted string
		if (strcmp(current->string, data) == 0)
		{
			StrList_removeAt(StrList, index);
			current = next_node;
		}
		else
		{
			index +=1;
			current = current->next;
		}
		if (current)
		{
			next_node = current->next;
		}
	}
}

/**
 * Given an index and a list, remove the string at that index.
 */
void StrList_removeAt(StrList* StrList, int index)
{
    if (StrList_size(StrList) == 0)
    {
        return;
    }
	Node* current = StrList->head;
	Node* next_node = NULL;
	Node* prev = NULL;
	// reach the wanted index
	for (int i = 0; i < index; i++)
	{
		next_node = current->next;
		prev = current;
		current = next_node;
	}

	// putting his prev child to be his next child
	if (prev == NULL){ // mean we are deleting the head
		StrList->head = current->next;
	}
	else
	{
		prev->next = current->next;
	}

	// free the skipped node
	Node_free(current);
	StrList->size -= 1;
}

/**
 * Checks if two StrLists have the same elements
 * returns 0 if not and any other number if yes
 */
int StrList_isEqual(const StrList* StrList1, const StrList* StrList2)
{
    const int _equal= 1;
    const int _notequal= 0;


    if (StrList1 == NULL && StrList2 == NULL)
    {
        return _equal;
    }

    const Node* h1= StrList1->head;
    const Node* h2= StrList2->head;

    while(h1) // as long as there is nodes left
    {
        if (strcmp(h1-> string, h2->string) != 0) // if the two node do not contain the same string
        {
            return _notequal;
        }
        h1= h1->next;
        h2= h2->next;
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
    const Node* old = StList->head;
    Node** copy = &(copyS->head); // copy the head
    if(copy == NULL)
    {
        printf("Clone memory allocation failed");
        return NULL;
    }

    copyS->size = StrList_size(StList); // copying the size

    char* str;
    while(old)
    {
        str = (char*)malloc(strlen(old->string)+1); // deepcopy the String
        if (str == NULL)
        {
            printf("Error allocating memory for string in StrList_clone\n");
            StrList_free(copyS); // Free memory allocated so far
            return NULL;
        }
        strcpy(str, old->string);
        *copy= Node_alloc(str, NULL);
        if (*copy == NULL)
        {
            printf("Error allocating memory for node in StrList_clone\n");
            free(str); // Free memory allocated for string
            StrList_free(copyS); // Free memory allocated so far
            return NULL;
        }
        old= old->next;
        copy= &((*copy)->next);
        free(str);
    }
    return copyS;
}

//Reverses the given StrList.
void StrList_reverse( StrList* StrList)
{
    if (StrList_size(StrList) == 0)  // if the size is zero do nothing
    {
        return;
    }
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
// simple swap function of strings
void swap(char** xp, char** yp)
{
	char* temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// 00Bubble Sort
void sort_array(char * array[], int n)
{
	int i, j;
	int swapped = 0;
	for (i = 0; i < n - 1; i++) {
		swapped = 0;
		for (j = 0; j < n - i - 1; j++) {
			if (strcmp(array[j], array[j + 1]) > 0) {
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}
		}

		// If no two elements were swapped by inner loop,
		if (swapped == 0)
			break;
	}
}



//Sort the given list in lexicographical order
void StrList_sort( StrList* StrList)
{
	// extracting all the string into an array
	char* array[StrList_size(StrList)];

	Node* current = StrList->head;
	for (int i = 0;current; i += 1)
	{
		array[i] = current->string;
		current = current->next;
	}

	// sorting the array with an helper function
	sort_array(array, (int)StrList_size(StrList));

	// putting back all the data in the right order
	current = StrList->head;
	for (int i = 0;current; i += 1)
	{

		current->string = array[i];
		current = current->next;
	}

}

/**
 * Checks if the given list is sorted in lexicographical order
 * returns 1 for sorted,   0 otherwise
 */
int StrList_isSorted(StrList* StList)
{
    StrList* s = StrList_clone(StList); // cloning the inputed list
    StrList_sort(s); // sorting the cloned list
    if (s == NULL){
        return 0;
    }

    int result = StrList_isEqual(StList,s ); // if the sorted version is equal to the original StrList

    StrList_free(s);
    free(s);
    return result;
}
