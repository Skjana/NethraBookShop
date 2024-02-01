#include <iostream>
#include <fstream>
#include<ctime>
#include<vector>
using namespace std;

//structure to represent a book
struct Book
{
    int bookID;
    string bookName;
    string author;
    double price;
};

//structure to represent an user
struct User
{
    int userID;
    string Name;
    string userName;
    int phoneNo;
    string role;
    string password;
};

//structure to represent an Order
struct Order
{
    int orderID;
    string customerName;
    string contact;
    vector<int> bookIDs;
    vector<string> bookNames;
    vector<int> quantities;
    double totalPrice;
    string date;
    string time;
};

//structure to represent a Quotation
struct Quotation
{
    int orderID;
    string customerName;
    string contact;
    vector<int> bookIDs;
    vector<string> bookNames;
    vector<int> quantities;
    double totalPrice;
    double discountedPrice;
    string date;
    string time;
};

void mainMenu();
void menuSelection();
void registerUser();
int getUserId();
void loginPage();
void loginOption();
void login();
void adminMenu();
void viewUser();
void userMenu();
void adminOption();
void userOption();
void login_err();
void userBack();
void adminBack();
void deleteUser();

// manage book functions
void addBook();
int getBookId();
void viewBook();
void searchBook();
void updateBook();
void deleteBook();
void logout();
void exit();

// manage order functions
void getDaytime(string &currentDate, string &currentTime);
double calculateDiscount(double totalAmount);
bool getBookDetails(int bookID, Book &book);
int getOrderId();
void saveQuotation(const Quotation &quotation);
void printQuotation(const Quotation &quotation);
void addOrder();
void userAddOrder();
void adminAddOrder();
void viewOrders();
void searchOrderAndPrintQuotation();
void userSearchOrder();
void adminSearchOrder();
void editOrder();
void userEditOrder();
void adminEditOrder();
void deleteOrder();
void deleteQuotation();
void searchOrder();
bool getOrderDetails(int orderID, Order &order);
int main()
{
//adminMenu();
//userMenu();
//addBook();
    mainMenu();
    return 0;
}

void mainMenu()
{
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"======================================="<<endl;
    cout<<"\t\t\t\t\t"<<"   NETHRA BOOK STORE MANGEMENT SYSTEM  "<<endl;
    cout<<"\t\t\t\t\t"<<"======================================="<<endl;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"*--------------------------------------*"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                      |"<<endl;
    cout<<"\t\t\t\t\t"<<"|              MAIN MENU               |"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                      |"<<endl;
    cout<<"\t\t\t\t\t"<<"|           ENTER-1 :LOGIN             |"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                      |"<<endl;
    cout<<"\t\t\t\t\t"<<"|           ENTER-2 :REGISTER          |"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                      |"<<endl;
    cout<<"\t\t\t\t\t"<<"|           ENTER-3 :EXIT              |"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                      |"<<endl;
    cout<<"\t\t\t\t\t"<<"*--------------------------------------*"<<endl;
    cout<<endl;
    menuSelection();
}

void menuSelection()
{
    int ch;
    cout<<"\t\t\t\t\t"<<"Please Enter Your Choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        loginPage();
        break;
    case 2:
        system("cls");
        registerUser();
        break;
    case 3:
        exit();
        break;
    default:
        system("cls");
        cout<<endl;
        cout<<"\t\t\t\t\t"<<"\033[1;31m"<<"Invalid Option..! Please Select Given Options."<<"\033[0m";
        mainMenu();
        break;
    }
}

// function to register new user
void registerUser()
{
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<"\t\t\t\t\t"<<"       NEW USER REGISTRATION       "<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"REGISTER AS [ ADMIN | CASHIER ] "<<endl<<endl;
    User newUser;
    newUser.userID = getUserId();// Auto Increment User Id
    cout<<"\t\t\t\t\t"<<"Enter Your user Role: ";
    cin>>newUser.role;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"Enter Your Name: ";
    cin>>newUser.Name;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"Enter Your user Name: ";
    cin>>newUser.userName;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"Enter Your Contact Number: ";
    cin>>newUser.phoneNo;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"Enter Your Password: ";
    cin>>newUser.password;
    cout<<endl;

    ofstream userfile("User.txt",ios::app);
    userfile<<newUser.userID<<"\t"<<newUser.Name<<"\t"<<newUser.userName<<"\t"<<newUser.phoneNo<<"\t"<<newUser.role<<"\t"<<newUser.password<<endl;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"\033[1;32m"<<"Your Are Successfully Registered as "<<newUser.role<<"\033[0m"<<".!"<<endl;
    userfile.close();

    char ch;
    cout<<endl<<endl;
    cout<<"\t\t"<<"Go Back Enter m: ";
    cin>> ch;
    if(ch=='m')
    {
        system("cls");
        mainMenu();
    }
}
// function to get last user id from the file and return the next id
int getUserId()
{
    User obj;
    int lastId;
    ifstream userfile("User.txt",ios::in);
    while(userfile>>obj.userID>>obj.Name>>obj.userName>>obj.phoneNo>>obj.role>>obj.password)
    {
        lastId = obj.userID;
    }
    userfile.close();
    return lastId +1;
}

