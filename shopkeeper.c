#include<stdio.h>
#include "header.h"

void add_inv()
{
    invent *inv;
    FILE *fp;
    int num, i;

    printf("\n\t::: CAREFULL ::: Your old data will be overwritten....");
    printf("\n\tPress 1 to overwrite.\n\tPress 2 to quit.\n\t::: ");
    scanf("%d", &num);
    if (num == 1)
    {
        printf("Enter HOW many stock you have: ");
        scanf("%d", &num);

        inv = (invent*) calloc(num, sizeof(invent));
        fp = fopen("hardware.txt", "w");

        for(i=0; i<num; i++)
        {
            printf("\nEnter Item code: ");
            scanf("%d", &inv[i].itm_ID);
            fflush(stdin);
            printf("Enter Item Name: ");
            scanf("%[^\n]s", inv[i].itm_na);
            printf("Enter no. of items(qty): ");
            scanf("%d", &inv[i].qty);
            printf("Enter Item's cost: ");
            scanf("%f", &inv[i].itm_cst);

//            bool flag = true;
//            invent i1;
//            FILE *fp1 = fopen("hardware.txt", "r");
//            while(fread(&i1, sizeof(invent), 1, fp1))
//            {
//                if(inv[i].itm_ID == i1.itm_ID){
//                    flag = false;
//                    i--;
//                    printf("\n ITEM WITH ENTERED ITEM ID ALREADY EXIST. PLEASE ENTER ITEM AGAIN WITH A DIFFERENT ITEM ID!!");
//                    break;
//                }
//            }

//            if(flag){
                fwrite(&inv[i], sizeof(invent), 1, fp);
//            }

        }
        fclose(fp);
    }
}


void append_inv()
{
    invent *inv;
    FILE *fp;
    int num, i;

    printf("Enter HOW many stock you have: ");
    scanf("%d", &num);

    inv = (invent*) calloc(num, sizeof(invent));
    fp = fopen("hardware.txt", "a");

    for(i=0; i<num; i++)
    {
        printf("\nEnter Item code: ");
        scanf("%d", &inv[i].itm_ID);
        fflush(stdin);
        printf("Enter Item Name: ");
        scanf("%[^\n]s", inv[i].itm_na);
        printf("Enter no. of items(qty): ");
        scanf("%d", &inv[i].qty);
        printf("Enter Item's cost: ");
        scanf("%f", &inv[i].itm_cst);

        fwrite(&inv[i], sizeof(invent), 1, fp);
    }
    fclose(fp);
}

void mod_inv()
{
    invent inv;
    int new_id, flag=0;
    FILE *Ofp = fopen("hardware.txt", "r");
    FILE *Tfp = fopen("temp.txt", "w");

    printf("\nEnter Item Code to MODIFY: ");
    scanf("%d", &new_id);
    while(fread(&inv, sizeof(invent), 1, Ofp))
    {
        if(inv.itm_ID == new_id)
        {
            printf("\tEnter new (qty & cost) for item %d :-", new_id);
            printf("\n\t\tEnter new Quantity: ");
            scanf("%d", &inv.qty);
            printf("\t\tEnter Item's new cost: ");
            scanf("%f", &inv.itm_cst);
            flag=1;
        }
        fwrite(&inv, sizeof(invent), 1, Tfp);       //writing into temp file
    }
    fclose(Ofp);
    fclose(Tfp);
    if(flag)
    {
        Tfp = fopen("temp.txt", "r");
        Ofp = fopen("hardware.txt", "w");
        while(fread(&inv, sizeof(invent), 1, Tfp))
        {
            fwrite(&inv, sizeof(invent), 1, Ofp);   //copying back to original file:all records
        }
        fclose(Ofp);
        fclose(Tfp);
        printf("\n\tItem Modified successfully");
    }
    else
    {
        printf("\n Item NOT FOUND... So use Append option for this Item...");
    }
}

void del_inv()
{
    invent inv;
    int new_id, flag=0;
    FILE *Ofp = fopen("hardware.txt", "r");
    FILE *Tfp = fopen("temp.txt", "w");

    printf("\nEnter Item Code to DELETE: ");
    scanf("%d", &new_id);
    while(fread(&inv, sizeof(invent), 1, Ofp))
    {
        if(inv.itm_ID == new_id)
            flag=1;
        else
            fwrite(&inv, sizeof(invent), 1, Tfp);
    }
    fclose(Ofp);
    fclose(Tfp);
    if(flag)
    {
        Tfp = fopen("temp.txt", "r");
        Ofp = fopen("hardware.txt", "w");
        while(fread(&inv, sizeof(invent), 1, Tfp))
        {
            fwrite(&inv, sizeof(invent), 1, Ofp);
        }
        fclose(Ofp);
        fclose(Tfp);
        printf("\n\tItem Deleted successfully");
    }
    else
    {
        printf("\n Item NOT FOUND...");
    }
}

void prnt_inv()
{
    invent i;
    FILE *fp = fopen("hardware.txt", "r");

    printf("\n\nItem_Code  Item_Name\t  Quantity  Cost\n");
    printf("--------------------------------------------\n");
    while(fread(&i, sizeof(invent), 1, fp))
    {
        printf("%-5d%-25s%-5d %5.2f\n", i.itm_ID, i.itm_na, i.qty, i.itm_cst);
    }
    printf("--------------------------------------------\n");
    fclose(fp);
}


