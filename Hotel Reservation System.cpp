#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <conio.h>

using namespace std;

/// ============== ANSI Colors ============== ///
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BG_GREEN "\033[42m"
#define BRIGHT_RED "\033[91m"
#define DIM "\033[2m"
#define BG_BRIGHT_CYAN "\033[106m"
#define BLACK "\033[30m"

/// Bright Background Colors */
#define BG_BRIGHT_BLACK "\033[100m"
#define BG_BRIGHT_RED "\033[101m"
#define BG_BRIGHT_GREEN "\033[102m"
#define BG_BRIGHT_YELLOW "\033[103m"
#define BG_BRIGHT_BLUE "\033[104m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_BRIGHT_CYAN "\033[106m"
#define BG_BRIGHT_WHITE "\033[107m"

///* Bright Foreground Colors */
#define BRIGHT_BLACK "\033[90m"
#define BRIGHT_RED "\033[91m"
#define BRIGHT_GREEN "\033[92m"
#define BRIGHT_YELLOW "\033[93m"
#define BRIGHT_BLUE "\033[94m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_CYAN "\033[96m"
#define BRIGHT_WHITE "\033[97m"



/// ============== INVALID INPUTS ============== ///
void invalid_input ()
{
    cin.clear ();
    cin.ignore (1000, '\n');
}

/// ============== Enter to Continue ============== ///
void continueProcess()
{
    cin.ignore();
    cout << RED <<"\n\nPress Enter To Continue..." <<RESET;
    cin.get();
    system("cls");
}

/// ============== GLOBAL VARIABLE ============== ///
bool loggedIn = false;
bool superAdmin = false;


/// ============== CLASS ROOM ============== ///
class Room {

    string roomNumber;
    bool isBooked;
    int customerID;
    double roomPrice;
    int roomFloor;

public:
    // Parameterized Constructor
    Room(string number, double price, int floor) {
        setRoomNumber(number);
        isBooked = false;
        customerID = -1;
        setRoomPrice(price);
        setRoomFloor(floor);
    }

    // Setter and Getter for roomNumber
    void setRoomNumber(string number) {
        roomNumber = number;
    }
    string getRoomNumber() const {
        return roomNumber;
    }

    // Setter and Getter for isBooked
    void setIsBooked(bool booked) {
        isBooked = booked;
    }
    bool getIsBooked() const {
        return isBooked;
    }

    // Setter and Getter for customerID
    void setCustomerID(int customer) {
        customerID = customer;
    }
    int getCustomerID() const {
        return customerID;
    }

    // Setter and Getter for roomPrice
    void setRoomPrice(double price) {
        roomPrice = price;
    }
    double getRoomPrice() const {
        return roomPrice;
    }

    // Setter and Getter for roomFloor
    void setRoomFloor(int floor) {
        roomFloor = floor;
    }
    int getRoomFloor() const {
        return roomFloor;
    }

    // Book and Vacate methods
    void book(int customer) {
        isBooked = true;
        customerID = customer;
    }
    void vacate() {
        isBooked = false;
        customerID = -1;
    }

    // Details method
    void getDetails() const {
        cout << "Room No: " << roomNumber << endl;
        cout << "Floor No: " << roomFloor << endl;
        cout << "Price ($): " << roomPrice << endl;
        cout << "Available: " << (isBooked ? "No" : "Yes") << endl;
        if (isBooked) {
            cout << "Booked by Customer ID: " << customerID << endl;
        }
    }
};

/// ============================================== FINISHED ROOM CLASS ============================================== ///



/// ============== CLASS CUSTOMER ============== ///
class Customer
{
    static int lastID;
    int customerID;
    string customerName;
    string customerAddress;
    string customerPhone;
    string customerEmail;

public:
    // Default Constructor
    Customer()
    {
        customerID = ++lastID;
        cin.ignore();

        cout << "Customer ID: " << customerID << endl;

        setCustomerName();
        setCustomerAddress();
        setCustomerPhone();
        setCustomerEmail();
    }

    // Parameterized Constructor
    Customer(int last_ID, int customer_ID, const string& name, const string& address, const string& phone, const string& email)
    {
        setLastID(last_ID);
        setCustomerID(customer_ID);
        setCustomerName(name);
        setCustomerAddress(address);
        setCustomerPhone(phone);
        setCustomerEmail(email);
    }

