#include "Book.h"

Book::Book(const string& title, const string& author)
    : title(title), author(author) {}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}
