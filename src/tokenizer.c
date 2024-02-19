#include <stdio.h>
#include <stdlib.h>
#include <tokenizer.h>
#include <history.h>


//returns true if char c is a whitespace char or \t
int space_char(char c)
{
   if((c == ' ' || c == '\t' ) && c != '\0')
   {
      return 1;
   }
   return 0;
}

// returns true if the char c is a nonspace char being: ' ', '\t', or '\0'
int non_space_char(char c)
{
   if((c == ' ' || c == '\t' ) || c == '\0')
   {
      return 0;
   }
   return 1;
}

//returns a pointer to the next word in a string (pointer to the next char after a ' ' or '\t' )
char *token_start(char *str)
{
    int i = 0;
    while(*(str + i))
    {
        if(non_space_char(*(str +i)))//dereferencing *str to see what is in str at the current address of str + i // could use == 1 but in c 1 or 0 are the values for true or flase so it is not needed
        {
            return str + i;
        }
        i++;
    }
        return str + i;
}

//returns a pointer to the next blank space or \t after the token passed 
char *token_terminator(char *token)
{
int i = 0;
    while(*(token + i))
    {
        if(space_char(*(token +i)))//dereferencing *token to see what is in token at the current address of token + i
        {
            return token + i;
        }
        i++;
    }
        return token + i;    
}

int count_tokens(char *str)
{
 int count = 0;
 char *temp = str;
 temp = token_start(temp);
 while(*temp)
 {
    
 }

}
