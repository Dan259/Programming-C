#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void wday(struct tm time_info){
    printf("It's %s\n", days_of_week[time_info.tm_wday]);
}

int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char *months[] = {
    "", "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};
const char *days_of_week[] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
};


int main() {
    int year, month, day;
    char c[10];
    
    printf("Enter date: ");
    scanf("%s", c);
    
    if(strchr(c, '.') != NULL){
    	printf("1");
	}
	else{
		if()
			//
		else
			//cur_time
			printf(2);
	}

    if (year < 1900 || month < 1 || month > 12 || day < 1 || day > 31) {
        printf("Error.\n");
        return 1;
    }
	struct tm time_info = {0};
    
    time_info.tm_year = year - 1900;
    time_info.tm_mon  = month - 1;
    time_info.tm_mday = day;

	mktime(&time_info);
	
    

    return 0;
}


