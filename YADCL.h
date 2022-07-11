#include <cmath>
#include <ctime>
//#include <cstdio>

/**
 * @brief Yet another dates C++ library. Simply work with days, nothing more. Include cstdio for more functions.
 * 
 */
namespace YADCL
{
    /**
     * @brief Implementation of the date itself.
     * 
     */
    struct date
    {
        unsigned short day = 0;
        unsigned short month = 0;
        long long year = 0;

        ///Returns count in days from zero date.
        long long toDays() const
        {
            if((day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                long long yearsToDay = std::abs(year) * 365 + std::abs(year) / 4;
                unsigned long long monthsToDay = month*(double(365)/12);
                long long allDays = yearsToDay + day + monthsToDay;
                return allDays;
            }
            else
            {
                return 0;
            }
        }

        bool operator==(const date& compared) const
        {
            return day == compared.day and month == compared.month and year == compared.year;
        }

        bool operator!=(const date& compared) const
        {
            return day != compared.day or month != compared.month or year != compared.year;
        }

        bool operator>(const date& compared) const
        {
            if(year > compared.year)
            {
                return true;
            }
            else if(month > compared.month)
            {
                return true;
            }
            else if(day > compared.day)
            {
                return true;
            }
            else return false;
        }

        bool operator<(const date& compared) const
        {
            if(year < compared.year)
            {
                return true;
            }
            else if(month < compared.month)
            {
                return true;
            }
            else if(day < compared.day)
            {
                return true;
            }
            else return false;
        }

        bool operator>=(const date& compared) const
        {
            if(year >= compared.year)
            {
                return true;
            }
            else if(month >= compared.month)
            {
                return true;
            }
            else if(day >= compared.day)
            {
                return true;
            }
            else return false;
        }

        bool operator<=(const date& compared) const
        {
            if(year <= compared.year)
            {
                return true;
            }
            else if(month <= compared.month)
            {
                return true;
            }
            else if(day <= compared.day)
            {
                return true;
            }
            else return false; //I knew the else if was a lie.
        }

        date& operator=(const date& checkedDate)
        {
            day = checkedDate.day;
            month = checkedDate.month;
            year = checkedDate.year;
            return *this;
        }

        /**
         * @brief Distance between itself and date.
         * 
         * @param checkedDate Date to compare to.
         * @return unsigned long long Distance between two dates.
         */
        unsigned long long distance(const date& checkedDate) const
        {
            long long date1 = toDays();
            long long date2 = checkedDate.toDays();
            if(date1 >= date2)
            {
                return std::abs(date1 - date2);
            }
            else
            {
                return std::abs(date2 - date1);
            }
        }

        date() = default;
        ~date() = default;

        #ifdef _STDIO_H
        explicit date(const char* checkedString)
        {
            if(sscanf(checkedString, "%02hu.%02hu.%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%lld/%02hu/%02hu", &year, &month, &day) and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%02hu/%02hu/%lld", &day, &month, &year) and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%lld-%02hu-%02hu", &year, &month, &day) and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%lld.%02hu.%02hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%2hu.%2hu.%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%2hu/%2hu/%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%lld/%2hu/%2hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%lld-%2hu-%2hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%lld.%2hu.%2hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else if(sscanf(checkedString, "%02hu%02hu%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return;
            }
            else
            {
                day = 0;
                month = 0;
                year = 0;
            }
        }

        date& operator=(const char* checkedString)
        {
            if(sscanf(checkedString, "%02hu.%02hu.%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%lld/%02hu/%02hu", &year, &month, &day) and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%02hu/%02hu/%lld", &day, &month, &year) and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%lld-%02hu-%02hu", &year, &month, &day) and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%lld.%02hu.%02hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%2hu.%2hu.%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%2hu/%2hu/%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%lld/%2hu/%2hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%lld-%2hu-%2hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%lld.%2hu.%2hu", &year, &month, &day) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else if(sscanf(checkedString, "%02hu%02hu%lld", &day, &month, &year) == 3 and (day <= 31 and day != 0) and (month <= 12 and month != 0))
            {
                return *this;
            }
            else
            {
                day = 0;
                month = 0;
                year = 0;
            }
            return *this;
        }
        #endif
    };

    #ifdef _TIME_H
    inline date currentDate()
    {
        time_t theCurrent = time(NULL);
        auto theDate = *localtime(&theCurrent);
        date newDate{(unsigned short)theDate.tm_mday, static_cast<unsigned short>((unsigned short)theDate.tm_mon + 1), theDate.tm_year + 1900};
        return newDate;
    }
    #endif
}
