/*
Name: Layan Khalaf
Student ID: 991274007
Password Management System
Winter 2026
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include<ctime>
using namespace std;


/*          
*
*
* EncryptPassword class to encode and decode passwords
*
*/
class EncryptPassword {

private:
    string password; // Store the encoded password
    
public:
    // Constructor
    EncryptPassword() {
        password ="";
    }
    
    // Constructor with password parameter
    EncryptPassword( const string& p) {
        password = Encode_password(p);
    }
    
    // Method to encode password: reverse string and convert to ASCII codes
    string Encode_password(const string& p) {
        // Step 1: Reverse the string
        string reversed = "";
        // used size_t because it will hold the size of any object in bytes
        for (size_t i = p.length(); i > 0; i--)
         {
            reversed += p[i - 1];
        }
        
          // Step 2: Convert each character to ASCII code format
        string encoded = "";
        for (size_t i = 0; i < reversed.length(); i++) 
        {
            // Cast character to int to get ASCII code
            encoded += to_string(static_cast<int>(reversed[i]));
            // Add comma separator except for the last character
            if (i < reversed.length() - 1) 
            {
                encoded += ",";
            }
        }
        
        return encoded;
    }
    
    // Method to decode password: convert ASCII codes to characters, then reverse
        string decode_password( const string& encoded) {
        string reversed , num;   
        // Parse comma-separated ASCII codes
        for (size_t i = 0; i < encoded.length(); i++)
         {
            if (encoded[i] == ',') {
                // Convert string number to int, then cast to char line by line 

                reversed += static_cast<char>(stoi(num));
                num = "";
            } else {
                num += encoded[i];
            }
        }
        // Add the last character
        if (!num.empty()) {
            reversed += static_cast<char>(stoi(num));
        }
        
        // Reverse the string to get original
        string original ;
        for (int i = reversed.length() - 1; i >= 0; i--)
        {
            original += reversed[i];
        }
        return original;
        }
    
    // Getter for encoded password
    string getPassword() const {
        return password;
    }
    
    // Setter for password encodes before storing
    void setPassword(string p) {
        password = Encode_password(p);
    }
    
    // Method to display decoded password
    void displayPassword() {
        cout << "Decoded Password: " << decode_password(password) << endl;
    }
    
    // Method to display encoded password
    void displayEncodedPassword() {
    cout << "Encoded Password: " << password << endl;
    }
  
};

/*
*
*  Passoword Item Class
*
*/
class PasswordItem
{ 
    
private:
    // Variables to store the details of the password item
    int item_id;
    string name;
    string category;
    string user_name;
    string password; // stored as encoded password
    
public:

    // Default constructor
    PasswordItem() 
     {
        item_id = 0;
        name = "";
        category = "";
        user_name = "";
        password = "";  
     }

    // constructor to initialize all member variable
    PasswordItem(int id, string n, string c, string un, string p) {
            item_id = id;
             name =  n;
            category = c;
            user_name = un; 
            EncryptPassword ep;
            password = ep.Encode_password(p); 
    }

// get and set functions for each member variable
    int getItemId() const 
    {
        return item_id;
    }

    void setItemId(int id) 
    {
        // make sure item id contains only 5 digits 
        if (id < 10000 || id > 99999)
        {
            cout << " Item ID must be a 5 digit number" << endl;
        } 
        else
            item_id = id;
    }

    string getName() const 
    {
        return name;
    }

    void setName(string n) 
    {
        // make sure name contains only string characters and spaces
        bool valid = true;
        for(char c : n)
        {
            if(!isalpha(c) && c != ' ')
            {
                cout << "Error: Name must contain only letters ." << endl;
                valid = false;
                break;
            }
        }
        if(valid)
        {
            name = n;
        }
   }
    string getCategory() const 
    {
        return category;
    }
    void setCategory( const string& c) 
    {
        // ensure category is a string and unique
         if (c.empty()) 
        {
            cout <<  "Category cannot be empty.\n";
            return;
        }
        bool valid = true;
        for(char ch : c) 
        {
            if(!isalpha(ch) && ch != ' ' && !isdigit(ch)) 
            {
                cout << "Error: Category must contain string " << endl;
                valid = false;
                break;
            }
        }
        if(valid)
        {
            category = c;
        }
    } 
      string getUserName() const 
      {
        return user_name;
    }
    void setUserName(string un) 
    {
        // ensure username is not empty and is a string
        if (un.empty()) {
            cout << "Error: Username cannot be empty" << endl;
            return;
        }
        bool valid = true;
        for (char c : un)
        {
            if (!isalpha(c) && c != '_' && c != '.' && c != '@' && !isdigit(c))
            {
                cout << "Error: Username contains invalid characters" << endl;
                valid = false;
                break;
            }
        }
        if (valid) {
            user_name = un;
        }
    }
   string getPassword() const { return password; }
    void setPassword(const string& p)
     {
        EncryptPassword ep;
        password = ep.Encode_password(p);
    }
    

