#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

int isDigit(char *, char *, char*);       //function for checking characters
int convertToInt(char *);                 //function for converting string

int dayOfWeek(int mmonth, int dday, int yyear){
  int dayOftheWeek,dayOftheMonth,monthVariable,yearOfCentury,zeroBasedCentury;
  if(mmonth == 1) {
    mmonth = 13;
    yyear--;        
  }
  
  if (mmonth == 2){
    mmonth = 14;        
    yyear--;
  }
  
  dayOftheMonth = dday;
  monthVariable = mmonth;
  yearOfCentury = yyear % 100;
  zeroBasedCentury = yyear / 100;
  dayOftheWeek = dayOftheMonth + 13*(monthVariable+1)/5 + yearOfCentury + yearOfCentury/4 + zeroBasedCentury/4 + 5*zeroBasedCentury;
  dayOftheWeek = dayOftheWeek % 7;
  return dayOftheWeek;
}

int dayOfYear(int month, int day, int year){
     int  days_in_feb = 28;    
      int doy = day;
      if( (year % 4 == 0 && year % 100 != 0 ) || (year % 400 == 0) ){
        days_in_feb = 29;
    }
    switch(month) {
        case 2:
            doy += 31;
            break;
        case 3:
            doy += 31+days_in_feb;
            break;
        case 4:
            doy += 31+days_in_feb+31;
            break;
        case 5:
            doy += 31+days_in_feb+31+30;
            break;
        case 6:
            doy += 31+days_in_feb+31+30+31;
            break;
        case 7:
            doy += 31+days_in_feb+31+30+31+30;
            break;            
        case 8:
            doy += 31+days_in_feb+31+30+31+30+31;
            break;
        case 9:
            doy += 31+days_in_feb+31+30+31+30+31+31;
            break;
        case 10:
            doy += 31+days_in_feb+31+30+31+30+31+31+30;            
            break;            
        case 11:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31;            
            break;                        
        case 12:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31+30;            
            break;      }
            return doy;
}

void solutionFunction(int m, int d, int y){
    int dow=dayOfWeek(m,d,y);
    switch(dow){
    case 0 : printf("Saturday\n"); break;
    case 1 : printf("Sunday\n"); break;
    case 2 : printf("Monday \n"); break;
    case 3 : printf("Tuesday \n"); break;
    case 4 : printf("Wednesday \n"); break;
    case 5 : printf("Thursday \n"); break;
    case 6 : printf("Friday \n"); break;    
    }
    int doy=dayOfYear(m,d,y);
    printf("Day of year: %d", doy); 
}

int main(){
  char monthArray[MAX], dayArray[MAX], yearArray[MAX];
  int digit, m, d, y, leap;
  int invalid = 0;
  
  do{
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s %s %s", monthArray, dayArray, yearArray);
    
    digit = isDigit(monthArray, dayArray, yearArray);
    m = convertToInt(monthArray);
    d = convertToInt(dayArray);
    y = convertToInt(yearArray);
    dayOfYear(m,d,y);
    
    if (digit == 0)
      printf("Invalid Input.\n");
    
    }while(digit==0);

  if(m>=1 && m<=12){        
    if((d>=1 && d<=31) && (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)){
            solutionFunction(m,d,y);
            invalid=1;
        }
        else if((d>=1 && d<=30) && (m==4 || m==6 || m==9 || m==11)){
            solutionFunction(m,d,y);
            invalid=1;
        }
        else if(d==29 && m==2 && (y%400==0 ||(y%4==0 && y%100!=0))){
            solutionFunction(m,d,y);
            invalid=1;
        }
        else{
            printf("Invalid input. ");
        }
    return 0; 
    }
}

int isDigit(char*m, char*d, char*y){ 
    char string[MAX];
    strcpy(string, m);
    strcat(string, d);
    strcat(string, y);

    for(int i=0; string[i]!='\0'; i++){
        if(isdigit(string[i])==0){
            return 0;
        }
    }
    return 1;
}

int convertToInt(char*string){
    return(atoi(string));
}


