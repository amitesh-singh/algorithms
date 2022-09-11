#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
   struct tm t = {
        .tm_year = 559444 - 1900, .tm_mon = 2, .tm_mday = 8,
        .tm_hour = 13, .tm_min = 40, .tm_sec = 15, .tm_isdst = -1
   };


   time_t now = time(NULL);
   struct tm *t_now = localtime(&now);

   t = *t_now;
   t.tm_hour = 18;
   t.tm_min = 30;
   t.tm_sec = 0;

   time_t future = mktime(&t);


   double diff_in_sec = difftime(future, now);

   printf("Current time is %s", ctime(&now));
   printf("the future time is %s", ctime(&future));
   printf("the diff in sec from now to future is %f\n", diff_in_sec);


   return 0;
}
