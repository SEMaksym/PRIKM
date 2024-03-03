#include  <iostream>
#include <stdlib.h>
#include<stdio.h>
#include<string> 
#include<sstream>
#include <cstring>
using namespace std;
typedef struct {
  int day;
  int mouth;
  int year;	
  char* text;
  int dayOfYear;
}DATE;
string ConvertToSting(int num){
	stringstream ss;
	ss<<num;  
	string s;  
	ss>>s;  
	return s;
	
}
void SplitDate(char* date,int *day,int *mouth,int *year){
	char *copy, *p;
	char lim[] = " .,";
	
	copy = (char*)malloc(strlen(date)+1);
	strcpy(copy, date);
	
	p = strtok(copy, lim);
	sscanf(p, "%d", day);
	p = strtok(NULL, lim);
	sscanf(p, "%d", mouth);
	p = strtok(NULL, lim);
	sscanf(p, "%d", year);
	p = strtok(NULL, lim);
	
	free(copy);
	copy = NULL;
}
int DateToDays(DATE *date){
	int day=date->day,mouth=date->mouth,year=date->year;
	int DayOfYear = day;
	int February = 28;
	if(year%4 == 0 && (year%100 != 0 || year%400 == 0)){
		February = 29;
	}
	int mothsDays[12] = {31,February,31,30,31,30,31,31,30,31,30,31};
	for(int i = 0;i < mouth-1;i++){
		DayOfYear += mothsDays[i];
	}
	return DayOfYear;
	
}

DATE ** Input(int n)
{
	DATE** Date=(DATE**)malloc(n*sizeof(DATE*));
	for(int i = 0; i < n; i++)
	{
		Date[i]=(DATE*) malloc(sizeof(DATE));
		
		printf(" Enter date %d: ",i);
		char buffer[127];
		scanf("%s",&buffer);
		Date[i]->text = (char*)malloc(strlen(buffer)+1);
		strcpy(Date[i]->text, buffer);
		
		SplitDate(Date[i]->text,&Date[i]->day,&Date[i]->mouth,&Date[i]->year);
		
		Date[i]->dayOfYear = DateToDays(Date[i]);
		
		rewind(stdin);
	}
	
	return Date;
}
bool isBiger(DATE *dateA,DATE *dateB){
	if(dateA->year > dateB->year){
		return true;
	}
	if(dateA->year == dateB->year && dateA->mouth > dateB->mouth){
		return true;
	}
	if(dateA->year == dateB->year && dateA->mouth == dateB->mouth && dateA->day > dateB->day){
		return true;
	}
	return false;
}
bool Copmare(DATE *boundA,DATE *boundB,DATE *date){
	if(isBiger(date,boundA) && isBiger(boundB,date)){
		return true;
	}
	return false;
}
int main(){
	
	int N = 3;
	printf("Input size: ");
    scanf("%d",&N);
	DATE** dates;
	dates = Input(N);
	
	for(int i=0;i<N;i++){
		printf("\n%s is %i day of a year",dates[i]->text,dates[i]->dayOfYear);
	}
	
	DATE** Bounds;
	printf("\n\nInput bounds for deletion\n");
	Bounds = Input(2);
	for(int i =0;i < N;i++){
		if(Copmare(Bounds[0],Bounds[1],dates[i])){
			free(dates[i]);	
			dates[i] = NULL;
		}
	}
	
	
	printf("\n\nDates deleted\n");
	for(int i=0;i<N;i++){
		if(dates[i] != NULL){
			printf("\n%s is %i day of a year",dates[i]->text,dates[i]->dayOfYear);
		}
	}
	
	free(dates);
    return 0;
} 
