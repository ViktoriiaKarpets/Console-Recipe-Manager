# Console Recipe Manager 🍳📖

A comprehensive command-line interface (CLI) application developed in **C++** that functions as an interactive culinary recipe book. The project demonstrates core Object-Oriented Programming (OOP) principles, efficient data structures, custom file handling, and search/filtering algorithms.

## 🚀 Key Features
* **Smart Ingredient Matching:** Input the ingredients you currently have, and the system will filter and suggest recipes you can cook.
* **Multi-Criteria Search:** Search and filter recipes by name, specific category, maximum preparation time, or difficulty level.
* **Persistent Data Storage:** Full CRUD operations (Create, Read, Update, Delete) for recipes, automatically synced and saved to external text files (`recipes.txt`).
* **Favorites System:** Users can bookmark their favorite dishes into a personalized list saved dynamically in `favorites.txt`.
* **Telegram Integration:** Features an integrated routing option to launch a dedicated culinary Telegram bot.

## 🛠️ Tech Stack & Concepts Demonstrated
* **Language:** C++17
* **Environment:** Visual Studio
* **Core Concepts:** Object-Oriented Programming (Classes, Encapsulation, Structs), File I/O (`std::fstream`), Dynamic Arrays (`std::vector`), String Manipulation (`std::string`), Data Sorting and Filtering Algorithms.

## 📂 File Structure
* `Recipe.cpp` — Core application code containing the business logic, data models, and interactive menu system.
* `recipes.txt` — Main text-based database file storing the recipe catalog.
* `favorites.txt` — Storage file for user-bookmarked favorite recipes.

## 💻 How to Run
1. Clone this repository to your local machine.
2. Open `Recipe.cpp` in Visual Studio or any C++ IDE.
3. Ensure `recipes.txt` and `favorites.txt` are placed in the same directory as the executable.
4. Compile and run the project.