void viewUser()
{
    cout<<endl;
    User temp;
    ifstream userfile("User.txt",ios::in);
    cout<<"UserId"<<"\t\t"<<"Name"<<"\t\t"<<"User Name"<<"\t\t"<<"Phone Number"<<"\t\t"<<"Role"<<"\t\t"<<"password"<<endl;
    cout<<"================================================================================================================"<<endl;
    while(userfile>>temp.userID>>temp.Name>>temp.userName>>temp.phoneNo>>temp.role>>temp.password)
    {
        cout<<temp.userID<<"\t\t"<<temp.Name<<"\t\t"<<temp.userName<<"\t\t\t"<<temp.phoneNo<<"\t\t\t"<<temp.role<<"\t\t"<<temp.password<<endl;
    }
    userfile.close();
    char ch;
    cout<<endl<<endl;
    cout<<"\t\t"<<"Go Back Enter m: ";
    cin>> ch;
    if(ch=='m')
    {
        system("cls");
        adminMenu();
    }
}

void deleteUser()
{

    User temp;
    int Id;
    ifstream userfile("User.txt",ios::in);
    ofstream tempfile("temp.txt", ios::app);
    cout<<endl<<endl;
    cout << "Enter User ID for Delete: ";
    cin >> Id;
    User user;
    while (userfile >>temp.userID >>temp.Name >> temp.userName >> temp.role>>temp.password)
    {
        if (user.userID == Id)
        {
            cout<<"\t\t\t"<<"User Deleted Successfully!"<<endl;
        }
        tempfile<<"\t"<<temp.userID<<"\t"<<temp.Name<<"\t"<<temp.userName<<"\t"<<temp.role<<"\t"<<temp.password<< endl;
    }
    userfile.close();
    tempfile.close();
    remove("Book.txt");
    rename("temp.txt","Book.txt");
    cout<<"\t\t\t\t\t"<<"do you want to add another book?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    string option;
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        deleteUser();
    }
    else
    {
        system("cls");
        adminMenu();
    }
}


void loginPage()
{
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<"\t\t\t\t\t"<<"             LOGIN PAGE            "<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<"\t\t\t\t\t"<<"|                                 |"<<endl;
    cout<<"\t\t\t\t\t"<<"|     ENTER-1 :LOGIN              |"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                 |"<<endl;
    cout<<"\t\t\t\t\t"<<"|     ENTER-2 :FORGOT PASSWORD    |"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                 |"<<endl;
    cout<<"\t\t\t\t\t"<<"|     ENTER-3 :GO BACK            |"<<endl;
    cout<<"\t\t\t\t\t"<<"|                                 |"<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<endl<<endl;
    loginOption();
}

void loginOption()
{
    int ch;
    cout<<"\t\t\t\t\t"<<"Please Enter Your Choice: ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        login();
        break;
    case 2:
        //forgot_password();
        break;
    case 3:
        system("cls");
        mainMenu();
        break;
    default:
        system("cls");
        cout<<endl;
        cout<<"\t\t\t\t\t"<<"\033[1;31m"<<"Invalid Option..! Please Select Given Options."<<"\033[0m"<<endl;
        loginPage();
        break;
    }
}

