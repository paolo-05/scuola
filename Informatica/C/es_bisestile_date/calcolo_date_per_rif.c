#include <stdio.h>

int bisestile(int *anno)
{
    return (*anno % 4 == 0 && *anno % 100 != 0 || *anno % 400 == 0) ? 1 : 0;
}

int controllodata(int *giorno, int *mese, int *anno)
{
    if (*anno >= 1900 && *anno <= 2100)
    {
        if (*mese >= 1 && *mese <= 12)
        {
            switch (*mese)
            {
            case 1:
                return (*giorno >= 1 && *giorno <= 31) ? 1 : 0;
                break;
            case 2:
                return (bisestile(&*anno) == 1 && *giorno >= 1 && *giorno <= 29 || bisestile(&*anno) == 0 && *giorno >= 1 && *giorno <= 28) ? 1 : 0;
                break;
            case 3:
                return (*giorno >= 1 && *giorno <= 31) ? 1 : 0;
                break;
            case 4:
                return (*giorno >= 1 && *giorno <= 30) ? 1 : 0;
                break;
            case 5:
                return (*giorno >= 1 && *giorno <= 31) ? 1 : 0;
                break;
            case 6:
                return (*giorno >= 1 && *giorno <= 30) ? 1 : 0;
                break;
            case 7:
                return (*giorno >= 1 && *giorno <= 31) ? 1 : 0;
                break;
            case 8:
                return (*giorno >= 1 && *giorno <= 31) ? 1 : 0;
                break;
            case 9:
                return (*giorno >= 1 && *giorno <= 30) ? 1 : 0;
                break;
            case 10:
                return (*giorno >= 1 && *giorno <= 31) ? 1 : 0;
                break;
            case 11:
                return (*giorno >= 1 && *giorno <= 30) ? 1 : 0;
                break;
            case 12:
                return (*giorno >= 1 && *giorno <= 31) ? 1 : 0;
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
        return 1;
    else if (aa2 > aa1)
        return 0;
    else if (aa1 = aa2)
        if (mm1 > mm2)
            return 1;
        else if (mm2 < mm1)
            return 0;
        else if (mm1 = mm2)
            if (gg1 > gg2)
                return 1;
            else if (gg2 > gg1)
                return 0;
            else
                return 2;
}
int acquisiciData(int *gg, int *mm, int *aa, int volte)
{
    do
    {
        printf("\ninserisci la %d^ data(gg/mm/aa): ", volte);
        scanf("%d/%d/%d", &*gg, &*mm, &*aa);
    } while (controllodata(&*gg, &*mm, &*aa) == 0);
    return (bisestile(&*aa) == 1) ? 1 : 0;
}

int main(void)
{
    int gg1, gg2, mm1, mm2, aa1, aa2;
    int confdat;
    int volte = 1;
    (acquisiciData(&gg1, &mm1, &aa1, volte) == 1) ? printf("\nL'anno %d e' bisestile", aa1) : printf("\nL'anno %d non e' bisestile", aa1);
    volte++;
    (acquisiciData(&gg2, &mm2, &aa2, volte) == 1) ? printf("\nL'anno %d e' bisestile", aa2) : printf("\nL'anno %d non e' bisestile", aa2);
    confdat = confrontodate(gg1, mm1, aa1, gg2, mm2, aa2);
    (confdat == 0)
        ? printf("\nLa seconda data (%d/%d/%d) e' maggiore della prima (%d/%d/%d)\n", gg2, mm2, aa2, gg1, mm1, aa1)
    : (confdat == 1)
        ? printf("\nLa prima data (%d/%d/%d) e' maggiore della seconda (%d/%d/%d)\n", gg1, mm1, aa1, gg2, mm2, aa2)
        : printf("\nLe due date (%d/%d/%d) sono uguali\n", gg1, mm1, aa1);

    return 0;
}