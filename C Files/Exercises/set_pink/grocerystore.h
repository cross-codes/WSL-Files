#ifndef __STORE_H
#define __STORE_H

#include <stdio.h>
#include <stdlib.h>

struct item
{
    int ID;
    char name[50];
    float price;
    int quantity;
};

struct gNode
{
    struct item gro_item;
    struct gNode * next;
};

struct gLinkedList
{
    int count;
    struct gNode * first;
};

struct item * readGroceryList(int count);
void printGroceryList(struct item * gItems, int count);
struct item findItem(int qVal, struct item * gItems, int count);
struct item findMaxPriceItem(struct item * gItems, int count);
struct gLinkedList * createGLL(struct item * gItems, int count);
void printGLinkedList(struct gLinkedList * newList);

#endif