#include <iostream>
#include <vector> 
#include <string> 
#include <fstream>
#include <sstream> 
#include <algorithm> 
#include <cstdlib> 
using namespace std; 

// Structure to represent a traditional dish.
struct Dish {
    string name;       
    string ingredients;
    string recipe;     
    string history;    
    string inventor;   
    string originDate; 
};
// Structure to represent a country and its traditional dish.
struct Country {
    string name;       
    Dish traditionalDish;
};


// Structure to store information about a recipe.
struct Recipe {
    string name;
    vector<string> ingredients;
    string cookingTime;
    string instructions;
};


// Function to convert a string to lowercase.
string toLowerCase(const string& str) {
    string lowerStr = str; // Create a copy of the input string to modify.
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower); // Transform each character to lowercase.
    return lowerStr; 
}
// Function to display information about a dish.
void showDish(const Dish& dish) {
    cout << "Nazwa dania: " << dish.name << endl; 
    cout << "Skladniki: " << dish.ingredients << endl; 
    cout << "Sposob przygotowania: " << dish.recipe << endl; 
    cout << "Historia: " << dish.history << endl; 
    cout << "Kto wymyslil: " << dish.inventor << endl; 
    cout << "Data powstania: " << dish.originDate << endl;
    cout << "----------------------" << endl; 
}
// Function to initialize and return a collection of countries with their traditional dishes.
vector<Country> initializeCountries() {
    static const vector<Country> countries =  {
        {"Ameryka", {"Burger", "bulka, mieso, salata, sosy.", "Usmaz mieso, zloz burgera z bulka, salata i sosami.", "Burger pojawil sie w XIX wieku w USA.", "Nie mozna powiedziec, kto dokladnie wynalazl burgera, byl to proces ewolucji.", "XIX wiek."}},
        {"Wlochy", {"Pizza", " ciasto, sos, ser i inne skladniki.", "Rozwalkuj ciasto, posmaruj sosem, posyp serem i upiecz w piekarniku.", "Pizza zostala wymyslona we Wloszech w XVIII wieku.", "Wloscy kucharze z Neapolu stworzyli pizze.", "XVIII wiek."}},
        {"Ukraina", {"Borszcz", "kapusta, ziemniaki, buraki, mięso, przyprawy.", "Ugotuj warzywa i mieso, dodaj przyprawy i buraki.", "Borszcz jest tradycyjna ukraińska potrawa od czasow starozytnych.", "Dokladnie nie wiadomo, kto wymyslil borszcz.", "Starozytna Ukraina."}},
        {"Polska", {"Pierogi", "ciasto, mieso lub warzywa do farszu.", "Zrob ciasto, nadziewaj farszem, gotuj w osolonej wodzie.", "Pierogi sa tradycyjna potrawa Polski znana od sredniowiecza.", "Polscy kucharze stworzyli pierogi.", "Sredniowiecze."}},
        {"Niemcy", {"Kiszona kapusta", "kapusta, sol, woda.", "Posiekaj kapuste, dodaj sol, zakonserwuj i daj czas na fermentacje.", "Kiszona kapusta pojawila sie w Niemczech w sredniowieczu.", "Historia stworzenia jest nieznana.", "Sredniowiecze."}},
        {"Francja", {"Kruasan", "maka, maslo, drozdze.", "Przygotuj ciasto z maslem i drozdzami, uformuj i upiecz.", "Kruasan zostal stworzony we Francji w XVII wieku.", "Kruasan zostal wymyslony przez austriackiego piekarza, ale stal sie popularny we Francji.", "XVII wiek."}},
        {"Anglia", {"Fish and chips", "ryba, ziemniaki, maka, olej.", "Usmaz rybe i ziemniaki w glebokim oleju.", "Potrawa ta pojawila sie w Anglii w XIX wieku.", "Nie wiadomo, kto dokladnie wymyslil te potrawe.", "XIX wiek."}},
        {"Lotwa", {"Zupa kapusciana", "kapusta, ziemniaki, marchew, mieso.", "Ugotuj kapuste i warzywa z miesem, dodaj przyprawy.", "Ta zupa byla popularna na Lotwie od czasow sredniowiecza.", "Nie wiadomo, kto wymyslil przepis.", "Sredniowiecze."}},
        {"Austria", {"Sznycel", "mieso, bulka tarta, olej.", "Obtoc mieso w bulce tartej i usmaz na oleju.", "Sznycel jest tradycyjna austriacka potrawa, popularna od XIX wieku.", "Sznycel zostal wymyslony w Austrii.", "XIX wiek."}},
        {"Norwegia", {"Rakfisk", "ryba, sol, przyprawy.", "Zasol rybe i zakonserwuj na kilka tygodni.", "Rakfisk to tradycyjna norweska potrawa, ktora przetrwala od czasow wikingow.", "Historia stworzenia jest nieznana.", "Wikingowie."}}
    };
    return countries; 
}
// Function to display a list of traditional recipes.
void TraditionalRecipes(const vector<Country>& countries) {
    cout << "================== TRADYCYJNE DANIA ==================" << endl;
    cout << "To tradycyjne dania roznych krajow, uznawane za najbardziej popularne.\n";
    cout << "Mozesz zapoznac sie z ich historia, skladnikami i sposobem przygotowania.\n";
    cout << "======================================================" << endl;

    for (const auto& country : countries) {
        cout << "Kraj: " << country.name << endl;
        showDish(country.traditionalDish);
    }
}

