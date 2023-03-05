#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int kuyruk[10];
int Rear = - 1;
int Front = - 1;

void kuyruk_ekle();
void veri_duzenleme(); 
void kuyruk_listele();

int main() {
    int musteri_bilgi_kodu[10]={3,1,2,2,2,1,3,1,3,2};
    for(int i=0;i<10;i++){
        if(musteri_bilgi_kodu[i]==1){
            printf("%d-kurumsal müşteri\n",i+1);
        }
        if(musteri_bilgi_kodu[i]==2){
            printf("%d-bireysel müşteri\n",i+1);
        }
        if(musteri_bilgi_kodu[i]==3){
            printf("%d-65 yaş müşteri\n",i+1);
        }
    }
    printf("\n");
    veri_duzenleme(musteri_bilgi_kodu);
    
}

veri_duzenleme(int kod[]){
    for(int i=0;i<10;i++){
        if(kod[i]==3){
            kuyruk_ekle(kod[i]);
            kod[i]=0;
        }
    }
    for(int i=0;i<10;i++){
        if(kod[i]==2 && kod[i-1]==2){
            for(int j=i;j<10;j++){
                if(kod[j]==1){
                    int temp=kod[j];
                    kod[j]=kod[i+1];
                    kod[i+1]=temp;
                    kuyruk_ekle(kod[j]);
                    break;
                }
            }
            
        }
        else if(kod[i]==1){
            kuyruk_ekle(kod[i]);
            
        }
        else if(kod[i]==2){
            kuyruk_ekle(kod[i]);
            
        }
    }kuyruk_listele();
}

void kuyruk_ekle(int veri){
    if (Front == - 1){
        Front = 0;
    }
    Rear = Rear + 1;
    kuyruk[Rear] = veri;
} 

void kuyruk_listele(){
    for (int i = Front; i <= Rear; i++){
        if(kuyruk[i]==1){
            printf("kurumsal müşteri\n");
        }
        if(kuyruk[i]==2){
            printf("bireysel müşteri\n");
        }
        if(kuyruk[i]==3){
            printf("65 yaş müşteri\n");
        }
    }
}