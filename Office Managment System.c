// User-id = user
// Password = pass

//  ** Notice **
// If you are running the code for first time then you have to use the *Populate function* first to create and populate the File.
// Otherwise the other function won't run properly.


#include<stdio.h>
#include<string.h>
#define MAX_REC 50


typedef struct
{
    char name[50];
    char address[100];
    char rank[50];
    int age;
    int salary;
    int id;

}rec;

void add(rec r[MAX_REC])
{

   int i=0;
   int n;

    FILE *num;
    num=fopen("num.txt","r");
    fscanf(num,"%d",&n);
    fclose(num);
    num=fopen("num.txt","w");
    n+=1;
    fprintf(num,"%d",n);
    fclose(num);


    gets(stdin);
    printf("Enter employee name: \n");
    gets(r[i].name);
    printf("Enter employee address : \n");
    gets(r[i].address);
    printf("Enter employee rank : \n");
    gets(r[i].rank);
    printf("Enter employee age: \n");
    scanf("%d",&r[i].age);
    printf("Enter employee salary : \n");
    scanf("%d",&r[i].salary);
    printf("Enter employee id : \n");
    scanf("%d",&r[i].id);
    fflush(stdin);

    FILE *bp;
    bp=fopen("bp.txt","a");
    fprintf(bp,"%s\n%s\n%s\n%d\n%d\n%d\n",r[i].name,r[i].address,r[i].rank,r[i].age,r[i].salary,r[i].id);
    fclose(bp);

    printf("\nSuccessfully Added\n\n");
    printf("Press any key to return to \'Main Menu\' .......");

    getch();
    system("cls");


}

void view(rec r[MAX_REC])
{
    int i,n;
    FILE *numv;
    numv=fopen("num.txt","r");
    fscanf(numv,"%d",&n);
    fclose(numv);

    FILE *bpv;
    bpv=fopen("bp.txt","r");
    for(i=0;i<n;i++){

        fgets(r[i].name,100,bpv);
        fgets(r[i].address,100,bpv);
        fgets(r[i].rank,100,bpv);
        fscanf(bpv,"%d %d %d",&r[i].age,&r[i].salary,&r[i].id);
        getc(bpv);



    }
    fclose(bpv);



   printf("\nThese are the employees currently working in our company: \n\n");
   for(i=0;i<n;i++)
   {
        printf("\nEmployee name:%s",r[i].name);
        printf("Employee address:%s",r[i].address);
        printf("Employee rank:%s",r[i].rank);
        printf("Employee age:%d \n",r[i].age);
        printf("Employee salary:%d \n",r[i].salary);
        printf("Employee id :%d \n",r[i].id);
        printf("______________________________________________________\n");
   }
   printf("\n\nPress any key to return to \'Main Menu\' .......");
   getch();
   system("cls");
}

void search(rec r[MAX_REC])
{
    int n;
    FILE *numv;
    numv=fopen("num.txt","r");
    fscanf(numv,"%d",&n);
    fclose(numv);

    FILE *bpv;
    bpv=fopen("bp.txt","r");
    int i;
    for(i=0;i<n;i++){
        fgets(r[i].name,100,bpv);
        fgets(r[i].address,100,bpv);
        fgets(r[i].rank,100,bpv);
        fscanf(bpv,"%d %d %d",&r[i].age,&r[i].salary,&r[i].id);

        getc(bpv);
    }
    fclose(bpv);


 int found=0;

 gets(stdin);
 char search_emp[50];
 printf("Enter name of Employee: ");
 fgets(search_emp,100,stdin);

    for(i=0;i<MAX_REC;i++)
    {
        if(strcmp(search_emp,r[i].name)==0)
            {
                found=1;
                printf("\nEmployee details:");
                printf("\nEmployee name: %s",r[i].name);
                printf("Employee address: %s",r[i].address);
                printf("Employee rank: %s",r[i].rank);
                printf("Employee age: %d\n",r[i].age);
                printf("Employee salary: %d\n",r[i].salary);
                printf("Employee id: %d\n",r[i].id);
            }

    }
    if(found==0)
    {
    printf("Employee does not exist!\n");
    }
    printf("\n\n\nPress any key to return to \'Main Menu\' .......");
    getch();
    system("cls");

}

