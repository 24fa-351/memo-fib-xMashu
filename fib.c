#include <stdio.h>


long long int iterative(long long int n)
{
   if (n == 0)
   {
      return 0;
   }
   else if(n == 1)
   {
      return 1;
   }

   long long int current = 1;
   long long int prev = 0;
   long long int next = 0;
   for(int i = 1; i < n; ++i)
   {
      next = prev + current;
      prev = current;
      current = next;
   }
   return current;

}

long long int recursion(long long int n)
{
   if(n == 0)
   {
      return 0;
   }
   else if (n == 1)
   {
      return 1;
   }
   else
   {
      return recursion(n-1) + recursion(n-2);
   }


}

//https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Iterative-Fibonacci.html
// helped with understanding iterative fib again


long long int iterative_term[5000] = {0}; //5000 lowkey high and makes it slightly slower

long long int fib_Iterative_Wrapper(long long int n)
{
      if (n == 0)
   {
      return n;
   }

   if(iterative_term[n] != 0)
   {
      return iterative_term[n];
   }
   else
   {
      iterative_term[n] = iterative(n);
      return iterative(n);

   }


}

long long int recursive_term[5000] = {0};

long long int fib_Recursive_Wrapper(long long int n)
{
   if (n == 0)
   {
      return n;
   }
   else if (n==1)
   {
      return n;
   }


   if (recursive_term[n])
   {
      return recursive_term[n];
   }
   else
   {
      recursive_term[n] = fib_Recursive_Wrapper(n-1) + fib_Recursive_Wrapper(n-2);
      return recursive_term[n];
   }

}




int main(int argc, char *argv[]) {

   int  commandLineInt = 0;
   sscanf(argv[1], "%d", &commandLineInt);
   //https://www.geeksforgeeks.org/c-program-for-char-to-int-conversion/

   char fibOption = *argv[2];
   char *filename = argv[3];


   //scanf("%s", filename);
   FILE *file = fopen(filename, "r"); 
   // https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm


   int fileInteger;
   fscanf(file, "%d", &fileInteger);
   //https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm
   fclose(file);

   long long int n = 0;
   n = commandLineInt + fileInteger -1; 
   // -1 cuz fib has to start at 0




   long long int result = 0;
 
   if(fibOption == 'i')
   {
      result = fib_Iterative_Wrapper(n);
   }
   else if(fibOption == 'r')
   {
      result = fib_Recursive_Wrapper(n);
   }

   printf("%lld\n", result);





}