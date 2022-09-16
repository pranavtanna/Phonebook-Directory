//PROGRAM FOR PHONEBOOK ***********

//HEADER FILES ****************

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<alloc.h>
#include<string.h>
#include<graphics.h>

//STRUCTURE DEFINE ************

struct entry
{
char name[50];
char city[50];
char cont[50];
struct entry *lptr;
struct entry *rptr;
}*temp,*newe,*l,*r;

//FUNCTION DEFINE ***************

typedef struct entry *list;
void newentry();
void display(char n[50]);
void deletentry(char n[50]);
void displayall();
void makempty();
int isempty();
void saventry();
void loadentry();
void deleteall();
void newentry()

{
char b[50],c[50],d[50];
int i,k=0;
printf("\n\t ENTER REQUIRED INFORMATION :");
printf("\n Name :-");
scanf("%s",b);
printf("\n City :-");
scanf("%s",c);
printf("\n Contact No :-");
scanf("%s",d);

newe=(struct entry*)malloc(sizeof(struct entry));

for(i=0;i<50;i++)
{
 newe->name[i]=' ';
 newe->city[i]=' ';
 newe->cont[i]=' ';
}

for(i=0;i<50;i++)
{
 newe->name[i]=b[i];
 newe->city[i]=c[i];
 newe->cont[i]=d[i];
}
 if(isempty())
  {
   newe->lptr=newe->rptr=NULL;
   l=r=newe;
   printf("\n\t YOUR ENTRY HAS BEEN ADDED !!!");
  }
 else
  {
   temp=l;
   while(temp!=NULL)
   {
     i=stricmp(newe->name,temp->name);
      if(i<0)
      break;
      else if(i>0)
      temp=temp->rptr;
      else if(i==0)
	{
	  printf("\n\t Name ALREADY EXSISTS ! Entry cannot be ADDED !");
	  k=1;
	  break;
	}
   }
  if(k!=1)
   {
    if(temp==l)
     {
       newe->lptr=NULL;
       newe->rptr=l;
       l->lptr=newe;
       l=newe;
       printf("\n\t YOUR ENTRY HAS BEEN ADDED !!!");
     }
    else if(temp==NULL)
     {
       newe->rptr=NULL;
       newe->lptr=r;
       r->rptr=newe;
       r=newe;
       printf("\n\t YOUR ENTRY HAS BEEN ADDED !!!");
     }
   else
     {
       newe->rptr=temp;
       newe->lptr=temp->lptr;
       temp->lptr=newe;
       (newe->lptr)->rptr=newe;
       printf("\n\t YOUR ENTRY HAS BEEN ADDED !!!");
     }
   }
 }
}

void displayall()
{
  int n=1;
  if(!isempty())
   {
    temp=l;
    while(temp!=NULL)
     {
       printf("[%d] \n Name :%s \n City :%s \n Contact.No:%s ",n,temp->name,temp->city,temp->cont);
       temp=temp->rptr;
       n++;
     }
   }
    else
     printf("\n\t ADDRESS BOOK IS EMPTY !!!");
}

void deletentry(char n[50])
{
 int i;
 if(isempty())
 printf("\n\t ADDRESS BOOK IS EMPTY !!!");
 else
  {
   temp=l;
   while(temp!=NULL)
    {
      i=stricmp(temp->name,n);
      if(i==NULL)
       {
	 if(l==r)
	  {
	    l=r=NULL;
	    printf("\n\t ENTRY DELETED SUCCESSFULLY !!");
	    break;
	  }
	 else if(temp==l)
	 {
	    l=l->rptr;
	    l->lptr=NULL;
	    printf("\n\t ENTRY DELETED SUCCESSFULLY !!");
	    break;
	 }
	 else if(temp==r)
	 {
	    r=r->lptr;
	    r->rptr=NULL;
	    printf("\n\t ENTRY DELETED SUCCESSFULLY !!");
	    break;
	  }
	 else
	  {
	    (temp->lptr)->rptr=temp->rptr;
	    (temp->rptr)->lptr=temp->lptr;
	    printf("\n\t ENTRY DELETED SUCCEESSFULLY ");
	    break;
	  }
      }
     temp=temp->rptr;
   }
  if(temp==NULL)
 printf("\n\t NOT FOUND");
 }
}

int isempty()
{
 return l==NULL;
}

void makempty()
{
 l=r=NULL;
 printf("\n\t ADDRESS BOOK EMPTIED SUCCESSFULLY !!");
}