    // Setter and Getter for lastID
    static void setLastID(int last_ID)
    {
        lastID = last_ID;
    }
    static int getLastID()
    {
        return lastID;
    }

    // Setter and Getter for customerID
    void setCustomerID(int customer_ID)
    {
        customerID = customer_ID;
    }
    int getCustomerID() const
    {
        return customerID;
    }

    // Setter and Getter for customerName
    void setCustomerName(const string& name)
    {
        if (!name.empty())
        {
            customerName = name;
        }
        else
        {
            throw invalid_argument("Customer name cannot be empty.");
        }
    }

    // Method to set customer name with validation
    void setCustomerName()
    {
        while (true)
        {
            cout << "Customer Name: ";
            getline(cin, customerName);
            if (!customerName.empty())
            {
                break;
            }
            else
            {
                cerr << '\a';  // Beep sound
                cout << "Customer name cannot be empty. Please enter the customer name." << endl;
            }
        }
    }

    string getCustomerName() const
    {
        return customerName;
    }

    // Setter and Getter for customerAddress
    void setCustomerAddress(const string& address)
    {
        if (!address.empty())
        {
            customerAddress = address;
        }
        else
        {
            throw invalid_argument("Customer address cannot be empty.");
        }
    }

    // Method to set customer address with validation
    void setCustomerAddress()
    {
        while (true)
        {
            cout << "Customer Address: ";
            getline(cin, customerAddress);
            if (!customerAddress.empty())
            {
                break;
            }
            else
            {
                cerr << '\a';  // Beep sound
                cout << "Customer address cannot be empty. Please enter the customer address." << endl;
            }
        }
    }

    string getCustomerAddress() const
    {
        return customerAddress;
    }

    // Setter and Getter for customerPhone
    void setCustomerPhone(const string& phone)
    {
        if (isValidPhone(phone))
        {
            customerPhone = phone;
        }
        else
        {
            cerr << '\a';  // Beep sound
            throw invalid_argument("Phone number must be exactly 11 digits and contain only numbers.");
        }
    }

    // Method to set customer phone with validation
    void setCustomerPhone()
    {
        while (true)
        {
            cout << "Customer Phone: ";
            getline(cin, customerPhone);
            if (isValidPhone(customerPhone))
            {
                break;
            }
            else
            {
                cerr << '\a';  // Beep sound
                cout << RED << "Invalid phone number. It must be exactly 11 digits and contain only numbers. "
                "Please re-enter the phone number." << RESET << endl;
            }
        }
    }

    string getCustomerPhone() const
    {
        return customerPhone;
    }

    // Setter and Getter for customerEmail
    void setCustomerEmail(const string& email)
    {
        if (isValidEmail(email))
        {
            customerEmail = email;
        }
        else
        {
            cerr << '\a';  // Beep sound
            throw invalid_argument("Invalid email format");
        }
    }

    // Method to set customer email with validation
    void setCustomerEmail()
    {
        while (true)
        {
            cout << "Customer Email: ";
            getline(cin, customerEmail);
            if (isValidEmail(customerEmail))
            {
                break;
            }
            else
            {
                cerr << '\a';  // Beep sound
                cout << YELLOW << "Invalid email format. Please re-enter the email." << RESET << endl;
            }
        }
    }

    string getCustomerEmail() const
    {
        return customerEmail;
    }

    // Print customer details
    void getDetails() const
    {
        cout << "Customer ID: " << customerID << endl;
        cout << "Customer Name: " << customerName << endl;
        cout << "Customer Address: " << customerAddress << endl;
        cout << "Customer Phone: " << customerPhone << endl;
        cout << "Customer Email: " << customerEmail << endl;
    }

    // Print customer details in flat format
    void getDetailsFlat() const
    {
        cout <<CYAN<< "\n["<<(customerID < 10 ? "00" : (customerID < 100 ? "0" : ""))<<customerID<< "] "<<RESET;
        cout <<BOLD<<"NAME\t: "<<RESET << customerName <<"\n      "<<BOLD<<"ADDRESS\t: "<<RESET<< customerAddress ;
        cout <<"\n      "<<BOLD<<"PHONE\t: "<<RESET<< customerPhone<<"\n      "<<BOLD<<"EMAIL\t: "<<RESET<< customerEmail;
        cout <<endl;
    }

private:
    // Validate email format
    bool isValidEmail(const string& email) const
    {
        const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
        return regex_match(email, pattern);
    }

