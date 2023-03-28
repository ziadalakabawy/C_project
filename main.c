#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "project.h"
int main()
{
    uint8 id,year,i=0,res,count;
    uint8 subjects[3],grades[3],list[10];
    uint8 choice;
    while(choice!=0)
    {
        printf("1-add entry\t2-delete entry\t3-check database\t4-used size\t5-read entry\t6-get id list\t7-check for id\t0-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            Add(&id, &year, subjects,grades);
            res=SDB_AddEntry(id, year, subjects,grades);
            if(res==1) printf("the entry has been added successfully\n");
            else if(res==0) printf("try again");
            break;
        case 2:
            printf("Enter the student ID you want to delete: ");
            scanf("%u", &id);
            SDB_DeleteEntry(id);
            break;
        case 3:
            res=SDB_IsFull();
            if(res==1) printf("the database is full\n");
            else if(res==0) printf("there is still space\n");
            break;
        case 4:
            res=SDB_GetUsedSize();
            printf("the number of entries: %d\n",res);
            break;
        case 5:
            printf("Enter the student ID: ");
            scanf("%u", &id);
            res=SDB_ReadEntry(id, &year, subjects,grades);
            if(res==1)
            {
                prnt(year,subjects,grades);
            }
            else if(res==0) printf("try again");
            break;
        case 6:
            SDB_GetIdList(&count,list);
            for(i=0; i<count; i++)
            {
                printf("ID %d: %d\n",i,list[i]);
            }
            break;
        case 7:
            printf("Enter the student ID: ");
            scanf("%u", &id);
            res=SDB_IsIdExist(id);
            if(res==1) printf("this ID exists \n");
            else if(res==0) printf("this ID does not exist\n");
            break;
        case 0:
            printf("exiting");
            break;
        default:
            printf("try again");
        }
    }
    return 0;
}
