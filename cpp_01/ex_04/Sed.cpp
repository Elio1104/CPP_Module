#include "Sed.hpp"

Sed::Sed(std::string filename) : _inFile(filename)
{
	this->_outFile = this->_inFile + ".replace";
}

Sed::~Sed() {

}

void Sed::replace(std::string s1, std::string s2) {
	std::ifstream	ifs(this->_inFile);
	if (ifs.is_open()) {
		std::string content;
		if (std::getline(ifs, content, '\0')) {
			std::ofstream ofs(this->_outFile);
			size_t pos = content.find(s1);
			while (pos != std::string::npos) {
				content.erase(pos, s1.length());
				content.insert(pos, s2);
				pos = content.find(s1);
			}
			ofs << content;
			ofs.close();
		} else {
			std::cerr << "File is empty." << std::endl;
		}
		ifs.close();
	} else {
		std::cerr << "Unable to open file." << std::endl;
	}
}