#pragma once
#include<string>
class Om {
protected:
	std::string m_nume;
	std::string m_prenume;
	int m_varsta;
	std::string m_email;
	const int m_id;
	static int m_next_id;
public:
	virtual ~Om() = default;
	Om();
	std::string GetNume() const;
	std::string GetPrenume() const;
	int GetVarsta() const;
	std::string GetEmail() const;
};
