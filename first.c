#include <stdio.h>

int main(void)
{
    int temp1, temp2, temp3,sum;
    int notrepetive=1;
    int first[4] = {1, 2, 3, 4};
    int second[4] = {1, 2, 3, 4};
    int third[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
        {
        temp1=first[i];
        for (int j = 0; j < 4; j++)
            {
            temp2=second[j];
            for (int k = 0; k < 4; k++)
                temp3=third[k];
                sum=temp1*100+temp2*10+temp3;
                if (temp1 != temp2 && temp2 != temp3 && temp1 != temp3)
                    notrepetive++;
            printf("%d  ",sum);
            }
            }
    printf("\n not repetive=%d",notrepetive);
    return 0;
}