//function to login
void login()
{
    User obj;
    string uname;
    string pass;
    bool match;
    ifstream userfile("User.txt",ios::in);
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"======================"<<endl;
    cout<<"\t\t\t\t\t"<<"      LOGIN HERE      "<<endl;
    cout<<"\t\t\t\t\t"<<"======================"<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t"<<"Please Enter Your user Name: ";
    cin>>uname;
    cout<<endl;
    cout<<"\t\t\t"<<"Please Enter Your Pssword: ";
    cin>>pass;
    while(userfile>>obj.userID>>obj.Name>>obj.userName>>obj.phoneNo>>obj.role>>obj.password)
    {
        if( uname==obj.userName && pass==obj.password)
        {
            match = true;
            userfile.close();
        }
    }
    userfile.close();
    switch(match)
    {
    case true:
        if(obj.role=="admin")
        {
            system("cls");
            cout<<endl;
            cout<<"\t\t\t\t\t"<<"\033[1;32m"<<"Successfully Login.!"<<"\033[0m"<<endl;
            adminMenu();
            userfile.close();
        }
        else if(obj.role=="cashier")
        {
            system("cls");
            cout<<endl;
            cout<<"\t\t\t\t\t"<<"\033[1;32m"<<"Successfully Login.!"<<"\033[0m"<<endl;
            userMenu();
            userfile.close();
        }
        break;
    case false:
        system("cls");
        login_err();
        break;
    }
}
// function for show admin menu
void adminMenu()
{
    cout<<endl;
    cout<<"\t\t"<<"*-----------------------------------------------------------------------------------*"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|                                ADMIN DASH BOARD                                   |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 1: ADD BOOKS                     ENTER 9: UPDATE BOOK ORDERS        |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 2: VIEW BOOKS                    ENTER 10: DELETE BOOK ORDERS       |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 3: SEARCH BOOKS                  ENTER 11: DELETE QUOTATION         |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 4: UPDATE BOOKS                  ENTER 12: UPDATE USER              |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 5: DELETE BOOKS                  ENTER 13: SEARCH USER              |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 6: ADD BOOK ORDERS               ENTER 14: VIEW USER                |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 7: VIEW BOOK ORDERS              ENTER 15: DELETE USER              |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 8: SEARCH BOOK ORDERS            ENTER 0:  LOG OUT                  |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"*-----------------------------------------------------------------------------------*"<<endl;
    cout<<endl;
    adminOption();
}
void adminOption()
{
    int op;
    cout<<"\t\t\t\t"<<"Please Enter Your Choice: ";
    cin>>op;
    switch(op)
    {
    case 0:
        system("cls");
        logout();
        break;
    case 1:
        system("cls");
        addBook();
        break;
    case 2:
        system("cls");
        viewBook();
        adminBack();
        break;

    case 3:
        system("cls");
        searchBook();
        adminBack();
        break;
    case 4:
        system("cls");
        updateBook();
        break;
    case 5:
        system("cls");
        deleteBook();
        break;
    case 6:
        system("cls");
        adminAddOrder();
        break;
    case 7:
        system("cls");
        viewOrders();
        adminBack();
        break;
    case 8:
        system("cls");
        adminSearchOrder();
        break;
    case 9:
        system("cls");
        adminEditOrder();
        break;
    case 10:
        system("cls");
        deleteOrder();
        break;
    case 11:
        system("cls");
        deleteQuotation();
        break;
    case 12:
        system("cls");
        break;
    case 13:
        system("cls");
        break;
    case 14:
        system("cls");
        viewUser();
        break;
    case 15:
        system("cls");
        void deleteUser();
        break;
    default:
        system("cls");
        cout<<endl;
        cout<<"\t\t\t\t"<<"\033[1;31m"<<"Invalid Option..! Please Select Given Options."<<"\033[0m";
        adminMenu();
        break;
    }
}
// function for show user menu
void userMenu()
{
    cout<<endl<<endl<<endl;
    cout<<"\t\t"<<"*-----------------------------------------------------------------------------------*"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|                                CASHIER DASH BOARD                                 |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 1: VIEW BOOKS                    ENTER 5: SEARCH BOOK ORDERS        |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 2: SEARCH BOOKS                  ENTER 6: EDIT BOOK ORDERS          |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 3: ADD BOOK ORDERS               ENTER 7: CHANGE PASSWORD           |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|         ENTER 4: VIEW BOOK ORDERS              ENTER 8: LOGOUT                    |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"|                                                                                   |"<<endl;
    cout<<"\t\t"<<"*-----------------------------------------------------------------------------------*"<<endl;
    cout<<endl;
    userOption();
}
//function to user selections
void userOption()
{
    int option;
    cout<<"\t\t\t\t"<<"Please Enter Your Choice: ";
    cin>>option;
    switch(option)
    {
    case 1:
        system("cls");
        viewBook();
        userBack();
        break;
    case 2:
        system("cls");
        searchBook();
        userBack();
        break;
    case 3:
        system("cls");
        userAddOrder();
        break;
    case 4:
        system("cls");
        viewOrders();
        userBack();
        break;
    case 5:
        system("cls");
        userSearchOrder();
        break;
    case 6:
        system("cls");
        userEditOrder();
        break;
    case 7:
        system("cls");
        break;
    case 8:
        system("cls");
        logout();
        break;
    default:
        system("cls");
        cout<<endl;
        cout<<"\t\t\t\t"<<"\033[1;31m"<<"Invalid Option..! Please Select Given Options."<<"\033[0m";
        userMenu();
        break;
    }
}
//------------------ USERS BACK TEIR MENU FUNCTIONS ---------------------------

//function for admin back admin menu
void adminBack()
{

    char ch;
    cout<<endl<<endl;
    cout<<"\t\t"<<"Go Back Enter m: ";
    cin>> ch;
    if(ch=='m')
    {
        system("cls");
        adminMenu();
    }
}

//function for admin back admin menu
void userBack()
{
    char ch;
    cout<<endl<<endl;
    cout<<"\t\t"<<"Go Back Enter m: ";
    cin>> ch;
    if(ch=='m')
    {
        system("cls");
        userMenu();
    }

}
//------------------    BOOK FUNCTIONS   ---------------------------