    // Validate phone format
    bool isValidPhone(const string& phone) const
    {
        const regex pattern("^\\d{11}$");
        return regex_match(phone, pattern);
    }
};

/// ============================================== FINISHED CUSTOMER CLASS ============================================== ///

/// ============================== Static Value Declaration (Auto Increment ID)  ============================== ///
int Customer::lastID = 0;

/// ============================== Supporting Functions ============================== ///

// To get customer by ID
Customer* checkCustomer(vector<Customer>& customers, int id)
{
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getCustomerID() == id)
        {
            customers[i].getDetails();
            return &customers[i];
        }
    }
    return nullptr;
}

// View all customers
void viewAllCustomers(const vector<Customer>& customers)
{
    if (customers.empty()) {
        cout << "\nNo Registered Customers Yet!";
    } else {
        for (const auto& customer : customers)
        {
            customer.getDetailsFlat();
        }
    }
}
/// ============================== FINISHED Supporting Functions ============================== ///



/// ============== CLASS HOTEL ============== ///
class Hotel
{
    string hotelName;
    vector<Room> rooms;
    int totalFloors;
    int eachFloorRoomCount;

public:
    // Parameterized Constructor
    Hotel(const string& name, int floors, int roomEach, double price)
    {
        setHotelName(name);
        setTotalFloors(floors);
        setEachFloorRoomCount(roomEach);

        char floorChar = 'A';
        int floorExt = 1;
        for (int floor = 1; floor <= totalFloors; ++floor)
        {
            for (int roomNum = 1; roomNum <= eachFloorRoomCount; ++roomNum)
            {
                string roomNumber = floorChar + to_string(floorExt) +
                                    (roomNum < 10 ? "00" : (roomNum < 100 ? "0" : "")) + to_string(roomNum);
                rooms.push_back(Room(roomNumber, price, floor));
            }
            if (floorChar == 'Z')
            {
                floorChar = 'A';
                floorExt++;
            }
            else
            {
                floorChar++;
            }
        }
    }


    // Setters and Getters Hotel Name
    void setHotelName(const string& name)
    {
        hotelName = name;
    }
    string getHotelName() const
    {
        return hotelName;
    }

    // Setters and Getters Total Floor
    void setTotalFloors(int floors)
    {
        totalFloors = floors;
    }
    int getTotalFloors() const
    {
        return totalFloors;
    }

     // Setters and Getters Each Room Count
    void setEachFloorRoomCount(int roomEach)
    {
        eachFloorRoomCount = roomEach;
    }
    int getEachFloorRoomCount() const
    {
        return eachFloorRoomCount;
    }

    // Check if a room is available
    bool isRoomAvailable(const string& roomNumber) const
    {
        for (const auto& room : rooms)
        {
            if (room.getRoomNumber() == roomNumber && !room.getIsBooked())
            {
                return true;
            }
        }
        return false;
    }

    // Book a room for a customer
    bool bookRoom(const string& roomNumber, Customer& customer)
    {
        for (auto& room : rooms)
        {
            if (room.getRoomNumber() == roomNumber && !room.getIsBooked())
            {
                room.book(customer.getCustomerID());
                cout << GREEN << "Room " << roomNumber << " Booked For " << customer.getCustomerName() << RESET << endl;
                // Custom booking sound
                cout << "\a"; // ASCII bell character for demonstration, replace with custom sound
                return true;
            }
        }
        cout << RED << "Room " << roomNumber << " Is Not Available!" << RESET << endl;
        return false;
    }

    // Vacate a room
    void vacateRoom(const string& roomNumber)
    {
        for (auto& room : rooms)
        {
            if (room.getRoomNumber() == roomNumber)
            {
                if (room.getIsBooked())
                {
                    room.vacate();
                    cout << GREEN << "Room " << roomNumber << " Vacated!" << RESET << endl;
                    // Custom vacating sound
                    cout << "\a"; // ASCII bell character for demonstration, replace with custom sound
                }
                else
                {
                    cout << GREEN << "Room " << roomNumber << " Is Available To Book!" << RESET << endl;
                }
                return;
            }
        }
        cout << RED << "Room " << roomNumber << " Doesn't Exist!" << RESET << endl;
    }

