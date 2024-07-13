#ifndef TIMEFORMAT_H
#define TIMEFORMAT_H

#include <ctime>
#include <QDateTime>

namespace timeformat
{
    time_t toTime_t(QDateTime qDateTime);
    time_t toTime_t(int year, int month, int day, int hour, int minute);
    time_t toTime_tSegment(int hour, int minute);
} // namespace

#endif // TIMEFORMAT_H
