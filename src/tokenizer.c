#include <stdio.h>
#include <stdlib.h>
//#include <tokenizer.h>

int main()
{
  char string[25];
  printf("Enter String to be tokenized\n");
  printf("> ");
  scanf("%[^\n]", string);//takes in input until it encounters a new line i.e. the end of a string
  printf("%s\n", string);

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

}


void print_tokens(char **tokens)
{


}


void free_tokens(char **tokens)
{


}
