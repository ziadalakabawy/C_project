#include "project.h"
static uint8 num_entries=0;

typedef struct SimpleDb
{
    uint8 Student_ID;
    uint8 Student_Year;
    uint8 course_id[3];
    uint8 course_grade[3];
} simple;

static simple entries[MAX];

bool SDB_IsFull()
{
    if (num_entries == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
uint8 SDB_GetUsedSize()
{
    return num_entries;
}
bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades)
{
    uint8 i=0;
    if (SDB_IsFull()==1) return 0;
    for(i=0; i<3; i++)
    {
        if(grades[i]>100||grades[i]<0)
        {
            return 0;
        }
    }
    entries[num_entries].Student_ID = id;
    entries[num_entries].Student_Year = year;
    entries[num_entries].course_id[0] = subjects[0];
    entries[num_entries].course_grade[0] = grades[0];
    entries[num_entries].course_id[1] = subjects[1];
    entries[num_entries].course_grade[1] = grades[1];
    entries[num_entries].course_id[2] = subjects[2];
    entries[num_entries].course_grade[2] = grades[2];
    /*printf("id=%d",id);
     printf("year=%d",year);
    printf("grade=%d",grades[1]);
    printf("id=%d",entries[num_entries].course_id[0]);
     printf("year=%d",entries[num_entries].Student_Year );
    printf("grade=%d",entries[num_entries].course_grade[1]);*/
    num_entries++;
    return 1;
}
void SDB_DeleteEntry(uint8 id)
{
    uint8 i=0,j=0;
    for (i = 0; i < num_entries; i++)
    {
        if (entries[i].Student_ID == id)
        {
            for (j = i + 1; j < num_entries; j++)
            {
                entries[j - 1] = entries[j];
            }
            num_entries--;
            return;
        }
    }
}
bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades)
{
    uint8 i=0,j=0;

    for (i = 0; i < num_entries; i++)
    {
        if (entries[i].Student_ID == id)
        {
            year=entries[i].Student_Year;

            for(j=0; j<3; j++)
            {
                subjects[j]=entries[i].course_id[j];
                grades[j]=entries[i].course_grade[j];
            }
            return 1;
        }
    }
    return 0;
}
void SDB_GetIdList(uint8* count, uint8* list)
{
    uint8 i=0;
    *count =num_entries;
    for(i=0; i<*count; i++)
    {
        list[i]=entries[i].Student_ID;
    }
}
bool SDB_IsIdExist(uint8 ID)
{
    uint8 i=0;
    for (i=0; i < num_entries; i++)
    {
        if (entries[i].Student_ID == ID)
        {
            return 1;
        }
    }
    return 0;
}
void Add(uint8* id, uint8* year, uint8* subjects, uint8* grades)
{
    printf("Enter the student ID: ");
    scanf("%u", id);

    printf("Enter the student year: ");
    scanf("%u", year);

    printf("Enter the student ID for course 1: ");
    scanf("%u", &subjects[0]);

    printf("Enter the student ID for course 2: ");
    scanf("%u", &subjects[1]);

    printf("Enter the student ID for course 3: ");
    scanf("%u", &subjects[2]);

    printf("Enter the student grade for course 1: ");
    scanf("%u", &grades[0]);

    printf("Enter the student grade for course 2: ");
    scanf("%u", &grades[1]);
    printf("Enter the student grade for course 3: ");
    scanf("%u", &grades[2]);
}
void prnt(uint8 year, uint8* subjects, uint8* grades)
{
    printf("student year:%u\n",year);
    printf("student id in course[1]:%u\n",subjects[0]);
    printf("student grades in course[1]:%u\n",grades[0]);
    printf("student id in course[2]:%u\n",subjects[1]);
    printf("student grades in course[2]:%u\n",grades[1]);
    printf("student id in course[3]:%u\n",subjects[2]);
    printf("student grades in course[3]:%u\n",grades[2]);
}
//}
