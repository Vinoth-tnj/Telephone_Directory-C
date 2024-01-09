#include<stdio.h>
#include<conio.h>
#include<string.h>
#define N 150
struct contact
{
 char name[26];
 char mobile[11];
}data[N];
void addcontact();
void search();
void view();
void Delete();
void deleteall();
void menu();

void main()
{
int cho;
clrscr();
printf("\n\n\t\t-----Telephone Directory-----");
printf("\n\t1.Add contact\n\t2.Search contact\n\t3.View all contacts\n\t4.Delete a particular contact\n\t5.Delete All\n\t6.Press any key for Exit");
printf("\n\tEnter your choice:");
scanf("%d",&cho);
if(cho==1)
addcontact();
else if(cho==2)
search();
else if(cho==3)
view();
else if(cho==4)
Delete();
else if(cho==5)
deleteall();
else
exit(0);
}

void addcontact()
{
FILE *fp;
int i;
char name[]="exit";
clrscr();
fp=fopen("contact.txt","a");
for(i=0;i<N;++i)
{
 fflush(stdin);
 printf("\nEnter Name:");
 gets(data[i].name);
 if(strcmp(data[i].name,name)==0)
 {
  fwrite(data,sizeof(struct contact),i,fp);
  fclose(fp);
  main();
  break;
 }
 printf("\nEnter mobile no.:");
 scanf("%s",data[i].mobile);
}
fwrite(data,sizeof(struct contact),1,fp);
fclose(fp);
getch();
}

void search()
{
FILE *fp;
struct contact s;
int i,a;
char num[11];
clrscr();
fp=fopen("contact.txt","r");
printf("Enter the searching Number:");
scanf("%s",num);
while(fread(&s,sizeof(struct contact),1,fp))
{
 if(strcmp(num,s.mobile)==0)
  a=0;
}
if(a==0)
{
 printf("\nName:%s",s.name);
 printf("\nNumber:%s",s.mobile);
}
else
{
 printf("No data found!");
}
fclose(fp);
getch();
main();
}

void view()
{
FILE *fp;
struct contact s;
clrscr();
fp=fopen("contact.txt","r");
printf("\n\n\t\tContact List");
printf("\n\t     ==================");
while(fread(&s,sizeof(struct contact),1,fp))
{
  printf("\nName:%s",s.name);
  printf("\nNumber:%s",s.mobile);
}
fclose(fp);
getch();
main();
}

void Delete()
{
FILE *fp,*fptr;
struct contact s;
char number[11];
clrscr();
printf("Which number you want to delete?");
fflush(stdin);
gets(number);
fp=fopen("contact.txt","r");
fptr=fopen("temp.txt","w");
while(fread(&s,sizeof(struct contact),1,fp))
{
 if(strcmp(number,s.mobile)!=0)
 fwrite(&s,sizeof(struct contact),1,fptr);
}
fclose(fp);
fclose(fptr);
remove("contact.txt");
rename("temp.txt","contact.txt");
printf("%s deleted successfully",number);
getch();
main();
}

void deleteall()
{
FILE *fp,*fptr;
struct contact s;
char number[11];
clrscr();
fp=fopen("contact.txt","r");
fptr=fopen("temp.txt","w");
fclose(fp);
fclose(fptr);
remove("contact.txt");
rename("temp.txt","contact.txt");
printf("All Contacs has been deleted successfully");
getch();
main();
}

