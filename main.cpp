//
//  main.cpp
//  Bookstore Management System
//

#include <iostream>
#include <string.h>
using namespace std;

// ----------------------------------------------------------------------- //
// DATE CLASS //
// ----------------------------------------------------------------------- //
class Date
{
private:
    int month;
    int day;
    int year;
    
public:
    // Regular Constructor
    Date(int month, int day, int year)
    {
        this -> month = month;
        this -> day = day;
        this -> year = year;
    }
    
    // Destructor
    ~Date()
    {
        
    }
    
    // output()
    void output()
    {
        // * Note - User enters in this format: MM / YY / DDDD.
        cout << month << " / " << day << " / "<< year;
    }
};


// ----------------------------------------------------------------------- //
// BOOK CLASS //
// ----------------------------------------------------------------------- //
class Book
{
private:
    char *title;
    char *author;
    char *bookID;
    int *available;
    double *price;
    Date *publishDate;
    
public:
    
    // Regular Constructor
    Book(char author[99], char title[99], char bookID[], int available, double price, Date publishDate)
    {
        this -> author = author;
        this -> title = title;
        this -> bookID = bookID;
        this -> available = &available;
        this -> price = &price;
        this -> publishDate = &publishDate;
    }
    
    // Copy Constructor
    // *Note - aB = ALL books.
    Book(const Book& aB)
    {
        author = aB.author;
        title = aB.title;
        bookID = aB.bookID;
        available = aB.available;
        price = aB.price;
        publishDate = aB.publishDate;
    }
    
    // Deconstructor
    ~Book()
    {
        
    }
    
    // Default Constructor
    Book()
    {
        author= new char[99];
        title= new char[99];
        bookID = new char[99];
        price = new double;
        available = new int;
    }
    
    // Virtual Void Function
    virtual void print() const
    {
        std::cout << endl;
    }
    
    // Void Functions
    void addBook();
    void deleteBook();
    void modifyBook();
    void displayBook();
    void purchaseBook();
    
    // Int Function
    int bookSearch(char[]);
    
};

// Add book [Input book ID, title, author, publishing date, price, and availability]
void Book::addBook()
{
    cin.ignore();
    cout << "Input book ID ~ ";
    cin.getline(bookID,99);
    
    cout << "Input title ~ ";
    cin.getline(title,99);
    
    cout << "Input author ~ ";
    cin.getline(author,99);
    
    cout << "Input publishing date (in this format - MM DD YYYY) ~ ";
    int month;
    int day;
    int year;
    cin >> month >> day >> year;
    publishDate = new Date(month,day,year);
    
    cout << "Input price ~ ";
    cin >> *price;
    
    cout << "Input availability ~ ";
    cin >> *available;
}

// Delete book [Inputs book ID]
void Book::deleteBook()
{
    cin.ignore();
    cout << "Input book ID ~  ";
    cin.getline(bookID,99);
}

// Modifies book [Input title, author, publishing date, price, and availability]
void Book::modifyBook()
{
    cout << endl;
    cout << "Input title ~ ";
    cin.getline(title,99);
    
    cout << "Input author ~ ";
    cin.getline(author,99);
    
    cout << "Input publishing date (in this format - MM DD YYYY) ~ ";
    int month;
    int day;
    int year;
    cin >> month >> day >> year;
    publishDate = new Date(month,day,year);
    
    cout << "Input price ~ ";
    cin >> *price;
    
    cout << "Input availability ~ ";
    cin >> *available;
    
}

// Displays book [Title, author, publishing date, price, and # available]
void Book::displayBook()
{
    cout << "Title ~ " << title << endl;
    
    cout << "Author ~ "<< author << endl;
    
    cout << "Publish date ~ ";
    publishDate -> output();
    cout << endl;
    
    cout << "Price ~ "<< *price;
    cout << endl;
    
    cout << "Amount available ~ "<< *available;
    cout << endl;
}

// Searches book
int Book::bookSearch(char idbuy[99])
{
    if(strcmp(idbuy,bookID)==0)
        return 1;
    else return 0;
}

// Book purchase [int num & *available]
void Book::purchaseBook()
{
    int num;
    cout << "How many books would you like to purchase?: ";
    cin >> num;
    
    if(num <= *available)
    {
        *available = *available-num;
        cout << endl;
        cout << "Thank you for your purchase!";
        cout << endl;
        cout << "Total Price: $" << (*price) * num;
    }
    else
        cout << "The book is not available!";
}