void display(char n[50])
{
 int i,p=1;
 if(isempty())
 printf("\n\t ADDRESS BOOK IS EMPTIED SUUCCESSFULLY !!");
 else
  {
   temp=l;
   while(temp!=NULL)
    {
     i=stricmp(temp->name,n);
     if(i==NULL)
      {
       if(p==1)
       printf("\n ENTRY is found in %dst position",p);
       else if(p==2)
       printf("\n ENTRY is found in %dnd position",p);
       else if (p==3)
       printf("\n ENTRY is found in %drd position",p);
       else
       printf("\n ENTRY is found in %dth position",p);
       printf("\n\t Name :%s \n\t City : %s \n\t Contact.No:%s ",temp->name,temp->city,temp->cont);
       break;
      }
    temp=temp->rptr;
    p++;
  }
 if(temp==NULL)
 printf("\n\t NOT FOUND");
 }
}

void saventry()
{
  char n[50];
  int c;
  list t;
  int i;t=l;
  printf("\n\t ENTER NAME OF PERSON :- ");
  scanf("%s",n);
  if(isempty())
  printf("\n\t Address Book is Empty");
  else
   {
     FILE *f;
     f=fopen("entry.c","a");
     while(t!=NULL)
      {
	i=stricmp(t->name,n);
	if(i==0)
	    {
	       fprintf(f,"%s %s %s",t->name,t->city,t->cont);
	       printf("\n\t ENTRY SAVED !");
	       printf("\n\t Add ANOTHER ENTRY ? (1-yes/2-no)");
	       scanf("%d",&c);
	       if(c==1)
	       saventry();
	       else if(c==2)
	       break;
	      }
	    t=t->rptr;
	   }
	 fclose(f);
	 if(t==NULL)
	 printf("\n\t Entry Not Found");
	}
     }

void loadentry()
 {
  int i=1;
  list t;
  FILE *f;
  f=fopen("entry.c","r");
  if(f==NULL)
   {
     printf("\n\t Cannot Be Open");
     exit(1);
   }
  while(fscanf(f," %s %s %s ",t->name,t->city,t->cont)!=EOF)
   {
     printf("[%d]\n\t Name :%s \n\t City :%s \n\t Contact.No:%s",i,t->name,t->city,t->cont);i++;}
     fclose(f);
   }

void deleteall()
  {
    FILE *f;
    f=fopen("entry.c","w");
    fclose(f);
    printf("\n\t All Files Have been Deleted !");
  }


//MAIN FUNCTION **************


void main()
{
 int l,m;
 int gd=DETECT,gm;
 char n[50];
 initgraph(&gd,&gm,"C:\TURBOC3\BGI");
 while(l!=9)
 {
  clrscr();
  textmode(C80);
  textcolor(3);
  cprintf("\n !! PHONEBOOK DIRECTORY !!\n");
  cprintf(" COLLEGE - KC College Of Engineering Management Studies and Research ,BY - Akash And Pranav");
  cprintf("\n Enter Your Choice \n ------ \n ");
  cprintf("(1)-NEW ENTRY");
  cprintf("(2)-DISPLAY AN ENTRY");
  cprintf("(3)-DELETE AN ENTRY");
  cprintf("(4)-DISPLAY ENTRIES");
  cprintf("(5)-EMPTY DIRECTORY");
  cprintf("(6)-SAVE ENTRY");
  cprintf("(7)-LOAD ENTRIES");
  cprintf("(8)-DELETE SAVED ENTRIES");
  cprintf("(9)-END");
  cprintf(" -----");
  retur:
  scanf("%d",&l);
  switch(l)
   {
     case 1:
	     textcolor(3);
	     newentry();
	     getch();
		  break;
     case 2:
	     textcolor(3);
	     cprintf("\n Enter the Name of the Person to Display - \n");
	     scanf("%s",&n);
	     display(n);
	     getch();
	     break;
     case 3:
	     textcolor(3);
	     cprintf("\n Enter the Name of the Person to Deleted - \n ");
	     scanf("%s",&n);
	     deletentry(n);
	     getch();
	     break;
     case 4:
	     textcolor(3);
	     displayall();
	     getch();
	     break;
     case 5:
	     textcolor(3);
	     makempty();
	     getch();
	     break;
     case 6:
	     textcolor(3);
	     saventry();
	     getch();
	     break;
     case 7:
	     textcolor(3);
	     loadentry();
	     getch();
	     break;
     case 8:
	     textcolor(3);
	     deleteall();
	     getch();
	     break;
     case 9:
	     textcolor(3);
	     printf("\n\t THANK YOU !!!");
	     getch();
	     break;
     default:
	     textcolor(2);
	     printf("\n ENTER RIGHT CHOICE 1-9");
	     getch();
	     goto retur;
   }
 }
}


