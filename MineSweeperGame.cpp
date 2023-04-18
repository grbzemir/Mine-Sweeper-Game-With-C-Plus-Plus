#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stddef.h>

// Kodu Calistirdiktan Sonra Komut Sistemine Gelmesi İcin Lütfen 5 Saniye Bekleyiniz!
using namespace std;

int alan[12][12];
int gorusAlani[12][12];

int matrix[2][8] = { {-1,-0,+1,-1,-0,+1,-1,+1},
{-1,-1,-1,+1,+1,+1,-0,-0} };

// matris[i-1][j-1] dediğimiz şey matris[i][j] nin sol üst çaprazdaki komşusudur. matris[i-0][j-1] dediğimiz şey matris[i][j] nin soldaki 3 komşusundan ortadaki gibi.

//{-1,-0,+1,-1,-0,+1,-1,+1}

//{-1,-1,-1,+1,+1,+1,-0,-0}

int acilacaklar[100];

int in=0;
int nerdeyim=0;
int acilanKare=0;


// Mayınların rastegele yerleştirilmesi

int randNumber(void)

{
    int i;

    i= rand() % 9 +1;
    srand(time(NULL));

    return i;

}

void baslat( int alan[12][12] , int Bilgi)

{

    int i;
    int j;
    
    for ( i = 0; i < 12; i++)

    {
        for( j = 0; j < 12; j++)
       
    {

        alan[i][j] = Bilgi;
        
   
    }

    }


}

void matrixYazdir(int alan[12][12])

