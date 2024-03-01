#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#define MAXTOKENS 100

List* init_history()
{
    List *history = malloc(sizeof(List));//allocates memory for List
    history->root = NULL;//sets initial root pointer to null will be changed in futher functions
    return history;
}

void add_history(List *list, char *str)
{
    static int pos_id = 0;//declare variable pos_id to keep count of items to use count as item id
    if(list != NULL)//if list exists
    {
        Item *new_item = malloc(sizeof(Item));//declare new item and allocate size
        if(new_item != NULL)//if new_item exists
        {
            new_item->id = pos_id;//set new_items id to pos_id

            int i;
            for(i = 0; i < MAXTOKENS && str[i] != '\0'; i++)//loop till the end of the str array is met or till MAXTOKENS is reached
            {
                new_item->str[i] = str[i];//assign str[i] in new_item to str[i](str array passed as parameter)
            }
            new_item->str[i] = '\0';//end the new_item's str array with zero terminator
            new_item->next = NULL;//set next to NULL

            if(list->root == NULL)//if list has no item in root
            {
                list->root = new_item;//If list has no items in it new_item will be the root
            }
            else
            {
                Item *temp = list->root;//create copy of list->root
                while(temp->next != NULL)//iterate through temp unli the end of the list is met
                {
                    temp = temp->next;//advance to next item in list
                }
                temp->next = new_item;//add new_item to list
            }
            pos_id++;//increase static variable pos_id for next method call
        }
    }
    
}

char *get_history(List *list, int id)
{

    Item *temp;//create temp item for use ahead
    if(!list)//if tlist is empty retun '\0'
        return '\0';
    else
    {
        temp = list->root;// make temp a copy of the root
        while (temp)//while temp is not NULL
        {
            if(temp->id == id)//if id is found return str of item with matching id
            {
                return temp->str;
            }
            temp = temp->next;//move the pointer forward to next Item
        }
        return'\0';//if not found return '\0'
    }
}

void print_history(List *list)
{
    if(!list)//if tlist is empty return
      printf("Nothing is in the history");
    else
    {
        Item *temp = list->root;//copy root into temp
        while(temp)//while temp is not null
        {
	  printf(" %d: %s\n", temp->id,temp->str);
            temp = temp->next;//move to ext Item
        }
	printf("\n");
    }
}

void free_history(List *list)
{
    if(!list)//list is empty so return
    {
        return;
    }
    Item *temp;//temp Item for ease of use
    Item *curr_item = list->root;//current item in list
    while(curr_item)
    {
        temp = curr_item;//copy curr_item into temp
        curr_item = curr_item->next;//move curr_item to next item
        free(temp->str);//free temps str
        free(temp);//free temp
    }
}




