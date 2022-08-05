#include <iostream>
#include <memory.h>
#include "sharedPtr.h"

int main(int argc, char *argv[])
{
    int x = 7;
    int * ptr = &x;
//    std::cout << "* ptr: " << * ptr << std::endl
//              << "ptr: " << ptr << std::endl
//              << "& ptr: " << & ptr << std::endl;
//    SharedPtr<int> sptr(ptr);
//    SharedPtr<int> sptr2(ptr);
//    std::cout << std::boolalpha
//              << "Shared pointer 1 exists: " << sptr.exists() << std::endl
//              << "Shared pointer 1: " << sptr.getPtr() << "; ptr: " << ptr << std::endl
//              << "Shared pointer 1 value: " << * sptr << std::endl
//              << "Shared pointer 2 exists: " << sptr2.exists() << std::endl
//              << "Shared pointer 1 is stored in: " << & sptr << std::endl
//              << "initial pointer exists: " << ((ptr == nullptr) ? "false" : "true") << std::endl;
//    SharedPtr<int> sptr3(sptr);
//    std::cout << std::boolalpha
//              << "Shared pointer 3 exists: " << sptr.exists() << std::endl
//              << "Shared pointer 3 value: " << * sptr << std::endl
//              << "Shared pointer 1 exists: " << sptr.exists() << std::endl
//              << "Shared pointer 1 value: " << * sptr << std::endl;

//    std::pair<int, std::string> p = {5,"abc"};
//    auto & [a, b] = p;
//    std::cout<< a << ' ' << b << std::endl;

    std::shared_ptr<int> sptr = std::make_shared<int>(* ptr);
    auto sptr2 = sptr;


//    std::shared_ptr<int> sptr(new int(3));
    std::cout << * sptr << std::endl;
//    std::cout << * ptr << std::endl;


}
