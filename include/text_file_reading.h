#ifndef CPP_COMMONS_TEXT_FILE_READING_H
#define CPP_COMMONS_TEXT_FILE_READING_H

#include <string>

/**
 * The namespace of the current library.
 */
namespace commons::io {

	/**
	  * @brief Reads the text file specified by the passed filename.
	  * @param filename the name of the file to read.
	  * @return the content of the file.
	  */
	[[maybe_unused]] std::string readTextFile(const std::string &filename);
}

#endif //CPP_COMMONS_TEXT_FILE_READING_H