    void displayEncodedPassword() const {
        cout << "Encoded Password: " << password << endl;
    }

    void displayPassword() const {
        EncryptPassword ep;
        cout << "Decoded Password: " << ep.decode_password(password) << endl;
    }
    void display() const {
        EncryptPassword ep;
        cout << "ID: " << item_id << endl;
        cout << "Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Username: " << user_name << endl;
        cout << "Password (encoded): " << password << endl;
        cout << "Password (decoded): " << ep.decode_password(password) << endl;
    }
};



/*
*
* PasswordStorage class to manage multiple PasswordItem objects
*
*/
class PasswordStorage {

private:

    string storage_name;
    map<int, PasswordItem> password_storage;// map to store password items 

public:
// constructor
  PasswordStorage(string name) 
    {
        storage_name = name; 
    } 
    
  
    
    /// first method : view all stored PasswordItem objects
    void view_PasswordStorage() 
    {
        if (password_storage.empty()) {
            cout << "No password items stored yet." << endl;
            
        }
        for (auto& p : password_storage) {
            p.second.display();
        }
    }   
   
      // second method :  add a new PasswordItem to the storage
     void add_PasswordItem(PasswordItem newItem)
{
    int id;
    do
     {
        id = 10000 + rand() % 90000;   // random 5 digit number
    } 
    while (password_storage.find(id) != password_storage.end());

    newItem.setItemId(id);
    password_storage[id] = newItem;

    cout << "Generated Item ID: " << id << endl;
}

          
   
    // third method : update a item details by its ID
    void update_PasswordItem(int id) {
         auto updateitems = password_storage.find(id);
         if(updateitems == password_storage.end()) {
            cout << "Password Item with id " << id << " not found." << endl;
            return;
         }
           
        string newName, newCategory, newUsername, newPassword;
            cin.ignore(); 
            cout << "Enter new name: "<< endl;
            cin >> newName;
            cout << "Enter new category: "<< endl;
            cin >> newCategory;
            cout << "Enter new username: "<< endl;
            cin >> newUsername;
            cout << "Enter new password: "<< endl;
            cin >> newPassword;
            
            updateitems->second.setName(newName);
            updateitems->second.setCategory(newCategory);
            updateitems->second.setUserName(newUsername);
            updateitems->second.setPassword(newPassword);

            cout << "Password Item updated ." << endl;
        }
    
    // forth method : delete an item by its ID 
    void remove_item(int id)
    {
        if (password_storage.erase(id) ) {
            cout <<"item with ID " << id << " removed successfully." << endl;
        } else {
            cout << "Password Item with ID " << id << " not found." << endl;
        }
    }
       // fifth method : find password item by its ID
     PasswordItem find_Password_Item(int id) 
    {
        auto it = password_storage.find(id);
        if (it != password_storage.end())
       {
            cout << "Password Item found:" << endl;
            it->second.display();
            return it->second;
       }
       else
       {
            cout << "Password Item with ID  "  <<  id  << " not found." << endl;
            return PasswordItem();
       }
    }
    // 6th method : find password item by its name
    PasswordItem find_item_by_name(string name) 
    {
        for (auto& p : password_storage)
         {
            if (p.second.getName() == name)
             {
                cout << "Password Item found:" << endl;
                p.second.display();
                return p.second;
            }
        }
        cout << "Password Item with name " << name << " not found." << endl;
        return PasswordItem();
    }
 
    // 7th method :find item by category        
    vector<PasswordItem> find_item_by_category( const string& category)const 
    {   
        vector<PasswordItem> items;
        for (auto& p : password_storage) 
        {
            if (p.second.getCategory() == category) 
            {
                cout << "Password Item found:" << endl;
                p.second.display();
                items.push_back(p.second);
            }
        }
        if (items.empty()) {
            cout << "No items found in category: " << category << endl;
        }
        return items;
    }
};

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    
    // Create a password storage object with a storage name
    PasswordStorage storage(" Password Storage");
    
    // Add 10 password items to the store with various categories
