#include "My_Library.h"



ostream& operator<<(ostream& os, const Book& book)
{
    os << "Book's autor     :: ";
    book.showAutor();
    cout << endl;
    os << "Book's name      :: ";
    book.showName();
    cout << endl;
    os << "Book's date      :: " << book.date_of << endl;
    os << "Book's availeble :: " << book.available << endl;
    return os;
}

void Book::showName() const
{
    for (size_t i = 0; i < SIZE; i++)
    {
        if (name[i] != '\0')
            cout << name[i];
        else return;
    }
}

void Book::showAutor() const
{
    for (size_t i = 0; i < SIZE; i++)
    {
        if (autor[i] != '\0')
            cout << autor[i];
        else return;
    }
}

string Book::getName() const
{
    return string(name);
}

string Book::getAuhor() const
{
    return string(autor);
}

void Book::setAvailable()
{
    if (this->available == 0)
        this->available = 1;
    else
        this->available = 0;
}

bool Book::getAvailable() const
{
    return this->available;
}

Date Book::getDate() const
{
    return this->date_of;
}

void Book::setName(const string& name) 
{
    for (size_t i = 0; i < SIZE; i++)
        if (i < name.size())
            this->name[i] = name[i];
        else
            this->name[i] = '\0';
}

void Book::setAuthor(const string& author)
{
    for (size_t i = 0; i < SIZE; i++)
        if (i < author.size())
            this->autor[i] = author[i];
        else
            this->autor[i] = '\0';
}

void Book::setDate(const Date& date)
{
    this->date_of = date;
}











void Library::addBook()
{
    size_t day, mon, year;
    char name[SIZE], autor[SIZE];
    cout << "Enter day :: ";
    cin >> day;
    cout << "Enter mounth :: ";
    cin >> mon;
    cout << "Enter year :: ";
    cin >> year;
    cout << "Enter author of book :: "; std::cin.ignore(); std::cin.getline(autor, SIZE);
    cout << "Enter name of book :: "; std::cin.ignore(); std::cin.getline(name, SIZE);
    Book book(day, mon, year, autor, name);
    
    lib.push_front(book);
}

void Library::print() const
{
    for (auto i : lib)
    {
        cout << i << "\t";
    }cout << endl;
}

void Library::addBook(const Book& book)
{
    lib.push_back(book);
}

void Library::search(const string& name, const string& author)
{
   /* auto it = find_if(this->lib.begin(), this->lib.end(), [name](const Book& b) { return b.getName() == name;});

    if (it == lib.end())
        cout << "-" << endl;
    else
        cout << "+" << endl;*/
    auto it = std::find_if(lib.begin(), lib.end(), [author, name](const Book& book)
        {
            return (book.getAuhor() == author and book.getName() == name);
        });

    if (it != lib.end())
    {
        cout << ":)" << endl;
    }
    else
        cout << ":(" << endl;
    
}

void Library::editBook(const string& author, const string& name)
{
    size_t day, mounth, year;
    char name_[SIZE];
    char author_[SIZE];
    auto it = std::find_if(lib.begin(), lib.end(), [author, name](const Book& book)
        {
            return (book.getAuhor() == author and book.getName() == name);
        });
    if (it == lib.end()) return;
    cout << "Enter book's name      :: "; std::cin.ignore(); std::cin.getline(name_, SIZE);
    cout << "Enter book's author    :: "; std::cin.ignore(); std::cin.getline(author_, SIZE);
    cout << "Enter book's date(day) :: ";
    cin >> day;
    cout << "Enter book's date(mounth) :: ";
    cin >> mounth;
    cout << "Enter book's date(year) :: ";
    cin >> year;
    Date date(day, mounth, year);
    (*it).setAuthor(string(author_));
    (*it).setName(string(name_));
    (*it).setDate(date);
}

void Library::searchBooks(const string& author)
{
    std::vector<Book> copy;
    std::copy_if(lib.begin(), lib.end(), std::back_inserter(copy), [author](const Book& book)
        {
            return book.getAuhor() == author;
        });
    for (size_t i = 0; i < copy.size(); i++)
    {
        cout << copy[i] << endl;
    }
}

void Library::giveBook(const string& name)
{
    auto it = std::find_if(lib.begin(), lib.end(), [name](const Book& book)
        {
            return (book.getName() == name);
        });
    if (it != lib.end())
    {
        if ((*it).getAvailable() == 0)
            (*it).setAvailable();
        else
        {
            cout << "Book absent today :(\nTry next time :)\n";
        }
    }
    else
        cout << "Do't excist this book :(" << endl;
}

void Library::takeBook(const string& name)
{
    auto it = std::find_if(lib.begin(), lib.end(), [name](const Book& book)
        {
            return (book.getName() == name);
        });
    if (it != lib.end())
    {
        if ((*it).getAvailable() == 1)
            (*it).setAvailable();
        else
        {
            cout << "Book do'n return :(\nTry next time :)\n";
        }
    }
    else
        cout << "Do't excist this book :(" << endl;
}

void Library::sortByAutorNextByName()
{
    lib.sort([](const Book& book_1, const Book& book_2) {
        return book_1.getAuhor() > book_2.getAuhor();
        });
    this->print();
    lib.sort([](const Book& book_1, const Book& book_2) {
        return book_1.getName() > book_2.getName();
        });
    this->print();
}

void Library::pop(const string& autor, const string& name, const size_t& day, const size_t& mounth, const size_t& year)
{
    Date date;
    date.setDate(day, mounth, year);
    lib.remove_if([name, autor, date](const Book& book) {return book.getAuhor() == autor and book.getName() == name and book.getDate() == date;});
}

void Library::popIndex(const size_t& index)
{
    if (lib.size() <= index or index < 0)
        return;
    auto it = lib.begin();
    advance(it, index);
    lib.erase(it);
}

void Library::writeFile()
{
    std::ofstream outputFile;
    outputFile.open("data.dat", std::ios::binary | std::ios::trunc);
    outputFile.close();

    std::fstream file("data.dat", std::ios_base::out | std::ios_base::binary);
    file.clear();
    file.seekg(0);
    for (auto i : lib)
    {
        file.write(reinterpret_cast<char*>(&i), sizeof(Book));
    }
    file.close();
}






