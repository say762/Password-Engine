## Tech Stack and Concepts
* **Language:** C++
* **Concepts Used:** Object-Oriented Programming (OOP), Exception Handling, File I/O (`fstream`)

## Core Logic & Workflow
1. **User Input:** Prompts the user to enter a username and password.
2. **File Storage:** Stores the user credentials securely in a local file.
3. **Dictionary Check:** Searches for the entered password inside `common-passwords.txt`.
   * **If Found:** Flags it immediately as a **Weak Passcode** and prompts the user to try again.
   * **If Not Found:** Proceeds to evaluate password strength using defined parameters (length, uppercase, digits, symbols).
4. **Scoring & Display:** Calculates the total score and displays the security rating.
5. **Program Loop:** Repeats the process as long as the user enters `'yes'`.
