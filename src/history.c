#include <stdio.h>
#include <stdlib.h>
#include <history.h>

List* init_history()
{
    List *history;//create poiter to Root of list
    history = malloc(sizeof(List));//allocates memory for List since List type is just a pointer of type Item we could use List and Item in the same way as they are the same size
    history->root = NULL;//sets initial root pointer to null will be changed in futher functions
    if(history == NULL)//memory allocation error
    {
        free(history);
        return NULL;
    }
    return history;
}

void add_history(List *list, char *str)
{
    int pos_id = 1;//creates position id at 1 to correctly assign it for later additions
    Item *temp = list->root;//creates new Item named temp a copy of the root of the list
    while(temp)//traverses the array forward to get the position id of the new node and to move us to the tail of the list to add new Item
    {
        temp = temp->next;
        pos_id++;
    }
    temp = malloc(sizeof(Item));//alloctes memory for new Item at the end of the list 
    temp->id = pos_id;//assign pos_id to new Item 
    temp->str = str;//stores token into the Item str variable
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
        return;
    else
    {
        Item *temp = list->root;//copy root into temp
        while(temp)//while temp is not null
        {
            printf("Item %d: %s\n", temp->id,temp->str);
            temp = temp->next;//move to ext Item
        }
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




