 
//  #include <Arduino.h>
 
//   byte second = epoch%60; epoch /= 60;
//   byte minute = epoch%60; epoch /= 60;
//   byte hour   = epoch%24; epoch /= 24;

//   unsigned int years = epoch/(365*4+1)*4; epoch %= 365*4+1;
//   unsigned int year;
//   for (year=3; year>0; year--)
//   {
//       if (epoch >= days[year][0])
//           break;
//   }

//   unsigned int month;
//   for (month=11; month>0; month--)
//   {
//       if (epoch >= days[year][month])
//           break;
//   }

//   year  = years+year;
//   month = month+1;
//   unsigned int day   = epoch - days[year][month]+1;

//   unsigned int weekday  = (dayOfMonth += month < 3 ? year-- : year - 2, 23*month/9 + dayOfMonth + 4 + year/4- year/100 + year/400)%7;