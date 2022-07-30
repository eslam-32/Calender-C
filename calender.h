#ifndef CALENDER_H_INCLUDED
#define CALENDER_H_INCLUDED



#endif // CALENDER_H_INCLUDED
struct Date{
    int dd;
    int mm;
    int yy;
}date;
//struct Date date;

struct Notes{
    int dd;
    int mm;
    char note[50];
}R;
//struct Notes R;

enum week{Sun=1,Mon,Tue,Wed,Thur,Fri,Sat};

void printMonth(int mon,int year);

char *getDay(int dd,int mm,int yy);

int getDayNumber(int day,int mon,int year);

void printMonthName(int mm, int yy);

char *getName(int day);

int getNumberOfDays(int month,int year);

void decreaseMonth(int *mm,  int *yy);

void increaseMonth(int *mm,  int *yy);

int leapYear(int year);

void printFullMonth(int mm,int yy);
