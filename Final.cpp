#include <iostream>
#include <iomanip> // for setw
#include <string>  // for string

using namespace std;

// Enums for product categories
enum ProductCategory
{
    ELECTRONICS,
    CLOTHING,
    FOOD,
    FURNITURE,
    SPORTS,
    STATIONARY
};

// Structure for product
struct Product
{
    int id;
    string name;
    float price;
    int quantity;
    ProductCategory category;
};

// Structure for debit card information
struct DebitCardInfo
{
    string cardNumber;
    string expiryDate;
    string cvv;
};

// Class for managing inventory
class Inventory
{
private:
    Product *products;
    int numProducts;

public:
    Inventory()
    {
        products = nullptr;
        numProducts = 0;
    }

    void addProduct(Product product)
    {
        Product *temp = new Product[numProducts + 1];
        for (int i = 0; i < numProducts; ++i)
        {
            temp[i] = products[i];
        }
        temp[numProducts] = product;
        delete[] products;
        products = temp;
        numProducts++;
    }

    void editProduct(int id, string name, float price, int quantity)
    {
        for (int i = 0; i < numProducts; ++i)
        {
            if (products[i].id == id)
            {
                int diff = quantity - products[i].quantity; // Calculate difference
                products[i].name = name;
                products[i].price = price;
                products[i].quantity = quantity;
                cout << "Product edited successfully!\n";

                // Adjust inventory based on difference
                if (diff > 0)
                {
                    cout << "Added " << diff << " units to inventory.\n";
                }
                else if (diff < 0)
                {
                    cout << "Removed " << -diff << " units from inventory.\n";
                }
                return;
            }
        }
        cout << "Product not found!\n";
    }

    void buyProduct(int id, int quantity)
    {
        for (int i = 0; i < numProducts; ++i)
        {
            if (products[i].id == id)
            {
                if (quantity <= products[i].quantity)
                {
                    products[i].quantity -= quantity;
                    cout << "Product bought successfully!\n";
                    cout << "Remaining quantity: " << products[i].quantity << endl;
                }
                else
                {
                    cout << "Not enough quantity available!\n";
                }
                return;
            }
        }
        cout << "Product not found!\n";
    }

    void displayProducts(ProductCategory category)
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << "| ID    |        Name        |  Price   | Quantity |     Category                 |\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        for (int i = 0; i < numProducts; ++i)
        {
            if (products[i].category == category)
            {
                cout << "| " << setw(6) << left << products[i].id << " | " << setw(18) << left << products[i].name << " | $" << setw(8) << fixed << setprecision(2) << products[i].price << " | " << setw(8) << products[i].quantity << " | ";
                switch (products[i].category)
                {
                case ELECTRONICS:
                    cout << setw(10) << "Electronics";
                    break;
                case CLOTHING:
                    cout << setw(10) << "Clothing";
                    break;
                case FOOD:
                    cout << setw(10) << "Food";
                    break;
                case FURNITURE:
                    cout << setw(10) << "Furniture";
                    break;
                case SPORTS:
                    cout << setw(10) << "Sports";
                    break;
                case STATIONARY:
                    cout << setw(10) << "Stationary";
                    break;
                }
                cout << " |\n";
            }
        }
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
    }

    int getNumProducts() const
    {
        return numProducts;
    }

    Product getProductAtIndex(int index) const
    {
        return products[index];
    }

    ~Inventory()
    {
        delete[] products;
    }
};

// Function to get debit card information from customer
DebitCardInfo getDebitCardInfo()
{
    DebitCardInfo cardInfo;
    cout << "Enter debit card number: ";
    cin >> cardInfo.cardNumber;
    cout << "Enter expiry date (MM/YYYY): ";
    cin >> cardInfo.expiryDate;
    cout << "Enter CVV: ";
    cin >> cardInfo.cvv;
    return cardInfo;
}

