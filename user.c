#include<stdio.h>
#include "header.h"

void prnt_cart()
{
    cart i;
    FILE *fp = fopen("cart.txt", "r");

    printf("\n\nItem_Code Quantity\n");
    printf("--------------------------------------------\n");
    while(fread(&i, sizeof(cart), 1, fp))
    {
        printf("%d            %d\n", i.itm_ID, i.qty);
    }
    printf("--------------------------------------------\n");
    fclose(fp);
}

void append_cart()
{
    cart *crt;
    FILE *fp;

    int num;
    printf("Enter HOW many items you want to add in cart: ");
    scanf("%d", &num);

    crt = (cart*)calloc(num,sizeof(cart));
    fp = fopen("cart.txt","a");

    for(int i=0;i<num;i++){
        printf("\n\n Enter Details for Item : %d",i+1);
        printf("\n Enter Item Code that you want enter: ");
        scanf("%d", &crt[i].itm_ID);
        printf("\n Enter the quantity of the item: ");
        scanf("%d", &crt[i].qty);


        bool flag = false;
        invent i1;
        FILE *fp1 = fopen("hardware.txt", "r");
        while(fread(&i1, sizeof(invent), 1, fp1))
        {
            if(crt[i].itm_ID == i1.itm_ID){
                if(i1.qty > crt[i].qty){
                    mod_item(i1.qty - crt[i].qty,i1.itm_ID);
                    flag = true;
                }
                break;
            }
        }

        if(!flag){
            i--;
            printf("\n ITEM WITH ENTERED ITEM ID DOES NOT EXIST. PLEASE ENTER ITEM AGAIN WITH A DIFFERENT ITEM ID!!");
        }


        if(flag){
            fwrite(&crt[i],sizeof(crt),1,fp);
        }
    }

    fclose(fp);
}

void mod_item(int x,int id)
{
    invent inv;
    int new_id = id; int flag=0;
    FILE *Ofp = fopen("hardware.txt", "r");
    FILE *Tfp = fopen("temp.txt", "w");

//    printf("\nEnter Item Code to MODIFY: ");
//    scanf("%d", &new_id);
    while(fread(&inv, sizeof(invent), 1, Ofp))
    {
        if(inv.itm_ID == new_id)
        {
            inv.qty = x;
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
    }
    else
    {
        printf("\n Item NOT FOUND... So use Append option for this Item...");
    }
}
