#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define len(v) (int) v.size()
#define all(v) v.begin(), v.end()
#include <ctime>

#define input(v) for(auto&x:v)cin>>x;
#define print(v) for(auto&x:v)cout<<x<<' ';cout<<endl;
#define dbg(a) cout<<#a<<" = "<<a<<endl;

map<string, int> getMonthNumber = { 
    {"January", 1}, {"February", 2}, {"March", 3}, {"April", 4}, 
    {"May", 5}, {"June", 6}, {"July", 7}, {"August", 8}, 
    {"September", 9}, {"October", 10}, {"November", 11}, {"December", 12}
};

string monthName[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 1 based indexing
bool isLeapYear(int y) { return ((y % 400 == 0) or (y % 4 == 0 and y % 100 != 0)); }
int getNumberOfDays(int y, int m) { return (isLeapYear(y) and m == 2)? 29 : daysInMonth[m]; }

string weekDayName[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// using year and th day of the year
int getWeekDayWthDay(int year, int thDay) {
    struct tm datetime;
    datetime.tm_year = year - 1900;
    datetime.tm_yday = thDay;
    mktime(&datetime);
    // cout << asctime(&datetime);

    // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    return datetime.tm_wday; // weekday
}

// using tm data structure
int getWeekDayDS(int day, int month, int year) {
    // Create the datetime structure and use mktime to fill in the missing members
    struct tm datetime;
    datetime.tm_year = year - 1900; // Number of years since 1900
    datetime.tm_mon = month-1;
    datetime.tm_mday = day;
    datetime.tm_hour = 0; datetime.tm_min = 0; datetime.tm_sec = 0;
    datetime.tm_isdst = -1;
    mktime(&datetime);
    // cout << asctime(&datetime);

    // 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    return datetime.tm_wday; // weekday
}

// Zeller's Congruence to find the day of the week
int getDayOfWeek(int day, int month, int year) {
    if (month < 3) { 
        month += 12; 
        year--; 
    }
    int k = year % 100;  // Year within the century
    int j = year / 100;  // Zero-based century
    int dayOfWeek = (day + (13 * (month + 1)) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    // Adjust to make 0 = Sunday, 1 = Monday, ..., 6 = Saturday
    return (dayOfWeek + 6) % 7;
}

// Function to print the calendar of a given month and year, with a custom starting day
void printMonthCal(int month, int year, int startingWeekDay) {
    // Print the header of the calendar
    std::cout << "    " << monthName[month] << " " << year << "\n";

    // // Array of days starting from user-specified day
    std::string daysOfWeek[7];

    // Shift days according to the starting day
    for (int i = 0; i < 7; ++i) {
        daysOfWeek[i] = weekDayName[(i + startingWeekDay) % 7];
        std::cout << std::setw(2) << daysOfWeek[i].substr(0, 2) << " ";  // Print two-letter day abbreviations
    }
    std::cout << "\n";

    // Find the starting day of the week for the 1st of the month
    int firstDayOfWeek = getDayOfWeek(1, month, year);

    // Adjust the starting day to match the user's choice
    firstDayOfWeek = (firstDayOfWeek - startingWeekDay + 7) % 7;

    // Print leading spaces for the first row
    for (int i = 0; i < firstDayOfWeek; ++i) {
        std::cout << "   ";
    }

    // Print the days of the month
    for (int day = 1; day <= daysInMonth[month]; ++day) {
        std::cout << std::setw(2) << day << " ";
        // Move to the next line after the specified last day of the week
        if ((day + firstDayOfWeek) % 7 == 0) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void printYearCal(int year) {
    for (int i = 1; i <= 12; i++) {
        printMonthCal(i, year, 0);
    }
}

int solve(int y) 
{
    // int y; cin >> y;
    
    int ans = 0;
    for (int i = 1; i < 13; i++) {
        int first_day =  getDayOfWeek(1, i, y);
        first_day = ((first_day - 1) + 7) % 7; // res to monday
        
        int tot_days = getNumberOfDays(y, i);
        
        int first_row_slots = 7 - first_day;
        int full_row = (tot_days - first_row_slots) / 7;
        int count = full_row;
        int rem_days = tot_days - full_row * 7;

        // dbg(i);
        // dbg(first_day);
        // dbg(tot_days);
        // dbg(full_row);
        // dbg(rem_days);
        // dbg(first_row_slots);

        if (first_row_slots < rem_days)
            count += 2;
        else 
            count++;

        ans += count;
        
        // cout << count << endl;
        // cout << endl;
    }
    
    // cout << ans;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t = 1, tc = 1;
    
    // cout << "{" << endl;
    // for (int i = 1970; i <= 2037; i++) {
    //     cout << "{";
    //     cout << i << ", " << solve(i) << "}," << endl;
        
    // }
    // cout << "}" << endl;
    
    int y; cin >> y;
    cout << solve(y);

    // int wd = getDayOfWeek(21, 10, 2024);
    // cout << weekDayName[wd] << endl;

    // printYearCal(2023);
    
    return 0;
}