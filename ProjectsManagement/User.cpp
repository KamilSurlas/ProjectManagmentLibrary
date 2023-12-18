#include "User.h"

//Public
void User::setName(const string& newName)
{
}

void User::setPhoneNumber(const string& newPhoneNumber)
{
	isValidPhoneNumber(newPhoneNumber) ?
		m_phoneNumber = newPhoneNumber : throw invalid_argument("Wrong number");
}


//Private
bool User::isValidPhoneNumber(const string& phoneNumber)
{
	//Check if phone number has the correct length and contains only digits
	return phoneNumber.length() == 9 && phoneNumber.find_first_not_of("0123456789") == string::npos;
}

bool User::isValidName(const string& name)
{
	// Check if the name contains only letters (including characters like œæ) 
	// and has a length between 2 and 30 characters.
	string pattern = "\\p{L}{2,30}$";
	const regex nameRegex(pattern);

	return regex_match(name, nameRegex);
}
