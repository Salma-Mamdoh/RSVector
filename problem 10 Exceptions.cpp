// problem 10 Exceptions.cpp : 
#include<bits/stdc++.h>
using namespace std;
/*10.	Exceptions.  Ihab Ashraf is trying to write a program that converts dates from numerical month/day format to
alphabetic month/day (for example, 1/31 or 01/31 corresponds to January 31). You will define two exception classes,
one called MonthError and another called DayError. If the user enters anything other than a legal month number 
(integers from 1 to 12), then your program will throw and catch a MonthError. Similarly, 
if the user enters anything other than a valid day number (integers from 1 to either 29, 30, or 31, depending on the month), 
then your program will throw and catch a DayError. To keep things simple, always allow 29 days for February.*/
//1-January,2- February,3- March,4- April,5- May, 6-June, 7-July, 8-August, 9-September, 10-October,11- November and 12-December.

class DateException {
private:
	map<int, string>map_month{ {1,"January"},{2,"February"},{3,"March"},{4,"April"},{5,"May"},{6,"June"},
				{7,"July"},{8,"August"},{9,"September"},{10,"October"},{11,"November"},{12,"December"} };
	map<int, int>map_day{ {1,31},{2,29},{3,31},{4,30},{5,31},{6,30},{7,31},{8,31},{9,30},{10,31},{11,30},{12,31} };
public:
	DateException(){};
	string get_Date(string str) {
		string temp, day, month;
		vector<int>vec;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '/') {
				vec.push_back(stoi(temp));
				temp.clear();
				continue;
			}
			else {
				temp += str[i];
			}
		}
		vec.push_back(stoi(temp));
		if (vec[0] < 0 || vec[0]>12) {
			throw MonthError();
		}
		else {
			month = map_month[vec[0]];
		}
		if (vec[1] <= 0 || vec[1] > map_day[vec[0]]) {
			throw DayError();
		}
		else {
				day = to_string(vec[1]);
				//cout << month << " " << day << endl;
		
		}
		if ((vec[0] >= 0 && vec[0] <= 12) && (vec[1] > 0 && vec[1] <= map_day[vec[0]])) {
			string FinalDate = month + " " + day;
			return FinalDate;
		}
		
	}
	class MonthError {
	public:
		MonthError() {};
		void detect_MonthError() {
			cout << "the input Month is invalid " << endl;
		}
	};
	class DayError {
	public:
		DayError() {};
		void detect_DayError() {
			cout << "the input day is invalid " << endl;
		}
	};
};

int main() {

	string input;
	DateException d1;
	try {
		cout << "enter the date in this form 1/31 or 01/31 : ";
		cin >> input;
		cout<<d1.get_Date(input);
		
	}
	catch (DateException::MonthError a ) {
		a.detect_MonthError();
	}
	catch (DateException::DayError b) {
		b.detect_DayError();
	}
	
	

}