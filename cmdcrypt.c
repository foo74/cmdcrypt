#include "cmdcrypt.h"

/* potential command args -h for hash, -c for check hash. -pref? for bcrypt,a?  */
void clear_buffer(char buffer[], int size);

/*
 * If no args then loops through and hashes from stdin.
 * 
 */
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
      int i, counter;
      char junk;

      /* Keep looping until control-c. Same as encrypt(). */
      while ( 1 )
      {
         i = 0;
         counter = 0;

         // Fill the buffer 
         while ( counter < 11 && (input[counter] = getchar()) != '\n' && input[counter++] != EOF);

         // If we get to 11 then our buffer is full.
         if ( counter > 10 )
         {
            printf("\n\nERROR: 10 chars exceeded!\n\n");
  
            /* Clear the rest of stdin buffer up until the newline character. Otherwise
             * there is a nasty bug where the stdin buffer flows into the next while
             * loop and we get unexpected hashing behavior.
             */
            while ( ( junk = getchar())  != '\n');

            // Clear buffer.
            clear_buffer(input, sizeof(input));
         }
         else
         {
            crypt_newhash(input, pref, hashed_value, sizeof(hashed_value));
            printf("%s", hashed_value);

            printf("\n\n");
         }

         // Clear buffers.
         clear_buffer(input, sizeof(input));
         clear_buffer(hashed_value, sizeof(hashed_value));
      }
   }
   else if ( argc == 2 )
   {
      printf("\n\nInput = %s\n\n", argv[1]);
   }
   else
   {
      printf("\n\nUsage: blah blah\n\n");
   }

   return 0;
}


/*
 * Clear a buffer array.
 */
void clear_buffer(char buffer[], int size)
{
   int i = 0;
   for ( i = 0; i < size; i++ )
      buffer[i] = 0;
}





/*
EXAMPLE CODE FOR CHECK PASSWORD
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
*/


