//Program2 by Andy Stevens
//dated 1-30-15


#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MONTHROW -1  //to print month and year
#define WEEKROW 0 //to print days of the week
#define MONTHOVER -2 //to indicate that there are no more days left to print



/*
	leap function checks the given year and returns true if the year is a leap year, else false
*/
int leap( int year )
{
 	if ((year % 400 == 0) || ( year % 4 == 0 ) && (year % 100 != 0) )
 	{
 		return TRUE; 
 	}
 	return FALSE; 
}

/*
	daysInMonth function takes in given month and year and uses a switch and cases to return the number of days in the month
	  calls leap() if month is february to check for leap year
*/
int daysInMonth(int month, int year)
{
	int max;
	switch ( month )
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			max = 31;
			break;

		case 2:
			if (leap(year))
			{
				max = 29;
			}
			else
			{
				max = 28;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			max = 30;
			break;
	}
		return max;
}

/*
	zeller function takes in the day, month, and year and returns a number that corrseponds to what
	day of the week the given date was/will be on
*/
int zeller(int month, int day, int year)
{
	int newYear = year;
	int q = day;
	int M = month;
	if (M < 3)
	{
		M += 12;
		newYear -= 1;
	}

	//using all variable names from given algorithm: D = (q + [(M+1)*2.6]+K+[K/4]+[J/4]-2*J ) mod 7 
	int K = (newYear % 100);
	int J = (newYear / 100);
	int mPlus = (M + 1) * 2.6;
	int kDivided = K/4;
	int jDivided = J/4;
	int twoJ = -2 * J;
	int sum = (int) (q + mPlus + K + kDivided + jDivided + twoJ);
	int D = (sum % 7);
	if (D < 0)
	{
		D += 7;
	}
	return D;
}

/*
	Month function validates that the given month is between 1-12, and returns T/F
*/
int Month(int month, int year)
{
	if (month < 1 || month > 12 )
		return FALSE;
	else
		return daysInMonth(month, year);
}

/*
	Year function validates that the given year is at least 1582
*/
int Year(int year)
{
	if (year < 1583)
		return FALSE;
	else
		return TRUE;
}

/*
	PrintRow function takes a startDate, month, and year.  
	It could print: a Month and Year (days in month) header,
	  a Saturday through Friday header, print one line of the month starting with 
	  startDate or up to the last day of the month, or a row of spaces to even out the 3x4 pattern
*/
int printRow( int startDate, int month, int year)
{
	char days[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	char months[12][10] = {"January", "February", "March","April","May","June","July","August","September","October","November","December"};
	int endDate = 0; //used to return the last day printed or that the month is complete
	int dayOfWeek;  //used to store the zeller number

	if (startDate == MONTHOVER) //print a blank row so next month can start in correct place
	{
		printf("                            ");   
		return MONTHOVER;
	}
	else if (startDate == MONTHROW)  //print month and year header row
	{
		printf(" %10s %4d (%2d days) ", months[(month-1)], year, daysInMonth(month, year));
		endDate = startDate + 1;
	}
	else if (startDate == WEEKROW)  //print days of the week row
	{
		for (int day = 0; day < 7; day++)
		{
			printf("%c%c  ", days[day][0], days[day][1]);
			endDate = startDate + 1;
		}	
	}
	else if (startDate == 1)  //only start printing numbers from zeller to 7
	{
		endDate = 1;
		dayOfWeek = zeller(month, startDate, year);  //get zeller number
		for (int day = 0; day < 7; day++)
		{
			if ( day >= dayOfWeek ) //start displaying the day of the month
			{
				printf("%2d  ", endDate);
				endDate += 1;  //printed a day, so increment endDate by one
			}
			else  //not displaying a number here, place spaces to advance for the next day
			{
				printf("    ");
			}
		}
	}
	else //starting to go straight across the week till we reach the end of week or the last day of the month
	{
		endDate = startDate;
		for (int day = 0; (day < 7); day++)  //only display one week
		{
			//check to make sure that there are still days left to display, and that the month is not over
			if ( (endDate <= daysInMonth(month,year)) && ( endDate != MONTHOVER ) ) 
			{
				printf("%2d  ", endDate);
				endDate += 1;
			}
			else  //done printing days, so print blank spaces
			{
				printf("    ");
				endDate = MONTHOVER;
			}
		}
	}
	
	return endDate;
}


int main()
{
	char days[7][10] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
	int test = leap(2000);
	int done = FALSE;
	int lastDayPrinted;
	int lastDayPrinted1;
	int lastDayPrinted2;
	int lastDayPrinted3;
	int endCurrentMonth = FALSE;

	printf("%d\n", test);

	printf("M D Y: ");
	int month, day, year;  //used to display the calendar and/or day of the week
	do{
		scanf("%d %d %d", &month, &day, &year);  //take in 3 inputs for month, day, and year

		int falseOrDaysInMonth = Month(month, year); //
		int isValidYear = Year(year);

		if ( (day == 0) && (month == 0) && (year == 0))  //end loop condition
			done = TRUE;

		else if ( !isValidYear )  //check to see if year is valid
		{
			printf("Invalid year\n");
		}
		else if ( (day == 0) && (month == 0))  //display entre year calendar in 3*4 format
		{
			month = 1;  //set month to one to start in January
			do{
				//print year calendar in 3*4 format by calling printRow 3 times in a row before ending the line
				lastDayPrinted1 = MONTHROW; //set to display month header first for all three months
				lastDayPrinted2 = MONTHROW;
				lastDayPrinted3 = MONTHROW;
				do{
					lastDayPrinted1 = printRow(lastDayPrinted1, month, year);  //print one row for each of three months at a time
					printf("   ");
					lastDayPrinted2 = printRow(lastDayPrinted2, month + 1, year);
					printf("   ");
					lastDayPrinted3 = printRow(lastDayPrinted3, month + 2, year);
					printf("   ");

					//if all three months have been displayed, set variable to TRUE and end current do/while loop
					if ((lastDayPrinted1 == MONTHOVER) && (lastDayPrinted2 == MONTHOVER) && (lastDayPrinted3 == MONTHOVER))
					{
						endCurrentMonth = TRUE;
					}
					printf("\n");  //advance one row
				} while( !endCurrentMonth );  //keep iterating till all three months have no days left to print

				month += 3;  //advance month by 3 to start next cylce of see if done
				endCurrentMonth = FALSE; //set back to false for next cycle
			}while ( month < 12 ); 
		}
		else if ( (day == 0 ) && (month < 13) ) //print month calendar
		{
			lastDayPrinted = MONTHROW;//set to display month header first 
			do{
				lastDayPrinted = printRow(lastDayPrinted, month, year);
				printf("\n");
			} while( lastDayPrinted != MONTHOVER );

		}
		else if ( ( falseOrDaysInMonth == 0 ) || ( day > falseOrDaysInMonth ) )  //invalid date
		{
			printf("Invalid date\n");
		}
		else  //display the zeller day of the week
		{
			int zellers = zeller(month,day,year);
			printf("%d/%d/%d is on %s\n", month, day, year, days[zellers]);
		}
	} while ( !done );
	printf("Bye\n");
}
