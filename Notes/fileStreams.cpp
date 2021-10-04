// Streams: line of cars
// An input stream is a source of data
// An output stream is a destination of data

#include <iostream>
#include <ofstream> //output file stream
#include <fstream>  //for input and output of binary files

ifstream in_file;
in_file.open("input.txt"); //or ifstream in_file("input.txt");