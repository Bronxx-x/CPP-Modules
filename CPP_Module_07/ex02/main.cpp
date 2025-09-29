#include <iostream>
#include <Array.hpp>


#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << numbers[0] << " should equal " << mirror[0] << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {

        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    std::cout << "================= Custom Tests =================" << std::endl;
    std::cout << "================================================" << std::endl;    
    try {
        std::cout << "=== Test 1: Empty Array ===" << std::endl;
        Array<int> empty;
        std::cout << "Size: " << empty.getSize() << std::endl;

        std::cout << "\n=== Test 2: Array of ints ===" << std::endl;
        Array<int> numbers(5);
        for (unsigned int i = 0; i < numbers.getSize(); i++)
            numbers[i] = i * 10;
        for (unsigned int i = 0; i < numbers.getSize(); i++)
            std::cout << numbers[i] << " ";
        std::cout << std::endl;

        std::cout << "\n=== Test 3: Array of strings ===" << std::endl;
        Array<std::string> words(3);
        words[0] = "Hello";
        words[1] = "Array";
        words[2] = "World";
        for (unsigned int i = 0; i < words.getSize(); i++)
            std::cout << words[i] << " ";
        std::cout << std::endl;

        std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
        Array<std::string> copy(words);
        words[0] = "Changed";
        std::cout << "Original[0]: " << words[0] << std::endl;
        std::cout << "Copy[0]: " << copy[0] << std::endl;

        std::cout << "\n=== Test 5: Assignment operator ===" << std::endl;
        Array<int> other(2);
        other[0] = 100;
        other[1] = 200;
        numbers = other;
        std::cout << "numbers[0]: " << numbers[0] << ", numbers[1]: " << numbers[1] << std::endl;

        std::cout << "\n=== Test 6: Out of bounds access ===" << std::endl;
        std::cout << numbers[10] << std::endl;  // should throw
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}