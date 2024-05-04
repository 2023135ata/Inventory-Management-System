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
