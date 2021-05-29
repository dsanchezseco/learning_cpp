#include <iostream>

int main(){
    int not_initialized;
    // this does a copy assignment, creates an object of type int, value 5
    // and copies to the not_initialized address
    not_initialized = 5;

    // this performs a direct initialization, for ints is the same as copy
    // for complex types it is more efficient
    int direct_init(10);

    // this is the preffered way as the direct is not supported for all the
    // data types, additionally it prevents data narrowing
    // eg: int not_allowed{4.5}; //this fails as a double does not fit in an int
    int direct_list_init{15};

    // this zero init set the var to zero or empty, the more appropiate for the
    // given data type
    int zero_init{};


    /*  to sum up is better to use the zero init when a variable is going to be
        replaced immediately after, eg:

        int x{};
        std::cin >> x;

        and use the direct list init instead of the no-init plus copy that is
        usual in other languages, eg:

        int y{4}; // instead of "int y; y = 4;"
    */

    int x;
    int y{};

    std::cout << "not initialized x variable: " << x << "\n";
    std::cout << "initialized y variable to default value: " << y << "\n";

    return 0;
}
