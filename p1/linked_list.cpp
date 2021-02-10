#include "linked_list.h"

linked_list::linked_list()
{
	this->head = nullptr;
	this->tail = nullptr;
}

linked_list::~linked_list()
{
	this->head = nullptr;
	this->tail = nullptr;
}

void linked_list::set_head(url* head_url)
{
	this->head = head_url;
}

void linked_list::set_tail(url* tail_url)
{
	this->tail = tail_url;
}

url* linked_list::get_head() const
{
	return this->head;
}

url* linked_list::get_tail() const
{
	return this->tail;
}