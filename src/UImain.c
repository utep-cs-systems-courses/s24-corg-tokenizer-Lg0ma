#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main()
{
    List *history = init_history();
    char string[100];
    char *token;
    char select;
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
            print_tokens(tokens);
            add_history(history, *tokens);
            break;
        case '2':
            print_history(history);
            break;
        case '3':
            printf("Enter pos_id for item you are looking for\n");
            int pos;
            scanf(" %d", &pos);
            token = get_history(history,pos);
            int i;
            printf("Item of id: %d\n", pos);
            printf("\n");
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
