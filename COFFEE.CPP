#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void welcome();
void admin();
void update_stock()
{
	int milk,coffee_powder,water,cup,sugar,emilk,ecoffee,ewater,ecup,esugar;
	FILE *stock=fopen("C:\\coffee\\ingredients.txt","r");
	fscanf(stock,"%d\n%d\n%d\n%d\n%d",&emilk,&ecoffee,&ewater,&ecup,&esugar);
	printf("Enter\n 1.Quantity of milk\n 2.Quantity of Coffee Powder\n 3.Quantity of Water\n 4.Quantity of Sugar\n 5.Number of cups\n");
	scanf("%d\n%d\n%d\n%d\n%d",&milk,&coffee_powder,&water,&sugar,&cup);
	FILE *upd=fopen("c:\\coffee\\ingredients.txt","w");
	fprintf(upd,"%d\n%d\n%d\n%d\n%d",milk+emilk,coffee_powder+ecoffee,water+ewater,sugar+esugar,ecup+cup);
	fclose(upd);
	FILE *price=fopen("c:\\coffee\\costofingredients.txt","w");
	printf("Enter\n 1.cost of 1l milk\n 2.cost of 100gm Coffee Powder\n 3.cost of 1l Water\n 4.Cost of 100gm Sugar\n 5.cost of 1 cup\n");
	int cmilk,ccoffee_powder,cwater,ccup,csugar;
	scanf("%d\n%d\n%d\n%d\n%d",&cmilk,&ccoffee_powder,&cwater,&csugar,&ccup);
	fprintf(price,"%d\n%d\n%d\n%d\n%d",cmilk,ccoffee_powder,cwater,csugar,ccup);
	fclose(price);
	int k;
	printf("Press 1. to continue from main menu \n");
	printf("\nPress 0 to exit\n");
	scanf("%d",&k);
	switch(k)
	{
	  case 1:
		admin();
		break;
	  default:
		exit(0);	
	}
	
}
void type()
{	
	printf("\n3 types of coffee available\n");
	printf("\n1.Light Coffee\n2.Medium Coffee\n3.Strong Coffee\n");
	int l;
	printf("Press 1. to continue from main menu \n");
	printf("\nPress 0 to exit\n");
	scanf("%d",&l);
	switch(l)
	{
	  case 1:
		admin();
		break;
	  default:
		exit(0);	
	}
	getch();
}
int rate(int fmilk,int fcoffee,int fwater,int fsugar,int fcup,int cusmilk,int cuscoffee,int cuswater,int cussugar)
{
	int sum=0,rmilk,rcoffee,rwater,rsugar,rcup;
	sum=ceil(((cusmilk*fmilk)/1000.0)+((cuscoffee*fcoffee)/100.0)+((cuswater*fwater)/1000.0)+((cussugar*fsugar)/100.0)+(fcup*1.0));
	return sum;
}

