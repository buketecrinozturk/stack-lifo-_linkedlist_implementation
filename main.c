#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
}*top,*temp_top,*temp;
 
void push(int data);
void pop();     
void listele();  
void reset();
void yigin_sayac(); 
 
int sayac = 0;
 
void main()
{
    int eleman, secim, top_e;
 
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Exit");
    printf("\n 4 - listele");
    printf("\n 5 - Yigin Sayaci");
    printf("\n 6 - reset");
 
    top = NULL; // ba�lang��ta null yap�yoruz
 
    while (1)
    {
        printf("\n Yapmak Istediginiz Islemi Seciniz: ");
        scanf("%d", &secim);
 
        switch (secim)
        {
        case 1:
            printf("Eklenecek Elemani Giriniz : ");
            scanf("%d", &eleman);
            push(eleman);
            break;
        case 2:
            pop();
            break;
        case 3:
            exit(0);
            break;
        case 4:
            listele();
            break;
        case 5:
           yigin_sayac();
           break;
        case 6:
             reset();
            break;
        default :
            printf(" !!! Listede Olmayan Birsey Sectin ");
            break;
        }
    }
}
 

/* Count stack elements */
void yigin_sayac()
{
    printf("\n Yigin Eleman Sayisi : %d", sayac);
}
 
/************************** Push Kismi ***************************///buketecrinozturk
void push(int data)
{
	// gelen her veri �ne geciyor
    if (top == NULL) // bellek bo�sa ilk veriyi ekliyoruz
    {
        top =(struct node *)malloc(1*sizeof(struct node)); // bellekten yer ayiriyoruz
        top->next = NULL; // top d���m�n next h�cresini null yap�yoruz
        top->data = data; // top i�aret�isinin g�stedigi yerin datasina gelen datayi ekliyoruz
    }
    else // bellekte veri var ise 
    {
        temp =(struct node *)malloc(1*sizeof(struct node));// bellekten yer ayiriyoruz
        temp->next = top; // temp i�aret�inin next h�cresinin top d���m� g�stermesini sa�l�yoruz 
        temp->data = data;// temp i�aret�inin datas�na gelen datay� ekliyoruz
        top = temp;// temp art�k top oldu
    }
    sayac++;
}
/************************** Pop Kismi ***************************///buketecrinozturk
void pop()
{
    temp_top = top;
 
    if (temp_top == NULL) // Stack bo� ise
    {
        printf("\n !!! Yiginda Eleman Yok");
        return;
    }
    else
        temp_top = temp_top->next; // Bir sonraki eleman� g�ster
    printf("\n Cikarilan Eleman : %d", top->data);
    free(top);
    top = temp_top;
    sayac--; // Eleman sayisini bulmak i�in
}
 
/************************** Listele Kismi ***************************///buketecrinozturk
void listele()
{
    temp_top = top;
 
    if (temp_top == NULL)
    {
        printf("Yiginda Eleman Yok");
        return;
    }
 
    while (temp_top != NULL) // Son Eleman Olana Kadar Devam Et
    {
        printf("%d ", temp_top->data);
        temp_top = temp_top->next;
    }
 }

/************************** Reset Kismi ***************************///buketecrinozturk
void reset()
{
    temp_top = top;
 
    while (temp_top != NULL) // Liste bo� olana kadar
    {
        temp_top = top->next; //top d���mden bir �nceki d���m� temp_top i�aret�isine ata
        free(top); // ilk elemani serbest birak
        top = temp_top; // temp_top art�k top isaretcisi olsun 
        temp_top = temp_top->next; // temp_top isaretcisini bir sonraki d�g�me g�ndererek devam et
    }
    free(temp_top);
    top = NULL;
 
    printf("\n !!! Yigin Tamamen Silindi !!!");
    sayac = 0;
}
