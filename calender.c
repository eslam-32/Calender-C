#ifndef CALENDER_C_INCLUDED
#define CALENDER_C_INCLUDED
#endif // CALENDER_C_INCLUDED
#include "calender.h"
int leapYear(int year){ //checks whether the year passed is leap year or not
    if(year % 4 == 0 )
    return 1;
    return 0;
}

void increaseMonth(int *mm,  int *yy){ //increase the month by one
    ++*mm;
    if(*mm > 12){
        ++*yy;
        *mm = *mm - 12;
    }
}

void decreaseMonth(int *mm,  int *yy){ //decrease the month by one
    --*mm;
    if(*mm < 1){
        --*yy;
        *mm = *mm + 12;
    }
}


int getNumberOfDays(int month,int year){ //returns the number of days in given month
   switch(month){                          //and year
      case 1 : return(31);
      case 2 : if(leapYear(year)==1)
       return(29);
          else
       return(28);
      case 3 : return(31);
      case 4 : return(30);
      case 5 : return(31);
      case 6 : return(30);
      case 7 : return(31);
      case 8 : return(31);
      case 9 : return(30);
      case 10: return(31);
      case 11: return(30);
      case 12: return(31);
      default: return(-1);
   }
}

char *getName(int day){ //returns the name of the day

   switch(day){
      case 0 :return("Sunday");
      case 1 :return("Monday");
      case 2 :return("Tuesday");
      case 3 :return("Wednesday");
      case 4 :return("Thursday");
      case 5 :return("Friday");
      case 6 :return("Saturday");
      default:return("Error");
             }

}

void printMonthName(int mm, int yy){ //prints the name of month and year
    printf("\n---------------------------");

    switch(mm){
        case 1: printf("January"); break;
        case 2: printf("February"); break;
        case 3: printf("March"); break;
        case 4: printf("April"); break;
        case 5: printf("May"); break;
        case 6: printf("June"); break;
        case 7: printf("July"); break;
        case 8: printf("August"); break;
        case 9: printf("September"); break;
        case 10: printf("October"); break;
        case 11: printf("November"); break;
        case 12: printf("December"); break;
    }
    printf("%d", yy);

    printf("---------------------------\n");
    printf("\n");
}
int getDayNumber(int day,int mon,int year){ //retuns the day number by algorithm
    int res = 0, t1, t2, y = year;
    year = year - 1600;
    while(year >= 100){
        res = res + 5;
        year = year - 100;
    }
    res = (res % 7);
    t1 = ((year - 1) / 4);
    t2 = (year-1)-t1;
    t1 = (t1*2)+t2;
    t1 = (t1%7);
    res = res + t1;
    res = res%7;
    t2 = 0;
    for(t1 = 1;t1 < mon; t1++){
        t2 += getNumberOfDays(t1,y);
    }
    t2 = t2 + day;
    t2 = t2 % 7;
    res = res + t2;
    res = res % 7;
    if(y > 2000)
        res = res + 1;
    res = res % 7;
    return res;
}

char *getDay(int dd,int mm,int yy){
    int day;
    if(!(mm>=1 && mm<=12)){
        return("Invalid month value");
    }
    if(!(dd>=1 && dd<=getNumberOfDays(mm,yy))){
        return("Invalid date");
    }
    if(yy>=1600){
        day = getDayNumber(dd,mm,yy); //return the num of day
        day = day%7;
        return(getName(day));
    }else{
        return("Please give year more than 1600");
    }
}

void printMonth(int mm,int yy){ //prints the month (Name only)
    if(!(mm>=1 && mm<=12)){
        printf("INVALID MONTH");
        return;
    }
    if(!(yy>=1600)){
        printf("INVALID YEAR");
        return;
    }

    printMonthName(mm,yy);


}

void printFullMonth(int mm,int yy){
    int i,days;
    enum week start;
    do{

      }while(getNumberOfDays(mm,yy)<28 | getNumberOfDays(mm,yy)>31);
    do{
                printf("\nEnter the startDay no in month");
                printf(" 1-Sun 2-Mon 3-Tue 4-Wed 5-Thu 6-Fri 7-SAT\n");
                scanf("%d",&start);
      }
    while(start<0 | start>7);
    printMonthName(mm,yy); //print Month Name
    printf("\nSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n\n"); //print Days Fixed
    for(i=1;i<=getNumberOfDays(mm,yy)+start-1;i++)
    {
      if(i<start)
      {
               printf(" \t");  // msafa l7d ma ywsl l awl yom
      }
      else
      {
                printf("%d\t",i-start+1);
      }
      if((i%7)==0)
      printf("\n");
    }
printf("\n-------------------- \n");

}

void AddNote(){  //file handler in windows
    FILE *fp;
    fp = fopen("note.dat","ab+");
    system("cls");

    printf("Enter the date(DD/MM): ");
    scanf("%d%d",&R.dd, &R.mm);

    printf("Enter the Note(50 character max): ");
    fflush(stdin);
    scanf("%[^\n]",R.note);
    if(fwrite(&R,sizeof(R),1,fp)){

        puts("Note is saved sucessfully");
        fclose(fp);
    }else{


        puts("\aFail to save!!\a");

    }

    printf("Press any key............");
    getch();
    fclose(fp);
}

void showNote(int mm){
    FILE *fp;
    int i = 0, isFound = 0;
    system("cls");
    fp = fopen("note.dat","rb");
    if(fp == NULL){
        printf("Error in opening the file");
    }
    while(fread(&R,sizeof(R),1,fp) == 1){
        if(R.mm == mm){

            printf("Note %d  of Day = %d: %s\n", i+1, R.dd,  R.note);
            isFound = 1;
            i++;

        }
    }
    if(isFound == 0){

        printf(" or This Month contains no note\n");
    }

    printf("Press any key to return \n");
    getch();


}
