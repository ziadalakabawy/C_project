#ifndef PROJECT_H_INCLUDED
#define PROJECT_H_INCLUDED
#define MAX 10
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
typedef unsigned int uint8;
bool SDB_IsFull(void);
uint8 SDB_GetUsedSize(void);
bool SDB_AddEntry(uint8 id, uint8 year, uint8* subjects, uint8* grades);
void SDB_DeleteEntry(uint8 id);
bool SDB_ReadEntry(uint8 id, uint8* year, uint8* subjects, uint8* grades);
void SDB_GetIdList(uint8* count, uint8* list);
bool SDB_IsIdExist(uint8 ID);
void Add(uint8* id, uint8* year, uint8* subjects, uint8* grades);
void prnt(uint8 year, uint8* subjects, uint8* grades);
#endif // PROJECT_H_INCLUDED
