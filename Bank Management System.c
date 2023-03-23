#include<stdio.h>
#include<conio.h>
#include<string.h>

struct bank
{int age;
 int account;
 char password[50];
 int cnic;
 int mobile;
 int money;
 char name[50];
}ob[100];

void visit(struct bank ob[],int);
struct bank code(struct bank ob[], int, int);
int deposite(struct bank ob[], int);
int withdrawl(struct bank ob[], int );
void information(struct bank ob[],int );
int transfer(struct bank ob[], int ,int );
void action(struct bank ob[] , int , int);
	
 main()
{ int value,i,j,a=561,user;
  printf("\t\t\t\t\tWELCOME TO THE STATE BANK OF PAKISTAN\n");
  printf("\t\t\t\t\t=====================================\n\n\n");
  printf("PLEASE ENTER THE VALUE OF ACCOUNT USERS: ");
  scanf("%d",&value);
  printf("\n\n");
  for(i=0;i<value;i++)
  { printf("\n\n\n\nACCOUNT FOR THE USER  %d: \n\n",i+1);
    printf("ENTER THE NAME OF THE USER: ");
    scanf("%s",ob[i].name);
	j=0;  
  	printf("ENTER YOUR SECRET PASSWORD OF 8 CHARACTERS: ");
  	do{
    ob[i].password[j]=getch();
    printf("*");
    j++;}while(j<=7);
  	printf("\nENTER YOUR AGE: ");
  	scanf("%d",&ob[i].age);
  	printf("ENTER YOUR MOBILE NO: ");
  	scanf("%d",&ob[i].mobile);
  	printf("ENTER YOUR CNIC NO: ");
  	scanf("%d",&ob[i].cnic);
  	printf("ENTER THE AMOUNT OF MONEY WHICH YOU WANT TO DEPOSITE IN YOUR ACCOUNT: ");
  	scanf("%d",&ob[i].money);
    printf("\t\tTHANKS FOR MAKING AN ACCOUNT IN OUR BANK.\nYOUR ACCOUNT NO IS %d.\nPLEASE KEEP IT REMEMBER",a);  
    ob[i].account=a;
	a++;
   }	
   printf("\n\n\n\n\nFOR ANY USER VISIT PRESS 1 OTHERWISE 0 :  ");
   scanf("%d",&user);
   if(user==1)
   { visit(ob,value);
    getch();}
   else 
   getch();
	
}

void visit(struct bank ob[],int value)
{ int i,acc;
  printf("ENTER THE ACCOUNT NO OF THE USER: ");
  scanf("%d",&acc);	
  for(i=0;i<value;i++)
  { if(acc==ob[i].account)
    { code(ob,i,value);
    break;	
	}
	else
	{printf("\nYOUR ACCOUNT IS NOT REGISTERED\n.PLEASE TRY AGAIN.\n");
	visit(ob,value);}}}
