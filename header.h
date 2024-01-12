#ifndef HEADER_H
#define HEADER_H


typedef struct Inventory
{
    int itm_ID;
    int qty;
    float itm_cst;
    char itm_na[25];
}invent;

typedef struct Cart
{
    int itm_ID;
    int qty;
}cart;

void add_inv();
void append_inv();
void del_inv();
void mod_inv();
void prnt_inv();

void append_cart();
void prnt_cart();
void mod_item(int ,int );


#endif