    // Get room price
    double getRoomPrice(const string& roomNumber) const
    {
        for (const auto& room : rooms)
        {
            if (room.getRoomNumber() == roomNumber)
            {
                return room.getRoomPrice();
            }
        }
        cout << RED << "Room " << roomNumber << " Doesn't Exist!" << RESET << endl;
        return -1;
    }

    // Get room info and return customer ID if booked
    int checkRoom(const string& roomNumber) const
    {
        for (const auto& room : rooms)
        {
            if (room.getRoomNumber() == roomNumber)
            {
                room.getDetails();
                return room.getCustomerID();
            }
        }
        cout << RED << "Room " << roomNumber << " Doesn't Exist!" << RESET << endl;
        return -1;
    }

    // Edit room price
    bool editRoom(const string& roomNumber)
    {
        for (auto& room : rooms)
        {
            if (room.getRoomNumber() == roomNumber)
            {
                double price;
                cout << "New Price ($): ";
                while (!(cin >> price) || price < 0)
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "Invalid input. Please enter a positive price." << RESET << endl;
                    cout << "New Price ($): ";
                }
                room.setRoomPrice(price);
                cout << GREEN << "Room " << roomNumber << " Price Updated To " << price << RESET << endl;
                return true;
            }
        }
        cout << RED << "Room " << roomNumber << " Doesn't Exist!" << RESET << endl;
        return false;
    }

    // Get the list of all rooms
    void viewAllRooms() const
    {
        char floorChar = 'A';
        int floorExt = 1;
        for (int floor = 1; floor <= totalFloors; ++floor)
        {
            cout << "FLOOR " << (floor < 10 ? "00" : (floor < 100 ? "0" : "")) << floor << ":\n----------\n";
            for (int roomNum = 1; roomNum <= eachFloorRoomCount; ++roomNum)
            {
                string roomNumber = floorChar + to_string(floorExt) +
                                    (roomNum < 10 ? "00" : (roomNum < 100 ? "0" : "")) + to_string(roomNum);
                if (isRoomAvailable(roomNumber))
                {
                    cout << "[" << GREEN << roomNumber << RESET << "] ";
                }
                else
                {
                    cout << "[" << RED << roomNumber << RESET << "] ";
                }
            }
            cout << endl << endl;
            if (floorChar == 'Z')
            {
                floorChar = 'A';
                floorExt++;
            }
            else
            {
                floorChar++;
            }
        }
        cout << endl;
    }
};

/// ============================================== FINISHED HOTEL CLASS ============================================== ///


/// ============== CLASS ADMIN ============== ///
class Admin {
private:
    string username;
    string password;
    bool superAdmin;

public:
    // Default Constructor
    Admin(bool super = false) : superAdmin(super) {
        setUsernameWithPrompt();
        setPasswordWithConfirmation();
    }

    // Parameterized Constructor
    Admin(const string& user, const string& pass, bool super = false)
        : superAdmin(super) {
        setUsername(user);
        setPassword(pass);
    }

    // Setter for username with validation
    void setUsername(const string& user) {
        if (user.find(' ') != string::npos) {
            throw invalid_argument("Username cannot contain spaces.");
        }
        username = user;
    }

    // Getter for username
    string getUsername() const {
        return username;
    }

    // Setter for password with validation
    void setPassword(const string& pass) {
        if (pass.length() < 5) {
            throw invalid_argument("Password must be at least 5 characters long.");
        }
        password = pass;
    }

    // Getter for password
    string getPassword() const {
        return password;
    }

    // Setter for superAdmin
    void setSuperAdmin(bool super) {
        superAdmin = super;
    }

    // Getter for superAdmin
    bool isSuper() const {
        return superAdmin;
    }

private:
    void setUsernameWithPrompt() {
        string user;
        while (true) {
            cout << "Username: ";
            cin >> user;
            if (user.find(' ') != string::npos) {
                cout << "Username cannot contain spaces. Please try again.\n";
            } else {
                setUsername(user);
                break;
            }
        }
    }

