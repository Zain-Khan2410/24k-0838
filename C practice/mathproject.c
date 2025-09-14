#include <stdio.h>
#include <string.h>
// Function prototype
void differentiationMenu();
void integrationMenu();
void Basicdifferentiation();
// differentiation
void product(char term[], char derivative[])
{
    int coefficient = 1, power = 0;
    char base[100] = "";

    
    if (strchr(term, 'x') != NULL)
    {
        if (sscanf(term, "%[^x]x^%d", base, &power) == 2)
        {
            coefficient = (strlen(base) > 0) ? atoi(base) : 1;
            sprintf(derivative, "%dx^%d", coefficient * power, power - 1);
        }
        else if (sscanf(term, "%[^x]x", base) == 1)
        {
            coefficient = (strlen(base) > 0) ? atoi(base) : 1;
            sprintf(derivative, "%d", coefficient);
        }
        else
        {
            strcpy(derivative, "1");
        }
    }
    else
    {
        strcpy(derivative, "0");
    }
}

// Product Rule
void productRule()
{
    char term1[100], term2[100];
    char derivative1[100], derivative2[100];
    char result[500];

    printf("\nEnter the first term: ");
    scanf("%s", term1);
    printf("Enter the second term: ");
    scanf("%s", term2);

    // Displaying the function
    printf("\nExpression: %s . %s\n", term1, term2);
    product(term1, derivative1);
    product(term2, derivative2);

    printf("\nDerivative of first term (u'): %s\n", derivative1);
    printf("Derivative of second term (v'): %s\n", derivative2);

    // Applying product rule: u'v + uv'
    sprintf(result, "(%s)*(%s) + (%s)*(%s)", derivative1, term2, term1, derivative2);

    printf("\nDerivative: %s\n", result);
}

void quotientRule()
{
    char term1[100], term2[100];
    char derivative1[100], derivative2[100];
    char numerator[500], denominator[100], result[600];

    printf("\nEnter the numerator (u): ");
    scanf("%s", term1);
    printf("Enter the denominator (v): ");
    scanf("%s", term2);

    // Displaying the expression
    printf("\nExpression: (%s) / (%s)\n", term1, term2);

    product(term1, derivative1);
    product(term2, derivative2);

    printf("\nDerivative of numerator (u'): %s\n", derivative1);
    printf("Derivative of denominator (v'): %s\n", derivative2);

    // Applying quotient rule: (u'v - uv') / v^2
    sprintf(numerator, "(%s)*(%s) - (%s)*(%s)", derivative1, term2, term1, derivative2);
    sprintf(denominator, "(%s)^2", term2);
    sprintf(result, "(%s) / (%s)", numerator, denominator);

    // Display the result
    printf("\nDerivative: %s\n", result);
}

void simpletrigdiff()
{
    char input[50];

    printf("\nEnter a trigonometric function: ");
    scanf("%s", input);

    if (strcmp(input, "sinx") == 0)
    {
        printf("Derivative: cosx\n");
    }
    else if (strcmp(input, "cosx") == 0)
    {
        printf("Derivative: -sinx\n");
    }
    else if (strcmp(input, "tanx") == 0)
    {
        printf("Derivative: sec^2x\n");
    }
    else if (strcmp(input, "cscx") == 0)
    {
        printf("Derivative: -cscx * cotx\n");
    }
    else if (strcmp(input, "secx") == 0)
    {
        printf("Derivative: secx * tanx\n");
    }
    else if (strcmp(input, "cotx") == 0)
    {
        printf("Derivative: -csc^2x\n");
    }
    else
    {
        printf("Function not recognized or unsupported.\n");
    }
}
void simpletrigint()
{
    char input[50];

    printf("\nEnter a trigonometric function: ");
    scanf("%s", input);

    if (strcmp(input, "sinx") == 0)
    {
        printf("Integral: -cosx\n");
    }
    else if (strcmp(input, "cosx") == 0)
    {
        printf("Integral: sinx\n");
    }
    else if (strcmp(input, "tanx") == 0)
    {
        printf("Integral: -ln(cosx)\n");
    }
    else if (strcmp(input, "cscx") == 0)
    {
        printf("Integral: ln(cscx - cotx)\n");
    }
    else if (strcmp(input, "secx") == 0)
    {
        printf("Integral: ln(secx + tanx)\n");
    }
    else if (strcmp(input, "cotx") == 0)
    {
        printf("Integral: ln(sinx)\n");
    }
    else
    {
        printf("Function not recognized or unsupported.\n");
    }
}
void differentiatePolynomial()
{
    int numTerms;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);

    char term[100];
    char derivative[100];
    char result[1000] = "";

    for (int i = 0; i < numTerms; i++)
    {

        printf("Enter term %d: ", i + 1);
        scanf("%s", term);
        product(term, derivative);

        if (i == 0)
        {
            strcpy(result, derivative);
        }
        else
        {
            if (derivative[0] == '-')
            {
                strcat(result, " ");
                strcat(result, derivative);
            }
            else
            {
                strcat(result, " + ");
                strcat(result, derivative);
            }
        }
    }
    printf("\nThe derivative of the polynomial is: %s\n", result);
}
// Integration
void integrate(char term[], char integral[])
{
    int coefficient = 1, power = 0;
    char base[100] = "";

    
    if (strchr(term, 'x') != NULL)
    {

        if (sscanf(term, "%[^x]x^%d", base, &power) == 2)
        {
            coefficient = (strlen(base) > 0) ? atoi(base) : 1;
            if (power + 1 != 0)
            {
                sprintf(integral, "%.2lfx^%d", (double)coefficient / (power + 1), power + 1);
            }
            else
            {

                strcpy(integral, "ln|x|");
            }
        }
        else if (sscanf(term, "%[^x]x", base) == 1)
        {
            coefficient = (strlen(base) > 0) ? atoi(base) : 1;
            sprintf(integral, "%.2lfx", (double)coefficient / 2);
        }
        else
        {
            strcpy(integral, "x^2/2");
        }
    }
    else
    {
        coefficient = atoi(term);
        sprintf(integral, "%.2lfx", (double)coefficient);
    }
}

