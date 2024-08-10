#include <iostream>

int inch_to_cm()
{
    const float factor = 2.54;
    float x, in, cm;
    char ch = 0;

    // this writes to x
    std::cout << "\nenter length: ";
    std::cin >> x;
    // this writes to ch
    std::cout << "\nenter unit: ";
    std::cin >> ch;

    // the floating point number
    // we can't change types so we set it to float from the start
    // reading the suffix

    switch (ch)
    {
    case 'i':
        // inch
        in = x;
        cm = x * factor;
        break;

    case 'c':
        in = x / factor;
        cm = x;
        break;

    default:
        in = cm = 0;
        break;
    }

    std::cout << in << " in = " << cm << " cm\n";
    return 1;
}

int main()
{
    int num = 0;
    // an outstream
    std::cout << "enter a number: ";
    // an instream
    std::cin >> num;

    // prints whatever number we put into num
    std::cout << num;
    inch_to_cm();
}