// Function to open a Telegram bot link.
// Uses the system command to open the Telegram bot in the default web browser. || cstdlib
void openTelegramBot() {
    cout << "Otwieranie Telegram bota . . ." << endl;
#ifdef _WIN32
    system("start https://t.me/nieleobot"); // Open link on Windows.
#else
    system("xdg-open https://t.me/nieleobot"); // Open link on Linux/macOS.
#endif
}

// Function to remove leading and trailing spaces from a string.(Ensures that user inputs and data are cleaned of unnecessary whitespace.)
string trim(const string& str) {
    size_t first = str.find_first_not_of(' '); // Find the index of the first non-space character.
    if (first == string::npos) return "";      // If the string is empty or contains only spaces, return an empty string.
    size_t last = str.find_last_not_of(' ');  // Find the index of the last non-space character.
    return str.substr(first, (last - first + 1)); // Return the substring without leading/trailing spaces.
}

// Function for entering ingredients.(Allows the user to input a list of ingredients separated by commas and processes them into a vector.)
vector<string> inputIngredients() {
    vector<string> ingredients;  // Vector to store the list of ingredients.
    string input;               

    
    cout << "Podaj skladniki (oddzielone przecinkiem): ";
    cin.ignore();              
    getline(cin, input);        
    istringstream ss(input);   
    string ingredient;          // Temporary variable to hold each ingredient during processing.

    while (getline(ss, ingredient, ',')) {
        ingredients.push_back(toLowerCase(trim(ingredient))); 
    }

    return ingredients; 
}

// Function for loading recipes from a file.
void loadRecipes(const string& filename, vector<Recipe>& recipes) {
    try {
        ifstream file(filename); // Open the file for reading.
        if (!file.is_open()) {
            throw runtime_error("Nie mozna otworzyc pliku: " + filename); 
        }
        string line; // Temporary variable to hold each line from the file.
        while (getline(file, line)) {
            istringstream ss(line); 
            Recipe recipe;          // Create a Recipe object to store details.
            string ingredientsLine; // Temporary variable to hold the ingredients line.

            // Extract and parse each field of the recipe from the file.
            getline(ss, recipe.name, ';');        
            getline(ss, ingredientsLine, ';');     
            getline(ss, recipe.cookingTime, ';');  
            getline(ss, recipe.instructions);      

            // Split the ingredients into a list and process each one.
            istringstream ingredientsStream(ingredientsLine);
            string ingredient;
            while (getline(ingredientsStream, ingredient, ',')) {
                recipe.ingredients.push_back(toLowerCase(trim(ingredient))); 
            }

            recipes.push_back(recipe);
        }
    }
    catch (const exception& e) {
        cerr << "Wystapil blad podczas ladowania przepisow: " << e.what() << endl; 
    }
}

// Function for loading favorite recipes.(// Reads favorite recipes from a file and populates a vector with Recipe objects.)
void loadFavorites(const string& filename, vector<Recipe>& favorites) {
    try {
        ifstream file(filename); 
        if (!file.is_open()) {
            throw runtime_error("Nie mozna otworzyc pliku: " + filename); 
        }

        string line; 
        while (getline(file, line)) { // Read the file line by line.
            istringstream ss(line); // Create a string stream to process the line.
            Recipe recipe; // Create a Recipe object to store details.
            string ingredientsLine; // Temporary variable to hold the ingredients.

            // Extract and parse each field of the favorite recipe from the file.
            getline(ss, recipe.name, ';');         
            getline(ss, ingredientsLine, ';');     
            getline(ss, recipe.cookingTime, ';');  
            getline(ss, recipe.instructions);      

            // Process the ingredients line into a list.
            istringstream ingredientsStream(ingredientsLine);
            string ingredient;
            while (getline(ingredientsStream, ingredient, ',')) { 
                recipe.ingredients.push_back(trim(ingredient)); 
            }

            favorites.push_back(recipe); 
        }
    }
    catch (const exception& e) {
        cerr << "Blad podczas ladowania ulubionych przepisow: " << e.what() << endl; 
    }
}

