#include <stdio.h>

/* 分段计算奖金，输入/输出以万元为单位 */
double calc_bonus(double profit) {
    struct { double cap; double rate; } tiers[] = {
        {10, 0.10},
        {10, 0.075},
        {20, 0.05},
        {20, 0.03},
        {40, 0.01}
    };
    double bonus = 0.0;

    for (size_t i = 0; i < sizeof tiers / sizeof tiers[0] && profit > 0; ++i) {
        double chunk = profit < tiers[i].cap ? profit : tiers[i].cap;
        bonus += chunk * tiers[i].rate;
        profit -= chunk;
    }
    if (profit > 0) {
        bonus += profit * 0.01;  // 超过 100 万部分继续按 1%
    }

    return bonus;
}

int main(void) {
    double profit;
    printf("please input the profit (in 10k): ");
    if (scanf("%lf", &profit) != 1 || profit < 0) {
        puts("invalid input");
        return 1;
    }
    printf("the total bonus is %.2f\n", calc_bonus(profit));
    return 0;
}
