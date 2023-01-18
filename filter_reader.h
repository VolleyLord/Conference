#pragma once
#ifndef FILTER_H
#define FILTER_H

#include "conf_prog.h"

conf_prog** filter(conf_prog* array[], int size, bool (*check)(conf_prog* element), int& result_size);
bool check_book_subscription_by_wind(conf_prog* element);
bool check_book_subscription_by_speed(conf_prog* element);
#endif