// Function to display menu for employee
void employeeMenu(Inventory &inventory)
{
    int choice;
    do
    {
        cout << "\nEmployee Menu:\n";
        cout << "1. Add Product\n";
        cout << "2. Edit Product\n";
        cout << "3. Display Inventory\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Product product;
            int category;
            bool validCategory;
            do
            {
                validCategory = true;
                cout << "Enter product category (0 - Electronics, 1 - Clothing, 2 - Food, 3 - Furniture, 4 - Sports, 5 - Stationary): ";
                cin >> category;
                if (category < 0 || category > 5)
                {
                    cout << "Invalid category! Please enter a valid category.\n";
                    validCategory = false;
                }
            } while (!validCategory);

            product.category = static_cast<ProductCategory>(category);
            cout << "Enter product ID: ";
            cin >> product.id;

            // Check if the product ID already exists
            bool idExists = false;
            for (int i = 0; i < inventory.getNumProducts(); ++i)
            {
                if (inventory.getProductAtIndex(i).id == product.id)
                {
                    idExists = true;
                    break;
                }
            }
            if (idExists)
            {
                cout << "Product ID already exists! Please enter a unique product ID.\n";
                break;
            }

            cout << "Enter product name: ";
            cin.ignore();
            getline(cin, product.name);
            cout << "Enter product price: ";
            cin >> product.price;
            cout << "Enter product quantity: ";
            cin >> product.quantity;
            inventory.addProduct(product);
            break;
        }
        case 2:
        {
            int id;
            string name;
            float price;
            int quantity;
            cout << "Enter product ID: ";
            cin >> id;

            // Check if the product ID exists
            bool idExists = false;
            for (int i = 0; i < inventory.getNumProducts(); ++i)
            {
                if (inventory.getProductAtIndex(i).id == id)
                {
                    idExists = true;
                    break;
                }
            }
            if (!idExists)
            {
                cout << "Product ID does not exist! Please enter a valid product ID.\n";
                break;
            }

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new price: ";
            cin >> price;
            cout << "Enter new quantity: ";
            cin >> quantity;
            inventory.editProduct(id, name, price, quantity);
            break;
        }
        case 3:
        {
            int categoryChoice;
            bool validCategoryChoice;
            do
            {
                validCategoryChoice = true;
                cout << "Choose product category to display (0 - Electronics, 1 - Clothing, 2 - Food, 3 - Furniture, 4 - Sports, 5 - Stationary): ";
                cin >> categoryChoice;
                if (categoryChoice < 0 || categoryChoice > 5)
                {
                    cout << "Invalid choice! Please enter a number between 0 and 5.\n";
                    validCategoryChoice = false;
                }
            } while (!validCategoryChoice);
            ProductCategory category = static_cast<ProductCategory>(categoryChoice);
            inventory.displayProducts(category);
            break;
        }
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);
}

// Function to display menu for customer
void customerMenu(Inventory &inventory)
{
    int choice;
    do
    {
        cout << "\nCustomer Menu:\n";
        cout << "1. Display Inventory\n";
        cout << "2. Buy Product\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int categoryChoice;
            bool validCategoryChoice;
            do
            {
                validCategoryChoice = true;
                cout << "Choose product category to display (0 - Electronics, 1 - Clothing, 2 - Food, 3 - Furniture, 4 - Sports, 5 - Stationary): ";
                cin >> categoryChoice;
                if (categoryChoice < 0 || categoryChoice > 5)
                {
                    cout << "Invalid choice! Please enter a number between 0 and 5.\n";
                    validCategoryChoice = false;
                }
            } while (!validCategoryChoice);
            ProductCategory category = static_cast<ProductCategory>(categoryChoice);
            inventory.displayProducts(category);
            break;
        }
        case 2:
        {
            int id, quantity;
            cout << "Enter product ID: ";
            cin >> id;

            cout << "Enter quantity to buy: ";
            cin >> quantity;

            inventory.buyProduct(id, quantity);
            break;
        }
        case 3:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 3);
}