// Function to add new books
void addBook()
{
    Book newBook;
    string option;
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<"\t\t\t\t\t"<<"   ENTER NEW BOOK DETAIL HERE      "<<endl;
    cout<<"\t\t\t\t\t"<<"==================================="<<endl;
    cout<<endl<<endl;
    newBook.bookID = getBookId();// Auto Increment Book Id
    cout<<"\t\t\t\t\t"<<"Enter The Book Name: ";
    cin>>newBook.bookName;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"Enter The Book Author Name: ";
    cin>>newBook.author;
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"Enter The Book Price: ";
    cin>>newBook.price;
    cout<<endl;
    ofstream bookfile("Book.txt",ios::app);
    bookfile<<newBook.bookID<<"\t"<<newBook.bookName<<"\t"<<newBook.author<<"\t"<<newBook.price<<endl;
    cout<<"\t\t\t\t\t"<<"\033[1;32m"<<"Book Success fully Added.!"<<"\033[0m"<<endl;
    bookfile.close();
    cout<<"\t\t\t\t\t"<<"do you want to add another book?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        addBook();
    }
    else
    {
        system("cls");
        adminMenu();
    }

}
// function to get last book id from the file and return the next Id
int getBookId()
{
    Book temp;
    int lastId;
    ifstream bookfile("Book.txt",ios::in);
    while(bookfile>>temp.bookID>>temp.bookName>>temp.author>>temp.price)
    {
        lastId = temp.bookID;
    }
    bookfile.close();
    return lastId +1;
}
// function to view all books
void viewBook()
{
    cout<<endl;
    Book books;
    ifstream bookfile("Book.txt",ios::in);
    cout<<"\t\t\t"<<"BOOK_ID"<<"\t\t"<<"NAME"<<"\t\t"<<"AUTHOR"<<"\t\t"<<"PRICE"<<endl;
    cout<<"\t\t\t"<<"========================================================"<<endl;
    while(bookfile>>books.bookID>>books.bookName>>books.author>>books.price)
    {
        cout<<"\t\t\t"<<books.bookID<<"\t\t"<<books.bookName<<"\t\t"<<books.author<<"\t\t"<<books.price<<endl;
    }
    bookfile.close();
}
// function for search particular book using Id
void searchBook()
{
    Book books;
    int Id;
    string option;
    bool m;
    ifstream bookfile("Book.txt",ios::in);
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"Enter The Book Id: ";
    cin>>Id;
    cout<<endl;
    while(bookfile>>books.bookID>>books.bookName>>books.author>>books.price)
    {
        if(Id==books.bookID)
        {
            m =true;
            bookfile.close();
        }
    }
    bookfile.close();

    switch(m)
    {
    case true:
        system("cls");
        cout<<endl<<endl;
        cout<<"\t\t\t"<<books.bookID<<"\t\t"<<books.bookName<<"\t\t"<<books.author<<"\t\t"<<books.price<<endl;
        break;
    case false:
        system("cls");
        cout<<endl<<endl;
        cout<<"\t\t\t\t\t"<<"\033[1;31m"<<"Book record not found.!"<<"\033[0m"<<endl;
        break;
    }
}
// function for update book details
void updateBook()
{

}
// Function to delete books
void deleteBook()
{
    Book temp;
    int bId;
    string option;
    ifstream bookfile("Book.txt",ios::in);
    ofstream file;
    file.open("temp.txt",ios::app);
    cout<<"\t\t\t\t\t"<<"Enter The Book Id: "<<endl;
    cout<<"\t\t\t\t\t";
    cin>>bId;
    while(bookfile>>temp.bookID>>temp.bookName>>temp.author>>temp.price)
    {
        if(bId != temp.bookID)
        {
            file<<temp.bookID<<"\t"<<temp.bookName<<"\t"<<temp.author<<"\t"<<temp.price<<endl;
        }
        cout<<endl;
        cout<<"\t\t\t\t\t"<<"Book Successfully Deleted!"<<endl;
    }
    bookfile.close();
    file.close();
    remove("Book.txt");
    rename("temp.txt","Book.txt");

    cout<<"\t\t\t\t\t"<<"do you want to delete another Book?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        deleteBook();
    }
    else
    {
        system("cls");
        adminMenu();
    }
}

//------------------ USERS WITH ORDER FUNCTIONS  ---------------------------

// function to admin add order
void adminAddOrder()
{
    addOrder();
    string option;
    cout<<"\t\t\t\t\t"<<"do you want to add another Order?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        addOrder();
    }
    else
    {
        system("cls");
        adminMenu();
    }
}
//function to admin editOrder
void adminEditOrder()
{
    editOrder();
    string option;
    cout<<"\t\t\t\t\t"<<"do you want to edit another Order?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        editOrder();
    }
    else
    {
        system("cls");
        adminMenu();
    }
}
// function to admin search order
void adminSearchOrder()
{
    searchOrderAndPrintQuotation();
    string option;
    cout<<"\t\t\t\t\t"<<"do you want to search another Order?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        searchOrderAndPrintQuotation();
    }
    else
    {
        system("cls");
        adminMenu();
    }
}
// function to user search order
void userSearchOrder()
{
    searchOrderAndPrintQuotation();
    string option;
    cout<<"\t\t\t\t\t"<<"do you want to search another Order?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        searchOrderAndPrintQuotation();
    }
    else
    {
        system("cls");
        userMenu();
    }
}
//function to user edit order
void userEditOrder()
{
    editOrder();
    string option;
    cout<<"\t\t\t\t\t"<<"do you want to add another Order?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        editOrder();
    }
    else
    {
        system("cls");
        userMenu();
    }
}
//function to user add order
void userAddOrder()
{
    addOrder();
    string option;
    cout<<"\t\t\t\t\t"<<"do you want to search another Order?"<<endl;
    cout<<"\t\t\t\t\t"<<"Enter [ yes | no ]"<<endl;
    cout<<"\t\t\t\t\t";
    cin>>option;
    cout<<endl;
    if(option=="yes")
    {
        system("cls");
        addOrder();
    }
    else
    {
        system("cls");
        userMenu();
    }
}
//------------------ COMMON FUNCTIONS ---------------------------

