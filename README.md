# 🏥 Hospital Management System (CLI)

A **Command Line Interface (CLI)** based Hospital Management System developed in **C**.  
This project was built for the **Data Structures and Algorithms module** to demonstrate the practical application of various data structures in a real-world scenario.

---

## 🚀 Features & Data Structures

This system consists of **8 main modules**, each utilizing a specific data structure:

1. **Emergency Case Handling** *(Stack)*  
   Prioritizes the most recent critical patients (**LIFO**).

2. **OPD Waiting System** *(Queue)*  
   Manages patients in the order of their arrival (**FIFO**).

3. **Ward Navigation & Management** *(Doubly Linked List)*  
   Enables bidirectional navigation of patient records.

4. **ICU Bed Management** *(Array)*  
   Tracks occupancy status of a fixed number of ICU beds.

5. **Patient Treatment Sequence** *(Singly Linked List)*  
   Stores sequential treatment steps of a patient.

6. **Round-Robin Duty Rosters** *(Circular Singly Linked List)*  
   Manages continuous shift assignments for medical staff.

7. **Endless Vitals Monitor** *(Circular Doubly Linked List)*  
   Allows seamless looping through patient vitals.

8. **Pharmacy Inventory** *(Array + Sorting)*  
   Uses **Bubble Sort / Insertion Sort** to prioritize medicines based on expiration dates.

---

## 🛠️ How to Compile and Run

### 📌 Prerequisites

Ensure you have a C compiler installed (e.g., **GCC**):

- **Windows:** Install MinGW or use WSL  
- **Linux (Ubuntu/Debian):**
  ```bash
  sudo apt install build-essential
  ```
- **MacOs:**
  ```bash
  xcode-select --install
  ```

### ⚙️ Compilation Steps

-**Clone the Repository**
```bash
git clone https://github.com/your-username/your-repo-name.git
cd your-repo-name
```

#### 🔧 Method 1: Using Makefile (Recommended)

-**Open terminal in the project root directory**
