📌 Currency Converter (C++ Project)

This is a C++-based Global Currency Converter that supports 45+ international currencies.
It uses a clean console interface and applies a standard USD-based conversion formula for accurate results.
Users can convert one currency to another, or convert one currency to all supported currencies instantly.

🚀 Features

🌍 Supports 45+ world currencies (INR, USD, EUR, GBP, JPY, AED, etc.)

🔄 Convert ONE currency → ONE currency

🌐 Convert ONE currency → ALL currencies

⚡ Fast and lightweight

💻 Runs on any C++ compiler (GCC / MinGW / CodeBlocks / VS Code)

🧮 Uses standard conversion formula:
amount_in_usd = amount / rate[from]
final_amount = amount_in_usd * rate[to]

🔧 Easy to add or update exchange rates

🛠️ Technologies Used

C++

STL – unordered_map

Console-based UI



📦 How to Run

1] Clone the repository:
git clone https://github.com/<your-username>/Currency-Converter.git


2] Navigate into the folder:

cd Currency-Converter

3] Compile the code:

g++ currency_converter.cpp -o converter

4] Run:

./converter


📄 Project Structure
Currency-Converter/
│-- currency_converter.cpp
│-- README.md





📊 Example Output
Enter amount: 2000
Enter FROM currency code: INR
Enter TO currency code: USD

2000 INR = 22.3112 USD


Console-based UI

📦 How to Run 