// polynomial integration
void integratePolynomial()
{
    int numTerms;
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &numTerms);

    char term[100];
    char integral[100];
    char result[1000] = "";

    for (int i = 0; i < numTerms; i++)
    {

        printf("Enter term %d: ", i + 1);
        scanf("%s", term);
        integrate(term, integral);
        if (i == 0)
        {
            strcpy(result, integral);
        }
        else
        {

            if (integral[0] == '-')
            {
                strcat(result, " ");
                strcat(result, integral);
            }
            else
            {
                strcat(result, " + ");
                strcat(result, integral);
            }
        }
    }
    printf("\nThe integral of the polynomial is: %s + C\n", result);
}
void basicIntegration()
{
    char term[100];
    char integral[100];

    printf("Enter a term to integrate (e.g., 7x^3, 5x, x, or 3): ");
    scanf("%s", term);
    integrate(term, integral);
    printf("The integral of %s is: %s + C\n", term, integral);
}

// Main function
int main()
{
    int choice;
     printf("-----Integration and Differentiation Calculator-----\n");
    printf("1. Differentiation.\n");
    printf("2. Integration.\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        differentiationMenu();
        break;
    case 2:
        integrationMenu();
        break;
    case 3:
        printf("Exiting Program.\n");
        return 0;
    default:
        printf("Invalid Choice. Select a valid option.\n");
        break;
    }
    return 0;
}

// Differentiation menu 
void differentiationMenu()
{
    int choice;
    char term[100], derivative[100];
    printf("\n--- Differentiation Menu ---\n");
    printf("1. Basic differentiation.\n");
    printf("2. Polynomial Functions\n");
    printf("3. Trigonometric Functions\n");
    printf("4. Product Rule\n");
    printf("5. Quotient Rule\n");
    printf("6. Go Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the term to differentiate: ");
        scanf("%s", term);
        product(term, derivative);
        printf("Derivative: %s\n", derivative);
        break;
    case 2:
        differentiatePolynomial();
        break;
    case 3:
        simpletrigdiff();
        break;
    case 4:
        productRule();
        break;
    case 5:
        quotientRule();
        break;
    case 6:
        return;
    default:
        printf("Invalid choice! Returning to differentiation menu.\n");
        break;
    }
}

// Integration menu 
void integrationMenu()
{
    int choice;
    printf("\n--- Integration Menu ---\n");
    printf("1. Basic Integration\n");
    printf("2. Polynomial Functions\n");
    printf("3. Trigonometric Functions\n");
    printf("4. Go Back\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        basicIntegration();
        break;
    case 2:
        integratePolynomial();
        break;
    case 3:
        simpletrigint();
        break;
    case 4:
        return;
    default:
        printf("Invalid choice! Returning to integration menu.\n");
        break;
    }
}