//Function to ensure the favorites file exists.
void ensureFavoritesFile(const string & filename) {
    ifstream file(filename); // Attempt to open the file for reading.
    if (!file.is_open()) {
        ofstream newFile(filename); // Create a new file if it does not exist.
        newFile.close();
    }
}

// Function for saving favorite recipes.
void saveFavorites(const string& filename, const vector<Recipe>& favorites) {
    try {
        ofstream file(filename); // Open the file for writing.
        if (!file.is_open()) {
            throw runtime_error("Nie mozna otworzyc pliku do zapisu: " + filename); 
        }

        // Write each favorite recipe to the file.
        for (const auto& recipe : favorites) {
            file << recipe.name << ";"; // Write the recipe name.
            for (size_t i = 0; i < recipe.ingredients.size(); ++i) {
                file << recipe.ingredients[i]; // Write each ingredient.
                if (i != recipe.ingredients.size() - 1) file << ","; // Separate ingredients with commas.
            }
            file << ";" << recipe.cookingTime << ";"; // Write the cooking time.
            file << recipe.instructions << endl;     // Write the preparation instructions.
        }
    }
    catch (const exception& e) {
        cerr << "Wystapil blad podczas zapisywania ulubionych przepisow: " << e.what() << endl;
    }
}

// Function to add a new recipe.
void addRecipe(vector<Recipe>& recipes, const string& filename) {
    Recipe newRecipe; // Object to store the details of the new recipe.
    string input;     // Temporary string for user input.
    
    
    cout << "Podaj nazwe przepisu: ";
    cin.ignore();               
    getline(cin, newRecipe.name); 

    // Check if the recipe name already exists in the collection.
    for (const auto& recipe : recipes) {
        if (recipe.name == newRecipe.name) {
            cout << "Przepis o takiej nazwie juz istnieje." << endl;
            return;
        }
    }

    cout << "Podaj skladniki (oddzielone przecinkiem): ";
    getline(cin, input);          // Read the ingredients as a single input line.
    istringstream ss(input);      // Create a string stream to parse the input.
    string ingredient;
    while (getline(ss, ingredient, ',')) {
        newRecipe.ingredients.push_back(trim(ingredient)); 
    }

    cout << "Podaj czas przygotowania (np. 30 minut): ";
    getline(cin, newRecipe.cookingTime);

    cout << "Podaj instrukcje: ";
    getline(cin, newRecipe.instructions);

    // Add the new recipe to the list of recipes.
    recipes.push_back(newRecipe);

    // Save the new recipe to the file.
    try {
        ofstream file(filename, ios::app); // Open the file in append mode.
        if (!file.is_open()) {
            throw runtime_error("Nie mozna otworzyc pliku do zapisu: " + filename);
        }

        // Write the recipe details to the file.
        file << newRecipe.name << ";";
        for (size_t i = 0; i < newRecipe.ingredients.size(); ++i) {
            file << newRecipe.ingredients[i];
            if (i != newRecipe.ingredients.size() - 1) file << ",";
        }
        file << ";" << newRecipe.cookingTime << ";";
        file << newRecipe.instructions << endl;
        file.close();
        cout << "Przepis zostal dodany i zapisany do pliku!" << endl;
    }
    catch (const exception& e) {
        cerr << "Nie mozna zapisac przepisu do pliku: " << e.what() << endl;
    }
}

