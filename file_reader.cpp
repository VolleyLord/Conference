#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include<cstring>


date convert(char* str)
{
    date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.min = atoi(str_number);

    return result;
}


void read(const char* file_name, conf_prog* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            conf_prog* item = new conf_prog;


            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->finish = convert(tmp_buffer);
            file >> item->reader.first_name;
            file >> item->reader.maddle_name;
            file >> item->reader.last_name;

            file.read(tmp_buffer, 1);
            file.getline(item->title, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Error open file";
    }

}