#include <stdio.h>
#include <stdbool.h>

bool LR = true;
bool RL = false;

int getMobile(int a[], bool dir[], int n)
{
    int i;
    int prev = 0, mobile = 0;

    for (i = 0; i < n; i++)
    {
        if (dir[a[i] - 1] == RL && i != 0 && a[i] > a[i - 1] && a[i] > prev)
        {
            mobile = a[i];
            prev = mobile;
        }
        else if (dir[a[i] - 1] == LR && i != n - 1 && a[i] > a[i + 1] && a[i] > prev)
        {
            mobile = a[i];
            prev = mobile;
        }
    }

    return mobile;
}

int Perm(int a[], bool dir[], int n)
{
    int temp;
    int mobile = getMobile(a, dir, n);
    int pos;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mobile)
        {
            pos = i;
            break;
        }
    }

    if (dir[a[pos] - 1] == RL)
    {
        temp = a[pos];
        a[pos] = a[pos - 1];
        a[pos - 1] = temp;
    }
    else if (dir[a[pos] - 1] == LR)
    {
        temp = a[pos + 1];
        a[pos + 1] = a[pos];
        a[pos] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mobile)
        {
            dir[a[i] - 1] = !dir[a[i] - 1];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    printf(" ");
}

void perms(int n)
{
    int a[n];
    bool dir[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        printf("%d", a[i]);
    }
    printf(" ");

    for (int i = 0; i < n; i++)
        dir[i] = RL;

    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact = fact * i;

    for (int i = 1; i < fact; i++)
        Perm(a, dir, n);
}

int main(void)
{
    int n;
    printf("Enter positive value of n: ");
    scanf("%d", &n);
    perms(n);
}