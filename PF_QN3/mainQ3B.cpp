       //WATER BILLING SYSTEM    
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double balance, totalCost = 0.0;
    const double surchargeRate = 0.15;
    const double vatRate = 0.18;
    
    // This prompt user for input
    cout << "Enter the amount loaded onto your account (UGX): ";
    cin >> balance;
    
    int unitsConsumed;
    cout << "Enter the number of water units consumed: ";
    cin >> unitsConsumed;

    // Calculating total cost based on water usage
    if (unitsConsumed <= 10) {
        totalCost = unitsConsumed * 150;
    } else if (unitsConsumed <= 20) {
        totalCost = (10 * 150) + ((unitsConsumed - 10) * 175);
    } else {
        totalCost = (10 * 150) + (10 * 175) + ((unitsConsumed - 20) * 200);
    }
    
    //  Adding the surcharge
    totalCost += totalCost * surchargeRate;
    
    // Calculating  VAT
    double vat = totalCost * vatRate;
    totalCost += vat;

    // Checking the balance
    if (balance >= totalCost) {
        balance -= totalCost; 
        
        cout << "Transaction successful! Your remaining balance is: " << balance << " UGX" << endl;
    } else {
        cout << "Error: Insufficient balance! Remaining balance: " << balance << " UGX" << endl;
    }

    return 0;
}