    void setPasswordWithConfirmation() {
        password = getPasswordInput("Enter your password: ");
        while (password.length() < 5) {
            cout << RED << "Password must be at least 5 characters long. Please try again.\n" <<RESET;
            password = getPasswordInput("Enter your password: ");
        }

        string confirmPassword = getPasswordInput("Confirm Password: ");
        while (password != confirmPassword) {
            cout << RED << "\nPasswords do not match, please try again.\n" << RESET;
            password = getPasswordInput("Enter your password: ");
            while (password.length() < 5) {
                cout << RED <<"Password must be at least 5 characters long. Please try again.\n" <<RESET;
                password = getPasswordInput("Enter your password: ");
            }
            confirmPassword = getPasswordInput("Confirm Password: ");
        }

        cout << GREEN << "Password confirmed.\n" << RESET;
    }

    string getPasswordInput(const string& prompt) {
        string pass;
        char ch;
        cout << prompt;
        while (true) {
            ch = _getch();
            if (ch == 13) { // Enter key
                cout << endl;
                break;
            } else if (ch == 8 && !pass.empty()) { // Backspace key
                cout << "\b \b";
                pass.pop_back();
            } else if (ch != 8 && ch != 13) { // Other characters
                cout << '*';
                pass.push_back(ch);
            }
        }
        return pass;
    }
};

/// ============================================== FINISHED ADMIN CLASS ============================================== ///


/// ============================== Check If Admin Credentials Match ============================== ///
bool checkAdmin(vector<Admin>& admins, string username, string password)
{
    for (int i =0;i < admins.size();i++)
    {
        if (admins[i].getUsername() == username && admins[i].getPassword() == password)
        {
            if(admins[i].isSuper()){
                ::superAdmin = true;
            } else {
                ::superAdmin = false;
            }
            return true;
        }
    }
    return false;
}

/// ============================== Login Screen ============================== ///

