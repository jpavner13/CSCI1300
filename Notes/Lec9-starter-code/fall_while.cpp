#include <iostream>

using namespace std;

int main()
{
    int month = 7;
    int day_of_month = 24;
    
    while(month <= 9) // the following block of code will be executed as long as the condition for the while loop remains true
    {
        //advance the day
        day_of_month++;
        cout << day_of_month << endl;

        //check if it is the end of the month
        if(day_of_month >= 30){
            month++;
            day_of_month = 0;
        }

    }
    cout << "Fall is here!!!" << endl;
    return 0;
}

