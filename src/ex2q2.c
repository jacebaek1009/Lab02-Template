#include <stdio.h>
#include <math.h>

float findDistance(float firsta, float firstb, float seconda, float secondb)
{
    return sqrtf((firsta - seconda) * (firsta - seconda) +
                 (firstb - secondb) * (firstb - secondb));
}

// Print float with comma separator for thousands
void print_distance(float distance)
{
    int whole_part = (int)distance;
    int decimal_part = (int)((distance - whole_part) * 100 + 0.5);

    if (decimal_part >= 100)
    {
        whole_part++;
        decimal_part -= 100;
    }

    if (whole_part >= 1000)
    {
        printf("%d,%03d.%02d", whole_part / 1000, whole_part % 1000, decimal_part);
    }
    else
    {
        printf("%d.%02d", whole_part, decimal_part);
    }
}

int main()
{
    float coord1a, coord1b, coord2a, coord2b, coord3a, coord3b;
    char dummy;

    // Point 1
    printf("Point 1: ");
    if (scanf(" %c%f , %f%c", &dummy, &coord1a, &coord1b, &dummy) != 4)
    {
        return 1;
    }
    printf("(%g, %g)\n", coord1a, coord1b);

    // Point 2
    printf("Point 2: ");
    if (scanf(" %c%f , %f%c", &dummy, &coord2a, &coord2b, &dummy) != 4)
    {
        return 1;
    }
    printf("(%g, %g)\n", coord2a, coord2b);

    // Point 3
    printf("Point 3: ");
    if (scanf(" %c%f , %f%c", &dummy, &coord3a, &coord3b, &dummy) != 4)
    {
        return 1;
    }
    printf("(%g, %g)\n", coord3a, coord3b);

    printf("\n");

    float distance1 = findDistance(coord1a, coord1b, coord2a, coord2b);
    float distance2 = findDistance(coord2a, coord2b, coord3a, coord3b);
    float distance3 = findDistance(coord1a, coord1b, coord3a, coord3b);

    // Check equality first
    if (distance1 == distance2 && distance2 == distance3)
    {
        printf("P1<->P2: ");
        print_distance(distance1);
        printf("\n");
        printf("P2<->P3: ");
        print_distance(distance2);
        printf("\n");
        printf("P1<->P3: ");
        print_distance(distance3);
        printf("\n");
    }
    else if (distance1 == distance2)
    {
        printf("P1<->P2: ");
        print_distance(distance1);
        printf("\n");
        printf("P2<->P3: ");
        print_distance(distance2);
        printf("\n");
    }
    else if (distance1 == distance3)
    {
        printf("P1<->P2: ");
        print_distance(distance1);
        printf("\n");
        printf("P1<->P3: ");
        print_distance(distance3);
        printf("\n");
    }
    else if (distance2 == distance3)
    {
        printf("P2<->P3: ");
        print_distance(distance2);
        printf("\n");
        printf("P1<->P3: ");
        print_distance(distance3);
        printf("\n");
    }
    else if (distance1 > distance2 && distance1 > distance3)
    {
        printf("P1<->P2: ");
        print_distance(distance1);
        printf("\n");
    }
    else if (distance2 > distance1 && distance2 > distance3)
    {
        printf("P2<->P3: ");
        print_distance(distance2);
        printf("\n");
    }
    else if (distance3 > distance1 && distance3 > distance2)
    {
        printf("P1<->P3: ");
        print_distance(distance3);
        printf("\n");
    }

    return 0;
}
