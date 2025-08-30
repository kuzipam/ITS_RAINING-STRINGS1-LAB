#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//Function that accepts input of business names and displays them as a list.
void list_businesses_func(std::vector<std::string>& businesses) {

    // Printing a welcome message to the user.
    std::cout << "Welcome user, to the Business Sorting Program!\n"
              << "This program lists any local business you input and displays them in a list\n"
              << "Please add as many businesses as you want.\n";

    //While loop to keep the program running until the user is done.
    while (true) {
        std::string choice;

        std::cout << "\nWould you like to enter a business? (Y/Yes or N/No): ";
        std::cin >> choice;

        // This validates all the possible user choices.
        while (choice != "y" && choice != "Y" &&
               choice != "yes" && choice != "Yes" &&
               choice != "n" && choice != "N" &&
               choice != "no" && choice != "No") {
            std::cout << "Invalid input, try again (Y/Yes or N/No): ";
            std::cin >> choice;
        }

        if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes") {
            std::string input;
            
            //User inputs a business and the input is the stored in a vector.
            std::cout << "Please enter a business: ";
            std::cin.ignore(); 
            std::getline(std::cin, input);

            businesses.push_back(input);

            //Using the sort function to sort through the vector.
            std::sort(businesses.begin(), businesses.end());


            // Displaying all the entered businesses in a list.
            std::cout << "\nThank you for your input. Current list of businesses:\n";
            for (int i = 0; i < businesses.size(); i++) {
                std::cout << i + 1 << ". " << businesses[i] << "\n";
            }

            //Exiting the program if the user chooses No.
        } else { 
            std::cout << "\nThank you for using the Business Sorting Program!\n";
            break; 
        }
    }
}

int main() {
    std::vector<std::string> businesses;
    list_businesses_func(businesses);
    return 0;
}
