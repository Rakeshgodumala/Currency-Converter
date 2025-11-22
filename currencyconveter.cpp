#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>
using namespace std;

// Conversion Formula:
// amount in USD = amount / rate[from]
// final amount  = amount_in_USD * rate[to]
double convert(double amount, string from, string to,
               unordered_map<string, double> &rate)
{
    double usd = amount / rate[from];     // convert to USD
    return usd * rate[to];                // convert USD to required currency
}

int main()
{
    unordered_map<string, double> rate;

    // ==========================================================
    // 1 USD = X Currency (LATEST RATES — UPDATE WHEN YOU WANT)
    // ==========================================================
    rate = {
        {"USD", 1.00},
        {"INR", 89.64}, {"EUR", 0.92}, {"GBP", 0.79}, {"JPY", 157.50},
        {"AUD", 1.52}, {"CAD", 1.35}, {"CHF", 0.89}, {"CNY", 7.30},
        {"SGD", 1.36}, {"NZD", 1.68}, {"AED", 3.67}, {"SAR", 3.76},
        {"ZAR", 19.50}, {"BRL", 4.95}, {"RUB", 98.00}, {"KRW", 1360.0},
        {"HKD", 7.80}, {"DKK", 6.75}, {"SEK", 10.41}, {"NOK", 10.95},
        {"PLN", 4.15}, {"TRY", 37.10}, {"EGP", 48.50}, {"THB", 36.30},
        {"MYR", 4.80}, {"IDR", 16000.0}, {"PHP", 56.00}, {"BDT", 119.0},
        {"LKR", 300.0}, {"PKR", 278.0}, {"NGN", 1650.0}, {"TWD", 32.4},
        {"VND", 25000.0}, {"ARS", 850.0}, {"COP", 3920.0}, {"CLP", 950.0},
        {"MXN", 18.2}, {"ILS", 3.70}, {"QAR", 3.64}, {"BHD", 0.38},
        {"KWD", 0.31}, {"OMR", 0.38}
    };

    cout << fixed << setprecision(4);

    int choice;

    while (true)
    {
        cout << "\n============================================\n";
        cout << "          GLOBAL CURRENCY CONVERTER\n";
        cout << "============================================\n";
        cout << "1. Convert ONE currency to ONE\n";
        cout << "2. Convert ONE currency to ALL\n";
        cout << "3. Show all currency codes\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4)
        {
            cout << "\nThank you for using the converter!\n";
            break;
        }

        if (choice == 3)
        {
            cout << "\nAvailable Currency Codes:\n";
            for (auto &p : rate)
                cout << p.first << " ";
            cout << "\n";
            continue;
        }

        double amount;
        string from, to;

        cout << "\nEnter amount: ";
        cin >> amount;

        cout << "Enter FROM currency code (Example: USD, INR): ";
        cin >> from;

        for (char &c : from)
            c = toupper(c);

        if (rate.find(from) == rate.end())
        {
            cout << "❌ Invalid currency code!\n";
            continue;
        }

        if (choice == 1)
        {
            cout << "Enter TO currency code: ";
            cin >> to;

            for (char &c : to)
                c = toupper(c);

            if (rate.find(to) == rate.end())
            {
                cout << "❌ Invalid currency code!\n";
                continue;
            }

            double result = convert(amount, from, to, rate);

            cout << "\n--------------------------------------\n";
            cout << amount << " " << from << " = " << result << " " << to << endl;
            cout << "--------------------------------------\n";
        }

        else if (choice == 2)
        {
            cout << "\nConverting " << amount << " " << from << " to ALL currencies...\n";
            cout << "--------------------------------------\n";

            for (auto &p : rate)
            {
                double result = convert(amount, from, p.first, rate);
                cout << p.first << " = " << result << endl;
            }

            cout << "--------------------------------------\n";
        }

        else
        {
            cout << "❌ Invalid choice!\n";
        }
    }

    return 0;
}
