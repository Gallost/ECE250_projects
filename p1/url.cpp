#include "url.h"

url::url(const std::string& name_in, const std::string& val_in)
{
	this->url_name = name_in;
	this->url_val = val_in;
	this->next = nullptr;
	this->prev = nullptr;
}

url::~url()
{
	this->url_name = "\0";
	this->url_val = "\0";
	this->next = nullptr;
	this->prev = nullptr;
}

void url::set_next(url* next_url)
{
	this->next = next_url;
}

void url::set_prev(url* prev_url)
{
	this->prev = prev_url;
}

url* url::get_next() const
{
	return this->next;
}

url* url::get_prev() const
{
	return this->prev;
}

std::string url::get_data() const
{
	return this->url_name + " " + this->url_val;
}

std::string url::get_name() const
{
	return this->url_name;
}