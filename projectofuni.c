#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int comp=0;
int issue=0;
void computerdepartment();
void welcome();
void removebook();
void searchbook();
void modify();
void exitprogram();
void login();
void user();
void userlistbook();	
void screen();
void issuebook();
void issuerecord();
void issuedlist();

struct book
{
	char bookname[40];
	int id;
	float price;
		
};

struct book storing[400];

struct record
{
	int id;
	char name[60];
	float price;
	char author[60];
	int token;
	
	
};
struct record information[400];

void issuedlist()
{
	int i;
	printf("#. Name                      ID           PRICE\n");
	for (i=0;i<issue;i++)
	{
		printf("%d. %s                      %d           %f\n",i+1,storing[i].bookname,storing[i].id,storing[i].price);
	}
	
	printf("\n\n\t\t Press b to go back to main menu");
	char ch;
	while((ch=getch())!='b'){
	}
	computerdepartment();
	
}

void comprecord()
{
	FILE *filepointer;
	
	filepointer=fopen("record.txt","r");
	if (filepointer==NULL)
	{
	
	FILE *filepointer;
	filepointer=fopen("record.txt","w");
	fclose(filepointer);
    }
	char ch;static char string[40][40];int i=0,j=0;
	
	ch=getc(filepointer);
	
	if (ch<0)
	issuerecord();
	
	else
	{
	
	rewind(filepointer);

	while (!feof(filepointer))
	{
		
		while ((ch=getc(filepointer))!='\n')
		{
			string[j][i]=ch;
			i++;
		}
		
		i=0;
		
		strcpy(information[comp].name,string[j]);
		j++;
		
		static char string1[40][40];i=0,j=0;
		
		while ((ch=getc(filepointer))!='\n')
		{
			string1[j][i]=ch;
			i++;
		}

		i=0;
		
		strcpy(information[comp].author,string1[j]);
		j++;
		
	    fscanf(filepointer,"%d\n",&information[comp].id);
	    fscanf(filepointer,"%d\n",&information[comp].token);
		fscanf(filepointer,"%f\n",&information[comp].price);
		
		
		comp++;
	}
	fclose(filepointer);

	issuerecord();
    }
}

void searchbook()
{
	system("cls");
	
		if (comp==0)
	{
	int c,d;
	printf("\n\nPlease first enter any book in the records...");
		for (c = 1; c <= 20000; c++)
    for (d = 1; d <= 20000; d++)
    {}
	computerdepartment();}
	
	else{
	printf("Enter id of a book you want to search\n");
	int id,temp=0,c,d,i,count=0;
	scanf("%d",&id);
	
	for (i=0;i<comp;i++)
	{
		if (id==information[i].id)
		{
			temp=i;
			count++;
		}
	}
	
	if (count>0)
	{
		printf("\n\nBook Information :\n\nName: %s\nAuthor : %s \nID: %d\nPrice: %f\nToken No : %d",information[temp].name,information[temp].author,information[temp].id,information[temp].price,information[temp].token);
		
		printf("\n\nPress b to go back to main menu");
		
		char ch;
		while((ch=getch())!='b')
		{
		}
		computerdepartment();
	}
	
	else
	{
	
	printf("The following book doesn't exist.You can view ids of books in the list..\n \n\n\n \tReturning to the main menu...");
	for (c = 1; c <= 35000; c++)
    for (d = 1; d <= 35000; d++)
    {}
   } 
    
    computerdepartment();
}
}

