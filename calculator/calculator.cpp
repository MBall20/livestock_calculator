// Beginnings of a livestock calculator

#include <iostream> // Allows use with inputs and outputs
#include <sstream>
#include <string>
#include <cmath> // Include for math operations other than the 4 basic
#include <map> // Needed when working with maps


//#include <ctime> // Must be included to use dates and times

using namespace std;

/*
void centerString(char* s) {

    // Find the length of the string
    int length = strlen(s);

    // Position
    int position = (int)((120 - length) / 2);
    for (int i = 0; i < position; i++)
        cout << " ";
    cout << s << "\n";
}
*/
class Date {

public:

    int current_year;
    int current_month;
    int current_day;

    void date() {

        time_t t = time(0);   // get time now
        tm* now = localtime(&t);
        current_year = (now->tm_year + 1900);
        current_month = (now->tm_mon + 1);
        current_day = now->tm_mday;
        cout << current_year << '-'
            << current_month << '-'
            << current_day
            << "\n";
    }
};

class UserInput {

public:

};


int main() {

    //Project Title
    char title[] = "--CALCULATOR--";
    //centerString(title);

    Date current_date;
    cout << "Todays Date: ";
    current_date.date();

    // Declare variables so user input can be saved
    int select_year;
    int select_month;
    int select_day;

    // Variables for use in while loops
    bool month = false;
    bool day = false;

    // Map containing date split into Year Month Day
    map <string, int>  dateMap;

    // Get birth year
    cout << "Please enter birth year: ";
    cin >> select_year;

    // Update map with year
    dateMap.insert({ "Year", select_year });

    cout << "\n";

    // Get birth  month
    while (month == false) {

        cout << "Please enter birth month: ";
        cin >> select_month;

        // Input validation, fancy if else statement
        month = (select_month > 12 || select_month < 1) ? month = false : month = true;

    }

    // Update map with month
    dateMap.insert({ "Month", select_month });

    cout << "\n";

    // Get birth day
    while (day == false) {

        cout << "Please enter birth day: ";
        cin >> select_day;
        // Use long hand if else
        if (select_day < 1 || select_day > 30) {

            day = false;
            cout << "Please enter a valid day of the month: ";

        }
        else {

            day = true;

        }

    }

    // Update map with day
    dateMap.insert({ "Day", select_day });
    cout << "\n";

    // Fancy math to calculate weight
    int year_diff = (current_date.current_year - select_year);
    int month_diff = abs(current_date.current_month - select_month);
    int day_diff = abs(current_date.current_day - select_day);

    // Convert age to days
    int age_months = (year_diff * 12 - month_diff);
    int age_days = (year_diff * 12 - month_diff) * 30 + day_diff;

    // Based on 2 lbs/day agerage gain. Will be more precise in future. Changes through the stages of life.
    int estimated_weight = age_days * 2;

    cout << "Current age: " << age_months << " months\n";
    //cout << month_diff;
    cout << "\nTodays estimated weight is: " << estimated_weight << "lbs\n";
    cout << "\n";

    // Display map
    map <string, int>::iterator itr;
    for (itr = dateMap.begin(); itr != dateMap.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
            << '\n';
    }
    cout << endl;



}