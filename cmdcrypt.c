#include "cmdcrypt.h"

/* -h for hash, -c for check hash. */
int main(int argc, char *argv[])
{

   /* The input buffer. We need 2 more than allowed since last char will be newline
    * which will break the while loop. Then it will print the buffer, but if the
    * buffer does not have the newline then we get garbage.
    */
   char input[12] = {0}; // 0 to 11
   char hashed_value[1000] = {0};
   const char *pref = "bcrypt,a";

   /* If no command line arguments, then take input from stdin. */
   if ( argc == 1 )
   {
      int counter = 0;

      while ( (input[counter++] = getchar()) != '\n')
      {
         // If we get to 11 then our buffer is full.
         if ( counter > 10 )
         {
            printf("\n\nERROR: 10 chars exceeded!\n\n");
            exit ( 1 );
         }
      }


      //printf("\nYou entered: %s", input);
      crypt_newhash(input, pref, hashed_value, sizeof(hashed_value));
      //printf("hashed value is: %s\n\n", hashed_value);
      printf("%s", hashed_value);

      printf("\n\n");
   }
   else if ( argc == 2 )
   {
      printf("\n\nInput = %s\n\n", argv[1]);
   }
   else
   {
      printf("\n\nUsage: blah blah\n\n");
   }


/*
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
*/


   return 0;
}
