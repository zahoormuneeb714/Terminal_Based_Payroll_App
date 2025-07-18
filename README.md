# Payroll System (C++ | OOP-Based)

This is a simple terminal-based Payroll System built in C++ using core Object-Oriented Programming concepts.  
The project was inspired by a recorded university lecture on **Polymorphism, Dynamic Binding**, and **Abstract Classes**.

Although my main stack is **MERN (MongoDB, Express, React, Node.js)**, I created this C++ program to reinforce my understanding of OOP principles in a practical and hands-on way.

---

## 🚀 Features

- 📦 Abstract `Employee` base class with pure virtual function `calcSalary()`
- 👨‍💼 Multiple employee types:
  - `SalariedEmployee`
  - `HourlyEmployee`
  - `CommissionedEmployee`
- 💰 Polymorphic payroll calculation
- 🧠 Demonstrates:
  - Inheritance
  - Dynamic binding
  - Virtual destructors
  - Real-time salary computations

---

## 📂 Class Structure

```cpp
Employee (Abstract)
│
├── SalariedEmployee
├── HourlyEmployee
└── CommEmployee
