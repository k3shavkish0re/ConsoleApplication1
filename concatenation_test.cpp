//#include <systemc.h>
//
//int sc_main(int argc, char* argv[]) {
//    sc_int<1>  bit_size = 0;           // Better to use sc_bit or bool
//    sc_int<4>  nibble_size = 1;
//    sc_int<8>  byte_size = 2;
//    sc_int<32> dword_size = 3;
//
//    // Perform auto increment
//    dword_size++;
//    cout << "Value of dword_size : " << dword_size << endl;
//
//    // Terse method addition
//    byte_size += nibble_size;
//    cout << "Value of byte_size  : " << byte_size << endl;
//
//    // Bit selection
//    bit_size = dword_size[2];          // Consider using sc_bit or bool
//    cout << "Value of bit_size   : " << bit_size << endl;
//
//    // Range selection
//    nibble_size = dword_size.range(4, 1);  // Ensure selected range fits in nibble_size
//    cout << "Value of nibble_size: " << nibble_size << endl;
//
//    // Concatenated (use sc_biguint or sc_bv if necessary)
//    // dword_size = (byte_size, byte_size, byte_size, byte_size);  // This would be incorrect
//    sc_bv<32> concat_value = (sc_bv<8>(byte_size), sc_bv<8>(byte_size), sc_bv<8>(byte_size), sc_bv<8>(byte_size));
//    dword_size = concat_value.to_int();
//    cout << "Value of dword_size : " << dword_size << endl;
//
//    return 0;
//}
