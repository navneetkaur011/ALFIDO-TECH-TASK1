# ALFIDO-TECH-TASK1
# 🚀 C Data Structures: Linked Lists & Stacks

Welcome to my C data structures implementation repository! This project is dedicated to mastering the fundamentals of manual memory management and core data structure design in the C programming language.

Here, I document my progress in building foundational logic, starting with dynamic linked lists and fixed-capacity stack structures.

---

## 🛠️ Current Progress: Data Structures Implementation

Inside this repository, you will find two clean, well-commented C implementations:

*   **Linked List System:**
    *   **Insert at Head:** Dynamically allocates memory for new nodes and updates the head pointer.
    *   **Search List:** Traverses the linked list to find specific integers.
    *   **Delete Node:** Handles memory deallocation and pointer adjustment to remove specific items.
    *   **Display:** Prints the current state of the list from head to `NULL`.

*   **Stack Interactive System:**
    *   **Push:** Inserts elements onto the stack while checking for `MAX_CAPACITY` (Stack Overflow).
    *   **Pop:** Removes and returns the top element while checking for underflow conditions.
    *   **Search:** Provides the depth index of an element from the top.
    *   **Display:** Visualizes the LIFO (Last-In-First-Out) stack layout.

---

## ⚙️ Tech Stack & Concepts Covered

*   **Language:** C (Standard C99/C11).
*   **Key Concepts:**
    *   **Dynamic Memory Allocation:** Using `malloc` and `free` for linked nodes.
    *   **Pointers:** Mastering pointer-to-pointers (`struct Node**`) for modifying head references.
    *   **Stack Logic:** Array-based implementation with a fixed capacity.
    *   **Input Handling:** Sanitizing user input using `scanf` and `getchar`.
    *   **Clean Code Practices:** Modular function design and user-friendly console menus.
*   **Tools:** GCC Compiler, VS Code.

---

## 💻 How to Run

1.  **Ensure you have the GCC compiler installed on your machine.**
2.  **Clone this repository to your local system.**
3.  **Open your terminal** in the project directory.
4.  **Compile the code:**
    ```bash
    gcc linked_list.c -o linked_list
    # OR
    gcc stack.c -o stack
    ```
5.  **Run the executable:**
    ```bash
    ./linked_list
    # OR
    ./stack
    ```
