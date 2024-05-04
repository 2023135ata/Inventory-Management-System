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
};
