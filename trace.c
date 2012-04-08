/* Tracing tool
 * Ben Matthews <ben@kc2vjw.com>
 * compile your code with gcc -g -finstrument-functions
 * -O0 is also a good idea
 * and link with this file
 */

#include <stdio.h>
#include <execinfo.h>
#include <string.h>
#include <stdlib.h>


/* This function (more or less) stolen from GNU Libc
 * documentation
 * Obtain a backtrace (uncomment for loop to display
 * entire backtrace
 */
void
__attribute__((__no_instrument_function__))
print_trace (void)
{
  void *array[1000];
  size_t size;
  char **strings;
  size_t i;
  size = backtrace (array, 1000);
  strings = backtrace_symbols (array, size);

//  for (i = 0; i < size; i++)
     //printf ("%s\n", strings[i]);
     printf ("funcall: %s\n", strings[2]);

  free (strings);
}

/* Called when functions enter */
void
__attribute__((__no_instrument_function__))
__cyg_profile_func_enter(void* this_function, void* call_site)
{
	print_trace();
	(void) call_site;		
}

/* Called at when functions return() */
void
__attribute__((__no_instrument_function__))
__cyg_profile_func_exit(void* this_function, void* call_site)
{
	(void) call_site;
}