// Function to get the current date and time
void getDaytime(string &currentDate, string &currentTime)
{
    time_t now = time(0);
    tm *localTime = localtime(&now);
    currentDate = to_string(localTime->tm_year + 1900) + "-" + to_string(localTime->tm_mon + 1) + "-" +
                  to_string(localTime->tm_mday);
    currentTime = to_string(localTime->tm_hour) + ":" + to_string(localTime->tm_min) + ":" +
                  to_string(localTime->tm_sec);
}

// Function to calculate discount based on total amount
double calculateDiscount(double totalAmount)
{
    if (totalAmount > 10000)
    {
        return 10.0;
    }
    else if (totalAmount > 5000)
    {
        return 6.0;
    }
    else if (totalAmount > 2500)
    {
        return 3.5;
    }
    else
    {
        return 0.0;
    }
}

// Function to check if book with given ID exists and retrieve details
bool getBookDetails(int bookID, Book &book)
{
    ifstream bookfile("Book.txt", ios::in);

    while (bookfile >> book.bookID >> book.bookName >> book.author >> book.price)
    {
        if (book.bookID == bookID)
        {
            bookfile.close();
            return true;
        }
    }

    bookfile.close();
    return false;
}
// Function to get the last Order Id from the file and return the next Id
int getOrderId()
{
    Order temp;
    int lastId = 0;
    ifstream orderfile("Order.txt", ios::in);

    while (orderfile >> temp.orderID >> temp.customerName >> temp.contact >> temp.date >> temp.time >> temp.totalPrice)
    {
        lastId = temp.orderID;
    }

    orderfile.close();
    return lastId + 1;

}

//------------------ ORDERS RELATED FUNCTIONS ---------------------------

// function for add new order
void addOrder()
{
    Book book;
    Order order;

    // Get the current date and time
    getDaytime(order.date, order.time);

    // Get order details
    order.orderID = getOrderId();
    cout<<endl;
    cout << "Enter customer name: ";
    cin >> order.customerName;
    cout << "Enter customer Contact Number: ";
    cin >> order.contact;

    // Get book details and quantities
    int numBooks;
    cout << "Enter the number of books to order: ";
    cin >> numBooks;

    for (int i = 0; i < numBooks; ++i)
    {
        int bookID;
        cout << "Enter Book ID for book " << i + 1 << ": ";
        cin >> bookID;

        if (getBookDetails(bookID, book))
        {
            order.bookIDs.push_back(bookID);
            order.bookNames.push_back(book.bookName);

            int qty;
            cout << "Enter quantity for book " << i + 1 << ": ";
            cin >> qty;
            order.quantities.push_back(qty);

            order.totalPrice += book.price * qty;
        }
        else
        {
            cout << "Book with ID " << bookID << " not found.\n";
            return;
        }
    }

    // Save order details to file
    ofstream orderfile("Order.txt", ios::app);
    orderfile << order.orderID << " " << order.customerName << " " << order.contact << " " << order.date << " " << order.time << " "
              << order.totalPrice << " " << order.bookIDs.size() << " ";

    for (size_t i = 0; i < order.bookIDs.size(); ++i)
    {
        orderfile << order.bookIDs[i] << " " << order.bookNames[i] << " " << order.quantities[i] << " ";
    }

    orderfile << endl;
    cout<<"\033[1;32m"<< "Order placed successfully."<<"\033[0m"<<endl;
    orderfile.close();

    // Generate quotation
    Quotation quotation;
    quotation.orderID = order.orderID;
    quotation.customerName = order.customerName;
    quotation.contact = order.contact;
    quotation.bookIDs = order.bookIDs;
    quotation.bookNames = order.bookNames;
    quotation.quantities = order.quantities;
    quotation.totalPrice = order.totalPrice;
    quotation.discountedPrice = order.totalPrice - (order.totalPrice * calculateDiscount(order.totalPrice) / 100);
    quotation.date = order.date;
    quotation.time = order.time;

    // Save and print quotation
    saveQuotation(quotation);
    printQuotation(quotation);
}

