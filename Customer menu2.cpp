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
