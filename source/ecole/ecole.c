#include "ecole.h"

#include <exception>
#include <algorithm>
#include <functional>

School::School(const string& name):
school_name(name)
{}

School::~School()
{
}

const SchoolClass& School::get_class(const std::string& name) const
{
	auto same_name = [name](const SchoolClass& school_class)
	{
		return school_class.get_class_name() == name;
	};
	
	auto it = std::find_if (school_classes.begin(), 
							school_classes.end(), 
							same_name);
							
	if (it == school_classes.end())
		return nullptr;
	
	return *it;
}

SchoolClass& School::get_class(const std::string& name)
{
	const School* school = const_cast<const School*>(this);
	const SchoolClass& school_class = school->get_class(name);
	return const_cast<SchoolClass&>(school_class);
}

std::list<const std::string&> School::class_names() const
{
	std::list<const std::string&> name_list;

	for (const SchoolClass& school_class : school_classes)
	{
		name_list.push_back(school_class.get_class_name());
	}
	
	return name_list;
}
	
void School::add_class(const std::string& name)
{	
	for (const SchoolClass& school_class : school_classes)
	{
		if (school_class.get_class_name() == name)
		{
			throw new std::invalid_argument("A class with the same name exists");
		}
	}
	
	school_classes.emplace_back(name);
}

void School::remove_class(const std::string& name)
{
	auto same_name = [name](const SchoolClass& school_class)
	{
		return school_class.get_class_name() == name;
	};
	
	school_classes.remove_if(same_name);
}