// Function to remove a recipe from favorites. (allows the user to remove one by its index.) 
void removeFromFavorites(vector<Recipe>& favorites) {
    if (favorites.empty()) { // Check if there are any favorite recipes.
        cout << "Nie masz jeszcze ulubionych przepisow. Lista jest pusta." << endl;
        return; 
    }
    // Display the list of favorite recipes.
    cout << "Twoje ulubione przepisy:" << endl;
    for (size_t i = 0; i < favorites.size(); ++i) {
        cout << i + 1 << ". " << favorites[i].name << endl;
    }
    // Prompt the user to select a recipe to remove.
    cout << "Wybierz numer przepisu do usuniecia (0 aby anulowac): ";
    int choice;
    cin >> choice;
    cin.ignore(); // Clear the input buffer.
    if (choice == 0) {
        cout << "Operacja anulowana." << endl;
        return;
    }
    if (choice < 1 || choice > favorites.size()) {
        cout << "Nieprawidlowy wybor. Sprobuj ponownie." << endl;
        return;
    }
    // Remove the selected recipe from the favorites list.
    favorites.erase(favorites.begin() + (choice - 1));
    // Save the updated favorites list to the file.
    saveFavorites("favorites.txt", favorites);
    cout << "Przepis zostal usuniety z ulubionych." << endl;
}

// Function to add a recipe to favorites.
void addToFavorites(const Recipe& recipe, vector<Recipe>& favorites) {
    // Check if the recipe is already in the favorites list.
    for (const auto& fav : favorites) {
        if (fav.name == recipe.name) {
            cout << "Ten przepis juz jest w ulubionych." << endl;
            return; 
        }
    }
    // Add the recipe to the favorites list.
    favorites.push_back(recipe);
    // Save the updated favorites list to the file.
    saveFavorites("favorites.txt", favorites);
    cout << "Przepis zostal dodany do ulubionych!" << endl;
}

// Function to display a list of recipes.
void displayRecipes(const vector<Recipe>& recipes) {
    if (recipes.empty()) {
        cout << "Nie znaleziono zadnego przepisu." << endl;
        return; 
    }

    // Display each recipe with its basic details.
    cout << "Znalezione przepisy:" << endl;
    int recipeNumber = 1;
    for (const auto& recipe : recipes) {
        cout << "------------------" << endl;
        cout << recipeNumber << ". " << recipe.name << endl;
        cout << "Skladniki: ";
        for (const auto& ingredient : recipe.ingredients) {
            cout << ingredient << ", ";
        }
        cout << endl;
        cout << "Czas przygotowania: " << recipe.cookingTime << endl;
        cout << "------------------" << endl;
        recipeNumber++;
    }
}

// Function to display recipes with instructions.
void displayRecipesWithInstructions(const vector<Recipe>& recipes, vector<Recipe>& favorites) {
    displayRecipes(recipes);

    if (recipes.empty()) return;

    int choice;
    cout << "Wybierz numer przepisu, aby uzyskac instrukcje (0 aby wyjsc): ";
    cin >> choice;
    cin.ignore(); 

    if (choice == 0) {
        cout << "Powrot do menu glownego." << endl;
        return;
    }
    if (choice < 1 || choice > recipes.size()) {
        cout << "Nieprawidlowy wybor." << endl;
        return;
    }

    // Display the details of the selected recipe.
    const Recipe& selectedRecipe = recipes[choice - 1];
    cout << "\nWybrano przepis: " << selectedRecipe.name << endl;
    cout << "\nSkladniki: " << endl;
    for (const string& ingredient : selectedRecipe.ingredients) {
        cout << "- " << ingredient << endl;
    }
    cout << "\nCzas przygotowania: " << selectedRecipe.cookingTime << endl;
    cout << "\nInstrukcje: " << endl;
    cout << selectedRecipe.instructions << endl;

    // Ask if the user wants to add the recipe to favorites.
    char addToFavoritesChoice;
    cout << "Czy chcesz dodac ten przepis do ulubionych? (t/n): ";
    cin >> addToFavoritesChoice;
    cin.ignore();

    if (addToFavoritesChoice == 't' || addToFavoritesChoice == 'T') {
        addToFavorites(selectedRecipe, favorites);
    }
}

// Function to find recipes based on ingredients.
vector<Recipe> findRecipes(const vector<string>& ingredients, const vector<Recipe>& recipes) {
    vector<Recipe> foundRecipes; // Vector to store recipes that match the search criteria.

    // Iterate over each recipe in the list.
    for (const auto& recipe : recipes) {
        bool ingredientsFound = false; // Flag to check if any of the ingredients match.

        // Iterate over each ingredient in the current recipe.
        for (const auto& recipeIngredient : recipe.ingredients) {
            string recipeIngredientLower = toLowerCase(recipeIngredient); 

            // Check if any of the user-provided ingredients match the recipe's ingredients.
            for (const auto& ingredient : ingredients) {
                string ingredientLower = toLowerCase(ingredient); 

                // Check if the user ingredient is a substring of the recipe ingredient.
                if (recipeIngredientLower.find(ingredientLower) != string::npos) {
                    ingredientsFound = true; // A match is found.
                    break; 
                }
            }

            if (ingredientsFound) break; // Exit the loop if a matching ingredient is found.
        }

        // If the recipe contains any of the specified ingredients, add it to the results.
        if (ingredientsFound) {
            foundRecipes.push_back(recipe);
        }
    }

    return foundRecipes; 
}

