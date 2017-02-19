#ifndef ECOLE_H
#define ECOLE_H

#include <ctdio>
#include <cstdlib>

#include <string>
#include <list>

#include "ecole/classe.h"

class School 
{

public:
	
	// Constructor
	School(const std::string& name);
	
	// Destructor
	~School();
	
	// Get names of all school_classes
	std::list<const std::string&> class_names() const;
	
	// Get a school class identified by name
	const SchoolClass& get_class(const std::string& name) const;
	SchoolClass& get_class(const std::string& name);
	
	// Add a school class identified by name
	void add_class(const std::string& name);
	
	// Remove the school class identified by name
	void remove_class(const std::string& name);
	
private:

	string school_name;
	std::list<SchoolClass> school_classes;
}



#endif