struct bank code(struct bank ob[],int i,int value)
{ int j=0,b,d;
  char pass[50]; 
printf("ENTER YOUR SECRET PASSWORD: ");
do{
	pass[j]=getch();
    printf("*");
	j++;}while(j<=7);
b=strcmp(pass,ob[i].password);
if(b==0)
action(ob,i,value);
else 
{printf("\nYOUR PASSWORD IS INVALID. PLEASE TRYAGAIN\n");
 code(ob,i,value);		
} } 
void action(struct bank ob[], int i,int value)
{ int d,e;
 char f,c;
  printf("\n\n\n\tWHICH TYPE OF ACTION WOULD YOU LIKE TO PERFORM?\n");
  printf("\t===============================================\n\n\n");
  printf("\t||FOR TRANSFER  || FOR DEPOSITE  || FOR WITHDRAWL  || FOR CHECKING||\n");	
  printf("\t||    MONEY     ||     MONEY     ||     MONEY      ||  INFORMATION||\n");
  printf("\t||PRESS T OR t  ||  PRESS D OR d ||  PRESS W OR w  || PRESS I OR i||\n");
  printf("\t===================================================================\n\n\n\n");	
  c=getche();
  if(c=='D'||c=='d')
  { d=deposite(ob,i);
    ob[i].money=d;
    printf("\nYOUR TOTAL MONEY AFTER DEPOSITING ACCOUNT IS %d",ob[i].money);
	printf("\n\nFOR LOGOUT THE ACCOUNT PRESS O OR o ELSE I OR i : ");
	f=getche();
	if(f=='o'||f=='O')	
	{printf("\n\t\t\tYOU ARE LOGOUT.\n\t\tTHANKS FOR VISITING OUR BANK");}
	else 
	{action(ob,i,value);}
	printf("\n\n\nFOR ANY OTHER VISIT PRESS 1 ELSE 0 : ");
	scanf("%d",&e);
	if(e==1)
	visit(ob,value);}
  else if(c=='W'||c=='w')
  { d=withdrawl(ob,i);
    ob[i].money=d;
	printf("\nYOUR TOTAL MONEY AFTER THE AMOUNT YOU WITHDRAW IS %d",ob[i].money); 
	printf("\n\nFOR LOGOUT THE ACCOUNT PRESS O OR o ELSE I OR i : ");
	f=getche();
	if(f=='o'||f=='O')	
	{printf("\n\t\t\tYOU ARE LOGOUT.\n\t\tTHANKS FOR VISITING OUR BANK");}
    else 
    {action(ob,i,value);}
	printf("\n\n\nFOR ANY OTHER VISIT PRESS 1 ELSE 0 : ");
	scanf("%d",&e);
	if(e==1)
	visit(ob,value);}
  else if(c=='I'||c=='i')
  { information(ob,i);
  		printf("\n\nFOR LOGOUT THE ACCOUNT PRESS O OR o ELSE I OR i : ");
	f=getche();
	if(f=='o'||f=='O')	
	{printf("\n\t\t\tYOU ARE LOGOUT.\n\t\tTHANKS FOR VISITING OUR BANK");}
	else
	action(ob,i,value);
	printf("\n\n\nFOR ANY OTHER VISIT PRESS 1 ELSE 0 : ");
	scanf("%d",&e);
	if(e==1)
	visit(ob,value);}	 
  else if(c=='T'||c=='t')
  { d=transfer(ob,i,value);
    ob[i].money=d;
	printf("\nYOUR MONEY AFTER TRANSFERRING AMOUNT IS %d",ob[i].money);
	printf("\n\nFOR LOGOUT THE ACCOUNT PRESS O OR o ELSE I OR i : ");
	f=getche();
	if(f=='o'||f=='O')	
	{printf("\n\t\t\tYOU ARE LOGOUT.\n\t\tTHANKS FOR VISITING OUR BANK");}
	else
	action(ob,i,value);
	printf("\n\n\nFOR ANY OTHER VISIT PRESS 1 ELSE 0 : ");
	scanf("%d",&e);
	if(e==1)
	visit(ob,value);}	
}
int deposite(struct bank ob[], int i)	
  { int amount;
  printf("ENTER THE AMOUNT OF MONEY YOU WANT TO DEPOSITE: ");
  scanf("%d",&amount);
  ob[i].money=ob[i].money+amount;
 return ob[i].money;
     }
int withdrawl(struct bank ob[], int i)
{ int amount;
  printf("\nENTER THE AMOUNT OF MONEY YOU WANT TO WITHDRAWL: ");
  scanf("%d",&amount);
  if(amount>ob[i].money)
  { printf("\nYOUR ACCOUNT DOESNOT HAVE ENOUGH ENOUGH AMOUNT OF MONEY TO WITHDRAW FROM YOUR ACCOUNT\nPLEASE TRY AGAIN");
  	withdrawl(ob,i);
  }
  else 
  { ob[i].money=ob[i].money-amount;
    return ob[i].money;}}
		
void information(struct bank ob[],int i)	  	   
{ printf("\nYOUR NAME IS: ");
  puts(ob[i].name);
  printf("\nYOUR AGE IS: %d",ob[i].age);
  printf("\nYOUR MOBILE NO IS %d",ob[i].mobile);
  printf("\nYOUR C.N.I.C NO IS %d",ob[i].cnic);
  printf("\nYOUR ACCOUNT MONEY IS %d",ob[i].money);		  }	  	
	
int transfer(struct bank ob[], int i,int value)
{ int acc, j,amount; 
  printf("\nENTER THE ACOUNT NO TO WHICH YOU HAVE TO TRANSFER MONEY: ");
  scanf("%d",&acc);
  for(j=0;j<value;j++)	
  { if(acc=ob[j].account)
    { printf("\nENTER THE AMOUNT OF MONEY YOU HAVE TO TANSFER: ");
     scanf("%d",&amount);
    if(amount>ob[i].money)
    {printf("\nYOUR ACCOUNT DOESNOT HAVE ENOUGH AMOUNT OF MONEY TO TRANSFER FROM YOUR ACCOUNT.\nPLEASE TRY AGAIN");
     transfer(ob,i,value);}
   else 
  { ob[i].money=ob[i].money-amount;
  return ob[i].money;}	 
  
  break;}
  else 
  {printf("\nTHE TRANSFER ACCOUNT IS NOT VALID.\nPLEASE TRY AGAIN");
  
   transfer(ob, i, value);
  
  }
  }} 