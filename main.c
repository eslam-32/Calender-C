#include <stdio.h>
#include <stdlib.h>
#include "calender.c"
int main(){

    int choice;
    while(1){

        printf("                Calender Task ---- Eslam Mohamed\n");
        printf("----------------------------------------------------------------------------\n");
        printf("                ENTER YOUR CHOICE : \n");
        printf("----------------------------------------------------------------------------\n");
        printf("                1. Enter Day to find\n");
        printf("                2. Print Month Name\n");
        printf("                3. Check Leap Year\n");
        printf("                4. Number of Days in This Month\n");
        printf("                5. Print Full Month\n");
        printf("                6. Add Note\n");
        printf("                7. Show Note\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter date (Day Month Year) : ");
                scanf("%d %d %d",&date.dd,&date.mm,&date.yy);
                printf("Day is : %s\n",getDay(date.dd,date.mm,date.yy));
                printf("------------------------------\n");
                break;

            case 2 :
                printf("Enter Month and Year  MM YY: ");
                scanf("%d %d",&date.mm,&date.yy);
                printMonth(date.mm,date.yy);
                break;

            case 3:
                printf("Enter year to check leap or not \n");
                scanf("%d",&date.yy);

                if (leapYear(date.yy)== 1){
                    printf("Leap year :D\n");
                    printf("------------\n");}
                else {
                    printf("Not leap\n");
                    printf("------------\n");}
                break;

            case 4:
                printf("Enter Month and Year  MM YY: ");
                scanf("%d %d",&date.mm,&date.yy);
                printf("This Month have  %d  Days\n",getNumberOfDays(date.mm,date.yy));
                break;

            case 5:
                printf("Enter Month and Year  MM YY: ");
                scanf("%d %d",&date.mm,&date.yy);
                printFullMonth(date.mm,date.yy);
                break;
            case 6:
                AddNote();
                break;
            case 7:
                printf("Enter Month  MM: ");
                scanf("%d",&R.mm);
                showNote(R.mm);

        }
    }
    return 0;
}
