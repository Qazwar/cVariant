
/*
	Copyright 2016 Sychov Vitaliy

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

		http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*/
#include <string>
#include <vector>

#pragma once

/*
	Version:	1.0
*/
class cVariant
{
public:
	cVariant(void);
	cVariant(const cVariant &);
	cVariant(const bool);
	cVariant(const int);
	cVariant(const char);
	cVariant(const char *);
	cVariant(const double);
	cVariant(const float);
	cVariant(const long);
	cVariant(const unsigned long);
	cVariant(const std::string &);
	~cVariant(void);

	bool				GetBool() const;
	int					GetInt() const;
	char				GetChar() const;
	const char *		GetStr() const;
	double				GetDouble() const;
	float				GetFloat() const;
	long				GetLong() const;
	unsigned long		GetULong() const;
	const std::string *	GetString() const;

	cVariant & operator=(const cVariant &);
	cVariant & operator=(const bool);
	cVariant & operator=(const int);
	cVariant & operator=(const char);
	cVariant & operator=(const char *);
	cVariant & operator=(const double);
	cVariant & operator=(const float);
	cVariant & operator=(const long);
	cVariant & operator=(const unsigned long);
	cVariant & operator=(const std::string &);

private:
	std::vector<char> *var;
protected:
	int type;
};

