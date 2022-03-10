////
//// Created by avishav on 9.3.2022.
////
//#include "word.h"
//#include "ARE.h"
//
//void set_are_test();
//
//void set_opcode_test(){
//    word test_word;
//    test_word=init_word();
//    printf("testing set_opcode:\n");
//    set_data(test_word,0);
//    set_opcode(test_word,0);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,1);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,2);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,4);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,5);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,9);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,12);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,13);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,14);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_opcode(test_word,15);
//    print_word(stdout,test_word);
//}
//
//int main(){
//    word test_word,example_word;
//    int example=0x403c1;
//    test_word=init_word();
//    set_address(test_word,338);
////    print_word(stdout,test_word);
////    set_are(test_word,2);
////    print_word(stdout,test_word);
////    example_word=init_word();
////    set_data(example_word,example);
////    print_word(stdout,example_word);
////    set_data(test_word,example);
////    print_word(stdout,test_word);
//    set_data(test_word,0);
//    set_opcode_test();
//    set_are_test();
//    return 0;
//}
//
//void set_are_test() {
//    printf("\ntesting set_are:\n");
//    word test_word;
//    test_word=init_word();
//    set_are(test_word,A);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_are(test_word,E);
//    print_word(stdout,test_word);
//
//    set_data(test_word,0);
//    set_are(test_word,R);
//    print_word(stdout,test_word);
//
//}
