#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "header.h"
#include "user.c"
#include "shopkeeper.c"

int main()
{
    int opt;
    int opt1;
    int opt2;

    do{
        printf("\n\t*****ARE YOU A USER OR SHOPKEEPER? PRESS THE APPROPRIATE NUMBER TO ACCESS THE FUNCTIONALITIES!!*****");
        printf("\n 1. SHOPKEEPER");
        printf("\n 2. USER");
        printf("\n 0. Exit");

        printf("\n\t Select your option(0-2): ");
        scanf("%d", &opt1);

        switch(opt1)
        {
            case 1:
                do
                {
                    printf("\n\t*****INVENTORY OPTIONS*****");
                    printf("\n 1. Adding New");
                    printf("\n 2. Append");
                    printf("\n 3. Delete");
                    printf("\n 4. Modify");
                    printf("\n 5. Display");
                    printf("\n 0. Exit");

                    printf("\n\t Select your option(0-5): ");
                    scanf("%d", &opt);

                    switch(opt)
                    {
                        case 1:
                            add_inv();
                            break;

                        case 2:
                            append_inv();
                            break;

                        case 3:
                            del_inv();
                            break;

                        case 4:
                            mod_inv();
                            break;

                        case 5:
                            prnt_inv();
                            break;

                        case 0:
                            break;

                        default:
                            printf("Wrong option selected... \tChoose right option.\n");
                            break;

                    }


                }while(opt!=0);
                break;

            case 2:
                do{
                    printf("\n\t*****USER OPTIONS*****");
                    printf("\n 1. ORDER ITEMS");
                    printf("\n 2. DISPLAY ORDERED ITEMS");
                    printf("\n 3. DISPLAY ITEMS");
                    printf("\n 0. Exit");

                    printf("\n\t Select your option(0-2): ");
                    scanf("%d", &opt2);

                    switch(opt2)
                    {
                        case 1:
                            prnt_inv();
                            append_cart();
                            break;

                        case 2:
                            prnt_cart();
                            break;

                        case 3:
                            prnt_inv();
                            break;

                        case 0:
                            break;

                        default:
                            printf("Wrong option selected... \tChoose right option.\n");
                            break;
                    }

                }while(opt2!=0);
                break;


            case 0:
                printf("\nEXIT!!\n");
                break;

            default:
                printf("Wrong option selected... \tChoose right option.\n");
                break;

        }

    }while(opt1!=0);


    return (0);

}
