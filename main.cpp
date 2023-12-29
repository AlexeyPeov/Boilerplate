#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <assert.h>

void find_and_replace_each(
    std::string& from, 
    std::string replace_what, 
    std::string replace_with
)
{   
    size_t start_pos = 0;
    size_t what_size = replace_what.size();
    size_t with_size = replace_with.size();

    while((start_pos = from.find(replace_what, start_pos)) != std::string::npos) {
        from.replace(start_pos, what_size, replace_with);
        start_pos += with_size;
    }
}

std::string prettyfy_header(std::string class_header){
    for(auto it = std::next(class_header.begin()); it != class_header.end();){
        char up = std::toupper(*it);

        bool first = up == *it && up != '_';
        bool second = 
            std::next(it) != class_header.end() && 
            std::toupper(*std::next(it)) != *std::next(it); 

        if(first && second){
            it = class_header.insert(it, '_');
            it+=2;
        }
        else {
            it+=1;
        }
    }
    
    std::transform(
        class_header.begin(), 
        class_header.end(), 
        class_header.begin(), 
        [](char c){ 
            return std::toupper(c); 
        }
    );

    return class_header;
}



int main(int argc, char** argv){

    assert(argc == 2);
    
    std::string class_name = argv[1];

    std::ifstream input_header("boilerplate_header.txt");
    std::ifstream input_cpp("boilerplate_cpp.txt");

    std::string input_header_string(
        (std::istreambuf_iterator<char>(input_header)), 
        std::istreambuf_iterator<char>()
    );

    std::string input_cpp_string(
        (std::istreambuf_iterator<char>(input_cpp)), 
        std::istreambuf_iterator<char>()
    );

    std::ofstream output_header(std::string(class_name + ".h").c_str());
    std::ofstream output_cpp(std::string(class_name + ".cpp").c_str());

    std::ostream_iterator<char> ofs_iter_header{output_header};
    std::ostream_iterator<char> ofs_iter_cpp{output_cpp};

    std::string class_header = prettyfy_header(class_name);

    find_and_replace_each(input_header_string, "CLASS_NAME", class_header);
    find_and_replace_each(input_header_string, "class_name", class_name);
    find_and_replace_each(input_cpp_string, "class_name", class_name);


    copy(input_header_string.begin(), input_header_string.end(), ofs_iter_header);
    copy(input_cpp_string.begin(), input_cpp_string.end(), ofs_iter_cpp);

    return 0;
}