// Function to view favorite recipes.
void viewFavorites(const vector<Recipe>& favorites) {
    // Check if the favorites list is empty and notify the user.
    if (favorites.empty()) {
        cout << "Nie masz jeszcze ulubionych przepisow." << endl; 
        return; 
    }

    // Display each favorite recipe along with its details.
    cout << "Twoje ulubione przepisy:" << endl;
    for (size_t i = 0; i < favorites.size(); ++i) {
        cout << "------------------" << endl;
        cout << i + 1 << ". " << favorites[i].name << endl; 

        // List the ingredients for the recipe.
        cout << "Skladniki: ";
        for (const auto& ingredient : favorites[i].ingredients) {
            cout << ingredient << ", ";
        }
        cout << endl;

        // Display the preparation time and cooking instructions.
        cout << "Czas przygotowania: " << favorites[i].cookingTime << endl; 
        cout << "Instrukcje: " << favorites[i].instructions << endl; 
        cout << "------------------" << endl;
    }
}

// Main menu function.
void menu(vector<Recipe>& recipes, vector<Recipe>& favorites, const vector<Country>& countries) {
    while (true) { // Infinite loop to keep the menu running until the user decides to exit.
        try {
            // Display menu options in a formatted layout.
            cout << "================== MENU GLOWNE ==================" << endl;
            cout << "Wybierz opcje:" << endl;
            cout << "1. [Znajdz przepisy na podstawie skladnikow]" << endl; 
            cout << "2. [Zobacz ulubione przepisy]" << endl; 
            cout << "3. [Dodaj nowy przepis]" << endl; 
            cout << "4. [Usun przepis z ulubionych]" << endl; 
            cout << "5. [Przegladaj tradycyjne przepisy]" << endl; 
            cout << "6. [Kontakt z Telegram botem]" << endl; 
            cout << "7. [Wyjscie]" << endl; 
            cout << "=================================================" << endl;
            cout << "Twoj wybor: ";

            int choice;
            cin >> choice; 

            if (cin.fail()) { // Check if the input is invalid (e.g., not a number).
                throw invalid_argument("Nieprawidlowy wybor. Wprowadz liczbe od 1 do 7."); 
            }

            switch (choice) {
            case 1: {
                vector<string> ingredients = inputIngredients(); // Get the list of ingredients from the user.
                vector<Recipe> foundRecipes = findRecipes(ingredients, recipes); // Find matching recipes.
                displayRecipesWithInstructions(foundRecipes, favorites); // Display the matching recipes with details.
                break;
            }
            case 2:
                viewFavorites(favorites);
                break;
            case 3:
                addRecipe(recipes, "recipes.txt");
                break;
            case 4:
                removeFromFavorites(favorites);
                break;
            case 5:
                TraditionalRecipes(countries);
                break;
            case 6:
                openTelegramBot();
                break;
            case 7:
                cout << "Do widzenia!" << endl;
                return; 
            default:
               
                throw out_of_range("Nieprawidlowy wybor. Podaj liczbe od 1 do 7.");
            }
        }
        catch (const exception& e) {
            cerr << "Blad: " << e.what() << endl;
            cin.clear(); // Clear the error flag on the input stream.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input.
        }
    }
}

int main() {
    vector<Recipe> recipes; // Vector to store all recipes loaded from the file.
    vector<Recipe> favorites; // Vector to store favorite recipes loaded from the file.
    vector<Country> countries = initializeCountries(); // Initialize the list of countries with their traditional dishes.

    // Load recipes from the "recipes.txt" file into the `recipes` vector.
    loadRecipes("recipes.txt", recipes);
    // Ensure that the favorites file ("favorites.txt") exists; create it if it doesn't.
    ensureFavoritesFile("favorites.txt");
    // Load favorite recipes from the "favorites.txt" file into the `favorites` vector.
    loadFavorites("favorites.txt", favorites);
    menu(recipes, favorites, countries);
    return 0;
}
