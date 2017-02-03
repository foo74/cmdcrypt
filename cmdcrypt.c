#include <stdio.h>  // for printf(), getchar(), putchar()
#include <stdlib.h> // for exit()
#include <unistd.h>
#include <errno.h>


/* -h for hash, -c for check hash. */
int main(int argc, char *argv[])
{

   char input[10];
   //char a;

   if ( argc == 1 )
   {
      int counter = 0;

      while ( counter < 10 && (input[counter] = getchar()) != '\n' )
      {
         counter++;
         if ( counter == 10 )
         {
            printf("\n\nERROR: 10 chars exceeded!\n\n");
            exit ( 1 );
         }
      }

      printf("\nYou entered: %s", input);

      printf("\n\n");
   }
   else
   {
      int result = -1;

      const char *mypass = "hello";
      const char *wrongpass = "hello2";
      char hashed_value[1000] = {0};

      printf("\n\npassword is: %s\n", mypass);
      crypt_newhash(mypass, NULL, hashed_value, sizeof(hashed_value));
      printf("hashed value is: %s\n\n", hashed_value);

      printf("checking rightpass");
      result = crypt_checkpass(mypass, hashed_value);

      if ( result == 0 )
         printf("\nSUCCESS\n\n");
      else
         printf("\nFAILURE\n\n");

      printf("checking wrongpass");
      result = crypt_checkpass(wrongpass, hashed_value);

      if ( result == 0 )
         printf("\nSUCCESS\n\n");
      else
         printf("\nFAILURE\n\n");
   }

   return 0;
}
