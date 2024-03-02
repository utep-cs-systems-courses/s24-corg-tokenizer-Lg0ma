#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#define MAXTOKENS 100

List* init_history()
{
    List *history = (List*)malloc(sizeof(List));//allocates memory for List
    if(history != NULL)
    {
        history->root = NULL;
    }
    return history;
}

void add_history(List *list, char *str)
{
    static int pos_id = 1;//declare variable pos_id to keep count of items to use count as item id
    Item *new_item = (Item*)malloc(sizeof(Item));//create and allocate memory for new_item
    if(list == NULL)//handle memory allocation failure
    {
        fprintf(stderr,"Memory allocation Failed\n");
        return;
    }

    int len = 0;//create lenn var to store str length
    while(str[len] != '\0')//iterate through str until the zero terminator
    {
        len++;//increase len by 1
    }

    new_item->str = (char*)malloc((len + 1) * (sizeof(char)));//allocate memory to str based on the length of the string
    if(new_item == NULL)//handle memory allocation failure
    {
        fprintf(stderr,"new_item->str Memory allocation Failed\n");
    }

    for(int i =0;  i < len; i++)//iterate through str 
    {
        new_item->str[i] = str[i];//copy str into new_item->str one char at a time
    }
    new_item->next = NULL;//set next to NULL
    
    if(list->root == NULL)//if list is empty
    {
        new_item->id = pos_id;//set new_item id to pos_id
        list->root = new_item;//set new_item to list->root
    }
    else//else list has items in it 
    {
        Item *list_cpy = list->root;//create a copy of list root
        while (list_cpy->next != NULL)//iterate through the copy until there is no next pointer
        {
            list_cpy = list_cpy->next;//set list to next pointer
        }
        new_item->id = list_cpy->id + 1;// set new_item id 
        list_cpy->next = new_item;//assign list->next to the new_item
        
    }
    pos_id++;
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
    if(list->root == NULL || list == NULL)//if list is empty return
      printf("Nothing is in the history");
      return;
    {

        Item *temp = list->root;//copy root into temp
        printf("Printing History: \n");
        while(temp != NULL)//while temp is not null
        {
            if(temp->str != NULL)//chek if str is null or not
            {
                printf("[ID:[%d] : %s]", temp->id, temp->str);//print id and item->str associated with id
                temp = temp->next;//move temp to next 
            }
            else
            {
                printf("[ID:[%d] : NULL]", temp->id);//print id and NULL for when last item is met
 
            }
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

//testing main
// int main()
// {
//     List *history = init_history();
//     add_history(history,"hello");
//     add_history(history,"hello");
//     print_history(history);
//     return 0;

// }
