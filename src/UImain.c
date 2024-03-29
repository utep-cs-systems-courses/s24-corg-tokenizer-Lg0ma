#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
    char string[100];
    char *token;
    char select;
    List *history = init_history();
    printf("Please make a selection for what you want to do\n");
    while(1)
    {
        printf("Enter '1' to tokenize a new string, '2' to print the history, and '3' to find an Item in the history or 'q' to exit\n");
        scanf(" %c", &select);
        switch (select)
        {
        case '1':
            printf("Enter string to be tokenized\n>");
            scanf(" %[^\n]", &string);
            char **tokens = tokenize(string);
            printf("\n");
            add_history(history,&string);
            print_tokens(tokens);
            free_tokens(tokens);
            break;
        case '2':
            print_history(history);
            break;
        case '3':
            printf("Enter pos_id for item you are looking for\n");
            int pos;
            scanf(" %d", &pos);
            printf("Printing History Item of id:%d\n", pos);
            token = get_history(history,pos);
            char **item = tokenize(token);
            print_tokens(item);
            free_tokens(item);
            printf("-------------------------------\n");
            break;
	case 'q':
	  printf("Exiting system...\n");
	  free_history(history);
	  return 0;
        default:
            printf("Wrong input\n");
            break;
        }
        
    }
}
