//
//  main.cpp
//  PRG-3-14-Monthly-Sales-Tax
//
//  Created by Keith Smith on 10/6/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A retail company must file a monthly sales tax report listing the sales for the month and
//  the amount of sales tax collected. Write a program that asks for the month, the year,
//  and the total amount collected at the cash register (i.e. sales plus sales tax). Assume the
//  state sales tax is 4 percent, and the county sales tax is 2 percent.
//  If the total amount collected is known and the total sales tax is 6 percent, the amount
//  of product sales may be calculated as:
//  S = T / 1.06
//  S is the product salesa and T is the total income (product sales plus sales tax).
//  The program should display a report similar to:
//
//  Month: October
//  ---------------
//  Total Collected:        $26572.89
//  Sales:                  $25068.76
//  County Sales Tax:       $501.38
//  State Sales Tax:        $1002.75
//  Total Sales Tax:        $1504.13

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    // Declare constants
    const float FLT_SALES_TAX_COUNTY = 0.02f,
    FLT_SALES_TAX_STATE = 0.04f;
    
    // Declare variables
    string strMonthName;
    
    int intYear;
    
    float fltMonthlyIncomeGross,
          fltMonthlyIncomeNet,
    
          fltMonthlyTaxesCounty,
          fltMonthlyTaxesState,
          fltMonthlyTaxesTotal;
    
    cout << "Please enter the month: " << endl;
    cin >> strMonthName;
    
    cout << "Please enter the year: " << endl;
    cin >> intYear;
    while(!cin || intYear < 1990 || intYear > 2020)
    {
        cout << "Please enter a year between 1990 and 2020:\n";
        cin.clear();
        cin.ignore();
        cin >> intYear;
    }
    
    cout << "Please enter the total sales for the month: " << endl << "$";
    cin >> fltMonthlyIncomeGross;
    while(!cin || fltMonthlyIncomeGross < 0.0f || fltMonthlyIncomeGross > 1000000.0f)
    {
        cout << "Please enter a monthly gross between $0.00 and $1,000,000.00:\n";
        cin.clear();
        cin.ignore();
        cin >> fltMonthlyIncomeGross;
    }
    
    fltMonthlyIncomeNet = fltMonthlyIncomeGross * (1.0f - FLT_SALES_TAX_STATE - FLT_SALES_TAX_COUNTY);
    
    fltMonthlyTaxesCounty = fltMonthlyIncomeGross * FLT_SALES_TAX_COUNTY;
    fltMonthlyTaxesState = fltMonthlyIncomeGross * FLT_SALES_TAX_STATE;
    fltMonthlyTaxesTotal = fltMonthlyTaxesCounty + fltMonthlyTaxesState;
    
    // Configure decimal output for dollar amount, two points of precision
    cout << setprecision(2) << fixed << showpoint;
    
    // Output calculated value to console in format matching prompt
    cout << "Month: " << strMonthName << " , " << intYear << endl;
    cout << "--------------------------" << endl;
    cout << setw(20) << left << "Total Collected:"
    << setw(20) << right << "$" << setw(15) << right << fltMonthlyIncomeGross << endl;
    cout << setw(20) << left << "Sales:"
    << setw(20) << right << "$" << setw(15) << right << fltMonthlyIncomeNet << endl;
    cout << setw(20) << left << "County Sales Tax:"
    << setw(20) << right << "$" << setw(15) << right << fltMonthlyTaxesCounty << endl;
    cout << setw(20) << left << "State Sales Tax:"
    << setw(20) << right << "$" << setw(15) << right << fltMonthlyTaxesState << endl;
    cout << setw(20) << left << "Total Sales Tax:"
    << setw(20) << right << "$" << setw(15) << right << fltMonthlyTaxesTotal << endl;
    
    return 0;
}