void modify(rec r[MAX_REC])
{
    int n,i;
    int id1,par;

    FILE *numv;
    numv=fopen("num.txt","r");
    fscanf(numv,"%d",&n);
    fclose(numv);

    FILE *bpv;
    bpv=fopen("bp.txt","r");
    for(i=0;i<n;i++){
        fgets(r[i].name,100,bpv);
        fgets(r[i].address,100,bpv);
        fgets(r[i].rank,100,bpv);
        fscanf(bpv,"%d %d %d",&r[i].age,&r[i].salary,&r[i].id);
        getc(bpv);


    }
    fclose(bpv);
    int track=-1;

    printf("Enter id of employee whose records will be modified: \n");
    scanf("%d",&id1);
    for(i=0;i<n;i++)
    {
            if(r[i].id==id1)
            {
            track=i;
            }
    }
    if (track<0)
    {
        printf("INVALID ID!\n");
    }
    if (track>=0)
    {
        printf("Enter parameter to edit: \n");
        printf("1.Employee name:\n");
        printf("2.Employee address:\n");
        printf("3.Employee rank:\n");
        printf("4.Employee age:\n");
        printf("5.Employee salary:\n");
        printf("6.Employee id:\n");

        printf("Enter required number to continue: \n");
        scanf("%d",&par);
        char smod[100];
        int dmod;
        float id2;
        switch(par)
        {
            case 1:
                gets(stdin);
                printf("Enter name:");
                gets(smod);
                strcpy(r[track].name,smod);
                strcat(r[track].name,"\n");
                break;

            case 2:
                gets(stdin);
                printf("Enter address:");
                gets(smod);
                strcpy(r[track].address,smod);
                strcat(r[track].address,"\n");
                break;

            case 3:
                gets(stdin);
                printf("Enter rank: ");
                gets(smod);
                strcpy(r[track].rank,smod);
                strcat(r[track].rank,"\n");
                break;
            case 4:
                gets(stdin);
                printf("Enter age:");
                scanf("%d",&dmod);
                r[track].age=dmod;
                break;
            case 5:
                printf("Enter salary: ");
                scanf("%d",&dmod);
                r[track].salary=dmod;
                break;
            case 6:
                printf("Enter id: ");
                scanf("%d",&id2);
                r[track].id=id2;
                break;
            default:
                printf("WRONG INPUT!");
                break;
        }

    }
    bpv=fopen("bp.txt","w");
    for(i=0;i<n;i++){
        fprintf(bpv,"%s%s%s%d\n%d\n%d\n",r[i].name,r[i].address,r[i].rank,r[i].age,r[i].salary,r[i].id);
    }
    fclose(bpv);

    printf("\n\n\nPress any key to return to \'Main Menu\' .......");
    getch();
    system("cls");
}

void del(rec r[MAX_REC])
{
    int n;
    FILE *numv;
    numv=fopen("num.txt","r");
    fscanf(numv,"%d",&n);
    fclose(numv);

    int i;
    FILE *bpv;
    bpv=fopen("bp.txt","r");
    for(i=0;i<n;i++){
        fgets(r[i].name,100,bpv);
        fgets(r[i].address,100,bpv);
        fgets(r[i].rank,100,bpv);
        fscanf(bpv,"%d %d %d",&r[i].age,&r[i].salary,&r[i].id);

        getc(bpv);
    }
    fclose(bpv);

    gets(stdin);
    char name[100];
    printf("Enter name of the employee:");
    fgets(name,100,stdin);
    int m=0;
    int mark[m];
    for(i=0;i<n;i++){
        if(strcmp(r[i].name,name)==0){
            m++;
            mark[m-1]=i;
        }
    }
    int j;
    int k=0;
    for(i=0;i<m;i++){
    for(j=mark[i];j<n-1;j++){
        r[j]=r[j+1];
        }
    k++;
    mark[i+1]-=k;
    n--;
    }
    numv=fopen("num.txt","w");
    fprintf(numv,"%d",n);
    fclose(numv);
    bpv=fopen("bp.txt","w");
    for(i=0;i<n;i++){
        fprintf(bpv,"%s%s%s%d\n%d\n%d\n",r[i].name,r[i].address,r[i].rank,r[i].age,r[i].salary,r[i].id);
    }
    fclose(bpv);

    printf("Successfully Deleted");
    printf("\n\n\nPress any key to return to \'Main Menu\' .......");

    getch();
    system("cls");
}

void pop(rec r[MAX_REC],int n)
{
    int i;
    printf("Enter number of employees: \n");
    scanf("%d",&n);
    FILE *num;
    num=fopen("num.txt","w");
    fprintf(num,"%d",n);
    fclose(num);
    for(i=0;i<n;i++)
    {
    gets(stdin);
    printf("Enter employee name: \n");
    gets(r[i].name);
    printf("Enter employee address: \n");
    gets(r[i].address);
    printf("Enter employee rank: \n");
    gets(r[i].rank);
    printf("Enter employee age: \n");
    scanf("%d",&r[i].age);
    printf("Enter employee salary: \n");
    scanf("%d",&r[i].salary);
    printf("Enter employee id: \n");
    scanf("%d",&r[i].id);


    }
    FILE *bp;
    bp=fopen("bp.txt","w");
    for(i=0;i<n;i++)
    {
           fprintf(bp,"%s\n%s\n%s\n%d\n%d\n%d\n",r[i].name,r[i].address,r[i].rank,r[i].age,r[i].salary,r[i].id);
    }
    fclose(bp);

    printf("Press any key to return to \'Main Menu\' .......");
    getch();
    system("cls");

}


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{

    printf("\n  ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ");
    printf(" \n                        ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                        ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';

	i=0;
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)
	{
	printf("  \n\n\n \t\tWELCOME TO OFFICE MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL");
	    printf("\n LOADING PLEASE WAIT... \n");

	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();


	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for three times!!!");

		getch();
        exit(0);
		}
		system("cls");
}


int main()
{
   login();


   while(1){

    int m,n;
    rec r[100];

   printf("\n\n\n\n\t\t\t\t********** -------------------------**********\n");
   printf("\t\t\t\t********** OFFICE MANAGEMENT SYSTEM **********\n");
   printf("\t\t\t\t********** -------------------------**********\n");
    printf("Main menu: \n");
    printf("---------------------------------------------------------------------------------------------------\n\t");
    printf("1.View\n\t2.Add\n\t3.Search\n\t4.Modify records\n\t5.Delete records\n\t6.Populate Records\n\t7.Exit\n");
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("Enter the required number to proceed: \n");
    scanf("%d",&m);

    switch(m)
    {
    case 1:
        view(r);
        break;
    case 2:
        add(r);
        break;
    case 3:
        search(r);
        break;
    case 4:
        modify(r);
        break;
    case 5:
        del(r);
        break;
    case 6:
        pop(r,n);
        break;
    case 7:
        exit(0);
    default:
        printf("Invalid input!");
        break;
    }
   }


}