void availability()
{	clrscr();
	int avmilk,avcoffee,avwater,avsugar,avcup;
	FILE *available=fopen("c:\\coffee\\ingredients.txt","r");
	fscanf(available,"%d %d %d %d %d",&avmilk,&avcoffee,&avwater,&avsugar,&avcup);
	printf(" Quantity of Milk Available-%d\n Quantity of Coffee Powder Available-%d\n Quantity of water Available-%d\n Quantity of sugar available-%d\n Number of cups available-%d\n",avmilk,avcoffee,avwater,avsugar,avcup);
	fclose(available);
	int m;
	printf("Press 1. to continue from main menu \n");
	printf("\nPress 0 to exit\n");
	scanf("%d",&m);
	switch(m)
	{
	  case 1:
		admin();
		break;
	  default:
		exit(0);	
	}
	getch();
	
}
void cost()
{	
	clrscr();
	int comilk,cocoffee,cowater,cosugar,cocup;
	FILE *displaycost=fopen("c:\\coffee\\costofingredients.txt","r");
	fscanf(displaycost,"%d %d %d %d %d",&comilk,&cocoffee,&cowater,&cosugar,&cocup);
	printf(" 1.cost of 1l milk-%d\n 2.cost of 100gm Coffee Powder-%d\n 3.cost of 1l Water-%d\n 4.cost of 100gm Sugar-%d\n 5.cost of 1 cup-%d\n",comilk,cocoffee,cowater,cosugar,cocup);
	fclose(displaycost);
	int n;
	printf("Press 1. to continue from main menu \n");
	printf("\nPress 0 to exit\n");
	scanf("%d",&n);
	switch(n)
	{
	  case 1:
		admin();
		break;
	  default:
		exit(0);	
	}
	getch();
}
void strongcoffee()
{	
	clrscr();
	FILE *sptr=fopen("c:\\coffee\\ingredients.txt","r");
	int smilk,scoffee,swater,ssugar,scup,flag=0;
	fscanf(sptr,"%d %d %d %d %d",&smilk,&scoffee,&swater,&ssugar,&scup);
	FILE *cptr=fopen("c:\\coffee\\costofingredients.txt","r");
	int fmilk,fcoffee,fwater,fsugar,fcup;
	fscanf(cptr,"%d\n%d\n%d\n%d\n%d",&fmilk,&fcoffee,&fwater,&fsugar,&fcup);
	if((smilk>=100)&&(scoffee>=45)&&(swater>=40)&&(ssugar>=35)&&(scup>=1))
	{	
		int z=rate(fmilk,fcoffee,fwater,fsugar,fcup,100,45,40,35);
		printf("The cost of Your Coffee is Rs.%d\n",z);
		printf("\nPress 1 to continue or 2 to exit\n");
		int g;
		scanf("%d",&g);
		switch(g)
		{
		   case 1:
			printf("\nYour drink is dispensed... Have a nice day!!\n");
			flag=1;
			break;
		   default:
			welcome();
		}
	}
	else 
	   printf("Sorry!! Insufficient Quantities...\n");
	if(flag==1)
	{
	  smilk-=100;
	  scoffee-=45;
	  swater-=40;
	  ssugar-=35;
	  scup-=1;
	  FILE *dkd=fopen("c:\\coffee\\ingredients.txt","w");	
	  fprintf(dkd,"%d\n",(smilk<0)?0:smilk);
	  fprintf(dkd,"%d\n",(scoffee<0)?0:scoffee);
	  fprintf(dkd,"%d\n",(swater<0)?0:swater);
	  fprintf(dkd,"%d\n",(ssugar<0)?0:ssugar);
	  fprintf(dkd,"%d\n",(scup<0)?0:scup);
	}

	getch();
}
void mediumcoffee()
{	
	clrscr();
	FILE *mptr=fopen("c:\\coffee\\ingredients.txt","r");
	int mmilk,mcoffee,mwater,msugar,mcup,flag=0;
	fscanf(mptr,"%d\n%d\n%d\n%d\n%d",&mmilk,&mcoffee,&mwater,&msugar,&mcup);
	FILE *cptr=fopen("c:\\coffee\\costofingredients.txt","r");
	int fmilk,fcoffee,fwater,fsugar,fcup;
	fscanf(cptr,"%d\n%d\n%d\n%d\n%d",&fmilk,&fcoffee,&fwater,&fsugar,&fcup);
	if(mmilk>=100&&mcoffee>=35&&mwater>=45&&msugar>=30&&mcup>=1)
	{
		int z=rate(fmilk,fcoffee,fwater,fsugar,fcup,100,35,45,30);
		printf("The cost of Your Coffee is Rs.%d\n",z);
		printf("\nPress 1 to continue or 2 to exit\n");
		int f;
		scanf("%d",&f);
		switch(f)
		{
		   case 1:
			printf("\nYour drink is dispensed... Have a nice day!!\n");
			flag=1;
			break;
		   default:
			welcome();
		}
	}
	else 
	   printf("Sorry!! Insufficient Quantities...\n");
	if(flag==1)
	{
	  mmilk-=100;
	  mcoffee-=35;
	  mwater-=45;
	  msugar-=30;
	  mcup-=1;
	  FILE *dkd=fopen("c:\\coffee\\ingredients.txt","w");	
	  fprintf(dkd,"%d\n",(mmilk<0)?0:mmilk);
	  fprintf(dkd,"%d\n",(mcoffee<0)?0:mcoffee);
	  fprintf(dkd,"%d\n",(mwater<0)?0:mwater);
	  fprintf(dkd,"%d\n",(msugar<0)?0:msugar);
	  fprintf(dkd,"%d\n",(mcup<0)?0:mcup);
	}
	getch();
}
void lightcoffee()
{	
	clrscr();
	FILE *fptr=fopen("c:\\coffee\\ingredients.txt","r");
	int lmilk,lcoffee,lwater,lsugar,lcup,flag=0;
	fscanf(fptr,"%d\n%d\n%d\n%d\n%d",&lmilk,&lcoffee,&lwater,&lsugar,&lcup);
	FILE *cptr=fopen("c:\\coffee\\costofingredients.txt","r");
	int fmilk,fcoffee,fwater,fsugar,fcup;
	fscanf(cptr,"%d\n%d\n%d\n%d\n%d",&fmilk,&fcoffee,&fwater,&fsugar,&fcup);
	if(lmilk>=100&&lcoffee>=30&&lwater>=50&&lsugar>=25&&lcup>=1)
	{
		int z=rate(fmilk,fcoffee,fwater,fsugar,fcup,100,30,50,25);
		printf("The cost of Your Coffee is Rs.%d\n",z);
		printf("\nPress 1 to continue or 2 to exit\n");
		int e;
		scanf("%d",&e);
		switch(e)
		{
		   case 1:
			printf("\nYour drink is dispensed... Have a nice day!!\n");
			flag=1;
			break;
		   default:
			welcome();
		}
	}
	else 
	   printf("Sorry!! Insufficient Quantities...\n");
	if(flag==1)
	{
	  lmilk-=100;
	  lcoffee-=30;
	  lwater-=50;
	  lsugar-=25;
	  lcup-=1;
	  FILE *dkd=fopen("c:\\coffee\\ingredients.txt","w");	
	  fprintf(dkd,"%d\n",(lmilk<0)?0:lmilk);
	  fprintf(dkd,"%d\n",(lcoffee<0)?0:lcoffee);
	  fprintf(dkd,"%d\n",(lwater<0)?0:lwater);
	  fprintf(dkd,"%d\n",(lsugar<0)?0:lsugar);
	  fprintf(dkd,"%d\n",(lcup<0)?0:lcup);
	}
	getch();
}
void customcoffee()
{
	clrscr();
	FILE *fptr=fopen("c:\\coffee\\ingredients.txt","r");
	int cmilk,ccoffee,cwater,csugar,ccup,flag=0;
	fscanf(fptr,"%d\n%d\n%d\n%d\n%d",&cmilk,&ccoffee,&cwater,&csugar,&ccup);
	FILE *cptr=fopen("c:\\coffee\\costofingredients.txt","r");
	int fmilk,fcoffee,fwater,fsugar,fcup;
	fscanf(cptr,"%d\n%d\n%d\n%d\n%d",&fmilk,&fcoffee,&fwater,&fsugar,&fcup);
	int cusmilk,cuscoffee,cuswater,cussugar;
	printf(" Enter\n The amount of milk to be added:\n The amount of coffee powder to be added:\n The amount of water to be added:\n The amount of sugar to be added:\n");
	scanf("%d %d %d %d",&cusmilk,&cuscoffee,&cuswater,&cussugar);  
	if(cusmilk<=cmilk&&cuscoffee<=ccoffee&&cuswater<=cwater&&cussugar<=csugar&&ccup>=1)
	{	int z=rate(fmilk,fcoffee,fwater,fsugar,fcup,cusmilk,cuscoffee,cuswater,cussugar);
		printf("The cost of Your Coffee is Rs.%d\n",z);
		printf("\nPress 1 to continue or 2 to exit\n");
		int h;
		scanf("%d",&h);
		switch(h)
		{
		   case 1:
			printf("\nYour drink is dispensed... Have a nice day!!\n");
			flag=1;
			break;
		   default:
			welcome();
		}
	}
	else 
	   printf("Sorry!! Insufficient Quantities...\n");
	if(flag==1)
	{
	  cmilk-=cusmilk;
	  ccoffee-=cuscoffee;
	  cwater-=cuswater;
	  csugar-=cussugar;
	  ccup-=1;
	  FILE *dkd=fopen("c:\\coffee\\ingredients.txt","w");	
	  fprintf(dkd,"%d\n",(cmilk<0)?0:cmilk);
	  fprintf(dkd,"%d\n",(ccoffee<0)?0:ccoffee);
	  fprintf(dkd,"%d\n",(cwater<0)?0:cwater);
	  fprintf(dkd,"%d\n",(csugar<0)?0:csugar);
	  fprintf(dkd,"%d\n",(ccup<0)?0:ccup);
	}
	getch();
}

