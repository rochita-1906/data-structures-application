#include <stdio.h>
#include <stdlib.h>
int tsize,hash[10],count=0;
int cal_Hash(int key)
{
    return key % tsize;
}
int cal_ReHash(int key)
{
    return(key+1)%tsize;
}
void insert(int key)
{
    int index;
    if(count!=tsize)
    {
        index=cal_Hash(key);
        while(hash[index]!=-1)
        {
            index=cal_ReHash(index);
        }
    hash[index]=key;
    count++;
    }
    else
    {
        printf("\n table is full");
    }
    }
    int search (int key)
    {
        int i,index,loc=-1;
        index=cal_Hash(key);
        for(i=0;i<tsize;i++)
        {
            loc=(index+i)%tsize;
            if(hash[loc]==key)
            {
                return loc;

            }
        }
        return -1;
    }
    void delete(int key)
    {
        int loc;
        if(count==0)
        {
            printf("\n hash table empty,cant delete");
        }
        else
        {
            loc=search(key);
            if(loc!=-1)
            {
                hash[loc]=-1;
                count--;
                printf("\n key deleted");
            }
            else
            {
                printf("\n key not found");
            }
        }
    }
    void display()
    {
        int i;
        printf("\n the elements in the hash table are:\n");
        for(i=0;i<tsize;i++)
        {
            printf("element at position %d,%d \n",i,hash[i]);
        }
    }
    int main()
    {
        int key,i,ch,loc;
        printf("\n enter the size of the hash table:");
        scanf("%d",&tsize);
        for(i=0;i<tsize;i++)
        {
            hash[i]=-1;
        }
        while(1)
        {
            printf("\n 1.insert");
            printf("\n 2.search");
            printf("\n 3.delete");
            printf("\n 4.display");
            printf("\n 5.exit");
            printf("\n enter your choice");
            scanf("%d",&ch);
            switch(ch)
            {
                case 1: printf("\n enter key to insert:");
                        scanf("%d",&key);
                        insert(key);
                        break;
                case 2: printf("\n enter key to search");
                        scanf("%d",&key);
                        loc=search(key);
                        if(loc!=-1)
                            printf("\n key found at %d",loc);
                        else
                            printf("\n key not found");
                        break;
                case 3: printf("\n enter key to delete");
                        scanf("%d",&key);
                        delete(key);
                        break;
                case 4: display();
                        break;
                default: exit(0);
            }
        }
        return 0;
    }