// ----------------------------------------------------------------------- //
// FICTIONAL CLASS //
// ----------------------------------------------------------------------- //
class Fictional : public Book
{
private:
    int FicDiscount;
    
public:
    // Regular Constructor
    Fictional(int FicDiscount)
    {
        this -> FicDiscount = FicDiscount;
    }
    
    // Destructor
    ~Fictional()
    {
        
    }
    
    // print()
    void print()
    {
        Book::print();
        cout << "★★★★★★★★ Fiction book discount is currently " << FicDiscount << "% OFF ★★★★★★★★" << endl;
    }
    
};

// ----------------------------------------------------------------------- //
// NON-FICTIONAL CLASS //
// ----------------------------------------------------------------------- //
class nonFictional : public Book
{
private:
    int nonFicDiscount;
    
public:
    // Regular Constructor
    nonFictional(int nonFicDiscount)
    {
        this -> nonFicDiscount = nonFicDiscount;
    }
    
    // Destructor
    ~nonFictional()
    {
        
    }
    
    // print()
    void print()
    {
        Book::print();
        cout << "★★★★★★★★ Non Fiction book discount is currently " << nonFicDiscount << "% OFF ★★★★★★★★" << endl;
    }
    
};

// ----------------------------------------------------------------------- //
// CATALOG CLASS //
// ----------------------------------------------------------------------- //
class Catalog
{
private:
    // Array to store 200 books.
    Book *book[200];
    int x;
    int y = 0;
    int option;
    char idPurchase[99];
    
public:
    // Default Constructor
    Catalog()
    {
        
    }
    
    // Destructor
    ~Catalog()
    {
        delete *book;
    }
    
    // Catalog Main Menu
    void mainMenu()
    {
        bool finished = false;
        while(!finished)
        {
            cout << endl;
            cout << "------------------" << endl;
            cout << "  ~ MENU MENU ~     "     << endl;
            cout << "------------------" << endl;
            cout << "[0] Add Book" << endl;
            cout << "[1] Delete Book" << endl;
            cout << "[2] Purchase Book" << endl;
            cout << "[3] Search For Book" << endl;
            cout << "[4] Modify Book Info" << endl;
            cout << "[5] Exit" << endl << endl;
            
            cout << "Please select an option ~ ";
            cin >> option;
            
            cout << endl;
            
            switch(option)
            {
                    // Adds Book.
                case 0:
                    book[y] = new Book;
                    book[y] -> addBook();
                    y++; break;
                    
                    // Deletes book.
                case 1:
                    book[y] = new Book;
                    book[y] -> deleteBook();
                    y--;
                    cout << "Book is now removed from store!";
                    
                    break;
                    
                    // Purchases book.
                case 2:
                    cin.ignore();
                    cout << "Input book ID ~ ";
                    cin.getline(idPurchase,99);
                    for(x=0;x<y;x++)
                    {
                        if(book[x] -> bookSearch(idPurchase))
                        {
                            book[x] -> purchaseBook();
                            break;
                        }
                    }
                    if(x==1)
                        cout << "Book is not available."; break;
                    
                    // Searches book.
                case 3:
                    cin.ignore();
                    cout << "Book ID ~ "; cin.getline(idPurchase,99);
                    
                    for(x=0;x<y;x++)
                    {
                        if(book[x] -> bookSearch(idPurchase))
                        {
                            cout << "Book Availability & Info" << endl;
                            cout << "-------------------------" << endl;
                            book[x] -> displayBook(); break;
                        }
                    }
                    if(x==y)
                        cout << "Book is not available." << endl;
                    
                    break;
                    
                    // Modifies book information.
                case 4:
                    cin.ignore();
                    cout << "Book ID ~ ";
                    cin.getline(idPurchase,99);
                    
                    for(x=0;x<y;x++)
                    {
                        if(book[x] -> bookSearch(idPurchase))
                        {
                            cout << "Book is available!" << endl;
                            book[x] -> modifyBook(); break;
                        }
                    }
                    if(x==y)
                        cout << "Book is not available." << endl;
                    
                    break;
                    
                    // Exit program/store.
                case 5:
                    exit(0);
                default: cout << "Wrong option, please input number 1 - 5." << endl;
                    
                    
            }
        }
        
    }
    
    
};


int main()
{
    nonFictional book1(25);
    book1.print();
    
    Fictional book2(30);
    book2.print();
    
    Catalog Store;
    Store.mainMenu();
    
}