void modify()
{
		if (comp==0)
	{
	int c,d;
	printf("\n\nPlease first enter any book in the records...");
		for (c = 1; c <= 20000; c++)
    for (d = 1; d <= 20000; d++)
    {}
	computerdepartment();}
	
	else{
	printf("Enter id of a book you want to modify");
	int id,temp=0,c,d,i,count=0;
	scanf("%d",&id);
	
	for (i=0;i<comp;i++)
	{
		if (id==information[i].id)
		{
			temp=i;
			count++;
		}		
    }
    
    if (count==0)
    {
	
    printf("Id doesn't exist");
    printf("\n\n\n \tReturning back ....");
	
	int c,d;
	for (c = 1; c <= 30000; c++)
    for (d = 1; d <= 30000; d++)
    {}
    
	computerdepartment();
}
    else
    {
	
	fflush(stdin);
	printf("Enter book name\n");
	fflush(stdin);
	char ch;
	char string[40][40];
	int m,n=0;
	fflush(stdin);
	
	while ((ch=getch())!='\r')
	{
		printf("%c",ch);
		string[temp][n]=ch;
		n++;
		
	}
	printf("\n");
	m=n;
	
	fflush(stdin);
	n=0;
	fflush(stdin);
	string[temp][m]='\0';
	strcpy(information[temp].name,string[temp]);
	fflush(stdin);
	
	printf("Enter book author\n");
	fflush(stdin);

	n=0;
	fflush(stdin);
	
	char string1[40][40];
	while ((ch=getch())!='\r')
	{
		printf("%c",ch);
		string1[temp][n]=ch;
		n++;
		
	}
	printf("\n");
	m=n;
	
	fflush(stdin);
	n=0;
	fflush(stdin);
	string1[temp][m]='\0';
	strcpy(information[temp].author,string1[temp]);
	fflush(stdin);
	
	printf("Enter price of book\n");
	fflush(stdin);
	scanf("%f",&information[temp].price);
	fflush(stdin);
	
	printf("Enter token of book\n");
	fflush(stdin);
	scanf("%d",&information[temp].token);
	fflush(stdin);
	
	

	printf("You book has been entered in our record\n\n Returning to main menu.");
	

	int c,d;
	   for (c = 1; c <= 30000; c++)
       for (d = 1; d <= 30000; d++)
       {}
	computerdepartment();
    	
	}
}

}

void enterbookinfo()
{
	fflush(stdin);
	
	printf("Enter book id\n");
	fflush(stdin);
	scanf("%d",&information[comp].id);
	fflush(stdin);
	int i;
	fflush(stdin);
	for (i=0;i<comp;i++)
	{
	fflush(stdin);
		if (information[comp].id==information[i].id )
	    	{
		        printf("\n\nselect another id , it already exists\n\n");
	        	enterbookinfo();
        	}
	fflush(stdin);
	}
	
	
	for (i=0;i<issue;i++)
	{
	fflush(stdin);
		if (information[comp].id==storing[i].id)
	    	{
		        printf("\n\nselect another id , it already exists\n\n");
	        	enterbookinfo();
        	}
	fflush(stdin);
	}

	fflush(stdin);
	printf("Enter book name\n");
	fflush(stdin);
	char ch;
	char string[40][40];
	int m,n=0;
	fflush(stdin);
	
	while ((ch=getch())!='\r')
	{
		printf("%c",ch);
		string[comp][n]=ch;
		n++;
		
	}
	m=n;
	printf("\n");
	fflush(stdin);
	n=0;
	fflush(stdin);
	string[comp][m]='\0';
	strcpy(information[comp].name,string[comp]);
	fflush(stdin);
	//author
	
	printf("Enter book author\n");
	fflush(stdin);

	n=0;
	fflush(stdin);
	
	char string1[40][40];
	while ((ch=getch())!='\r')
	{
		printf("%c",ch);
		string1[comp][n]=ch;
		n++;
		
	}
	m=n;
	printf("\n");
	fflush(stdin);
	n=0;
	fflush(stdin);
	string1[comp][m]='\0';
	strcpy(information[comp].author,string1[comp]);
	fflush(stdin);
	

	
	printf("Enter price of book\n");
	fflush(stdin);
	scanf("%f",&information[comp].price);
	fflush(stdin);
	
	printf("Enter token of book\n");
	fflush(stdin);
	scanf("%d",&information[comp].token);
	fflush(stdin);
	FILE *filepointer;
	
	
	filepointer=fopen("record.txt","a");
	
	fprintf(filepointer,"%s\n",information[comp].name);
	fprintf(filepointer,"%s\n",information[comp].author);
	fprintf(filepointer,"%d\n",information[comp].id);
	fprintf(filepointer,"%d\n",information[comp].token);
	fprintf(filepointer,"%4f\n\n\n",information[comp].price);
	
	

	comp++;
	system("cls");
	printf("You book has been entered in our record\n\n Returning to main menu..");
	
	fclose(filepointer);
	int c,d;

	computerdepartment();
		for (c = 1; c <= 20000; c++)
    for (d = 1; d <= 20000; d++)
    {}
}

