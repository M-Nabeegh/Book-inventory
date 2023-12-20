#include <iostream>
#include <string>
using namespace std;
const int MAX_BOOKS = 3;

void displayInventory(const string titles[], const string authors[], const int quantities[]) {
    cout << "\nCurrent Inventory:\n"<<"-------------------"<<endl;

    for (int i = 0; i < MAX_BOOKS; ++i) {
        cout << "Title: " << titles[i] << "\nAuthor: " << authors[i]<< "\nQuantity in Stock: " << quantities[i] << endl;
        if (i < MAX_BOOKS - 1) {
            cout << "--------------------" << endl;
        }
    }
}

int main() {
    string titles[MAX_BOOKS] = {
        "Founding GIKI",
        "Charlie",
        "1984",
    };

    string authors[MAX_BOOKS] = {
        "Ghulam Ishaq",
        "Roald dahl",
        "George ",
    };

    int quantities[MAX_BOOKS] = {10, 8, 15};
    
    int totalBooksPurchased = 0;
    float totalAmount = 0.0;

    while (true) {
        displayInventory(titles, authors, quantities);

        string desiredTitle;
        int desiredQuantity;

        cout << "Enter the title of the book you want to buy (or type 'exit' to end): ";
        getline(cin, desiredTitle);

        if (desiredTitle == "exit") {
            break;
        }

        cout << "Enter the quantity you want to purchase: ";
        cin >> desiredQuantity;
        
        int bookIndex = -1;

        for (int i = 0; i < MAX_BOOKS; ++i) {
            if (titles[i] == desiredTitle) {
                bookIndex = i;
                break;
            }
        }

        if (bookIndex != -1 && quantities[bookIndex] >= desiredQuantity) {
            quantities[bookIndex] -= desiredQuantity;
            totalBooksPurchased += desiredQuantity;
            totalAmount += desiredQuantity * 10.0;

            cout << "\nPurchase successful!\n";
            cout << "Amount Due: $" << totalAmount << endl;
        } else {
            cout << "\nSorry, the requested quantity is not available or the book is not in stock.\n";
        }
    }

    return 0;
}
