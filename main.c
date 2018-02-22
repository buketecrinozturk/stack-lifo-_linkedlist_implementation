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
 
    top = NULL; // baþlangiçta null yapiyoruz
 
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
	// gelen her veri öne geciyor
    if (top == NULL) // bellek bossa ilk veriyi ekliyoruz
    {
        top =(struct node *)malloc(1*sizeof(struct node)); // bellekten yer ayiriyoruz
        top->next = NULL; // top dügümün next hücresini null yapiyoruz
        top->data = data; // top iþaretçisinin göstedigi yerin datasina gelen datayi ekliyoruz
    }
    else // bellekte veri var ise 
    {
        temp =(struct node *)malloc(1*sizeof(struct node));// bellekten yer ayiriyoruz
        temp->next = top; // temp isaretçinin next hücresinin top dügümü göstermesini sagliyoruz 
        temp->data = data;// temp isaretçinin datasina gelen datayi ekliyoruz
        top = temp;// temp artik top oldu
    }
    sayac++;
}
/************************** Pop Kismi ***************************///buketecrinozturk
void pop()
{
    temp_top = top;
 
    if (temp_top == NULL) // Stack bos ise
    {
        printf("\n !!! Yiginda Eleman Yok");
        return;
    }
    else
        temp_top = temp_top->next; // Bir sonraki elemani göster
    printf("\n Cikarilan Eleman : %d", top->data);
    free(top);
    top = temp_top;
    sayac--; // Eleman sayisini bulmak için
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
 
    while (temp_top != NULL) // Liste boþ olana kadar
    {
        temp_top = top->next; //top düðümden bir önceki dügümü temp_top iþaretçisine ata
        free(top); // ilk elemani serbest birak
        top = temp_top; // temp_top artik top isaretcisi olsun 
        temp_top = temp_top->next; // temp_top isaretcisini bir sonraki dügüme göndererek devam et
    }
    free(temp_top);
    top = NULL;
 
    printf("\n !!! Yigin Tamamen Silindi !!!");
    sayac = 0;
}
