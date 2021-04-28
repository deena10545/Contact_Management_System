#include <stdio.h>
#include <stdlib.h>

struct Contact
{
    char name[100];
    char email[100];
    char mob_no[50];
};
struct Contact s[100],temp;
void addition();
void deletion();
void search();
void display();
int validate();
void sort();
int choice,i,k=0,j=0,count=0,num,m,n;
char temp_name[100],temp_email[100],temp_mob_no[50];
char empty[100]="";
int main()
{
    while(1)
    {
        printf("\n-------------------------------------------------------------\n\n");
        printf("CONTACT MANAGEMENT SYSTEM\n");
        printf("\n 1. Addition\n 2. Deletion\n 3. Search\n 4. Contact book\n 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:
                {
                    addition();
                    break;
                }
            case 2:
                {
                    deletion();
                    break;
                }
            case 3:
                {
                    search();
                    break;
                }
            case 4:
                {
                    display();
                    break;
                }
            case 5:
                {
                    exit(1);
                    break;
                }
            default:
                {
                    printf("\nEnter the valid choice...\n");
                    break;
                }
        }
    }
}

void addition()
{
    printf("\nEnter the Name:  ");
    scanf("%s",temp_name);
    printf("\nEnter the Email:  ");
    scanf("%s",temp_email);
    printf("\nEnter the Mobile number: ");
    scanf("%s",temp_mob_no);
    validate();
    if(validate())
    {
        strcpy(s[j].name,temp_name);
        strcpy(s[j].mob_no,temp_mob_no);
        strcpy(s[j].email,temp_email);
        j++;
        k++;
        printf("\n\nContact saved successfully\n\n");
    }
}

int validate()
{
    for(i=0;i<j;i++)
    {
        if(!strcmp(s[i].name,temp_name))
        {
            printf("Name already exists...\n");
            main();
        }
    }
        if(i==j)
        {
            count=0;
            int at=0,dot=0,small=0,num=0;
            for(i=0;temp_email[i]!='\0';i++)
            {
                if(temp_email[i]=='@')
                    at++;
                else if(temp_email[i]=='.')
                    dot++;
                else if(temp_email[i]>='a' && temp_email[i]<='z')
                    small++;
                else if(temp_email[i]>='0' && temp_email[i]<='9')
                    num++;
                else
                {
                    printf("\nEnter valid mail address...\n");
                    main();
                }
            }
            if(at==1 && dot==1 && small>=5 && num>=2)
                {
                    count=1;
                }
            else
            {
                printf("\nPlease enter the valid mail address...\n");
                main();
            }
        }
        if(count==1)
        {
           num=0;
            for(i=0;temp_mob_no[i]!='\0';i++)
            {
                if(temp_mob_no[i]>='0' && temp_mob_no[i]<='9')
                    num++;
            }
            if(num==10 &&temp_mob_no[0]!='0')
            {
                return 1;
            }
            else
            {
                printf("\nPlease enter the valid Mobile number...\n");
                main();
            }
        }
}
void deletion()
{
    printf("Enter the name to delete the contact:\t");
    scanf("%s",temp_name);
    for(i=0;i<j;i++)
    {
        if(!strcmp(s[i].name,temp_name))
           {
               strcpy(s[i].name,empty);
               strcpy(s[i].email,empty);
               strcpy(s[i].mob_no,empty);
               printf("\n\nContact deleted successfully...\n\n");
               k--;
               break;
           }
    }
    if(i==j)
    {
        printf("\nNo contact found!!\n");
        main();
    }
}
void sort()
{
    for(m=1;m<j;m++)
	{
		for(n=0;n<j-m;n++)
		{
			if(strcmp(s[n].name,s[n+1].name)>0)
			{
				temp=s[n];
				s[n]=s[n+1];
				s[n+1]=temp;
			}
		}
	}
}
void display()
{
    if(k==0)
    {
        printf("\nNo contacts to displayed...!\n");
        main();
    }
    else
    {
        sort();
        printf("\n\n-------YOUR CONTACT BOOK IS--------\n\n");
        for(i=0;i<j;i++)
        {
            if(strcmp(s[i].name,empty))
            {
                printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mob_no,s[i].email);
				printf("\n--------------\n");
            }
        }
        printf("\n-------THE END--------\n");
    }
}
void search()
{
    printf("\n1. Search by name \n2. search by mobile number\n\n");
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                printf("Enter the name: ");
                scanf("%s",temp_name);
                for(i=0;i<j;i++)
                {
                    if(!strcmp(s[i].name,temp_name))
                    {
                        printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mob_no,s[i].email);
                        break;
                    }
                }
                if(i==j)
                    printf("\nContact not found!\n");
                main();
            }
        case 2:
            {
                printf("Enter the mobile number:");
                scanf("%s",temp_mob_no);
                for(i=0;i<j;i++)
                {
                    if(!strcmp(s[i].mob_no,temp_mob_no))
                    {
                        printf("Name : %s\nMobile No.: %s\nE-Mail : %s\n",s[i].name,s[i].mob_no,s[i].email);
                        break;
                    }
                }
                if(i==j)
                    printf("\nContact not found!\n");
                main();
            }
        default:
            {
                printf("Enter the valid choice");
                break;
            }
    }
}
