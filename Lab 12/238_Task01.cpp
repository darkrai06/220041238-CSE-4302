#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Book
{
    string author, ISBN, title;

public:
    Book(string t, string a, string i) : title(t), author(a), ISBN(i) {}

    string getT()const
    {
        return title;
    }

    string getA()const
    {
        return author;
    }
    string getI()const
    {
        return ISBN;
    }

    void display() const
    {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << ISBN << endl;
    }
};

class Library
{
    vector<Book> inventory;
    deque<Book> borrow;
    list<Book> archive;

public:
    void addBook(string title, string author, string ISBN)
    {
        inventory.push_back(Book(title, author, ISBN));
    }

    void borrowBook(const string& ISBN)
    {
        for (auto it = inventory.begin(); it != inventory.end(); ++it)
        {
            if (it->getI() == ISBN)
            {
                borrow.push_back(*it);
                inventory.erase(it);
                cout << "Book borrowed successfully!\n";
                return;
            }
        }
        cout << "Book not found in inventory.\n";
    }

    void returnBook(const string& ISBN)
    {
        for (auto it = borrow.begin(); it != borrow.end(); ++it)
        {
            if (it->getI() == ISBN)
            {
                inventory.push_back(*it);
                borrow.erase(it);
                cout << "Book returned successfully!\n";
                return;
            }
        }
        cout << "Book not found in borrowed list.\n";
    }

    void archiveBook(const string& ISBN)
    {
        for (auto it = inventory.begin(); it != inventory.end(); ++it)
        {
            if (it->getI() == ISBN)
            {
                archive.push_back(*it);
                inventory.erase(it);
                cout << "Book archived successfully!\n";
                return;
            }
        }
        cout << "Book not found in inventory.\n";
    }

    void displayBooks() const
    {
        cout << "\nInventory Books:\n";
        for (auto book : inventory)
            book.display();
        cout << "\nBorrowed Books:\n";
        for (auto book : borrow)
            book.display();
        cout << "\nArchived Books:\n";
        for (auto book : archive)
            book.display();
    }

    void saveData()
    {
        ofstream inv("inventory.txt");
        ofstream bor("borrowed.txt");
        ofstream arch("archived.txt");
        if (!inv.is_open() || !bor.is_open() || !arch.is_open())
        {
            cout << "Error: Unable to create/open files for saving!" << endl;
            return;
        }
        for (auto book : inventory)
            inv << book.getT() << "," << book.getA() << "," << book.getI() << "\n";
        for (auto book : borrow)
            bor << book.getT() << "," << book.getA() << "," << book.getI() << "\n";
        for (auto book : archive)
            arch << book.getT() << "," << book.getA() << "," << book.getI() << "\n";
    }

    void loadData()
    {
        ifstream inv("inventory.txt"), bor("borrowed.txt"), arch("archived.txt");
        string line, title, author, ISBN;
        while (getline(inv, line))
        {
            stringstream ss(line);
            getline(ss, title, ','); getline(ss, author, ','); getline(ss, ISBN, ',');
            inventory.push_back(Book(title, author, ISBN));
        }
        while (getline(bor, line))
        {
            stringstream ss(line);
            getline(ss, title, ','); getline(ss, author, ','); getline(ss, ISBN, ',');
            borrow.push_back(Book(title, author, ISBN));
        }
        while (getline(arch, line))
        {
            stringstream ss(line);
            getline(ss, title, ','); getline(ss, author, ','); getline(ss, ISBN, ',');
            archive.push_back(Book(title, author, ISBN));
        }
    }
};

int main()
{
    Library lib;
    int choice;
    string title, author, ISBN;
    lib.loadData();
    do {
        cout << "\nChose Your Action:\n";
        cout << "1. Add Book\n2. Borrow Book\n3. Return Book\n4. Archive Book\n5. Display Books\n6. Save and Exit\nChoice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter Title: "; getline(cin, title);
                cout << "Enter Author: "; getline(cin, author);
                cout << "Enter ISBN: "; getline(cin, ISBN);
                lib.addBook(title, author, ISBN);
                break;
            case 2:
                cout << "Enter ISBN to borrow: "; getline(cin, ISBN);
                lib.borrowBook(ISBN);
                break;
            case 3:
                cout << "Enter ISBN to return: "; getline(cin, ISBN);
                lib.returnBook(ISBN);
                break;
            case 4:
                cout << "Enter ISBN to archive: "; getline(cin, ISBN);
                lib.archiveBook(ISBN);
                break;
            case 5:
                lib.displayBooks();
                break;
            case 6:
                lib.saveData();
                cout << "Data saved. Action suspended.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);
}