int main()
{
    int runAgain;
    do
    {
        Inventory inventory;

        // Add more products for each category
        Product electronics[] = {
            {101, "Smartphone", 500.0, 20, ELECTRONICS},
            {102, "Laptop", 1000.0, 15, ELECTRONICS},
            {103, "Headphones", 50.0, 30, ELECTRONICS},
            {104, "Smartwatch", 200.0, 25, ELECTRONICS},
            {105, "Tablet", 300.0, 20, ELECTRONICS},
            {106, "Camera", 400.0, 20, ELECTRONICS},
            {107, "TV", 800.0, 15, ELECTRONICS},
            {108, "Wireless Earbuds", 100.0, 30, ELECTRONICS},
            {109, "Gaming Console", 600.0, 10, ELECTRONICS},
            {110, "Desktop Computer", 1200.0, 10, ELECTRONICS}};

        Product communicationDevicesProducts[] = {
            {111, "Router", 50.0, 20, ELECTRONICS},
            {112, "Modem", 60.0, 15, ELECTRONICS},
            {113, "Ethernet Cable", 10.0, 30, ELECTRONICS},
            {114, "Wifi Extender", 40.0, 25, ELECTRONICS},
            {115, "Bluetooth Dongle", 15.0, 20, ELECTRONICS},
            {116, "Network Switch", 30.0, 20, ELECTRONICS},
            {117, "Access Point", 70.0, 15, ELECTRONICS},
            {118, "VoIP Phone", 80.0, 30, ELECTRONICS},
            {119, "Satellite Phone", 500.0, 10, ELECTRONICS},
            {120, "Walkie Talkie", 50.0, 20, ELECTRONICS}};

        // Add more electronics subcategories...

        Product clothing[] = {
            {201, "T-Shirt", 20.0, 50, CLOTHING},
            {202, "Jeans", 30.0, 40, CLOTHING},
            {203, "Dress", 50.0, 25, CLOTHING},
            {204, "Sweater", 40.0, 30, CLOTHING},
            {205, "Jacket", 70.0, 20, CLOTHING},
            {206, "Socks", 5.0, 100, CLOTHING},
            {207, "Hat", 15.0, 40, CLOTHING},
            {208, "Shorts", 25.0, 35, CLOTHING},
            {209, "Skirt", 35.0, 25, CLOTHING},
            {210, "Suit", 100.0, 15, CLOTHING}};

        Product shirtsProducts[] = {
            {211, "Button-Down Shirt", 30.0, 40, CLOTHING},
            {212, "Polo Shirt", 25.0, 35, CLOTHING},
            {213, "Dress Shirt", 40.0, 30, CLOTHING},
            {214, "Turtleneck", 35.0, 25, CLOTHING},
            {215, "Flannel Shirt", 45.0, 20, CLOTHING},
            {216, "Hawaiian Shirt", 20.0, 30, CLOTHING},
            {217, "Tank Top", 15.0, 50, CLOTHING},
            {218, "Oxford Shirt", 40.0, 25, CLOTHING},
            {219, "Henley Shirt", 25.0, 40, CLOTHING},
            {220, "Graphic Tee", 20.0, 60, CLOTHING}};

        // Add more clothing subcategories...

        Product food[] = {
            {301, "Bread", 2.0, 100, FOOD},
            {302, "Milk", 3.0, 80, FOOD},
            {303, "Apple", 1.0, 150, FOOD},
            {304, "Chicken", 5.0, 50, FOOD},
            {305, "Rice", 4.0, 60, FOOD},
            {306, "Pizza", 8.0, 30, FOOD},
            {307, "Eggs", 2.0, 120, FOOD},
            {308, "Banana", 0.5, 200, FOOD},
            {309, "Potato", 1.0, 100, FOOD},
            {310, "Salad", 3.0, 40, FOOD}};

        Product snacksProducts[] = {
            {311, "Chips", 2.0, 50, FOOD},
            {312, "Chocolate", 1.0, 80, FOOD},
            {313, "Candy", 0.5, 100, FOOD},
            {314, "Popcorn", 3.0, 60, FOOD},
            {315, "Nuts", 4.0, 50, FOOD},
            {316, "Pretzels", 2.0, 70, FOOD},
            {317, "Crackers", 2.0, 80, FOOD},
            {318, "Granola Bar", 1.0, 90, FOOD},
            {319, "Fruit Snacks", 1.5, 70, FOOD},
            {320, "Beef Jerky", 3.0, 40, FOOD}};

        // Add more food subcategories...

        Product furniture[] = {
            {401, "Chair", 50.0, 20, FURNITURE},
            {402, "Table", 100.0, 15, FURNITURE},
            {403, "Sofa", 300.0, 10, FURNITURE},
            {404, "Bed", 200.0, 12, FURNITURE},
            {405, "Desk", 80.0, 20, FURNITURE},
            {406, "Bookshelf", 70.0, 25, FURNITURE},
            {407, "Wardrobe", 150.0, 10, FURNITURE},
            {408, "Dining Table", 250.0, 8, FURNITURE},
            {409, "Coffee Table", 90.0, 15, FURNITURE},
            {410, "TV Stand", 120.0, 18, FURNITURE}};

        Product partsProducts[] = {
            {411, "Screws", 2.0, 200, FURNITURE},
            {412, "Nails", 1.0, 250, FURNITURE},
            {413, "Hinges", 3.0, 150, FURNITURE},
            {414, "Drawer Slides", 5.0, 100, FURNITURE},
            {415, "Handles", 4.0, 120, FURNITURE},
            {416, "Knobs", 2.0, 150, FURNITURE},
            {417, "Brackets", 3.0, 120, FURNITURE},
            {418, "Casters", 8.0, 80, FURNITURE},
            {419, "Glides", 5.0, 100, FURNITURE},
            {420, "Furniture Legs", 10.0, 60, FURNITURE}};

        // Add more furniture subcategories...

        Product sports[] = {
            {501, "Football", 20.0, 30, SPORTS},
            {502, "Basketball", 25.0, 25, SPORTS},
            {503, "Tennis Racket", 50.0, 15, SPORTS},
            {504, "Yoga Mat", 15.0, 40, SPORTS},
            {505, "Running Shoes", 60.0, 20, SPORTS},
            {506, "Gym Gloves", 10.0, 50, SPORTS},
            {507, "Dumbbells Set", 80.0, 10, SPORTS},
            {508, "Jump Rope", 8.0, 30, SPORTS},
            {509, "Swimming Goggles", 15.0, 25, SPORTS},
            {510, "Treadmill", 500.0, 5, SPORTS}};

        Product exerciseEquipment[] = {
            {511, "Exercise Bike", 300.0, 10, SPORTS},
            {512, "Elliptical Machine", 400.0, 8, SPORTS},
            {513, "Rowing Machine", 350.0, 12, SPORTS},
            {514, "Punching Bag", 100.0, 15, SPORTS},
            {515, "Weight Bench", 150.0, 20, SPORTS},
            {516, "Resistance Bands Set", 30.0, 25, SPORTS},
            {517, "Medicine Ball", 25.0, 30, SPORTS},
            {518, "Yoga Blocks", 10.0, 40, SPORTS},
            {519, "Balance Board", 20.0, 35, SPORTS},
            {520, "Foam Roller", 15.0, 40, SPORTS}};

        // Add more sports subcategories...

        Product stationary[] = {
            {601, "Pen", 1.0, 100, STATIONARY},
            {602, "Pencil", 0.5, 150, STATIONARY},
            {603, "Notebook", 2.0, 80, STATIONARY},
            {604, "Eraser", 0.2, 200, STATIONARY},
            {605, "Ruler", 0.3, 150, STATIONARY},
            {606, "Highlighter", 1.5, 50, STATIONARY},
            {607, "Stapler", 3.0, 30, STATIONARY},
            {608, "Scissors", 2.0, 40, STATIONARY},
            {609, "Glue Stick", 1.0, 60, STATIONARY},
            {610, "Markers Set", 5.0, 20, STATIONARY}};

        Product officeSupplies[] = {
            {611, "Paper Clips", 0.5, 100, STATIONARY},
            {612, "Binder Clips", 1.0, 80, STATIONARY},
            {613, "Push Pins", 0.2, 120, STATIONARY},
            {614, "Rubber Bands", 0.3, 150, STATIONARY},
            {615, "Index Cards", 1.0, 80, STATIONARY},
            {616, "Hole Puncher", 5.0, 30, STATIONARY},
            {617, "File Folders", 2.0, 50, STATIONARY},
            {618, "Note Pads", 3.0, 40, STATIONARY},
            {619, "Whiteboard Eraser", 2.0, 60, STATIONARY},
            {620, "Binder Dividers", 4.0, 20, STATIONARY}};

        // Add more stationary subcategories...

        // Add more products...

        // Adding products to inventory
        for (int i = 0; i < sizeof(electronics) / sizeof(electronics[0]); ++i)
        {
            inventory.addProduct(electronics[i]);
        }
        for (int i = 0; i < sizeof(communicationDevicesProducts) / sizeof(communicationDevicesProducts[0]); ++i)
        {
            inventory.addProduct(communicationDevicesProducts[i]);
        }
        for (int i = 0; i < sizeof(clothing) / sizeof(clothing[0]); ++i)
        {
            inventory.addProduct(clothing[i]);
        }
        for (int i = 0; i < sizeof(shirtsProducts) / sizeof(shirtsProducts[0]); ++i)
        {
            inventory.addProduct(shirtsProducts[i]);
        }
        for (int i = 0; i < sizeof(food) / sizeof(food[0]); ++i)
        {
            inventory.addProduct(food[i]);
        }
        for (int i = 0; i < sizeof(snacksProducts) / sizeof(snacksProducts[0]); ++i)
        {
            inventory.addProduct(snacksProducts[i]);
        }
        for (int i = 0; i < sizeof(furniture) / sizeof(furniture[0]); ++i)
        {
            inventory.addProduct(furniture[i]);
        }
        for (int i = 0; i < sizeof(partsProducts) / sizeof(partsProducts[0]); ++i)
        {
            inventory.addProduct(partsProducts[i]);
        }
        for (int i = 0; i < sizeof(sports) / sizeof(sports[0]); ++i)
        {
            inventory.addProduct(sports[i]);
        }
        for (int i = 0; i < sizeof(exerciseEquipment) / sizeof(exerciseEquipment[0]); ++i)
        {
            inventory.addProduct(exerciseEquipment[i]);
        }
        for (int i = 0; i < sizeof(stationary) / sizeof(stationary[0]); ++i)
        {
            inventory.addProduct(stationary[i]);
        }
        for (int i = 0; i < sizeof(officeSupplies) / sizeof(officeSupplies[0]); ++i)
        {
            inventory.addProduct(officeSupplies[i]);
        }

        // Add more subcategory products to inventory...
        int userType;
        cout << "Enter user type (0 - Employee, 1 - Customer): ";
        cin >> userType;

        if (userType == 0)
        {
            employeeMenu(inventory);
        }
        else if (userType == 1)
        {
            customerMenu(inventory);
        }
        else
        {
            cout << "Invalid user type!\n";
        }

        cout << "Do you want to continue? (1 - Yes, 0 - No): ";
        cin >> runAgain;
    } while (runAgain != 0);

    return 0;
}