{

    int i=1;
    int j;


    cout<<"\n 01 02 03 04 05 06 07 08 09 10";

    for(i=1; i<11; i++)

    {

        printf("\n ----------------------------------------------------------\n%2.d",i);

        for(j=1; j<11; j++)

        {

            printf(" |%2.d| ", alan[i][j]);

        }

    }

        printf("\n ----------------------------------------------------------\n");

    

}

 void yerAl(int *row , int *col) // satır ve sütün değerlerini alıyoruz

 {
   
   do 

   {

    cout<<"Satir degeri giriniz: ";
    cin>>*row;
    cout<<"Sutun degeri giriniz: ";
    cin>>*col;

    // Girilen Yer Bilgileri Daha Önceden Acılmıs Olabilir

    if(gorusAlani[*row][*col] != 11)

    {

        cout<<"Bu Yer Daha Once Acilmistir. Lutfen Farkli Bir Yer Giriniz."<<endl;

        *row = 0; // while döngüsünün devam etmesi için


    }

    // girilen satır ve sutun yani row ve col degerlerini kontrol edelim matrix dışında olabilir

   }
   
   while(*row >10  || *row < 1 || *col > 10 || *col < 1); // 1 ve 10 arasında olmalı
   

 }


 void menu(int *secim)

 {

    cout<<endl;
    cout<<"[1] Kare Ac"<<endl;
    cout<<"[2] Mayinlari Isaretle"<<endl;
    cout<<"[3] Yeni Oyun"<<endl;
    cout<<"[4] Nasil Oynanir"<<endl;
    cout<<"[5] Cikis"<<endl;

    
    do 

    {
        cout<"Seciminizi Giriniz: ";
        cin>>*secim;


    }

    while(*secim < 1 || *secim > 5); // 1 ve 5 arasında olmalı

 }

 void ekle(int row , int col)

 {

    int i;

    for(i=0;i<in;i=i+1)

    {
        if(acilacaklar[i] == row && acilacaklar[i+1] == col)

        {
            return;
        }
    
    }

 

 // eklenmemiş ise ekle

    acilacaklar[in] = row;
    in++;
    acilacaklar[in] = col;
    in++;

    }

    void kareAc(int acilacaklarIndex)

    {
        int i;
        int j;
        int k;

        for(k=0;k<8;k++)

        {

            i = acilacaklar[acilacaklarIndex] + (matrix[0][k]);
            j = acilacaklar[acilacaklarIndex+1] + (matrix[1][k]);

            gorusAlani[i][j] = alan[i][j];

            acilanKare++;
            
            // eger acilan karelerden 0 olan varsa onları da acilacaklara ekleyelim
          
          if (alan[i][j]=0)

          {

            ekle(i,j);
            
          }

        }

        nerdeyim = nerdeyim +2; // kare actıgımız vakit 2 ileriliyoruz
    }

    void NasilOynanir()

    {

        cout<<"_______________________________________________________"<<endl;
        cout<<"|9 SAYISI MAYINLARI GOSTERIR!                         |"<<endl;
        cout<<"|10 SAYISI MAYIN ISARETLENMIS BOLGELERI  GOSTERIR!    |"<<endl;
        cout<<"|1-8 SAYISILARI MAYINLARIN KOMSULUK SAYISINI GOSTERIR |"<<endl;
        cout<<"|MAYIN TARLASI 10X10 BOYUTUNDADIR                     |"<<endl;
        cout<<"|SATIR VE SUTUN SAYILARINI SIZ GIRIYORSUNUZ           |"<<endl;
        cout<<"|BUTUN MAYINLARI ACARAK OYUNU BITIRIRSINIZ            |"<<endl;
        cout<<"|BOLSANS ASKER KILICIN KESKIN OLSUN                   |"<<endl;
        cout<<"_______________________________________________________"<<endl;

    }
    
    void Cikis();
    
    


    int main()

    {
        
        system("color 3F");
        int i;
        int j;
        int k=0;
        int numberOfMine; // mayın numaralari

        int secim;
        int userRow;
        int userCol;

        // Tarlayi Sifirla

        baslat(alan,10); // duvarlar 10 olsun
        baslat(gorusAlani,11); // 11 acilmamis kareleri göstermek icin

        // Mayinlari yerlestir

        while (k != 14)

        {

            i=randNumber();
            j=randNumber();

            if(alan[i][j] != 9) // mayinlar 9 olsun 9 olmayan yerlere mayin koy

            {

                alan[i][j] = 9; // mayinlar 9 olsun
                k++;

            }
            
        }

        for(i=1;i<11;i++)
        
        {
            
            for(j=1;j<11;j++)

            {

                if (alan[i][j] != 9)

                {

                    numberOfMine=0; // mayin sayisi 0 olsun

                    for(k=0;k<8;k++)

                    {

                        if(alan[i+(matrix[0][k])][j+(matrix[1][k])] == 9)

                        {

                            numberOfMine++;

                        }

                    }

                    alan[i][j] = numberOfMine;
                    
                }
            }
        }

        // Eger tüm kareler acildiysa ve mayınlar bulunduysa eger oyun biter ve bizde oyunu bitirelim

        while (acilanKare != 100)

        {

            matrixYazdir(gorusAlani);


            menu(&secim);

            switch (secim)

            {
            	
            	case 1:

                // Bolgeyi kazalım

                yerAl(&userRow,&userCol);

                // Eger mayin ise oyunu bitir

                if (alan[userRow][userCol] == 9)

                {

                    cout<<"Mayinlari Acarak Oyunu Kaybettiniz!"<<endl;
                    acilanKare = 100;
                    

                }

                // Eger mayin degil ise oyunu devam ettir

                else if (alan[userRow][userCol] != 0)

                {

                    gorusAlani[userRow][userCol] = alan[userRow][userCol];
                    acilanKare++;

                    
                }

                else

                {

                    gorusAlani[userRow][userCol] = 0;
                    acilanKare++;
                    ekle(userRow,userCol);

                    while(nerdeyim < in)

                    {
                        kareAc(nerdeyim);

                    }
                    
                }

                break;

                case 2:

                // istenen yere bayrak koyalım

                yerAl(&userRow,&userCol);

                gorusAlani[userRow][userCol] = 10;
                acilanKare++;

                break;


                case 3:

                // Yeni oyun baslat
                cout<<"Yeni Oyun Baslatiliyor..."<<endl;

                return 0;

                break;

                case 4:

                // Nasıl oynanır

                NasilOynanir();
                
                break;
                
                case 5:
                	
                return 0;
                
                break;
            
                }
            }

            cout<<"__________Mayin Tarlasi__________"<<endl;

            matrixYazdir(alan);

            return 0;

            
        }

    