// Function to view orders
void viewOrders()
{
    vector<Order> orders;
    Order temp;
    ifstream orderfile("Order.txt", ios::in);

    while (orderfile >> temp.orderID >> temp.customerName >> temp.contact >> temp.date >> temp.time >> temp.totalPrice)
    {
        orders.push_back(temp);
    }

    orderfile.close();

    if (orders.empty())
    {
        cout << "No orders available to display.\n";
    }
    else
    {
        cout << "\nOrders Details:\n";
        cout << "------------------------------------\n";

        for (const auto &order : orders)
        {
            cout << "Order ID: " << order.orderID << endl;
            cout << "Customer Name: " << order.customerName << endl;
            cout << "Contact: " << order.contact << endl;
            cout << "Date: " << order.date << endl;
            cout << "Time: " << order.time << endl;
            cout << "Total Price: " << order.totalPrice << endl;
            cout << "Books Ordered:\n";

            for (size_t i = 0; i < order.bookIDs.size(); ++i)
            {
                cout << "Book ID: " << order.bookIDs[i] << ", Book Name: " << order.bookNames[i] << ", Quantity: " << order.quantities[i] << endl;
            }

            cout << "------------------------------------\n";
        }
    }
}

// function to search order
void searchOrderAndPrintQuotation()
{
    int searchOrderId;
    cout<<endl<<endl;
    cout << "Enter Order ID to search: ";
    cin >> searchOrderId;

    Order foundOrder;
    if (getOrderDetails(searchOrderId, foundOrder))
    {
        // Display the details of the found order
        cout << "\nFound Order Details:\n";
        cout << "------------------------------------\n";
        cout << "Order ID: " << foundOrder.orderID << endl;
        cout << "Customer Name: " << foundOrder.customerName << endl;
        cout << "Contact: " << foundOrder.contact << endl;
        cout << "Date: " << foundOrder.date << endl;
        cout << "Time: " << foundOrder.time << endl;
        cout << "Total Price: " << foundOrder.totalPrice << endl;
        cout << "Books Ordered:\n";

        for (size_t i = 0; i < foundOrder.bookIDs.size(); ++i)
        {
            cout << "Book ID: " << foundOrder.bookIDs[i] << ", Book Name: " << foundOrder.bookNames[i] << ", Quantity: " << foundOrder.quantities[i] << endl;
        }

        cout << "------------------------------------\n";

        // Prompt the user to generate a quotation
        char generateQuotation;
        cout << "Do you want to generate a quotation for this order? (y/n): ";
        cin >> generateQuotation;

        if (generateQuotation == 'y' || generateQuotation == 'Y')
        {
            Quotation quotation;
            quotation.orderID = foundOrder.orderID;
            quotation.customerName = foundOrder.customerName;
            quotation.contact = foundOrder.contact;
            quotation.bookIDs = foundOrder.bookIDs;
            quotation.bookNames = foundOrder.bookNames;
            quotation.quantities = foundOrder.quantities;
            quotation.totalPrice = foundOrder.totalPrice;
            quotation.discountedPrice = foundOrder.totalPrice - (foundOrder.totalPrice * calculateDiscount(foundOrder.totalPrice) / 100);
            quotation.date = foundOrder.date;
            quotation.time = foundOrder.time;

            // Print the quotation
            system("cls");
            printQuotation(quotation);
        }
    }
    else
    {
        cout << "Order with ID " << searchOrderId << " not found.\n";
    }
}

// Function to get order details by order ID
bool getOrderDetails(int orderID, Order &order)
{
    ifstream orderfile("Order.txt", ios::in);

    while (orderfile >> order.orderID >> order.customerName >> order.contact >> order.date >> order.time >> order.totalPrice)
    {
        if (order.orderID == orderID)
        {
            int numBooks;
            orderfile >> numBooks;

            order.bookIDs.resize(numBooks);
            order.bookNames.resize(numBooks);
            order.quantities.resize(numBooks);

            for (int i = 0; i < numBooks; ++i)
            {
                orderfile >> order.bookIDs[i] >> order.bookNames[i] >> order.quantities[i];
            }

            orderfile.close();
            return true;
        }
    }

    orderfile.close();
    return false;
}

