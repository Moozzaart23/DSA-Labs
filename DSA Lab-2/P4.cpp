#include<stdio.h>
#include<stdlib.h>
struct DLL
{
    int data,color;
    struct DLL *prev,*next;
};

struct DLL* front=NULL,*rear=NULL;
int ct=2,c=0;

void D_Add(int x,int y,int z)
{
    struct DLL* t=(struct DLL*)malloc(sizeof(struct DLL));
    t->data=x;
    t->color=c;
    c=1-c;
    t->prev=NULL;
    t->next=NULL;
    if(front==NULL)
    {
        front=t;
        rear=t;
    }
    else
    {
        rear->next=t;
        t->prev=rear;
        rear=t;
        if(x-y>=2)
        {
            struct DLL* trav=front;
            while(trav!=NULL)
            {
                if(trav->data==y)
                {
                    rear->prev=trav;
                    break;
                }
                trav=trav->next;
            }
            if((x-y)%2==0)
            {
                ct=3;
            }
        }
    }
}

void loop()
{
    struct DLL* trav=front;
    int bef_c=1;
    if(trav!=NULL && trav->next!=NULL&&trav->next->next!=NULL)
    {
        trav=trav->next->next;
    }
    else
    {
        return;
    }
    while(trav!=NULL)
    {
        if(bef_c==trav->prev->color)
        {
            trav->color=(bef_c+1)%3;
        }
        else
        {
            trav->color=3-bef_c-trav->prev->color;
        }
        bef_c=trav->color;
        trav=trav->next;
    }
}

void col()
{
    int k=0;
    struct DLL* trav=front;
    while(trav!=NULL)
    {
        k=trav->color;
        if(k==0)
        {
            printf("B ");
        }
        else if(k==1)
        {
            printf("Y ");
        }
        else
        {
            printf("G ");
        }
        trav=trav->next;
    }
    printf("\n");
}

int main()
{
    int x,y,z;
    while(1)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(x==-1||y==-1||z==-1)
        {
            break;
        }
        else
        {
            D_Add(x,y,z);
        }
    }
    if(ct==3)
    {
        loop();
    }
    col();
    return 0;
}
