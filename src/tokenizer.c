#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *history = init_history();
  char string[25];
  printf("Enter String to be tokenized\n");
  printf("> ");
  scanf("%[^\n]", string);//takes in input until it encounters a new line i.e. the end of a string
  char *token = tokenize(string);
//   print_tokens(token);
  add_history(history,token);
  print_history(history);

  
  
//   char **tokens = tokenize(string);
//   print_tokens(tokens);


  return 0;

}

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
    temp = token_start(temp);// assigns temp the first instance of a nonspace char IE: a pointer to the first token
    while(*temp)//while temp still points to anything other than a terminator pointer loop
    {
        if(non_space_char(*temp))
        {
            count++;
        }
        temp = token_terminator(temp);//changes temp to the next space, '\t' 
        temp = token_start(temp);//changes temp to the next nonspace char after a space char
    }

    return count;
}

char *copy_str(char *inStr, short len)
{
    char *Str_copy = malloc((len+1)*sizeof(char));// allocates memory for a pointer of type char of size len +1 for all chars in the inStr and a zero-termnator * the size of a char in bytes
    // len + 1 wouldve worked as chars are of size 1 bytes but for good practice we still multiply by sizeof(char)
    int i;
    for(i = 0; i < len; i++)
    {
        Str_copy[i] = inStr[i];// copies the value stored at inStr[i] into the new pointer at Str_copy[i]

    }
    Str_copy[i] = '\0';// ends the copy with a zero-terminator
    return Str_copy;
}


//** is a pointer to a pointer 
// arrays of strings are pointers to pointers of chars 
char **tokenize(char* str)
{
  int num_tokens = count_tokens(str);//number of tokens we will have to tokenize
  char **tokens = malloc(sizeof(char *)* (num_tokens + 1)); //allocate size of tokens array using sizeof(char) times num_tokens + 1 for the '\0' char 
  char *token = str;//copy of the str pointer 

  for (int i = 0; i < num_tokens; i++)//loop that goes for the number of tokens in the str pointer
  {
    token = token_start(token);//moves token pointer to the start of a token in the string
    char *token_end = token_terminator(token);//creates a pointer to the end of the current token
    int len = token_end - token;//gets the length of the token by subtracting the end by the start
    tokens[i] = copy_str(token, len);// copies the token into tokens array at i
    token = token_terminator(token);//token = token_end; could work too    //moves token pointer to the end of the current token
  }
  tokens[num_tokens] = '\0';  //ends the tokens array with a '\0' char
  return tokens;
}


void print_tokens(char **tokens)
{
int i = 0;
while (tokens[i])//traverses the array till reaching the '\0' token
{
    printf("Token #%d: %s\n", i, tokens[i]);//prints token as: Token #i: tokens[i]
    i++;
}
 printf("Token #%d: %s\n",i, tokens[i]);


}


void free_tokens(char **tokens)
{
int i = 0;
while(tokens[i])//traverses the array till reaching the '\0' token
{
    free(tokens[i]);//frees token at i 
    i++;
}

}

