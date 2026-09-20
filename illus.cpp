#include <iostream>
#include <limits>   // Required for std::numeric_limits
#include <cstdint>  // Required for fixed-width types like int16_t, int64_t

int main() {
    // Set cout to print standard numbers instead of scientific notation for large values
    std::cout << std::fixed;

    std::cout << "====================================================================\n";
    std::cout << " 1. STANDARD MODIFIER COMBINATIONS\n";
    std::cout << "====================================================================\n";
    
    std::cout << "unsigned short:      " << sizeof(unsigned short) << " bytes | Max: " 
              << std::numeric_limits<unsigned short>::max() << "\n";
              
    std::cout << "long int:            " << sizeof(long int) << " bytes | Max: " 
              << std::numeric_limits<long int>::max() << "\n";
              
    std::cout << "unsigned long long:  " << sizeof(unsigned long long) << " bytes | Max: " 
              << std::numeric_limits<unsigned long long>::max() << "\n";
              
    std::cout << "long double:         " << sizeof(long double) << " bytes\n\n";


    std::cout << "====================================================================\n";
    std::cout << " 2. FIXED-WIDTH TYPES (<cstdint>)\n";
    std::cout << "====================================================================\n";
    
    std::cout << "int16_t (Short):     " << sizeof(int16_t) << " bytes | Max: " 
              << std::numeric_limits<int16_t>::max() << "\n";
              
    std::cout << "uint32_t (Long/Int): " << sizeof(uint32_t) << " bytes | Max: " 
              << std::numeric_limits<uint32_t>::max() << "\n";
              
    std::cout << "int64_t (Long Long): " << sizeof(int64_t) << " bytes | Max: " 
              << std::numeric_limits<int64_t>::max() << "\n\n";


    std::cout << "====================================================================\n";
std::cout << "====================================================================\n";
    std::cout << " 3. COMPILER-SPECIFIC EXTENSIONS (GCC / Clang)\n";
    std::cout << "====================================================================\n";
    
    // Safely check if the 128-bit integer type is actually supported by this build
    #if defined(__SIZEOF_INT128__)
        std::cout << "__int128:            " << sizeof(__int128) << " bytes\n";
        std::cout << "Note: std::cout does not natively print 128-bit numbers, \n";
        std::cout << "but this type successfully provides a 16-byte integer footprint.\n";
    #else
        std::cout << "__int128 is not supported on your current compiler architecture.\n";
        std::cout << "You are likely running MSVC, or a 32-bit build of GCC/Clang.\n";
    #endif

    std::cout << "====================================================================\n";

    std::cout << "====================================================================\n";

    return 0;
}
