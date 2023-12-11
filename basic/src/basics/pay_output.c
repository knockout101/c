#include <stdio.h>


double get_paid(int hours, double pay_rate)
{
    double pay = 0;

    if (hours >= 40)
    {


        pay += 40 * pay_rate;
        hours -= 40;

        pay += hours * (pay_rate * 1.5);

        return pay;
    }

    pay += hours * pay_rate;

    return pay;
}

int main(int argc, char *argv[])
{
    int hours = 0;
    float base_rate = 12.00;
    double net_pay = 0;
    double taxes = 0;
    double deductions;

    printf("\nPlease enter the number of hours for the week: ");

    scanf("%d", &hours);

    printf("\nYou entered: %d hours\n", hours);

    printf("\nCalculating....\n");

    double gross_pay = get_paid(hours, base_rate);
    double gross_pay_copy = gross_pay;

    if (gross_pay >= 300)
    {
        gross_pay -= 300;

        deductions = 300 * 0.15;
        net_pay += 300 - deductions;

        taxes += deductions;

    }
    else
    {
        deductions = gross_pay * 0.15;
        net_pay += gross_pay - deductions;
    
        gross_pay = 0;

        taxes += deductions;
    }

    if (gross_pay >= 150)
    {
        gross_pay -= 150;

        deductions = 150 * 0.2;
        net_pay += 150 - deductions;

        taxes += deductions;
    }
    else
    {
        deductions = gross_pay * 0.2;
        net_pay += gross_pay - deductions;

        gross_pay = 0;

        taxes += deductions;
    }

    if (gross_pay)
    {
        deductions = gross_pay * 0.25;
        net_pay += gross_pay - deductions;

        taxes += deductions;
    }
 
    printf(
        "\nGross pay: $%.2lf\n\nTaxes: $%.2lf\n\nNet pay: $%.2lf\n\n",
        gross_pay_copy, taxes, net_pay
        );

    return 0;
}