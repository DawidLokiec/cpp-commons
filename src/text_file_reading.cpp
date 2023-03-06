#include "commons/text_file_reading.h"
#include <fstream>
#include <sstream>

namespace {
	void closeStreamIfOpen(std::ifstream &stream) {
		if (stream.is_open()) {
			stream.close();
		}
	}
}

[[maybe_unused]] std::string commons::io::readTextFile(const std::string &filename) {
	std::ifstream inputFileStream;
	// enable exception to let the caller know about occurred errors
	inputFileStream.exceptions(std::ifstream::failbit | std::ifstream::badbit | std::ifstream::eofbit);
	try {
		inputFileStream.open(filename);
		std::stringstream stringBuffer;
		stringBuffer << inputFileStream.rdbuf();
		closeStreamIfOpen(inputFileStream);
		return stringBuffer.str();
	} catch (const std::exception &error) {
		closeStreamIfOpen(inputFileStream);
		// rethrow
		throw error;
	}
}
