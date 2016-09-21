#include "NODE.H"
#include "QUEUE.H"
#include "EXTQUEUE.H"

void introduction();
void help();
char get_command();
int do_command(char, Extended_queue &);
 
void main()
/* PRE:  None.
   POST: A linked Queue demonstration has been performed.
   USES: get_command, do_command, class Extended_queue 
                                  (linked implementation) */
{
   Extended_queue test_queue;
   introduction();
   while (do_command(get_command(), test_queue));
}
 
void introduction()
/* PRE:  None.
   POST: Instructions for the Queue testing program are printed */
{
   cout << "\n\t\tExtended Queue Testing Program\n\n"
      << "The program demonstrates an extended queue of "
      << "single character keys. \nAdditions occur at "
      << "the end of the queue, while deletions can only "
      << "be\ndone at the front. The queue can hold a "
      << "any number of characters.\n\n"
      << "Valid commands are to be entered at each prompt.\n"
      << "Both upper and lower case letters can be used.\n"
      << "At the command prompt press H for help.\n\n";
}
 
void help()
/* PRE:  None.
   POST: Instructions for the Queue operations have been printed.     */
{
   char c;
   cout << "\nThis program allows one command to be entered on each line.\n"
      << "For example, if the command S is entered at the command line then\n"
      << "the program will serve the front of the queue."
      << "\nValid commands are:\n"
      << "\tS - Serve the front of the extended queue\n"
      << "\t# - The current size of the extended queue\n"
      << "\tA - Append the next input character to the extended queue\n"
      << "\tC - Clear the extended queue (same as delete)\n"
      << "\tH - This help screen\n"
      << "\tQ - Quit\n"
      << "\tP - Print the extended queue\n"
      << "\tR - Retrieve and print the front entry of the extended queue\n"
      << "Press <Enter> to continue.";
   do {
      cin.get(c);
   } while (c != '\n');
}
 
char get_command()
/* PRE:  None.
   POST: A character command belonging to the set of legal commands for the
         Queue demonstration has been returned.                         */
{
   char c, d;
   cout << "Select command and press <Enter>:";
   while (1) {
      do {
         cin.get(c);
      } while (c == '\n');
      do {
         cin.get(d);
      } while (d != '\n');
      c = tolower(c);
      if (c == 's' || c == '#' || c == 'a' || c == 'c' ||
         c == 'h' || c == 'q' || c == 'p' || c == 'r') {
         return (c);
      }
      cout << "Please enter a valid command or H for help:";
      cout << "\n\t[S]erve  entry\t[P]rint queue\t[#] size of queue\n"
         << "\t[C]lear queue\t[R]irst entry\t[A]ppend entry\n"
         << "\t[H]elp\t[Q]uit.\n";
   }
}
 
int do_command(char c, Extended_queue &test_queue)
/* PRE:  The Extended_queue has been created and c is a valid Queue
         operation.
   POST: The command c has been executed.
   USES: The class Extended_queue.                */
{
   Queue_entry x;
   switch (c) {
   case 'r':
      if (test_queue.retrieve(x) == fail) cout << "Queue is empty.\n";
      else cout << "\nThe first entry is: " << x << endl;
      break;
   case 's':
      if (test_queue.empty()) cout << "Queue is empty.\n";
      else test_queue.serve();
      break;
   case 'a':
      if (test_queue.full()) cout << "Sorry, queue is full.\n";
      else {
         cout << "Enter new key to insert:";
         cin.get(x);
         test_queue.append(x);
      }
      break;
   case 'c':
      test_queue.clear();
      cout << "Queue is cleared.\n";
      break;
   case '#':
      cout << "The size of the queue is " << test_queue.size() << "\n";
      break;
   case 'h':
      help();
      break;
   case 'q':
      cout << "Extended queue demonstration finished.\n";
      return (0);
   case 'p':
      int sz = test_queue.size();
      if (sz == 0) cout << "Queue is empty.\n";
      else {
         cout << "\nThe queue contains:\n";
         for (int i = 0; i < sz; i++) {
            test_queue.retrieve(x);
            test_queue.append(x);
            cout << "  " << x;
            test_queue.serve();
         }
         cout << endl;
      }
      break;
   //  additional cases cover other commands
   }
   return (1);
}
