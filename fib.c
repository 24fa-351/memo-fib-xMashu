#include <stdio.h>
#include <stdlib.h>

long long int iterativeCore(long long int nThTerm)
{
   if (nThTerm == 0)
   {
      return 0;
   }
   else if (nThTerm == 1)
   {
      return 1;
   }

   long long int current = 1;
   long long int prev = 0;
   long long int next = 0;
   for (int i = 1; i < nThTerm; ++i)
   {
      next = prev + current;
      prev = current;
      current = next;
   }
   return current;
}

long long int recursionCore(long long int nThTerm)
{
   if (nThTerm == 0)
   {
      return 0;
   }
   else if (nThTerm == 1)
   {
      return 1;
   }
   else
   {
      return recursionCore(nThTerm - 1) + recursionCore(nThTerm - 2);
   }
}

// https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Iterative-Fibonacci.html
//  helped with understanding iterativeCore fib again

long long int iterative_term[5000] = {0}; // 5000 lowkey high and makes it slightly slower

long long int fibIterativeWrapper(long long int nThTerm)
{
   if (nThTerm == 0)
   {
      return nThTerm;
   }

   if (iterative_term[nThTerm] != 0)
   {
      return iterative_term[nThTerm];
   }
   else
   {
      iterative_term[nThTerm] = iterativeCore(nThTerm);
      return iterativeCore(nThTerm);
   }
}

long long int recursive_term[5000] = {0};

long long int fibRecursiveWrapper(long long int nThTerm)
{
   if (nThTerm == 0)
   {
      return nThTerm;
   }
   else if (nThTerm == 1)
   {
      return nThTerm;
   }

   if (recursive_term[nThTerm])
   {
      return recursive_term[nThTerm];
   }
   else
   {
      recursive_term[nThTerm] = fibRecursiveWrapper(nThTerm - 1) + fibRecursiveWrapper(nThTerm - 2);
      return recursive_term[nThTerm];
   }
}

int main(int argc, char *argv[])
{
   if (argc < 3)
   {
      printf("Too few arguments, only need int, r/i, and filename\nThTerm");
      exit(EXIT_FAILURE);
   }

   int commandLineInt = 0;
   sscanf(argv[1], "%d", &commandLineInt);

   char fibOption = *argv[2];
   /*
      char *filename = "test.txt";

      if (argc >= 4)
      {
         filename = argv[3];
      }

      FILE *file = fopen(filename, "r");

      int fileInteger;
      fscanf(file, "%d", &fileInteger);

      fclose(file);
      //Re-add for test.txt if needed
   */
   long long int nThTerm = 0;
   nThTerm = commandLineInt - 1; //+ fileInteger - 1; // add this too if test.txt is added again

   long long int result = 0;

   if (fibOption == 'i')
   {
      result = fibIterativeWrapper(nThTerm);
   }
   else if (fibOption == 'r')
   {
      result = fibRecursiveWrapper(nThTerm);
   }

   printf("%lld\n", result);
}