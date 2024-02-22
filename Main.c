#include <stdio.h>
#include "StrList.h"


int main()
{
    int choice;
    int num;
    char data[MAX_STRING_SIZE];
    int index;
    StrList* SList = StrList_alloc();
	size_t size;
	int count;

    while(1)
    {
        scanf("%d", &choice);

        //using in switch case
        switch (choice)
        {
            case 1:
                scanf("%d", &num);

                for(int i=0; i< num; i++)
                {
                    scanf("%s", data);
                    StrList_insertLast(SList, data);
                }
                break;

            case 2: // insert at
                scanf("%d", &index);
                scanf("%s", data);
                StrList_insertAt(SList,data,index);
                break;

            case 3:
                StrList_print(SList);
                break;

            case 4:
                size = StrList_size(SList);
				printf("%d\n",(int)size);
                break;

            case 5:
                scanf("%d", &index);
                StrList_printAt(SList,index);
                break;

            case 6:
                count = StrList_printLen(SList);
				printf("%d\n", count);
                break;

            case 7:
                scanf("%s", data);
                count = StrList_count(SList,data);
				printf("%d\n", count);
                break;

            case 8 :
                scanf("%s", data);
                StrList_remove(SList,data);
                break;

            case 9:
                scanf("%d", &index);
                StrList_removeAt(SList,index);
                break;

            case 10:
                StrList_reverse( SList);
                break;

            case 11:
                StrList_free(SList);

                break;

            case 12:
                StrList_sort( SList);
                break;

            case 13:
                count = StrList_isSorted(SList);
				if (count == 0)
				{
					printf("false\n");
				}
				else
				{
					printf("true\n");
				}
                break;

            case 0:
                StrList_free(SList);
				free(SList);
                return 0;
        }
    }
}