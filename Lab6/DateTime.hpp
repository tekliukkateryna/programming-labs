#pragma once
#include <iomanip>

struct DateTime {
    int year, month, day, hour, minute;

    bool operator<(const DateTime& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        if (day != other.day) return day < other.day;
        if (hour != other.hour) return hour < other.hour;
        return minute < other.minute;
    }

    bool operator==(const DateTime& other) const {
        return year == other.year && month == other.month &&
               day == other.day && hour == other.hour &&
               minute == other.minute;
    }

    bool operator>(const DateTime& other) const  { return other < *this; }
    bool operator<=(const DateTime& other) const { return !(*this > other); }
    bool operator>=(const DateTime& other) const { return !(*this < other); }
    bool operator!=(const DateTime& other) const { return !(*this == other); }
};

//щоб було гарненько
std::ostream& operator<<(std::ostream& os, const DateTime& dt) {
    os << dt.year << "-"
       << setfill('0') << setw(2) << dt.month << "-"
       << setw(2) << dt.day << " "
       << setw(2) << dt.hour << ":"
       << setw(2) << dt.minute;
    return os;
}