storage.add_PasswordItem(PasswordItem(0, "Gmail", "Email", "Layan.khalaf@gmail.com", "gmailPass123"));
storage.add_PasswordItem(PasswordItem(0, "Outlook", "Email2", "Zaina@outlook.com", "OutlookPass123"));
storage.add_PasswordItem(PasswordItem(0, "RBC", "Bank", "RBC_user", "RBCBank123"));
storage.add_PasswordItem(PasswordItem(0, "TD Bank", "Finance", "TD_User", "TDBank123"));
storage.add_PasswordItem(PasswordItem(0, "Facebook", "SocialMedia", "FB_user", "FBaccount123"));
storage.add_PasswordItem(PasswordItem(0, "Instagram", "SocialMedia2", "insta_user", "instPass123"));
storage.add_PasswordItem(PasswordItem(0, "Netflix", "Entertainment", "netflix_account", "netflixPass123"));
storage.add_PasswordItem(PasswordItem(0, "Amazon", "Shopping", "amazon_user", "amazonPrime123"));
storage.add_PasswordItem(PasswordItem(0, "GitHub", "Work", "github_account", "gitHubPass123"));
storage.add_PasswordItem(PasswordItem(0, "LinkedIn", "Work2", "linkedin_account", "linkedPass123"));


    
    // Menu-driven interface
    int choice;
    bool running = true;
    
    while (running) {
        cout << "\n========================================" << endl;
        cout << "   PASSWORD STORAGE MANAGEMENT SYSTEM   " << endl;
        cout << "========================================" << endl;
        cout << "1. Display all password items" << endl;
        cout << "2. Add a new password item" << endl;
        cout << "3. Remove a password item" << endl;
        cout << "4. Update a password item" << endl;
        cout << "5. Find item by ID" << endl;
        cout << "6. Find item by name" << endl;
        cout << "7. Find items by category" << endl;
        cout << "8. Test EncryptPassword class" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice (1-9):\n ";
        cin >> choice;
        cout << endl;
        
        // Handle invalid input (non-integer)
        if (cin.fail()) {
            cin.clear(); // clear error flag
            cin.ignore(10000, '\n'); // discard invalid input
            cout << "Invalid input! Please enter a number between 1 and 9" << endl;
            continue; // skip to next iteration
        }
        
        switch (choice) {
            case 1: {
                // Display all password items
                storage.view_PasswordStorage();
                break;
            }
            case 2: {
                // Add a new password item
                string name, category, username, password;

                // Generate random 5-digit ID
            
                 int id = rand() % 90000 + 10000;
                
                cout << "Enter Name: "<< endl;
                 cin>> name;
                
                cout << "Enter Category: "<< endl;
               cin>> category;
                
                cout << "Enter Username: "<< endl;
                cin>> username;
                
                cout << "Enter Password: "<< endl;
                cin>> password;
                
                PasswordItem newItem(id, name, category, username, password);
                storage.add_PasswordItem(newItem);
                cout << "Password item added successfully!" << endl;
                break;
            }
            case 3: {
                // Remove a password item
                int id;
                cout << "Enter Item ID to remove: ";
                cin >> id;
                storage.remove_item(id);
                break;
            }
            case 4: {
                // Update a password item
                int id;
                cout << "Enter Item ID to update: ";
                cin >> id;
                storage.update_PasswordItem(id);
                break;
            }
            case 5: {
                // Find item by ID
                int id;
                cout << "Enter Item ID to find: ";
                cin >> id;
                storage.find_Password_Item(id);
                break;
            }
            case 6: {
                // Find item by name
                string name;
                cout << "Enter Item Name to find: "<< endl;
                cin>> name;
                storage.find_item_by_name(name);
                break;
            }
            case 7: {
                // Find items by category
                string category;
                cout << "Enter Category to search: "<< endl;
                cin>> category;
                storage.find_item_by_category(category);
                break;
            }
            case 8: {
                // Test EncryptPassword class
                string testPassword;
                cout << "Enter a password to encrypt: "<< endl;
                cin >> testPassword;
            
                EncryptPassword ep(testPassword);
                ep.displayEncodedPassword();
               
                break;
            } 
            case 9: {
                // Exit
                running = false;
                cout << "Exiting ..... Goodbye!" << endl;
                break;
            }
       
            default: {
                cout << "Invalid choice! Please enter a number between 1 and 9" << endl;
                break;
            }
        }
    }
    
    return 0;
}