#include <stdio.h>
#include <stdlib.h>

int main()
{
    int oda[3][12][100]= {0};
    int hafta,misafir,ek_misafir,deneme=0,oran=0,mevsimler; // deneme degiskeni girilen haftanin yanlis girilmesini tutan bir sayacim
    int i,j,k,secilen_oda;
    float ucret,ucret2,odenecek;
    char mevsim,odasecim,ek_kisi,karar,odeme;
    int standart,delux,large_delux;
    for(k=0; k<3; k++)
    {
        for (j=0; j<12; j++ )
        {
            for(i=0; i<100; i++)
                oda[k][j][i]=0;
        }
    }
    do
    {
        printf("Hangi mevsimde konaklama yapmak istersiniz:\n");
        printf("Sonbahar icin 'S', Bahar icin 'B', Yaz icin 'Y' tusuna basiniz:");
        scanf("%c",&mevsim);

        switch (mevsim)
        {
        case 'S':
        case 's':
            standart=25;   //secilen oda tipine gore hesaplanan fiyatlardaki degisikligi sabitledim
            delux=50;
            large_delux=250;
            mevsimler=0;
            break;
        case 'B':
        case 'b':
            standart=40;
            delux=75;
            large_delux=300;
            mevsimler=1;
            break;
        case 'y':
        case 'Y':

            standart=60;
            delux=90;
            large_delux=400;
            mevsimler=2;
            break;
        default:
            printf("yanlis karakter girdiniz.");
            break;

        }
        printf("Kacinci hafta konaklama yapacaksiniz:");
        scanf("%d",&hafta);

        if(hafta<1&&hafta>12)
        {
            while (deneme<3) //girdigimiz haftanin 3 ten fazla yanlis girilmesinde sistemden çıkan döngü
            {
                printf("Kacinci hafta konaklama yapacaginizi tekrar girmelisiniz:");
                scanf("%d",&hafta);
                deneme++;
                if (hafta>=1 && hafta<=12)
                    break;
                if (deneme==3)
                    return 0;

            }
        }
        printf("Oda tipini seciniz:\n");
        printf("Standart oda icin 'S', deluxe oda icin 'D', large deluxe oda icin 'L' kodunu giriniz: ");
        scanf(" %c",&odasecim);
        if (odasecim=='s'|| odasecim=='S')
        {
            for(i=1; i<100; i+=2)
            {
                if(oda[mevsimler][hafta-1][i]==0)
                {
                    printf("%d\t",i);
                }
            }

            printf("nolu odalar standart odalara mevcuttur birini seciniz:");
            scanf("%d",&secilen_oda);
            if (secilen_oda%2==0)
            {
                do //ekranda cift sayili olmayan odalari sectigimizde uyari veren döngü
                {
                    printf("boyle bir oda yoktur.");
                    printf("\nnolu odalar standart odalara mevcuttur birini seciniz:");
                    scanf("%d",&secilen_oda);

                }
                while (secilen_oda%2==0);
            }


            do //secilen odanin dolu olup olmadigini kontrol eden döngü
            {
                if(oda[mevsimler][hafta-1][secilen_oda-1]==1)
                {
                    printf("\nbu oda doludur.");
                    printf("\nBir oda seciniz:");
                    scanf("%d",&secilen_oda);

                    break;
                }
                else
                {
                    oda[mevsimler][hafta-1][secilen_oda-1]=1;
                    break;
                }

            }
            while(1==1);

            oda[mevsimler][hafta-1][secilen_oda]=1;
            printf("Misafir sayisini giriniz:");
            scanf("%d",&misafir);
            if (misafir>4)
            {

                ucret=standart*4;
                printf("\nkonuklar icin ek olarak oda secmek ister misiniz(E/H)?");
                scanf(" %c",&ek_kisi);
                if(ek_kisi=='E'|| ek_kisi=='e')
                {
                    ek_misafir=misafir-4;

                    for(i=1; i<100; i+=2)
                    {
                        if(oda[mevsimler][hafta-1][i]==0)
                        {
                            printf("%d\t",i);
                        }

                    }


                    printf("nolu odalar standart odalara mevcuttur birini seciniz:");
                    scanf("%d",&secilen_oda);
                    if (secilen_oda%2==0)
                    {
                        do
                        {
                            printf("boyle bir oda yoktur.");
                            printf("\nnolu odalar standart odalara mevcuttur birini seciniz:");
                            scanf("%d",&secilen_oda);

                        }
                        while (secilen_oda%2==0);
                    }



                    ucret2=ek_misafir*standart;
                    if (ek_misafir>4)
                    {

                        do
                        {
                            printf("\nkonuklar icin ek olarak oda secmek ister misiniz(E/H)?");
                            scanf(" %c",&ek_kisi);
                            if(ek_kisi=='E'|| ek_kisi=='e')
                            {
                                for(i=1; i<100; i+=2)
                                {
                                    if(oda[mevsimler][hafta-1][i]==0)
                                    {
                                        printf("%d\t",i);
                                    }
                                }
                                printf("nolu odalar standart odalara mevcuttur birini seciniz:");
                                scanf("%d",&secilen_oda);

                                break;
                            }
                        }
                        while(ek_misafir>4);
                    }
                    do
                    {
                        if(oda[mevsimler][hafta-1][secilen_oda-1]==1)
                        {
                            printf("\nbu oda doludur.");
                            printf("\nBir oda seciniz:");
                            scanf("%d",&secilen_oda);

                            break;

                        }
                        else
                        {
                            oda[mevsimler][hafta-1][secilen_oda-1]=1;
                            break;
                        }

                    }
                    while(1==1);
                    oda[mevsimler][hafta-1][secilen_oda]=1;
                }
            }
            else if(misafir==0)
            {
                printf("Hatali bir misafir sayisi girdiniz.");
                printf("\nTekrar rezervasyon yapmak istermisiniz?:");
                scanf(" %c",&karar);
                break;

            }
            else if (misafir>0 && misafir<=4)
            {
                ucret=misafir*standart;

            }

            printf("\nRezervasyon tiplerinden birini seciniz");
            printf("\non odemeli islem icin 'O',havale ile odeme icin 'H',standart odeme icin 'S': ");
            scanf("  %c",&odeme);
            switch (odeme)
            {
            case 'O':
            case 'o':
                if (misafir>4)
                {
                    odenecek=((ucret+ucret2)-(ucret*0.15+ucret2*0.15))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                else if (misafir>0 && misafir<=4)
                {
                    odenecek=(ucret-(ucret*0.15))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                for (j=0; j<12; j++) //oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\n\n\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            case 'H':
            case 'h':
                if (misafir<5)
                {
                    odenecek=((ucret+ucret2)-(standart*0.5))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                else if (misafir>=0 && misafir<=3)

                {
                    odenecek=ucret*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                else if (misafir>5)
                {
                    odenecek=((ucret+ucret2)-(standart*0.75))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                for (j=0; j<12; j++) //oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\n\n\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            case 'S':
            case 's':
                if (misafir>4)
                {
                    odenecek=(ucret+ucret2);
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                else if (misafir>0 && misafir<=4)
                {
                    odenecek=ucret*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);
                    break;
                }

                for (j=0; j<12; j++)
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\n\n\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;
                }
                break;
            default:

                printf("yanlis karakter girdiniz.");

                break;

            }


            printf("\nBaska bir rezervasyon yapmak ister misiniz:(e/h)");
            scanf(" %c",&karar);

        }

        else if (odasecim=='L'|| odasecim=='l')
        {
            for(i=6; i<100; i+=6)
            {
                if(oda[mevsimler][hafta-1][i-1]==0)
                {
                    printf("%d\t",i);
                }
            }
            printf("nolu odalar large deluxe odalara mevcuttur birini seciniz:");
            scanf("%d",&secilen_oda);

            if (secilen_oda%6!=0)
            {
                do //secilen oda 6nin kati degilse uyari veren döngü
                {
                    printf("boyle bir oda yoktur.");
                    printf("\nnolu odalar standart odalara mevcuttur birini seciniz:");
                    scanf("%d",&secilen_oda);

                }
                while (secilen_oda%6!=0);
            }
            do //odalarin doluluk bosluk oranlarini kontrol eden döngü
            {
                if(oda[mevsimler][hafta-1][secilen_oda-1]==1)
                {
                    printf("\nbu oda doludur.");
                    printf("\nBir oda seciniz:");
                    scanf("%d",&secilen_oda);

                }
                else
                {
                    oda[mevsimler][hafta-1][secilen_oda-1]=1;
                    break;
                }

            }
            while(1==1);
            oda[mevsimler][hafta-1][secilen_oda-1]=1;

            printf("Misafir sayisini giriniz:");
            scanf("%d",&misafir);
            if (misafir>7)
            {

                ucret=large_delux*4;
                printf("\nkonuklar icin ek olarak oda secmek ister misiniz(E/H)?");
                scanf(" %c",&ek_kisi);
                if(ek_kisi=='E'|| ek_kisi=='e')
                {
                    ek_misafir=misafir-7;

                    for(i=6; i<100; i+=6)
                    {
                        if(oda[mevsimler][hafta-1][i-1]==0)
                        {
                            printf("%d\t",i);
                        }

                    }


                    printf("nolu odalar large deluxe odalara mevcuttur birini seciniz:");
                    scanf("%d",&secilen_oda);
                    if (secilen_oda%6!=0)
                    {
                        do
                        {
                            printf("boyle bir oda yoktur.");
                            printf("\nnolu odalar standart odalara mevcuttur birini seciniz:");
                            scanf("%d",&secilen_oda);

                        }
                        while (secilen_oda%6!=0);
                    }
                    do
                    {
                        if(oda[mevsimler][hafta-1][secilen_oda-1]==1)
                        {
                            printf("\nbu oda doludur.");
                            printf("\nBir oda seciniz:");
                            scanf("%d",&secilen_oda);

                            break;

                        }
                        else
                        {
                            oda[mevsimler][hafta-1][secilen_oda-1]=1;
                            break;
                        }

                    }
                    while(1==1);
                    oda[mevsimler][hafta-1][secilen_oda-1]=1;
                    ucret2=ek_misafir*large_delux;
                    if (ek_misafir>7)

                        do
                        {
                            printf("\nkonuklar icin ek olarak oda secmek ister misiniz(E/H)?");
                            scanf(" %c",&ek_kisi);
                            if(ek_kisi=='E'|| ek_kisi=='e')
                            {
                                for(i=6; i<100; i+=6)
                                {
                                    if(oda[mevsimler][hafta-1][i-1]==0)
                                    {
                                        printf("%d\t",i);
                                    }
                                }
                                printf("nolu odalar large deluxe odalara mevcuttur birini seciniz:");
                                scanf("%d",&secilen_oda);
                                break;
                            }
                        }
                        while(ek_misafir>7);
                }
            }
            else if(misafir==0)
            {

                printf("Hatali bir misafir sayisi girdiniz.");
                printf("\nTekrar rezervasyon yapmak istermisiniz?:");
                scanf(" %c",&karar);
                break;

            }
            else if (misafir>0 && misafir<=7)
            {
                ucret=misafir*large_delux;

            }
            printf("\nRezervasyon tiplerinden birini seciniz");
            printf("\non odemeli islem icin 'O',havale ile odeme icin 'H',standart odeme icin 'S': ");
            scanf("  %c",&odeme);
            switch (odeme)
            {
            case 'O':
            case 'o':
                if (misafir>7)
                {
                    odenecek=((ucret+ucret2)-(ucret*0.15+ucret2*0.15))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                else if (misafir>0 && misafir<=7)
                {
                    odenecek=(ucret-(ucret*0.15))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                for (j=0; j<12; j++) //oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\n\n\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            case 'H':
            case 'h':
                if (misafir<5)
                {
                    odenecek=((ucret+ucret2)-(large_delux*0.5))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                else if (misafir>=0 && misafir<=3)

                {
                    odenecek=ucret*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                else if (misafir>5)
                {
                    odenecek=((ucret+ucret2)-(large_delux*0.75))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                for (j=0; j<12; j++) //oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\n\n\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            case 'S':
            case 's':
                if (misafir>7)
                {
                    odenecek=(ucret+ucret2)*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                else if (misafir>0 && misafir<=7)
                {
                    odenecek=ucret*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                for (j=0; j<12; j++) //oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\n\n\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            default :
                printf("Yanlis karakter girdiniz.");
                break;
            }

            printf("\nBaska bir rezervasyon yapmak ister misiniz:(e/h)");
            scanf(" %c",&karar);
        }
        else  if (odasecim=='D'|| odasecim=='d')
        {
            for(i=0; i<100; i+=2)
            {
                if(oda[mevsimler][hafta-1][i]==0)
                {
                    if (i%6==0)
                        continue;
                    printf("%d\t",i);
                }
            }




            printf("nolu odalar deluxe odalara mevcuttur birini seciniz:");
            scanf("%d",&secilen_oda);
            if (secilen_oda%2==1 || secilen_oda%6==0) //ekranda olmayan odalar secildiginde uyari veren döngü
            {
                do
                {
                    printf("boyle bir oda yoktur.");
                    printf("\nnolu odalar standart odalara mevcuttur birini seciniz:");
                    scanf("%d",&secilen_oda);

                }
                while (secilen_oda%6==1);
            }

            do //secilen odanin dolu olup olmadigini gosteren dongu
            {
                if(oda[mevsimler][hafta-1][secilen_oda-1]==1)
                {
                    printf("\nbu oda doludur.");
                    printf("\nBir oda seciniz:");
                    scanf("%d",&secilen_oda);

                    break;
                }
                else
                {
                    oda[mevsimler][hafta-1][secilen_oda-1]=1;
                    break;
                }

            }
            while(1==1);
            oda[mevsimler][hafta-1][secilen_oda]=1;
            printf("Misafir sayisini giriniz:");
            scanf("%d",&misafir);
            if (misafir>4)
            {

                ucret=delux*4;
                printf("\nkonuklar icin ek olarak oda secmek ister misiniz(E/H)?");
                scanf(" %c",&ek_kisi);
                if(ek_kisi=='E'|| ek_kisi=='e')
                {
                    ek_misafir=misafir-4;

                    for(i=0; i<100; i+=2)
                    {
                        if(oda[mevsimler][hafta-1][i]==0)
                        {
                            if (i%6==0)
                                continue;
                            printf("%d\t",i);
                        }
                    }



                    printf("nolu odalar deluxe odalara mevcuttur birini seciniz:");
                    scanf("%d",&secilen_oda);
                    if (secilen_oda%2==1 || secilen_oda%6==0) //ekranda olmayan odalar secildiginde uyari veren döngü
            {
                do
                {
                    printf("boyle bir oda yoktur.");
                    printf("\nnolu odalar standart odalara mevcuttur birini seciniz:");
                    scanf("%d",&secilen_oda);

                }
                while (secilen_oda%6==1);
            }

                    do
                    {
                        if(oda[mevsimler][hafta-1][secilen_oda-1]==1)
                        {
                            printf("\nbu oda doludur.");
                            printf("\nBir oda seciniz:");
                            scanf("%d",&secilen_oda);

                            break;

                        }
                        else
                        {
                            oda[mevsimler][hafta-1][secilen_oda-1]=1;
                            break;
                        }

                    }
                    while(1==1);
                    oda[mevsimler][hafta-1][secilen_oda-1]=1;
                    ucret2=ek_misafir*delux;
                    if (ek_misafir>4)
                    {

                        do
                        {
                            printf("\nkonuklar icin ek olarak oda secmek ister misiniz(E/H)?");
                            scanf(" %c",&ek_kisi);
                            if(ek_kisi=='E'|| ek_kisi=='e')
                            {
                                for(i=0; i<100; i+=2)
                                {
                                    if(oda[mevsimler][hafta-1][i-1]==0)
                                    {
                                        if (i%6==0)
                                            continue;
                                        printf("%d\t",i);
                                    }
                                }


                                printf("nolu odalar deluxe odalara mevcuttur birini seciniz:");
                                scanf("%d",&secilen_oda);
                                break;
                            }
                        }
                        while(ek_misafir>4);
                    }

                }
            }
            else if(misafir==0)
            {

                printf("Hatali bir misafir sayisi girdiniz.");
                printf("\nTekrar rezervasyon yapmak istermisiniz?:");
                scanf(" %c",&karar);
                break;

            }
            else if (misafir>0 && misafir<=4)
            {
                ucret=misafir*delux;

            }

            printf("\nRezervasyon tiplerinden birini seciniz");
            printf("\non odemeli islem icin 'O',havale ile odeme icin 'H',standart odeme icin 'S': ");
            scanf("  %c",&odeme);
            switch (odeme)
            {
            case 'O':
            case 'o':
                if (misafir>4)
                {
                    odenecek=((ucret+ucret2)-(ucret*0.15+ucret2*0.15))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                else if (misafir>0 && misafir<=4)
                {
                    odenecek=(ucret-(ucret*0.15))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                for (j=0; j<12; j++) //oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            case 'H':
            case 'h':
                if (misafir<5)
                {
                    odenecek=((ucret+ucret2)-(delux*0.5))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                else if (misafir>=0 && misafir<=3)

                {
                    odenecek=ucret*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }
                else if (misafir>5)
                {
                    odenecek=((ucret+ucret2)-(delux*0.75))*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                for (j=0; j<12; j++) //oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            case 'S':
            case 's':
                if (misafir>4)
                {
                    odenecek=(ucret+ucret2)*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                else if (misafir>0 && misafir<=4)
                {
                    odenecek=ucret*7;
                    printf("\nOdenecek toplam tutar:%.2f$",odenecek);

                }

                for (j=0; j<12; j++)//oteldeki odalarin haftalik dolu oranlarinin yuzdesini gösteren döngü
                {
                    for (i=0; i<100; i++)
                    {
                        if (oda[mevsimler][j][i]==1)
                            oran++;
                    }
                    printf("\nSonbahar %d. haftasi doluluk orani:%%%d\n",j+1,oran);
                    oran=0;

                }
                break;
            default:
                printf("Yanlis karakter girdiniz.");
                break;
            }

            printf("\nBaska bir rezervasyon yapmak ister misiniz:(e/h)");
            scanf(" %c",&karar);
        }



    }
    while(karar=='E'|| karar=='e');


    return 0;
}
