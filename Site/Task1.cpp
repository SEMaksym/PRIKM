#include<stdio.h>
#include<string> 
#include<sstream>
#define N 5 

using namespace std;

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

string Convert(int num){
	string months [] = { "January", "February", "March", "April", "May","June","July","August","September","October","November", "December"};
	int monthsDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int DayOfYear = num;
	int month = 0;
	while(DayOfYear - monthsDays[month] > 0){
		DayOfYear -= monthsDays[month];
		month++;
	}
	int day = DayOfYear;
	stringstream ss;
	ss<<day;  
	string s;  
	ss>>s;  
	return s + " " + months[month];
	
}


int main(){
	//input
	int days[N];
	for(int i = 0; i < N;i++){
		printf("Input day of year: ");
		scanf("%d",&days[i]);
	}
	//Sort
	int temp;
    for (int i = 0; i < N - 1; i++) {
        temp = i;
        for (int j = i + 1; j < N; j++)
            if (days[j] < days[temp])
                temp= j;
        swap(&days[temp], &days[i]);
    }
    //print
    for(int i = 0; i < N;i++){
		printf("\n%d day of a year is %s",days[i],Convert(days[i]).c_str());
	}
} 
 
