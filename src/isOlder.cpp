/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int date_valid(char *str)
{
	int   date = ((str[0] - 48) * 10) + (str[1] - 48);
	int month = (((str[3] - 48)) * 10) + (str[4] - 48);
	int year = ((str[6] - 48) * 1000) + ((str[7] - 48) * 100) + ((str[8] - 48) * 10) + (str[9] - 48);
	int valid;
	if ((date>31) || (month>12) || (date <= 0) || (month <= 0) || (str[2] != '-') || (str[5] != '-'))
	{
		valid = 0;
	}
	else
	{
		if ((month == 2) && (((year) % 4) != 0) && (date>28))
		{
			valid = 0;
		}
		else if (((month) == 2) && ((year) % 4 == 0) && ((date)>29) && ((year) % 100 == 0) && ((year) % 400 == 0))
		{

			valid = 0;
		}
		else if ((month <= 7) && (month % 2 == 0) && (date>30))
		{
			valid = 0;
		}
		else if ((month <= 7) && (month % 2 == 1) && (date>31))
		{
			valid = 0;
		}
		else if ((month>7) && (month % 2 == 0) && (date>31))
		{
			valid = 0;
		}
		else if ((month>7) && (month % 2 == 1) && (date>30))
		{
			valid = 0;
		}
		else
			valid = 1;
	}
	if (valid == 1)
	{
		return 0;
	}
	else return -1;
}

int isOlder(char *dob1, char *dob2) {
	int date1, date2, year1, year2, month1, month2,valid1,valid2;
	valid1 = date_valid(dob1);
	valid2 = date_valid(dob2);
	if (valid1== -1 || valid2 == -1)
		return -1;
	else
	{
		date1 = ((dob1[0] - 48) * 10) + (dob1[1] - 48);
		month1 = (((dob1[3] - 48)) * 10) + (dob1[4] - 48);
		year1 = ((dob1[6] - 48) * 1000) + ((dob1[7] - 48) * 100) + ((dob1[8] - 48) * 10) + (dob1[9] - 48);
		date2 = ((dob2[0] - 48) * 10) + (dob2[1] - 48);
		month2 = (((dob2[3] - 48)) * 10) + (dob2[4] - 48);
		year2 = ((dob2[6] - 48) * 1000) + ((dob2[7] - 48) * 100) + ((dob2[8] - 48) * 10) + (dob2[9] - 48);
		if (year1 > year2)
			return 2;
		else if (year1 < year2)
			return 1;
		else if (month1 > month2)
			return 2;
		else if (month2 > month1)
			return 1;
		else if (date1 > date2)
			return 2;
		else if (date2 > date1)
			return 1;
		else return 0;
	}
}
