#include <iostream>
#include <cd-linearlist.h>

std::string
    data[] = {"Penguins","Panthers","Bulldogs","Quakers","Cardinals"}; // NOLINT(cert-err58-cpp)
int
    positions[] = {0,1,0,3,2};

// a useful little kludge, gets the number of elements in an initialized array
const int NUM_ELEMENTS = sizeof(positions) / sizeof(positions[0]);

void display(std::string &s) {
    std::cout << s << ' ';
}

void flipCase(std::string &s) {

    if (isupper(s[0]))
        for (char & i : s)
            i = (char)tolower(i);
    else
        for (char & i : s)
            i = (char)toupper(i);
}

int main() {
    CDLinearList<std::string>
        myList;

    // add elements to the list in some arbitrary order
    for (int i=0;i<NUM_ELEMENTS;i++)
        myList.insert(positions[i],data[i]);

    // display all elements of the list
    myList.map(display);
    std::cout << std::endl;

    // use the cursor to display the list
    myList.first();
    std::cout << myList.cur();
    do {
        myList.next();
        std::cout << ' ' << myList.cur();
    } while (!myList.isLast());
    std::cout << std::endl;

    // use the cursor to display the list backward
    myList.last();
    std::cout << myList.cur();
    do {
        myList.previous();
        std::cout << ' ' << myList.cur();
    } while (!myList.isFirst());
    std::cout << std::endl;

    // change the case of all letters and redisplay... twice
    myList.map(flipCase);
    myList.map(display);
    std::cout << std::endl;

    myList.map(flipCase);
    myList.map(display);
    std::cout << std::endl;

    // display the list in reverse order
    for (int i=0;i<NUM_ELEMENTS;i++)
        std::cout << myList[4-i] << ' ';
    std::cout << std::endl;

    // display the list in reverse order using negative indexing
    for (int i=-1;i>=-NUM_ELEMENTS;i--)
        std::cout << myList[i] << ' ';
    std::cout << std::endl;

    std::cout << "Number of elements: " << myList.size() << std::endl;

    // searches
    try {
        std::cout << "Found in position " << myList.search("PENGUINS")
            << std::endl;
    } catch (std::domain_error &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "Found in position " << myList.search("Panthers")
                  << std::endl;
    } catch (std::domain_error &e) {
        std::cout << e.what() << std::endl;
    }

    // remove some elements
    myList.remove(0);
    myList.remove(2);
    myList.remove(-2);

    // change a list element
    myList[0] = "Penguins";

    // add an element using negative indexing
    myList.insert(-1,"Squids");
    myList.insert(-3,"Octopodes"); // "octopi" is incorrect plural

    myList.map(display);
    std::cout << std::endl;

    std::cout << "List empty: " << (myList.isEmpty() ? "yes" : "no") << std::endl;

    // clear the list
    myList.clear();

    std::cout << "List empty: " << (myList.isEmpty() ? "yes" : "no") << std::endl;

    myList.map(display);
    std::cout << std::endl;

    return 0;
}
