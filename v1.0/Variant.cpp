
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

#include "Variant.h"

#define FillVector(Vector,Str,StrLen)	\
	if(Vector.size() > 0)				\
	Vector.clear();						\
	for(int i = 0; i < StrLen; i++)		\
	Vector.push_back(Str[i])

#define safe_new(A,B)					\
	if(A){							\
		delete A;						\
	}else								\
		A = new std::vector<char>(B);

std::string str;

cVariant::cVariant(void)
{
	//printf("cVariant::cVariant(void)\n\n");
	var = new std::vector<char>();
}

cVariant::cVariant(const cVariant & _copy)
{
	var = new std::vector<char>(*_copy.var);
}

cVariant::cVariant(const bool value)
{
	var = new std::vector<char>();
	*this = value;
}
cVariant::cVariant(const int value)
{
	//printf("cVariant::cVariant(const int value)\n\n");
	var = new std::vector<char>();
	*this = value;
}

cVariant::cVariant(const char value)
{
	var = new std::vector<char>();
	*this = value;
}

cVariant::cVariant(const char * value)
{
	var = new std::vector<char>();
	*this = value;
}

cVariant::cVariant(const double value)
{
	var = new std::vector<char>();
	*this = value;
}
cVariant::cVariant(const float value)
{
	var = new std::vector<char>();
	*this = value;
}

cVariant::cVariant(const unsigned long value)
{
	var = new std::vector<char>();
	*this = value;
}

cVariant::cVariant(const std::string & value)
{
	var = new std::vector<char>();
	*this = value;
}

cVariant::~cVariant(void)
{
	if(var)
	{
		var->clear();
		delete var;
		var = NULL;
	}
	//printf("cVariant::~cVariant(void): %s\n\n",GetStr());
}

int	cVariant::GetInt() const
{
	int num = 0;
	try{
		sscanf_s (var->data(),"%x",&num);
	}catch(...){}
	return num;
}

char cVariant::GetChar() const
{
	try{
		return var->data()[0];
	}catch(...)
	{
		return NULL;
	}
}

double cVariant::GetDouble() const
{
	try{
		return atof(var->data());
	}catch(...)
	{
		return 0.0;
	}
}
float	cVariant::GetFloat() const
{
	try{
		return (float)atof(var->data());
	}catch(...)
	{
		return 0.0;
	}
}

/// BUGFIX: GetStr == null
const char * cVariant::GetStr() const
{

	try{
		std::string *str2 = new std::string(var->data());
		return str2->c_str();
	}catch(...)
	{
		return NULL;
	}
}

const std::string * cVariant::GetString() const
{
	try{
		FillVector(str,(*var),((int)var->size()));
		return &str;
	}catch(...)
	{
		return NULL;
	}
}

unsigned long cVariant::GetULong() const
{
	try{
		return (unsigned long) atol(var->data());
	}catch(...)
	{
		return NULL;
	}
}

cVariant & cVariant::operator=(const cVariant & obj)
{
	*var = *obj.var;
	return *this;
}
cVariant & cVariant::operator=(const bool value)
{
	if(!var)
		var = new std::vector<char>();
	char buf[64];
	_itoa_s((int)value,buf,10);
	//sprintf(buf,"%b",value);
	FillVector((*var),buf,64);
	return *this;
}
cVariant & cVariant::operator=(const int value)
{
	if(!var)
		var = new std::vector<char>();
	char buf[64];
	_itoa_s(value,buf,10);
	FillVector((*var),buf,64);
	return *this;
}
cVariant & cVariant::operator=(const char value)
{
	if(!var)
		var = new std::vector<char>();
	var->push_back(value);
	return *this;
}
cVariant & cVariant::operator=(const char * value)
{
	if(!var)
		var = new std::vector<char>();
	int len = strlen(value);
	FillVector((*var),value,len);
	var->push_back('\0');
	return *this;
}
cVariant & cVariant::operator=(const double value)
{
	if(!var)
		var = new std::vector<char>();
	char buf[64];
	sprintf_s(buf,"%f",value);
	FillVector((*var),buf,64);
	return *this;
}
cVariant & cVariant::operator=(const float value)
{
	if(!var)
		var = new std::vector<char>();
	char buf[64];
	sprintf_s(buf,"%f",value);
	FillVector((*var),buf,64);
	return *this;
}
cVariant & cVariant::operator=(const long value)
{
	if(!var)
		var = new std::vector<char>();
	char buf[64];
	_ultoa_s(value,buf,10);
	FillVector((*var),buf,64);
	return *this;
}
cVariant & cVariant::operator=(const unsigned long value)
{
	if(!var)
		var = new std::vector<char>();
	char buf[64];
	_ltoa_s(value,buf,10);
	FillVector((*var),buf,64);
	return *this;
}
cVariant & cVariant::operator=(const std::string & value)
{
	if(!var)
		var = new std::vector<char>();
	FillVector((*var),value,((int)value.length()));
	var->push_back('\0');
	return *this;
}

