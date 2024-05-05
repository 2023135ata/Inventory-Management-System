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
