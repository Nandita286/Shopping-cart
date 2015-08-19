#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#define SERVER "127.0.0.1"
#define BUFLEN 512
#define PORT 8888 

void registration();
void help();
void login();
void book();
void cancel();
void logout();
void read();

int main()
  {
    
    printf("\t\t\tMOVIE BOOKING SYSTEM\n");
    printf("\t\t\t********************\n\n");
    printf("LOGIN >>\n");
    printf("REGISTER >>\n");
    printf("BOOK >>\n");
    printf("CANCEL >>\n");
    printf("LOGOUT >>\n");
    printf("HELP >>\n");
	read();
         
  } 

void read()
{
char str[25];
int ch1,i;
do
{
printf("\n>");
    scanf("%s",str);
for(i=0;str[i]!='\0';i++)
	str[i]=toupper(str[i]);
//printf("\n%s\n",str);
    if(strcmp(str,"LOGIN")==0)
	ch1=1;
    else if(strcmp(str,"REGISTER")==0)
        ch1=2;
    else if(strcmp(str,"BOOK")==0)
        ch1=3;
    else if(strcmp(str,"CANCEL")==0)
        ch1=4;
    else if(strcmp(str,"LOGOUT")==0)
        ch1=5; 
    else if(strcmp(str,"HELP")==0)
        ch1=6; 
	else
	{
		printf("Invalid Command!!\n");
		ch1=6;
	}
	str[0]='\0';
    switch(ch1)
      {
        case 1: login();
		break;
	case 2: registration();
		break;
        case 3: book();
		break;
	case 4: cancel();
		break;
	case 5: logout();
		break;
	case 6: help();
		break;
      }
}while(ch1!=5);
}


void login()
 {
   char usrname[50],pswd[50];
   printf("\t\t\tMOVIE BOOKING SYSTEM\n");
   printf("\t\t\t********************\n\n");
   printf("\tUSER LOGIN\n");
   printf("\t-----------\n");
   printf(" ____________________________\n");
   printf("|                            |\n");
   printf("|USERNAME:");
   scanf("%s",usrname);
   printf("                             |\n");
   printf("|                            |\n");
   printf("|PASSWORD:");
   scanf("%s",pswd);
   printf("                             |\n");
   printf("|____________________________|\n");
	
 }


void die(char *s)
 {
    perror(s);
    exit(1);
 }
void registration()
{
char name[20],usrname[20],mail[20],address[20],mob[10],pswd[10],cpswd[20];
    
    printf("NAME : ");
    scanf("%s",name);
    
    printf("USERNAME: ");
    scanf("%s",usrname);
   
     printf("E-MAIL : ");
     scanf("%s",mail);
    
     printf("ADDRESS : ");
     scanf("%s",address);
     
      printf("MOBILE : ");
      scanf("%s",mob);
     
      printf("PASSWORD : ");
      scanf("%s",pswd);
      
      printf("CONFIRM PASSWORD : ");
      scanf("%s",cpswd);
     
     
 }


void book()
{
	char date[10],class,confirm,row[10],select_ano;
	int movie_code,col[10],show;
	int i=0,j,k,class_id,no_of_seats;
	char *s=",",n='A',unrsrvd='O';
	printf("\nEnter the date(yyyy/mm/dd) : ");
	scanf("%s",date);
	printf("\nmovie code movie name show");
	printf("\n     1       fly      s2,s3");
	printf("\n\nshow\ttimings\ns1\t11.30am\t\ns2\t3.30pm\t\ns3\t6.30pm\t\ns4\t9.30pm");
	printf("\nEnter the movie code : ");
	scanf("%d",&movie_code);
	printf("\nEnter movie show(1-4) : ");
	scanf("%d",&show);

	for(i=-1;i<9;i++)
	{
		printf("\n");
		//to print header 1-18		
		if(i==-1)   
		{	
			printf(" ");
			for(k=1;k<=18;k++)		
			{
				printf("%3d",k);
				if(k==9)
					printf("        ");
			}
		continue;
		}
		//for printing o or x
		for(j=-1;j<18;j++)
		{ 
			if(j==-1)
				printf("%c",n);
			else
				printf("%3c",unrsrvd);	
			if(j==8)
			printf("   H   H");
		}
		n++;
		//for printing class
		if(i<5)
			printf(" |SILVER");
		else if(i<8)
			printf(" |GOLD");
		else
			printf(" |PLATINUM");
	}
	printf("\nEnter the no.of required seats : ");
	scanf("%d",&no_of_seats);
	printf("\nEnter the required class (S/G/P): ");
	scanf(" %c",&class);
	printf("\nSugested Seats : A1,A2,A3");
	printf("\nSelect another seat ? (Y/N) : ");
	scanf(" %c",&select_ano);
	if(select_ano=='y' || select_ano=='Y')
	{
		for(i=0;i<no_of_seats;i++)
		{
			printf("\nEnter the row         : ");
			scanf(" %c",&row[i]);
			printf("\nEnter the seat number : ");
			scanf(" %d",&col[i]);		
		}
	}
	
	printf("\nConfirm booking (Y/N) : ");
	scanf(" %c",&confirm);
	if(confirm=='y' || confirm=='Y')
	{
		printf("\n\nBooking Id  : 1234");
		printf("\nMovie Name  : fly");	
		printf("\nShow Time   : 11.30am");
		printf("\nSeat Number : ");
		for(i=0;i<no_of_seats;i++)
		{
			printf(" %c",row[i]);
			printf("%d  ",col[i]);
					
		}
		printf("\nAmount      : 240\n");
	}
	else
		printf("\nBooking Terminated\n");
	

}
void cancel()
{
int booking_id;
printf("\nEnter the booking id");
scanf("%d",&booking_id);
printf("\nBooking for %d cancelled.\n ",booking_id);

}
void logout()
{
printf("\nYou are succesfully logged out\n");
}
	
void help()
{
printf("\t\t\tMOVIE BOOKING SYSTEM\n");
    printf("\t\t\t********************\n\n");
    printf("LOGIN >>\n");
    printf("REGISTER >>\n");
    printf("BOOK >>\n");
    printf("CANCEL >>\n");
    printf("LOGOUT >>\n");
    printf("HELP >>\n");
}
