#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stu
{
    int rollno;
    char name[20];
    float marks;
    struct stu *next;
};
int rl=0;
int c=0;
void add(struct stu **);
void show(struct stu *);
void delete(struct stu **);
void modify(struct stu *);
void save(struct stu *);
int main()
{
    struct stu *headptr=NULL;
    FILE *fp;
    fp=fopen("student.csv","r");
    struct stu *new;
    fscanf(fp,"%*[^\n]\n");
    while(1)
    {
        new=malloc(sizeof(struct stu));
        if(fscanf(fp,"%d,%19[^,],%f",&new->rollno,new->name,&new->marks)==-1)
        break;
        new->next=0;
        rl=new->rollno;
        if(headptr==0)
        {
            headptr=new;
        }
        else
        {
            struct stu *last=headptr;
            while(last->next)
            last=last->next;
            last->next=new;
        }
    }
    int op;
    while(1)
    {
        
        printf("1: add new record\n2: delete record\n3: show\n4: modify\n5:save\n");
        scanf("%d",&op);
        printf("==========================================\n");
        switch(op)
        {
            case 1:add(&headptr);break;
            case 2:delete(&headptr);break;
            case 3:show(headptr);break;
            case 4:modify(headptr);break;
            case 5:save(headptr);break;
        }
        printf("==========================================\n");
    }   
}
void add(struct stu **ptr)
{
    struct stu *new;
    new=malloc(sizeof(struct stu));
    if(c==0)
    new->rollno=++rl;
    else
    {
    new->rollno=c;
    c=0;
    }
    printf("enter the name and marks\n");
    scanf("%s %f",new->name,&new->marks);
    new->next=0;
    if(*ptr==0)
    {
        *ptr=new;
    }
    else
    {
        struct stu *last=*ptr;
        while(last->next)
        last=last->next;
        last->next=new;
    }
}
void delete(struct stu **ptr)
{
    printf("1->based on rollno\n2->based on name\n");
    int option;
    scanf("%d",&option);
    if(option==1)
    {
        int r;
        printf("enter the roll number\n");
        scanf("%d",&r);
        struct stu *del=*ptr;
        struct stu *prev=0;
        while(del)
        {
            if(del->rollno==r)
            {
                c=del->rollno;
                if(del==*ptr)
                    *ptr=del->next;
                else
                    prev->next=del->next;

                free(del);
                return;
            }
            prev=del;
            del=del->next;
        }
        printf("num not found\n");
    }
    else if(option==2)
    {
        char name[20];
        printf("enter the name\n");
        scanf("%s",name);
        struct stu *del=*ptr;
        while(del)
        {
            if(strcmp(del->name,name)==0)
            {
                printf("%d %s %f\n",del->rollno,del->name,del->marks);
            }
            del=del->next;
        }
            int rn;
            printf("now choose the rollno now which one need to delete\n");
            scanf("%d",&rn);
            struct stu *d=*ptr;
            struct stu *prev=0;
            while(d)
            {
                if(d->rollno==rn)
                {
                    c=d->rollno;
                    if(d==*ptr)
                        *ptr=d->next;
                    else
                        prev->next=d->next;

                    free(d);
                    return;
                }
                prev=d;
                d=d->next;
            }
        
    }
}
void modify(struct stu *ptr)
{
    printf("which option need to modify\n");
    printf("1->rollno\n2->name and marks\n");
    int op;
    scanf("%d",&op);
    if(op==1)
    {
        int rn;
        printf("enter the rollnumber\n");
        scanf("%d",&rn);
        struct stu *del=ptr;
        while(del)
        {
            if(del->rollno==rn)
            {
                printf("rollnumber is present\n");
                printf("fill the required rollno\n");
                int n;
                scanf("%d",&n);
                del->rollno=n;
                break;
            }
            del=del->next;
        }
    }
    else if(op==2)
    {
        char name[20];
        printf("enter the name\n");
        scanf("%s",name);
        struct stu *del=ptr;
        while(del)
        {
            if(strcmp(del->name,name)==0)
            {
                printf("%d %s %f\n",del->rollno,del->name,del->marks);
            }
            del=del->next;
        }
        
        printf("now tell which roll number name and marks u want to modify\n");
        int rno;
        scanf("%d",&rno);
        struct stu *d=ptr;
        while(d)
        {        
            if(d->rollno==rno)
            {
                char nam[20];
                printf("enter the new name\n");
                scanf("%s",nam);
                float newmarks;
                printf("enter the new marks\n");
                scanf("%f",&newmarks);
                strcpy(d->name,nam);
                d->marks=newmarks;
                break;
            }
            d=d->next;
        }
    }
}
void save(struct stu *ptr)
{
    FILE *fp;
    fp=fopen("student.csv","w");
    if(fp==0)
    {
        perror("fopen");
        return;
    }
    fprintf(fp,"rollno,name,marks\n");
    while(ptr)
    {
        fprintf(fp,"%d,%s,%f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
    fclose(fp);
}
void show(struct stu *ptr)
{
    if(ptr==0)
    {
        printf("no records found\n");
        return;
    }
    while(ptr)
    {
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);
        ptr=ptr->next;
    }
    printf("==========================================\n");
}