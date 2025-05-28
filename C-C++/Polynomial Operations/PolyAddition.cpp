#include <iostream>
struct PolyAddition
{
    float coeff;
    int exp;
} p1[10], p2[10], p3[10];

int read(PolyAddition p[])
{

    int t1;
    std::cout << "Enter the max count";
    std::cin >> t1;
    for (int i = 0; i < t1; i++)
    {
        std::cout << "Enter the " << i + 1 << "th coefficient\n";
        std::cin >> p[i].coeff;
        std::cout << "Enter the " << i + 1 << "th exponent\n";
        std::cin >> p[i].exp;
    }
    return t1;
}
void display(PolyAddition p[], int t1)
{
    for (int i = 0; i < t1; i++)
    {
        std::cout << "The " << i + 1 << "coefficient is " << p[i].coeff << "\n";
        std::cout << "The " << i + 1 << "exponent is " << p[i].exp << "\n";
    }
}
int polyaddition(PolyAddition p1[], PolyAddition p2[], PolyAddition p3[], int t1, int t2)
{

    int i = 0, j = 0, k = 0;
    while (i <= t1 && j <= t2)
    {
        if (p1[i].exp == p2[j].exp)
        {
            float coeff = p1[i].coeff + p2[j].coeff;
            p3[k].coeff = coeff;
            p3[k].exp = p1[i].exp;
            i++;
            j++;
            k++;
        }
        else if (p1[i].exp < p2[j].exp)
        {
            p3[k].coeff = p2[j].coeff;
            p3[k].exp = p2[j].exp;
            j++;
            k++;
        }
        else
        {
            p3[k].coeff = p1[i].coeff;
            p3[k].exp = p1[i].exp;
            i++;
            k++;
        }
    }
    while (i < t1)
    {
        p3[k].coeff = p1[1].coeff;
        p3[k].exp = p1[1].exp;
        i++;
        k++;
    }
    while (j < t1)
    {
        p3[k].coeff = p2[j].coeff;
        p3[k].exp = p2[j].exp;
        j++;
        k++;
    }

    return k;
}

int main()
{

    int t1 = read(p1);

    int t2 = read(p2);
    std::cout << "Adding.....\n";
    int k = polyaddition(p1, p2, p3, t1, t2);
    std::cout << "After Addition...\n";
    display(p3, k);
}