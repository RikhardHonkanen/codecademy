#include <stdio.h>
#include <stdbool.h>

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap_year(int year)
{
    return (year % 4 == 0 && (year % 100 || year % 400 == 0));
}

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add)
{
    int days_left_in_month;

    while (days_left_to_add > 0)
    {
        days_left_in_month = days_in_month[*mm] - *mm;
        if (*mm == 2 && is_leap_year(*yy))
        {
            days_left_in_month++;
        }
        if (days_left_to_add > days_left_in_month)
        {
            days_left_to_add -= days_left_in_month;
            days_left_to_add--; // Cycle over to next month
            *dd = 1;
            if (*mm == 12)
            {
                (*yy)++; // Happy New Year
                *mm = 1;
            }
            else
            {
                (*mm)++;
            }
        }
        else
        {
            *dd += days_left_to_add;
            days_left_to_add = 0;
        }
    }
}

int main()
{
    int mm, dd, yy, days_left_to_add;
    printf("Please enter a date between the years 1800 and 10000 in the format mm dd yy and provide the number of days to add to this date: ");
    scanf("%d %d %d %d", &mm, &dd, &yy, &days_left_to_add);
    add_days_to_date(&mm, &dd, &yy, days_left_to_add);
    printf("New date: %d/%d/%d", mm, dd, yy);

    // int year;
    // printf("%d", days_in_month[2]);
    // printf("Choose a year between 1800 and 10000: ");
    // if (scanf("%d", &year) == 1)
    // {
    //     if (year >= 1800 && year <= 10000)
    //     {
    //         printf("You chose: %d\n", year);
    //     }
    //     else
    //     {
    //         printf("The year is out of range.\n");
    //     }
    // }
    // else
    // {
    //     printf("Invalid input.\n");
    // }
    // if (is_leap_year(year))
    // {
    //     printf("Leap Year\n");
    // }
    // else
    // {
    //     printf("Not Leap Year\n");
    // }
}