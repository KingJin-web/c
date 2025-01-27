#include <cmath>
#include <iostream>
using namespace std;
int T1(int);
int main(int argc, char const *argv[])
{


    cout<<pow(2,3)<<endl;
    //printf("%d\n", T1(5));
    return 0;
}

/**
 * ### 1. 超级楼梯问题：
有一楼梯共M级，刚开始时你在第一级，若每次只能跨上一级或二级h或三级，
要走上第M级，共有多少种走法？要求时间复杂度为O(n)，空间复杂度为O(1)。

/*
/*
1级：1种
2级：2种
3级：4种
4级：1+2+4=7种 （前3个和）
5级：2+4+7=13种 （前3个和）
6级：4+7+13=24种 （前3个和）
7级：7+13+24=44种 （前3个和）
8级：13+24+44=81种（前3个和）

得到 自4级后
f(n) = f(n -1) + f(n-2) + f(n-3)
*/
int T1(int m)
{
    int F[5] = {0, 1, 2, 4, 0};

    if (m > 0 && m < 4)
        return F[m];

    for (int i = 4; i <= m; i++)
    {
        F[4] = F[1] + F[2] + F[3];
        F[1] = F[2];
        F[2] = F[3];
        F[3] = F[4];
    }

    return F[4];
}