void removebook()
{
	if (comp==0)
	{
	int c,d;
	printf("\n\nPlease first enter any book in the records...");
		for (c = 1; c <= 20000; c++)
    for (d = 1; d <= 20000; d++)
    {}
	computerdepartment();
}
	else{
	
	int searchid,temp;
	printf("Enter id of book you want to remove\n");
	scanf("%d",&searchid);
	int i,j,match=0;
	system("cls");
	for (i=0;i<=comp;i++)
	{
		if (information[i].id==searchid)
		{
			temp=i;
			match++;
		}
		
	}
	
	if (match>=1)
	{
	
	    for (i=temp;i<comp;i++)
	    {
	    	information[i]=information[i+1];
	    }
	    printf("The book has been removed");
	  comp--;
    }
    
    else
    {
	
         printf("The id doesn't exist that you entered \n");
    }    
    
	
	
	FILE *filepointer;
	filepointer=fopen("record.txt","w");
	
	for (i=0;i<comp;i++)
	{
		fprintf(filepointer,"%s\n",information[i].name);
        fprintf(filepointer,"%s\n",information[comp].author);
	    fprintf(filepointer,"%d\n",information[i].id);
	    fprintf(filepointer,"%d\n",information[i].token);
        fprintf(filepointer,"%4f\n\n\n",information[i].price);
        
	
	}
	fclose(filepointer);
	printf("\n\n\n Returning back ....");
	
	int c,d;
	for (c = 1; c <= 30000; c++)
    for (d = 1; d <= 30000; d++)
    {}
    
	computerdepartment();
}
	
}

void listbook()
{
	
	system("cls");
		if (comp==0)
	{
	int c,d;
	printf("\n\nPlease first enter any book in the records...");
		for (c = 1; c <= 20000; c++)
    for (d = 1; d <= 20000; d++)
    {}
	computerdepartment();
	}else{
	
	int i;
	printf("#. Name                      ID           PRICE\n");
	for (i=0;i<comp;i++)
	{
		printf("%d. %s                      %d           %f\n",i+1,information[i].name,information[i].id,information[i].price);
	}
	
	char ch;
	printf("\n\n\nGet the details of the book by searching.Option is available in the main menu.\n\nPress b to go back");
	while ((ch=getch())!='b')
	{
	}
	computerdepartment();
}
	
}

void computerdepartment()
{
	system("cls");
	int select;
	printf("\n\n\n\t\t\t\t\t1. Enter Book \n");
	printf("\t\t\t\t\t2. Remove Book\n");
	printf("\t\t\t\t\t3. List All Available books\n");
	printf("\t\t\t\t\t4. Search any Book\n");
	printf("\t\t\t\t\t5. Modify data \n");
	printf("\t\t\t\t\t6. Issued Books\n");
	printf("\t\t\t\t\t7. Go back\n");
	printf("\t\t\t\t\t8. Exit the program\n");
	
	
	scanf("%d",&select);
	
	switch (select)
	{
		case 1:
			enterbookinfo();
		
		case 2:
			removebook();
		
		case 3:
			listbook();
			
		case 4:
			searchbook();
			
		case 5:
		    modify();
		
		case 6:
		    issuedlist();	
			
		case 7:
		     screen();		

		case 8:
		 	exitprogram();
	}
}


main()
{
	//Storing records
	
	comprecord();
	
}

void welcome()
{
		
	printf("Welcome to our project\n\n Press any enter to continue");
	char ch;
	
	while((ch=getch())!='\r')
	{	}
	switch(ch)
	{
		default:
		screen();
	}
	
}

void screen()
{
	int n;	
	system("cls");
	printf("\n\n\n\t\t1. For admin use\n");
	printf("\t\t2. For user use\n");
	printf("\t\t3. For exit\n");
	scanf("%d",&n);
	
	switch (n)
	{
		case 1:
			login();
		
		case 2:
		    user();	
		    
		case 3:
			exitprogram();

	}
}

void user()
{
	system("cls");
	int n;

	printf("\n\n\n\n\t\t 1. Show All available Books\n");
	printf("\t\t 2. Issue book by id\n\t\t");
	printf(" 3. Back\n\t\t");
		scanf("%d",&n);
	
	switch (n)
	{
	
	case 1:
		userlistbook();
	
	case 2:
		issuebook();
		
	case 3:
		screen();
   }
}