//function for edit order
void editOrder()
{
    int editOrderId;
    cout << "Enter Order ID to edit: ";
    cin >> editOrderId;

    Order foundOrder;
    bool orderFound = false;
    ifstream orderfile("Order.txt", ios::in);
    vector<Order> orders;

    while (orderfile >> foundOrder.orderID >> foundOrder.customerName >> foundOrder.contact >> foundOrder.date >> foundOrder.time >> foundOrder.totalPrice)
    {
        foundOrder.bookIDs.clear();
        foundOrder.bookNames.clear();
        foundOrder.quantities.clear();

        int numBooks;
        orderfile >> numBooks;

        for (int i = 0; i < numBooks; ++i)
        {
            int bookID, quantity;
            string bookName;

            orderfile >> bookID >> bookName >> quantity;
            foundOrder.bookIDs.push_back(bookID);
            foundOrder.bookNames.push_back(bookName);
            foundOrder.quantities.push_back(quantity);
        }

        orders.push_back(foundOrder);
    }

    orderfile.close();

    for (size_t i = 0; i < orders.size(); ++i)
    {
        if (orders[i].orderID == editOrderId)
        {
            orderFound = true;

            // Display the current order details
            cout << "\nCurrent Order Details:\n";
            cout << "------------------------------------\n";
            cout << "Order ID: " << orders[i].orderID << endl;
            cout << "Customer Name: " << orders[i].customerName << endl;
            cout << "Contact: " << orders[i].contact << endl;
            cout << "Date: " << orders[i].date << endl;
            cout << "Time: " << orders[i].time << endl;
            cout << "Total Price: " << orders[i].totalPrice << endl;
            cout << "Books Ordered:\n";

            for (size_t j = 0; j < orders[i].bookIDs.size(); ++j)
            {
                cout << "Book ID: " << orders[i].bookIDs[j] << ", Book Name: " << orders[i].bookNames[j] << ", Quantity: " << orders[i].quantities[j] << endl;
            }

            cout << "------------------------------------\n";

            // Prompt the user for edits
            cout << "\nEnter new details:\n";
            cout << "Enter customer name: ";
            cin >> orders[i].customerName;
            cout << "Enter customer contact number: ";
            cin >> orders[i].contact;

            // Get book details and quantities
            int numBooks;
            cout << "Enter the number of books to edit: ";
            cin >> numBooks;

            orders[i].bookIDs.clear();
            orders[i].bookNames.clear();
            orders[i].quantities.clear();
            orders[i].totalPrice = 0;

            for (int j = 0; j < numBooks; ++j)
            {
                int bookID;
                cout << "Enter Book ID for book " << j + 1 << ": ";
                cin >> bookID;

                Book book;

                if (getBookDetails(bookID, book))
                {
                    orders[i].bookIDs.push_back(bookID);
                    orders[i].bookNames.push_back(book.bookName);

                    int qty;
                    cout << "Enter quantity for book " << j + 1 << ": ";
                    cin >> qty;
                    orders[i].quantities.push_back(qty);

                    orders[i].totalPrice += book.price * qty;
                }
                else
                {
                    cout << "Book with ID " << bookID << " not found.\n";
                    return;
                }
            }

            // Save the edited order details to file
            ofstream orderfile("Order.txt", ios::out);

            for (const auto &order : orders)
            {
                orderfile << order.orderID << " " << order.customerName << " " << order.contact << " " << order.date << " " << order.time << " "
                          << order.totalPrice << " " << order.bookIDs.size() << " ";

                for (size_t j = 0; j < order.bookIDs.size(); ++j)
                {
                    orderfile << order.bookIDs[j] << " " << order.bookNames[j] << " " << order.quantities[j] << " ";
                }

                orderfile << endl;
            }

            orderfile.close();

            // Generate quotation
            Quotation quotation;
            quotation.orderID = orders[i].orderID;
            quotation.customerName = orders[i].customerName;
            quotation.contact = orders[i].contact;
            quotation.bookIDs = orders[i].bookIDs;
            quotation.bookNames = orders[i].bookNames;
            quotation.quantities = orders[i].quantities;
            quotation.totalPrice = orders[i].totalPrice;
            quotation.discountedPrice = orders[i].totalPrice - (orders[i].totalPrice * calculateDiscount(orders[i].totalPrice) / 100);
            quotation.date = orders[i].date;
            quotation.time = orders[i].time;

            // Save and print quotation
            saveQuotation(quotation);
            printQuotation(quotation);

            cout << "Order edited successfully.\n";
            break;
        }
    }

    if (!orderFound)
    {
        cout << "Order with ID " << editOrderId << " not found.\n";
    }
}

//function for save quotation
void saveQuotation(const Quotation &quotation)
{
    ofstream quotationFile("Quotation.txt", ios::app);
    quotationFile << quotation.orderID << " " << quotation.customerName << " " << quotation.contact << " "
                  << quotation.date << " " << quotation.time << " "
                  << quotation.totalPrice << " " << quotation.discountedPrice << " " << quotation.bookIDs.size() << " ";

    for (size_t i = 0; i < quotation.bookIDs.size(); ++i)
    {
        quotationFile << quotation.bookIDs[i] << " " << quotation.bookNames[i] << " " << quotation.quantities[i] << " ";
    }

    quotationFile << endl;

    cout<<"\033[1;32m"<<"Quotation saved successfully."<<"\033[0m"<<endl;
    quotationFile.close();
}