void user()
{       
	clrscr();
 	printf(" Press 1 for Light Coffee\n Press 2 for medium Coffee\n Press 3 for strong coffee\n Press 4 to customize your own Coffee\n");
	int d;
	scanf("%d",&d);
	switch(d)
	{
	   case 1:
		lightcoffee();
		break;
	   case 2:
		mediumcoffee();
		break;
	   case 3:
		strongcoffee();
		break;	
	   case 4:
		customcoffee();
		break;
	   default:
		printf("Enter a Valid Key");
	}
	getch();
}	
	
void admin()
{	clrscr();
	printf("\n1.Update Stock\n2.Stock Availability\n3.Cost Of Ingredients\n4.Type of Coffee\n5.Exit\n");
	int b;
	scanf("%d",&b);
	switch(b)
	{	
		case 1:
			update_stock();
			break;
		case 2:
			availability();
			break;
		case 3:
			cost();
			break;
		case 4:
			type();
			break;
		case 5:
			welcome();
			break;
		default:
			printf("Enter a valid Number");
	}
	getch();
}


void login()
{
	clrscr();
	char username[10],pwd[10];
	printf("Enter the username:");
	scanf("%s",username);
	printf("Enter the password:");
	scanf("%s",&pwd);
	if((strcmp(username,"admin")==0)&&(strcmp(pwd,"dams")==0))
	  admin();
	else
	{
	  printf("Incorrect Username or Password\n");
          printf("\nPress any key to exit\n");
	  int t;
	  scanf("%d",&t);
	  switch(t)
	  {
		default:
		   welcome();
	  }
	  }
	getch();
}
void welcome()
{
    clrscr();
    
    printf("Welcome to DAMS Coffee Vending Machine\n");
    printf("\nPress 1 to login as ADMIN\n");
    printf("\nPress 2 to continue as USER\n");
    printf("\nPress 3 to EXIT\n");
    int a;
    scanf("%d",&a);
    switch(a)
    {
	case 1:
		login();
		break;
	case 2:
		user();
		break;
	case 3:
		exit(0);
		break;
	default:
		printf("Enter a valid number:");
    }
    getch();
}


int main()
{
	welcome();
	return 0;
}



