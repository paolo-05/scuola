#include <stdio.h>

int bisestile(int anno)
{
    if (anno % 4 == 0 && anno % 100 != 0 || anno % 400 == 0)
        return 1;
    else
        return 0;
}

int controllodata(int giorno, int mese, int anno)
{
    if (anno >= 1900 && anno <= 2100)
    {
        if (mese >= 1 && mese <= 12)
        {
            switch (mese)
            {
            case 1:
                if (giorno >= 1 && giorno <= 31)
                    return 1;
                else
                    return 0;
                break;
            case 2:
                if (bisestile(anno) == 1 && giorno >= 1 && giorno <= 29 || bisestile(anno) == 0 && giorno >= 1 && giorno <= 28)
                    return 1;
                else
                    return 0;
                break;
            case 3:
                if (giorno >= 1 && giorno <= 31)
                    return 1;
                else
                    return 0;
                break;
            case 4:
                if (giorno >= 1 && giorno <= 30)
                    return 1;
                else
                    return 0;
                break;
            case 5:
                if (giorno >= 1 && giorno <= 31)
                    return 1;
                else
                    return 0;
                break;
            case 6:
                if (giorno >= 1 && giorno <= 30)
                    return 1;
                else
                    return 0;
                break;
            case 7:
                if (giorno >= 1 && giorno <= 31)
                    return 1;
                else
                    return 0;
                break;
            case 8:
                if (giorno >= 1 && giorno <= 31)
                    return 1;
                else
                    return 0;
                break;
            case 9:
                if (giorno >= 1 && giorno <= 30)
                    return 1;
                else
                    return 0;
                break;
            case 10:
                if (giorno >= 1 && giorno <= 31)
                    return 1;
                else
                    return 0;
                break;
            case 11:
                if (giorno >= 1 && giorno <= 30)
                    return 1;
                else
                    return 0;
                break;
            case 12:
                if (giorno >= 1 && giorno <= 31)
                    return 1;
                else
                    return 0;
                break;
            }
        }
        else
            return 0;
    }
    else
        return 0;
}

int confrontodate(int gg1, int mm1, int aa1, int gg2, int mm2, int aa2)
{
    if (aa1 > aa2)
    {
        return 1;
    }
    else if (aa2 > aa1)
    {
        return 0;
    }
    else if (aa1 = aa2)
    {
        if (mm1 > mm2)
        {
            return 1;
        }
        else if (mm2 < mm1)
        {
            return 0;
        }
        else if (mm1 = mm2)
        {
            if (gg1 > gg2)
            {
                return 1;
            }
            else if (gg2 > gg1)
            {
                return 0;
            }
            else
            {
                return 2;
            }
        }
    }
}

int main()
{
    int giorno1, mese1, anno1, giorno2, mese2, anno2;

    do
    {
        printf("\ninserisci la prima data(gg/mm/aa): ");
        scanf("%d/%d/%d", &giorno1, &mese1, &anno1);
        if (bisestile(anno1) == 1)
            printf("l'anno e' bisestile\n");
        else
            printf("l'anno non e' bisestile\n");
    } while (controllodata(giorno1, mese1, anno1) == 0);
    do
    {
        printf("\ninserisci la seconda data(gg/mm/aa): ");
        scanf("%d/%d/%d", &giorno2, &mese2, &anno2);
        if (bisestile(anno2) == 1)
            printf("l'anno e' bisestile\n");
        else
            printf("l'anno non e' bisestile\n");
    } while (controllodata(giorno2, mese2, anno2) == 0);

    if (confrontodate(giorno1, mese1, anno1, giorno2, mese2, anno2) == 1)
    {
        printf("\nla prima data inserita e' maggiore della seconda\n");
    }
    else if (confrontodate(giorno1, mese1, anno1, giorno2, mese2, anno2) == 0)
    {
        printf("\nla seconda data inserita e' maggiore della prima\n");
    }
    else
    {
        printf("\nle due date sono uguali\n");
    }

    return 0;
}