// function for print quotation
void printQuotation(const Quotation &quotation)
{
    cout<<endl;
    cout << "\nQuotation Details:\n";
    cout << "------------------------------------\n";
    cout << "Order ID: " << quotation.orderID << endl;
    cout << "Customer Name: " << quotation.customerName << endl;
    cout << "Contact: " << quotation.contact << endl;
    cout << "Date: " << quotation.date << endl;
    cout << "Time: " << quotation.time << endl;
    cout << "Total Price: " << quotation.totalPrice << endl;
    cout << "Discounted Price: " << quotation.discountedPrice << endl;
    cout << "Books Ordered:\n";

    for (size_t i = 0; i < quotation.bookIDs.size(); ++i)
    {
        cout << "Book ID: " << quotation.bookIDs[i] << ", Book Name: " << quotation.bookNames[i] << ", Quantity: " << quotation.quantities[i] << endl;
    }

    cout << "------------------------------------\n";
    cout << "         Thanks For Coming          \n";
}
// Function to delete a specific order
void deleteOrder()
{
    int deleteOrderId;
    cout << "Enter Order ID to delete: ";
    cin >> deleteOrderId;

    Order foundOrder;
    bool orderFound = false;
    ifstream orderfile("Order.txt", ios::in);
    vector<Order> orders;

    while (orderfile >> foundOrder.orderID >> foundOrder.customerName >> foundOrder.contact >> foundOrder.date >> foundOrder.time >> foundOrder.totalPrice)
    {
        foundOrder.bookIDs.clear();
        foundOrder.bookNames.clear();
        foundOrder.quantities.clear();

        int numBooks;
        orderfile >> numBooks;

        for (int i = 0; i < numBooks; ++i)
        {
            int bookID, quantity;
            string bookName;

            orderfile >> bookID >> bookName >> quantity;
            foundOrder.bookIDs.push_back(bookID);
            foundOrder.bookNames.push_back(bookName);
            foundOrder.quantities.push_back(quantity);
        }

        orders.push_back(foundOrder);
    }

    orderfile.close();

    for (auto it = orders.begin(); it != orders.end(); ++it)
    {
        if (it->orderID == deleteOrderId)
        {
            orderFound = true;
            orders.erase(it);

            // Update the orders file
            ofstream orderfile("Order.txt", ios::out);

            for (const auto &order : orders)
            {
                orderfile << order.orderID << " " << order.customerName << " " << order.contact << " " << order.date << " " << order.time << " "
                          << order.totalPrice << " " << order.bookIDs.size() << " ";

                for (size_t j = 0; j < order.bookIDs.size(); ++j)
                {
                    orderfile << order.bookIDs[j] << " " << order.bookNames[j] << " " << order.quantities[j] << " ";
                }

                orderfile << endl;
            }

            orderfile.close();

            cout << "Order deleted successfully.\n";
            break;
        }
    }

    if (!orderFound)
    {
        cout << "Order with ID " << deleteOrderId << " not found.\n";
    }
}
// function to delete quotation
void deleteQuotation()
{
    int deleteQuotationId;
    cout << "Enter Quotation ID to delete: ";
    cin >> deleteQuotationId;

    Quotation foundQuotation;
    bool quotationFound = false;
    ifstream quotationFile("Quotation.txt", ios::in);
    vector<Quotation> quotations;

    while (quotationFile >> foundQuotation.orderID >> foundQuotation.customerName >> foundQuotation.contact
            >> foundQuotation.date >> foundQuotation.time >> foundQuotation.totalPrice >> foundQuotation.discountedPrice)
    {
        foundQuotation.bookIDs.clear();
        foundQuotation.bookNames.clear();
        foundQuotation.quantities.clear();

        int numBooks;
        quotationFile >> numBooks;

        for (int i = 0; i < numBooks; ++i)
        {
            int bookID, quantity;
            string bookName;

            quotationFile >> bookID >> bookName >> quantity;
            foundQuotation.bookIDs.push_back(bookID);
            foundQuotation.bookNames.push_back(bookName);
            foundQuotation.quantities.push_back(quantity);
        }

        quotations.push_back(foundQuotation);
    }

    quotationFile.close();

    for (auto it = quotations.begin(); it != quotations.end(); ++it)
    {
        if (it->orderID == deleteQuotationId)
        {
            quotationFound = true;
            quotations.erase(it);

            // Update the quotations file
            ofstream quotationFile("Quotation.txt", ios::out);

            for (const auto &quotation : quotations)
            {
                quotationFile << quotation.orderID << " " << quotation.customerName << " " << quotation.contact << " "
                              << quotation.date << " " << quotation.time << " "
                              << quotation.totalPrice << " " << quotation.discountedPrice << " " << quotation.bookIDs.size() << " ";

                for (size_t j = 0; j < quotation.bookIDs.size(); ++j)
                {
                    quotationFile << quotation.bookIDs[j] << " " << quotation.bookNames[j] << " " << quotation.quantities[j] << " ";
                }

                quotationFile << endl;
            }

            quotationFile.close();

            cout << "Quotation deleted successfully.\n";
            break;
        }
    }

    if (!quotationFound)
    {
        cout << "Quotation with ID " << deleteQuotationId << " not found.\n";
    }
}

// Function to login error
void login_err()
{
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"\033[1;31m"<<"Invalid UserName or Password..!"<<"\033[0m"<<endl;
    loginPage();
}
void logout()
{
    cout<<endl;
    cout<<"\t\t\t\t\t"<<"\033[1;32m"<<"Logout Successfully.!"<<"\033[0m"<<endl;
    mainMenu();
}
void exit()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t"<<"EXITING SYSTEM....."<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t"<<"THANK YOU.!"<<endl<<endl;
}
