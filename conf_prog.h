#pragma once
#ifndef CONF_PROG_H
#define CONF_PROG_H

#include "constants.h"

struct date
{
	int hour;
	int min;
};

struct person
{
	char first_name[MAX_STRING_SIZE];
	char maddle_name[MAX_STRING_SIZE];
	char last_name[MAX_STRING_SIZE];
};

struct conf_prog
{
	person reader;
	date start;
	date finish;
	char title[MAX_STRING_SIZE];
};

#endif