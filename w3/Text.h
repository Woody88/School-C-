#include<iostream>
#include<string>

namespace w3{
	class Text{
		std::string* strings;
		size_t record_count; 

		public:
		Text(); 	// Default Constructor
		~Text();	// Destructor
		Text(const std::string& );		// Constructor With One Argument
		Text(const Text&);				// Copy Constructor
		Text(Text&&);					// Move Constructor
		Text& operator=(const Text&);	// Copy Assignment operator
		Text& operator=(Text&&);		// Move Assignment operator
		size_t size() const;			// Return Size Function
	};
}


