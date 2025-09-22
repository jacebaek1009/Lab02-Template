#include <stdio.h>

float chipDiscount(int quantity, int candy)
{
    int i;
    if (candy >= 1 && quantity >= 2)
    {
        float percentage = 0;
        for (i = 0; i < quantity; i += 2)
        {
            percentage += 0.5;
        }
        return percentage;
    };

    return 0;
}

float totalDiscount(float apple, float carrot, float chip, float candy)
{
    float itemList[] = {apple, carrot, chip, candy};

    int counter = 0;
    for (int i = 0; i < 4; i++)
    {
        if (itemList[i] >= 1)
        {
            counter++;
        }
    };

    if (counter == 4)
    {
        return 0.1;
    };

    return 0;
}

void printHeader()
{
    for (int i = 0; i < 67; i++)
    {
        printf("-");
    }
    printf("\n");

    printf("| %s     | %s     | %s       | %s    | %s      |\n", "Item", "Quantity", "Cost", "Discount", "Total");
}

void printFooter()
{
    for (int i = 0; i < 67; i++)
    {
        printf("-");
    }
    printf("\n");
}

void printItemKg(char *item, float quantity, float cost, float discount, float total)
{
    if (quantity > 0)
    {
        printf("| %-8s | %.2f      kg | $%9.2f | -$%9.2f | $%9.2f |\n", item, quantity, cost, discount, total);
    }
}

void printItemUnit(char *item, int quantity, float cost, float discount, float total)
{
    if (quantity > 0)
    {
        printf("| %-8s | %-12d | $%9.2f | -$%9.2f | $%9.2f |\n", item, quantity, cost, discount, total);
    }
}

int customerChoseNth(float apple, float carrot, int chip, int candy)
{
    if (apple == 0 && carrot == 0 && chip == 0 && candy == 0)
    {
        return 0;
    }
    return 1;
}

int main()
{
    float apples[] = {5.99, 7.20};
    float carrots[] = {3.99, 4.10};
    float chips[] = {2.99, 9};
    float candys[] = {1.50, 3};

    char appleStr[20];
    char carrotStr[20];

    float apple;
    float carrot;
    int chip;
    int candy;

    printf("%-11s(%-5.2f kg) : ", "Apples", apples[1]);
    scanf("%s", appleStr);
    if (sscanf(appleStr, "%f", &apple) != 1)
    {
        return 1; // Invalid input
    }
    printf("%s\n", appleStr);
    if (apple > apples[1])
    {
        return 1;
    }
    printf("%-11s(%-5.2f kg) : ", "Carrots", carrots[1]);
    scanf("%s", carrotStr);
    if (sscanf(carrotStr, "%f", &carrot) != 1)
    {
        return 1; // Invalid input
    }
    printf("%s\n", carrotStr);
    if (carrot > carrots[1])
    {
        return 1;
    }
    printf("%-11s(%-2d units) : ", "Chips", 9);
    if (scanf("%d", &chip) != 1)
    {
        return 1; // Invalid input
    }
    printf("%d\n", chip);
    if (chip > chips[1])
    {
        return 1;
    }
    printf("%-11s(%-2d units) : ", "Candy", 3);
    if (scanf("%d", &candy) != 1)
    {
        return 1; // Invalid input
    }
    printf("%d\n", candy);
    if (candy > candys[1])
    {
        return 1;
    }
    if (customerChoseNth(apple, carrot, chip, candy) == 0)
    {
        return 0;
    }

    else
    {
        printf("\n");

        printHeader();

        printItemKg("Apples", apple, apple * apples[0], 0, apple * apples[0]);
        printItemKg("Carrots", carrot, carrot * carrots[0], 0, carrot * carrots[0]);
        printItemUnit("Chips", chip, chip * chips[0], 0, chip * chips[0]);
        printItemUnit("Candy", candy, candy * candys[0], candys[0] * chipDiscount(chip, candy), candy * candys[0] - (chipDiscount(chip, candy) * candys[0]));
        printFooter();
        printf("\n");

        float subtotal = (apple * apples[0]) + (carrot * carrots[0]) + (chip * chips[0]) + (candy * candys[0] - (chipDiscount(chip, candy) * candys[0]));
        float finalPrice = subtotal - (totalDiscount(apple, carrot, chip, candy) * subtotal);
        float afterTax = finalPrice * 1.05;

        float discount = totalDiscount(apple, carrot, chip, candy) * subtotal;
        if (discount > 0)
        {
            printf("Subtotal        : $%.2f - $%.2f = $%.2f\n", subtotal, totalDiscount(apple, carrot, chip, candy) * subtotal, finalPrice);
        }
        else
        {
            printf("Subtotal        : $%.2f\n", subtotal);
        }
        printf("Tax (5%%)        : $%.2f\n", finalPrice * 0.05);
        for (int i = 0; i < 52; i++)
        {
            printf("-");
        }
        printf("\n");
        printf("Total           : $%.2f", afterTax);
        return 0;
    }
}