void issuebook()
{
	printf("Enter id of a book that you want to issue");
	int issueid,i,tok;
	int c,d;
	
	scanf("%d",&issueid);
	int temp,count=0;
	for (i=0;i<comp;i++)
	{
		if (issueid==information[i].id)
		{
			temp=i;
			count++;
		}
	}
	
	if (count==0)
	{int c,d;
		printf("This id book doesn't exist.. Returning back....");
			for (c = 1; c <= 30000; c++)
    for (d = 1; d <= 30000; d++)
    
    {}
		user();
	}
	
	else
	{
		system("cls");
		printf("\n\n\n\t\t The details of the book is");
		
		printf("\n\nBook Information :\n\nName: %s\nAuthor : %s \nID: %d\nPrice: %f",information[temp].name,information[temp].author,information[temp].id,information[temp].price)
		
		;printf("\n\n You will receive token after payment from the counter\nEnter the token please : ");
		
		scanf("%d",&tok);
		
		if (tok==information[temp].token)
		{
		strcpy(storing[issue].bookname,information[temp].name);
		storing[issue].id=information[temp].id;
		storing[issue].price=information[temp].price;
	    }
	    
	}
	if (tok==information[temp].token)
	{
	
	FILE *filepointer;
	filepointer=fopen("issue.txt","a");
	
	fprintf(filepointer,"%s\n",storing[issue].bookname);
	fprintf(filepointer,"%d\n",storing[issue].id);
	fprintf(filepointer,"%f\n\n",storing[issue].price);
	
	issue++;
	
	
	      
      	for (i=temp;i<comp;i++)
	    {
	    	information[i]=information[i+1];
	    	comp--;
	    }
	
	printf("\n\n\t\t\t\t Code Authorized. Your book has been issued for 30 days");    
	    
    for (c = 1; c <= 30000; c++)
    for (d = 1; d <= 30000; d++)
    
    {}  
	user();
}

else {
printf("\n\n\n The token entered is invalid. Please repeat the process");
	for (c = 1; c <= 30000; c++)
    for (d = 1; d <= 30000; d++)
    {
	}
	
user();

	
}
	
}

void userlistbook()
{
	
	system("cls");
		if (comp==0)
	{
	int c,d;
	printf("\n\nPlease first enter any book in the records...");
		for (c = 1; c <= 20000; c++)
    for (d = 1; d <= 20000; d++)
    {}
	computerdepartment();
	}else{
	
	int i;
	printf("#. Name                      ID           PRICE\n");
	for (i=0;i<comp;i++)
	{
		printf("%d. %s                      %d           %f\n",i+1,information[i].name,information[i].id,information[i].price);
	}
	
	char ch;
	printf("\n\n\nPress b to go back");
	while ((ch=getch())!='b')
	{
	}
	user();
}
}

void login()
{
	char password[40]={"fcit"};
		int c,d;
	printf("\n\n\n \t\t Enter password to login\n\t\t");
	char string[40];
	scanf("%s",string);
	int i,count=0;
	for (i=0;i<4;i++){
	int c,d;
	if (password[i]==string[i])
	{
		
		count++;
	}
}
    if (count==4)
    {
	
	printf("\n\n\t\t Login Successful.");
    
    	for (c = 1; c <= 30000; c++)
    for (d = 1; d <= 30000; d++)
    
    
    {}
    computerdepartment();
    
    }
    
	else
	{
	
	printf("\n\n\t\tWrong password\n \t\tTry again");

	for (c = 1; c <= 30000; c++)
    for (d = 1; d <= 30000; d++)
    
    {}
    system("cls");
	login();
    }	
}

void issuerecord()
{
	
	FILE *filepointer;
	
	filepointer=fopen("issue.txt","r");
	if (filepointer==NULL)
	{
	
	FILE *filepointer;
	filepointer=fopen("issue.txt","w");
	fclose(filepointer);
    }
	char ch;static char string[40][40];int i=0,j=0;
	
	ch=getc(filepointer);
	
	if (ch<0)
	welcome();
	
	else
	{
	
	rewind(filepointer);

	while (!feof(filepointer))
	  {
		
		while ((ch=getc(filepointer))!='\n')
		{
			string[j][i]=ch;
			i++;
		}
		string[j][i]='\0';
		
		i=0;
		
		strcpy(storing[issue].bookname,string[j]);
		j++;
		
		fscanf(filepointer,"%d\n",&storing[issue].id);
	    fscanf(filepointer,"%f\n",&storing[issue].price);
issue++;
      }
      
      fclose(filepointer);

      welcome();

    }
    
    
    
}

void exitprogram()
{
	int i;
	FILE *filepointer;
	filepointer=fopen("record.txt","w");
	
	for (i=0;i<comp;i++)
	{
		fprintf(filepointer,"%s\n",information[i].name);
		fprintf(filepointer,"%s\n",information[i].author);
	    fprintf(filepointer,"%d\n",information[i].id);
	    fprintf(filepointer,"%d\n",information[i].token);
        fprintf(filepointer,"%4f\n\n\n",information[i].price);
        
	}
	fclose(filepointer);
	
	exit(0);
	printf("");
}
