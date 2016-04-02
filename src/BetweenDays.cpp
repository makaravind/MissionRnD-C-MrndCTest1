/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};
int countLeapYears(int day, int mon, int year);
struct node * GetValue(struct node *Startref, int *val, int digicount);
int FindNumberofDays(int day1, int mon1, int year1, int day2, int mon2, int year2);
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL) return -1;

	int day1, day2, mon1, mon2, year1, year2;
	// values for all one 
	struct node *Startref = date1head;
	Startref = GetValue(Startref, &day1, 2);
	Startref = GetValue(Startref, &mon1, 2);
	Startref = GetValue(Startref, &year1, 4);

	// values for all two
	Startref = date2head;
	Startref = GetValue(Startref, &day2, 2);
	Startref = GetValue(Startref, &mon2, 2);
	Startref = GetValue(Startref, &year2, 4);

	return FindNumberofDays(day1, mon1, year1, day2, mon2, year2)-1;	
}
int countLeapYears(int day, int mon, int year)
{
	int years = year;

	if (mon <= 2)
		years--;
	return years / 4 - years / 100 + years / 400;
}
int FindNumberofDays(int day1, int mon1, int year1, int day2, int mon2, int year2){

	int monthDays[] = { 31, 28, 31, 30, 31, 30,
		31, 31, 30, 31, 30, 31 };

	long int n1 = year1 * 365 + day1;

	
	for (int i = 0; i<mon1 - 1; i++)
		n1 += monthDays[i];

	
	n1 += countLeapYears(day1,mon1,year1);

	

	long int n2 = year2 * 365 + day2;
	for (int i = 0; i<mon2 - 1; i++)
		n2 += monthDays[i];
	n2 += countLeapYears(day2,mon2,year2);

	// return difference between two counts
	return (n2 - n1);
}
struct node * GetValue(struct node *Startref, int *val, int digicount){

	struct node *temp = Startref;
	int Toreturn = 0;
	int dc = 0;

	while (temp)
	{
		if (dc >= digicount) {
			Startref = temp;
			*val =  Toreturn;
			return temp;
		}
		else{
			int t = temp->data;
			Toreturn *= 10;
			Toreturn += t;
			dc++;
		}
		temp = temp->next;
	}
	*val = Toreturn;
	return temp;

}