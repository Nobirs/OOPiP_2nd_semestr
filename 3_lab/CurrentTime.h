#pragma once
#include <string>
#include <ctime>



inline string getCurrLocalDate() {
	struct tm buf;
	size_t dateSize = std::size("yyyy-mm-ddT");
	time_t now = time(0);
	char* dateStr = new char[dateSize];
	gmtime_s(&buf, &now);
	strftime(dateStr, dateSize, "%Y-%m-%d", &buf);
	string date(dateStr);
	return date;
}


inline string getCurrLocalTime() {
	struct tm buf;
	size_t timeSize = std::size("hh:mm:ssZ");
	time_t now = time(0);
	char* timeStr = new char[timeSize];
	gmtime_s(&buf, &now);
	strftime(timeStr, timeSize, "%H:%M:%S", &buf);
	string time(timeStr);
	return time;
}