bool loginScreen(vector<Admin>& admins)
{
    string username, password;
    char ch;
    cout <<  "\n\nLogin To Panel\n=================\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";

    // Reading password character by character
    ch = _getch(); // Read first character
    while (ch != 13) { // Enter key is ASCII code 13
        if (ch == 8) { // Backspace key is ASCII code 8
            if (!password.empty()) {
                password.pop_back();
                cout << "\b \b"; // Move back, print space, move back again
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    cout << endl;

    if (checkAdmin(admins, username, password)) {
        cin.get(); // To consume the newline character
        system("cls");
        return true;
    } else {
        return false;
    }
}


/// ============================== Menu Screen ============================== ///
void menuScreen(vector<Admin>& admins,vector<Customer>& customers,Hotel& hotel)
{
    // Temporary Variables
    int option;
    string id;
    int custType;
    int cust;
    Customer* tempCust;


    // Admin Panel UI
    cout << "Admin Panel\n=================\n";
    cout <<"Select An Option (1-6)\n\n";
    cout <<MAGENTA<< "[1] "<<RESET<< "All Rooms"<<endl;
    cout <<MAGENTA<< "[2] "<<RESET<< "All Customers"<<endl;
    cout <<MAGENTA<< "[3] "<<RESET<< "Room Details"<<endl;
    cout <<MAGENTA<< "[4] "<<RESET<< "Edit Room Price"<<endl;
    cout <<MAGENTA<< "[5] "<<RESET<< "Book A Room"<<endl;
    cout <<MAGENTA<< "[6] "<<RESET<< "Vacate A Room"<<endl;
    if(::superAdmin){
        cout <<MAGENTA<< "[7] "<<RESET<< "Add New Admin"<<endl;
        cout <<MAGENTA<< "[8] "<<RESET<< "Logout"<<endl;
    } else {
        cout <<MAGENTA<< "[7] "<<RESET<< "Logout"<<endl;
    }
    cout << "\n> ";
    cin >> option;
    invalid_input ();
    system("cls");


    // After Menu Selection
    switch(option)
    {
    case 1:
        // Check All Rooms
        cout << "All Rooms\n=================\nList of all rooms in the hotel\n\n";
        hotel.viewAllRooms();
        continueProcess();
        break;
    case 2:
        // Check All Registered Customers
        cout << "All Customers\n=================\nList of all registered customers in the hotel\n\n";
        viewAllCustomers(customers);
        continueProcess();
        break;
    case 3:
        // Check Room Details
        cout << "Room Details\n=================\nEnter a Room Number below to get the room details\n\n";
        cout << "Room Number: ";
        cin >> id;
        cout << endl<< endl;
        cust = hotel.checkRoom(id);
        checkCustomer(customers,cust);
        continueProcess();
        break;

    case 4:
        // Edit Room Price
        cout << "Edit Room Price\n=================\nEnter a Room Number below to edit it\'s details\n\n";
        cout << "Room No: ";
        cin >> id;
        hotel.editRoom(id);
        continueProcess();
        break;

    case 5:
        // Book A Room
        cout << "Book A Room\n=================\nEnter a Room Number below to book a room\n\n";
        cout << "Room No: ";
        cin >> id;
        if(!hotel.isRoomAvailable(id))
        {
            cout <<RED<< "Room " << id << " Is Not Available!"<<RESET << endl;
            continueProcess();
            break;
        }
        cout << "Room Price ($): " << hotel.getRoomPrice(id) <<endl;

        // Register A Customer or Use Existing
        cout << "\nCustomer Type:\n"<<MAGENTA<< "[1]"<<RESET<<" Existing\n"<<MAGENTA<<"[2]"<<RESET<<" New Customer\n\n> ";
        cin >> custType;
        if(custType == 1)
        {
            cout << "Customer ID:";
            cin >> cust;
            tempCust = checkCustomer(customers,cust);
            if(tempCust != nullptr)
            {
                hotel.bookRoom(id, *tempCust);
            }
            else
            {
                cout <<RED<< "\nInvalid Customer ID!"<<RESET;
            }
        }
        else if(custType == 2)
        {
            customers.push_back(Customer());
            hotel.bookRoom(id, customers.back());
        }
        else
        {
            cout <<RED<< "\nInvalid Choice!"<<RESET;
        }
        continueProcess();
        break;

    case 6:
        // Make A Room Available
        cout << "Vacant A Room\n=================\nEnter a Room Number below to make a room available\n\n";
        cout << "Room No:";
        cin >> id;
        hotel.vacateRoom(id);
        continueProcess();
        break;
    case 7:
        if(::superAdmin){
            cout << "Add An Admin\n=================\nEnter a login credentials of the new admin\n\n";
            admins.push_back(Admin());
            continueProcess();
        } else {
            ::loggedIn = false;
            system("cls");
            cout <<GREEN<< "Logged Out Successfully!...\n\n"<<RESET;
        }
        break;
    case 8:
        if(::superAdmin){
            ::loggedIn = false;
            system("cls");
            cout <<GREEN<< "Logged Out Successfully!...\n\n"<<RESET;
        } else {
            cout <<RED<< "Invalid Option! Try again...\n\n"<<RESET;
            continueProcess();
        }
        break;
    default:
        cout <<RED<< "Invalid Option! Try again...\n\n"<<RESET;
        continueProcess();
        break;
    }
}


int main()
{
    bool loggedIn = false;
    string hotelName;
    string hotelAddress;
    int totalFloors;
    int roomsPerFloor;
    double defaultRoomCost;


    /// Intro Screen
    cout << "========================================="<<endl;
    cout << BOLD<<BG_GREEN <<  "|| Hotel Reservation Management System ||" <<RESET<<endl;
    cout << "========================================="<<endl<<endl;
    cout << "This Management System is developed as a project of the course -"<<YELLOW <<" OOP\n" <<RESET;
    cout << "Given by our honerable Professor - ["<<YELLOW<<"Irfan Ullah Khan"<<RESET<<"]\n\n";
    cout << BOLD << BG_BRIGHT_CYAN << BLACK << "DESCRIPTION:"<<RESET <<"\n-----------\n" ;
    cout <<RED<< "A complete solution to manage your hotel with multiple admins and a super admin. Where only the super admin"
         " can add new admins. All admins can manage the rooms, book a room for the customers, check all rooms, "
         "edit price of the rooms, add new customers, and vacate a room when customers leave! \n\n"<<RESET;
    cout << BOLD << BG_BRIGHT_CYAN << BLACK << "DEVELOPED BY:"<<RESET <<"\n-----------\n";
    cout << "Student of Lahor Degree College Lahor Swabi";
    cout << "\n[NAME:"<<BLUE<<" Maaz Ur Rahman"<<RESET<<", ID:"<<BLUE<<" CS-23/302"<<RESET<<"]\n"<<endl;
    cout << "\nYou are just one step away from having your hotel management system!";
    cout << RED << "\nPress Enter To Continue..." << RESET;
    cin.get();
    system("cls");


    // First Time Hotel Setup
    cout << BLUE << "Before we can continue, let's setup your hotel first. "
            "Please fill the form below:\n\n"<<RESET;

    // Loop until a valid hotel name is entered
    do {
        cout << "Hotel Name: ";
        getline(cin, hotelName);

        if (hotelName.empty()) {
            cout << RED <<"Hotel name cannot be empty. Please enter the hotel name.\n"<<RESET;
        }
    } while (hotelName.empty());

    // Loop until a valid hotel address is entered
    do {
        cout << "Hotel Address: ";
        getline(cin, hotelAddress);

        if (hotelAddress.empty()) {
            cout <<RED<< "Hotel address cannot be empty. Please enter the hotel address.\n"<<RESET;
        }
    } while (hotelAddress.empty());

    // Loop until a valid total floors is entered
    do {
        cout << "Total Floors: ";
        cin >> totalFloors;

        if (cin.fail() || totalFloors <= 0) {
            cout << RED<<"Total floors must be a positive number. Please enter a valid number.\n"<<RESET;
            invalid_input();
        }
    } while (totalFloors <= 0);

    // Loop until a valid number of rooms per floor is entered
    do {
        cout << "Rooms In Each Floor: ";
        cin >> roomsPerFloor;

        if (cin.fail() || roomsPerFloor <= 0) {
            cout << RED <<"Rooms per floor must be a positive number. Please enter a valid number.\n" <<RESET;
            invalid_input();
        }
    } while (roomsPerFloor <= 0);

    // Loop until a valid default room cost is entered
    do {
        cout <<YELLOW<< "Default Room Cost ($): "<<RESET;
        cin >> defaultRoomCost;

        if (cin.fail() || defaultRoomCost <= 0) {
            cout <<RED<< "Default room cost must be a positive number. Please enter a valid number.\n"<<RESET;
            invalid_input();
        }
    } while (defaultRoomCost <= 0);

    cout << endl;

    Hotel hotel(hotelName,totalFloors,roomsPerFloor,defaultRoomCost);
    vector<Customer> customers;
    cout <<GREEN<< "Hotel Information Saved!"<<RESET;
    continueProcess();

    /// Proceed with the rest of your program
    cout <<GREEN<< "Hotel Information!"<<RESET<< endl;
    cout << "\nHotel Name entered: " << MAGENTA << hotelName << RESET << endl;
    cout << "Hotel Address entered: " <<  MAGENTA << hotelAddress << RESET << endl;
    cout << "Total Floors entered: " <<  MAGENTA << totalFloors << RESET << endl;
    cout << "Rooms In Each Floor entered: " <<  MAGENTA << roomsPerFloor << RESET <<endl;
    cout << "Default Room Cost entered: " << MAGENTA << defaultRoomCost<< "$"<< RESET <<endl;
    continueProcess();


    /// Super Admin Setup
    cout <<CYAN<< "Super Admin\n=================\n" <<RESET<<endl;
    cout << "Let\'s setup a super admin of your hotel. Only super admins have the power to"
         " add more admins and have all admin powers\n\n";
    vector<Admin> admins;
    admins.push_back(Admin(true));
    cout << "\nSuper Admin created! Now continue to the panel using your username "
         "and password to start managing your hotel";
    continueProcess();

    /// Admin Panel
    while(true)
    {
        if(::loggedIn)
        {
            //Main Menu
            menuScreen(admins,customers,hotel);


        }
        else
        {
            // Login Screen
            if(loginScreen(admins))
            {
                ::loggedIn = true;
            }
            else
            {
                system("cls");
                cout <<RED<< "Invalid Iogin Credentials!"<<RESET;

            }
        }
    }
    return 0;
}
