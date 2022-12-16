#include "Product.h"
void editProduct()
{
    FILE *fptr=fopen("storage.bin","rb");
    FILE *tempfptr=fopen("tempstorage.bin","wb");
    int id,flag=0;
    printf("struct product size= %d \n",sizeof(product));
    printf("enter product id which u want to edit :");
    scanf("%d",&id);
    product tempstr;
    while (fread(&tempstr,sizeof(product),1,fptr)==1)
    {
        if (tempstr.id==id)
        {
            printf("position -> %d \n",ftell(fptr));
            printf("Product Record Found !!\n");
            printf("id : %d \n",tempstr.id);
            printf("name : %s \n",tempstr.name);
            printf("price : %f \n",tempstr.price);
            printf("quantity : %d \n",tempstr.quantity);

            printf("==============Enter new Record ============== \n");
            printf("enter new product id -> ");
            scanf("%d%*c",&tempstr.id);
            printf("enter new product name -> ");
            scanf("%[^\n]%*c",tempstr.name);
            printf("enter new product price -> ");
            scanf("%f",&tempstr.price);
            printf("enter new product quantity -> ");
            scanf("%d",&tempstr.quantity);
            fwrite(&tempstr,sizeof(product),1,tempfptr);
            flag=1;
        }
        else
        {
            printf("position -> %d \n",ftell(fptr));
            fwrite(&tempstr,sizeof(product),1,tempfptr);
        }       
    }
    fclose(fptr);
    fclose(tempfptr);
    remove("storage.bin");
    rename("tempstorage.bin","storage.bin");

    if (flag==1)
    {
        printf("product edited succesfully !\n");
    }
    else
    {
            printf("product not found !\n");
    }
    
    char ch;
    scanf("%c",&ch);
     
}