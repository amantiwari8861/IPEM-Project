#include "Product.h"
void viewProduct()
{
    FILE *ptr=fopen("storage.bin","rb");

    product vp;

    
    while (fread(&vp,sizeof(product),1,ptr))
    {
            printf(" %d %s %0.2f %d \n",vp.id,vp.name,vp.price,vp.quantity);
    }
    fclose(ptr);
    char ch;
    printf("\nPress enter to continue  else press any key...  ");
    scanf("%c", &ch);
}