# 🏦 Bank Systems

A **C++ Object-Oriented Bank Management System** that demonstrates how real banking operations can be simulated using modern programming concepts.  
The project is built with a **modular architecture** based on the **Divide and Conquer (فرق تسد)** principle: every feature is separated into a dedicated class to improve readability, maintainability, and scalability.

---

## 📌 Features
- Add / Update / Delete **Clients**.
- Add / Update / Delete **Users**.
- Manage **Currencies** and exchange rates.
- Secure **Login / Register** system for users.
- Perform banking transactions:
  - Deposit 💰
  - Withdraw 💵
  - Transfer between accounts 🔄
- Generate reports:
  - List of Clients
  - List of Users
  - Transfer Logs
  - Total Balances
- Utility screens for input validation, string handling, and date management.

---

## 🏗️ Project Structure (Divide & Conquer)
The project is divided into small, focused classes.  
Here is the breakdown:

### 🔐 Authentication & Users
- **clsUser.h** → User entity (username, password, permissions).
- **clsLoginScreen.h** → Handles user login.
- **clsLoginRegisterScreen.h** → Tracks login/register activity.
- **clsManageUsersScreen.h** → Manage all users.
- **clsAddNewUserScreen.h** → Add new user.
- **clsDeleteUserScreen.h** → Delete user.
- **clsUpdateUserScreen.h** → Update user info.
- **clsListUsersScreen.h** → Show all users.
- **clsFindUserScreen.h** → Search for a user.

---

### 👥 Clients
- **clsBankClient.h** → Client entity (ID, balance, etc.).
- **clsAddNewClientScreen.h** → Add new client.
- **clsDeleteClientScreen.h** → Delete client.
- **clsUpdateClientScreen.h** → Update client info.
- **clsClientListScreen.h** → Show all clients.
- **clsFindClientScreen.h** → Search for a client.

---

### 💱 Currencies
- **clsCurrency.h** → Currency entity.
- **clsCurrenciesListScreen.h** → Show list of currencies.
- **clsUpdateCurrencyRateScreen.h** → Update exchange rate.
- **clsCurrencyExchangeMainScreen.h** → Currency exchange system.
- **clsCurrencyCalculatorScreen.h** → Currency calculator.

---

### 💳 Banking Transactions
- **clsDepositScreen.h** → Deposit money.
- **clsWithdrawScreen.h** → Withdraw money.
- **clsTransferScreen.h** → Transfer money between clients.
- **clsTransferLogScreen.h** → Show all transfer history.
- **clsTotalBalancesScreen.h** → Show total balances of all clients.

---

### 🖥️ Main System
- **clsMainScreen.h** → Central hub/menu for system navigation.
- **clsScreen.h** → Base class for all "screens".
- **clsInputValidate.h** → Helper for input validation.
- **clsString.h** → String manipulation helpers.
- **clsDate.h** → Date management.
- **clsUtil.h** → General utility functions.
- **Global.h** → Global definitions and constants.

---

## ⚙️ Technical Details
- **Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)
- **Architecture**: Divide and Conquer (فرق تسد)
  - Each feature is isolated in its own class.
  - Improves readability and future expansion.
- **Data Storage**: Simple `.txt` files (Clients.txt, Users.txt, Currencies.txt, etc.)

---

## 🚀 How to Run
1. Clone the repository:
   ```bash
   git clone https://github.com/ALi-ather/Bank-systems.git
