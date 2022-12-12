#include "Product.h"
void viewProduct()
{
    FILE *ptr=fopen("storage.bin","rb");

    product vp;
    fread(&vp,sizeof(product),1,ptr);

    printf(" %d %c %f %d ",vp.id,vp.name,vp.price,vp.quantity);

    char ch;
        printf("Press enter to continue  else press any key...  ");
        scanf("%c", &ch);
}