#include <stdio.h>
#include "billing.h"
#include "patient.h"
#include "hospital_data.h"

int specialtyQueue[4] = {0, 0, 0, 0};


double calculateWaitingTime(int specialtyID)
{
    int queueCount=0;
    double averageTime=0.0;

    queueCount = (int)specialtyQueue[specialtyID - 1];

    if (specialtyID == 1)
        averageTime = 15;
    else if (specialtyID == 2)
        averageTime = 20;
    else if (specialtyID == 3)
        averageTime = 30;
    else
        averageTime = 30;

    return queueCount * averageTime;
}



double calculateEmergencySurcharge(double baseFee, int urgencyLevel)
{
    if (urgencyLevel == 2)
        return baseFee * 0.20;
    else if (urgencyLevel == 3)
        return baseFee * 0.50;
    else
        return 0;
}



double calculateWardCost(int wardID, int days)
{
    double dailyRate = 0.0;

    if (wardID == 1)
        dailyRate = 3000;
    else if (wardID == 2)
        dailyRate = 6000;
    else if (wardID == 3)
        dailyRate = 12000;
    else if (wardID == 4)
        dailyRate = 25000;

    return dailyRate * days;
}



double calculateGrossTotal(double baseFee, double surcharge, double wardCost)
{
    return baseFee + surcharge + wardCost;
}



double calculateDiscount(double grossTotal, int age)
{
    if (age < 5 || age > 65)
        return grossTotal * 0.15;

    return 0;
}



double calculateFinalAmount(double grossTotal, double discount)
{
    return grossTotal - discount;
}



void displayPatientBill(int patientIndex)
{
    double baseFee=0.0;
    double surcharge=0.0;
    double wardCost=0.0;
    double grossTotal=0.0;
    double discount=0.0;
    double finalAmount=0.0;
    double waitingTime=0.0;

    const char *specialtyName;
    const char *wardName;
    const char *urgencyName;


    if (patientSpecialty[patientIndex] == 1)
    {
        specialtyName = "General Practice";
        baseFee = 1500;
    }
    else if (patientSpecialty[patientIndex] == 2)
    {
        specialtyName = "Paediatrics";
        baseFee = 2500;
    }
    else if (patientSpecialty[patientIndex] == 3)
    {
        specialtyName = "Cardiology";
        baseFee = 4500;
    }
    else
    {
        specialtyName = "Neurology";
        baseFee = 5000;
    }


    if (patientUrgency[patientIndex] == 1)
        urgencyName = "Normal";
    else if (patientUrgency[patientIndex] == 2)
        urgencyName = "Urgent";
    else
        urgencyName = "Critical";


    if (patientWard[patientIndex] == 1)
        wardName = "General Ward";
    else if (patientWard[patientIndex] == 2)
        wardName = "Paediatric Ward";
    else if (patientWard[patientIndex] == 3)
        wardName = "Surgical Ward";
    else if (patientWard[patientIndex] == 4)
        wardName = "ICU";
    else
        wardName = "Outpatient";

    surcharge = calculateEmergencySurcharge(baseFee,patientUrgency[patientIndex]);

    wardCost = calculateWardCost(patientWard[patientIndex],patientDays[patientIndex]);

    grossTotal = calculateGrossTotal(baseFee,surcharge,wardCost);

    discount = calculateDiscount(grossTotal,patientAge[patientIndex]);

    finalAmount = calculateFinalAmount(grossTotal,discount);

    waitingTime = calculateWaitingTime(patientSpecialty[patientIndex]);

    printf("\n");
    printf("===============================================================\n");
    printf("                       PATIENT BILL\n");
    printf("===============================================================\n");

    printf("Patient ID       : PAT-%04d\n", patientIndex + 1);
    printf("Patient Name     : %s\n", patientName[patientIndex]);
    printf("Age              : %d\n", patientAge[patientIndex]);

    if (patientAge[patientIndex] < 5 || patientAge[patientIndex] > 65)
        printf("Age Subsidy      : 15%%\n");
    else
        printf("Age Subsidy      : None\n");

    printf("Specialty        : %s\n", specialtyName);

    if (patientAdmitted[patientIndex] == 1)
    {
        printf("Assigned Ward    : %s\n", wardName);
        printf("Assigned Bed     : Bed #%02d\n", patientBed[patientIndex]);
    }
    else
    {
        printf("Assigned Ward    : Outpatient\n");
        printf("Assigned Bed     : None\n");
    }

    printf("Urgency          : %s\n", urgencyName);
    printf("Base Fee         : Rs. %.2f\n", baseFee);
    printf("Surcharge        : Rs. %.2f\n", surcharge);
    printf("Ward Cost        : Rs. %.2f\n", wardCost);
    printf("Gross Total      : Rs. %.2f\n", grossTotal);
    printf("Discount         : Rs. %.2f\n", discount);
    printf("Final Payable    : Rs. %.2f\n", finalAmount);
    printf("Waiting Time     : %.0f minutes\n", waitingTime);

    printf("===============================================================\n");
}
