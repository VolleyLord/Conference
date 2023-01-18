#include "file_reader.h"
#include <cstring>
#include <iostream>

conf_prog** filter(conf_prog* array[], int size, bool (*check)(conf_prog* element), int& result_size)
{
	conf_prog** result = new conf_prog * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_book_subscription_by_wind(conf_prog* element)
{

	return strcmp(element->reader.first_name, "Иванов") == 0 &&
		strcmp(element->reader.maddle_name, "Иван") == 0 &&
		strcmp(element->reader.last_name, "Иванович") == 0;


}

bool check_book_subscription_by_speed(conf_prog* element)
{
	return element->finish.min - element->start.min >= 15;
}