# Student-record-system-c
A beginner-level C project demonstrating binary file handling using fwrite and fread with structured records.

# Binary File Handling in C

## 📌 Project Overview

This project is a **beginner-level C program** that demonstrates how to store and manage data using **binary file handling**. It focuses on using core file I/O functions such as `fopen()`, `fwrite()`, `fread()`, and `fseek()` to work with structured data efficiently.

The goal of this project is to help understand how real-world applications store data in files instead of relying only on variables and memory.

---

## 🛠️ Technologies Used

* **Language:** C
* **Concepts:**

  * Binary File Handling
  * Structures in C
  * File I/O operations
  * Memory handling

---

## ✨ Features

* Store records in a **binary file**
* Read records from the binary file
* Append new data without deleting old records
* Uses `struct` to manage organized data
* Beginner-friendly and easy to understand

---

## 📂 Project Structure

```
binary-file-handling-c/
│
├── code.c        # Source code
├── student.dat     # Binary file (created at runtime)
├── README.md    # Project documentation
```

---

## ⚙️ How to Compile and Run

### Compile

```bash
gcc code.c -o binary_file
```

### Run

```bash
./binary_file
```

---

## 🧪 Example Operations

* Writing a structure to a binary file using `fwrite()`
* Reading data back using `fread()`
* Appending records using `"ab"` file mode

---

## 📖 What You Will Learn

* Difference between **text files** and **binary files**
* Proper use of `fwrite()` and `fread()`
* How binary files store raw data
* Basics of file-based data persistence in C

---

## 🚀 Future Improvements

* Add menu-driven options (Add / View / Update / Delete)
* Implement search functionality
* Improve error handling
* Use dynamic memory allocation

---

## ⚠️ Important Notes

* Binary files are **machine-dependent**
* Structure definition should not change after data is written
* Always check file pointers for `NULL`

---

## 👤 Author

* **Name:** Ansh Shukla
* **GitHub:** [https://github.com/ujjwal031shukla-svg](https://github.com/ujjwal031shukla-svg)

---

## 📄 License

This project is for **learning and educational purposes** only.
