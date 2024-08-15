#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct emp
{

    int id;
    char name[20];
    float sal;
    char dob[20];
    char b[30];
    float hra,da,pf,gs;

};
void append();
void display();
void modify();
void del();
int main()
{
    int pass;
    int n;
    char c;
    printf("enter the password\n");
    scanf("%d",&pass);
    if(pass==2004)
    {
        e:
            system("cls");
            printf("append        1\n");
            printf("display       2\n");
            printf("modify        3\n");
            printf("del           4\n");
            printf("exit          5\n");
            printf("enter your choice\n");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
                append();
                system("pause");
                goto e;
            case 2:
                display();
                system("pause");
                goto e;
            case 3:
                modify();
                system("pause");
                goto e;
            case 4:
                del();
                system("pause");
                goto e;
            case 5:
                exit(0);
                system("pause");
                goto e;
            }
    }
    else
    {
        printf("your password was wrong");
    }
}
void append()
{
    struct emp e1;

    FILE*fp;
    fp=fopen("pro.dat","ab+");
    if(fp==NULL)
    {
        printf("Error");
    }
    e:
        printf("enter emp id\n");
        scanf("%d",&e1.id);
        printf("enter the name\n");
        scanf("%s",e1.name);
        printf("enter the salary\n");
        scanf("%f",&e1.sal);
        printf("enter the dob\n");
        fflush(stdin);
        gets(e1.dob);
        printf("enter the blood group");
        gets(e1.b);
        e1.hra=(e1.sal*10)/100;
        e1.da=(e1.sal*5)/100;
        e1.pf=(e1.sal*9)/100;
        e1.gs=e1.sal+e1.hra+e1.da;
        fwrite(&e1,sizeof(e1),1,fp);
        fclose(fp);
        getch();
}
void display()
{

    int id;
    struct emp e1;
    FILE*fp;
    fp=fopen("pro.dat","rb+");
    e:
        printf("enter the id\n");
        scanf("%d",&id);
        while(fread(&e1,sizeof(e1),1,fp)>0)
        {
            if(id==e1.id)
            {
                printf("id=%d",e1.id);
                printf("\nname=%s",e1.name);
                printf("\nsalary=%f",e1.sal);
                printf("\nDOB=%s",e1.dob);
                printf("\nBLOODGROUP=%s",e1.b);
                printf("\nHRA=%f",e1.hra);
                printf("\nDA=%f",e1.da);
                printf("\nPF=%f",e1.pf);
                printf("\nGS=%f",e1.gs);


            }
        }
        fclose(fp);
        getch();
}
void modify()
{

    struct emp e1;
    FILE*fp,*fp1;
    int i,d =0;
    e:
        fp=fopen("pro.dat","rb+");
        fp1=fopen("drop.dat","ab+");
        if(fp==NULL&&fp1==NULL)
        {
            printf("insufficient memory");

        }
        printf("enter the modify id\n");
        scanf("%d",&i);
        while(1)
        {
            fread(&e1,sizeof(e1),1,fp);
            if(feof(fp))
            {
                break;
            }
            else
            {
                if(e1.id!=i)
                {
                    fwrite(&e1,sizeof(e1),1,fp1);
                }
            }
            d = 1;
        }
        if(d == 1)
        {
        printf("enter the modified details\n");
        e1.id = i;
        printf("enter the name\n");
        scanf("%s",&e1.name);
        printf("enter the salary\n");
        scanf("%f",&e1.sal);

        fwrite(&e1,sizeof(e1),1,fp1);
        fclose(fp);
        fclose(fp1);
        remove("pro.dat");
        rename("drop.dat","pro.dat");
        getch();
        }
        else{
            printf("Your entered Id is not found!");
        }
}
void del()
{
    struct emp e1;
    FILE*fp, *fp1;
    int i,d=0;
    e:
          fp=fopen("pro.dat","rb+");
        fp1=fopen("drop.dat","ab+");
        if(fp==NULL&&fp1==NULL)
        {
            printf("insufficient memory");

        }
        printf("enter the delete id\n");
        scanf("%d",&i);
        while(1)
        {
            fread(&e1,sizeof(e1),1,fp);
            if(feof(fp))
            {
                break;
            }
            else
            {
                if(e1.id!=i)
                {
                    fwrite(&e1,sizeof(e1),1,fp1);
                }
            }

        }
        printf("your entered id is deleted successfully");
        fclose(fp);
        fclose(fp1);
        remove("pro.dat");
        rename("drop.dat","pro.dat");
        getch();



}
