#include <gtest/gtest.h>
#include "text_file_reading.h"
#include "config.h"

TEST(IOTest, ShouldReadATextFileProperly) {
	const std::string expectedText =
			R"(Lorem ipsum dolor sit amet, consetetur sadipscing elitr, sed diam nonumy eirmod tempor invidunt ut labore et dolore
magna aliquyam erat, sed diam voluptua.

Duis autem vel eum iriure dolor in hendrerit in vulputate velit esse molestie consequat, vel illum dolore eu feugiat
nulla facilisis at vero eros et accumsan et iusto odio dignissim qui blandit praesent luptatum zzril delenit augue duis
dolore te feugait nulla facilisi.)";

	const std::string actualValue = commons::io::readTextFile(TEST_RESOURCES_FOLDER_PATH"/test.txt");

	ASSERT_EQ(expectedText, actualValue);

	ASSERT_EQ("", commons::io::readTextFile(TEST_RESOURCES_FOLDER_PATH"/empty.txt"));

	// Just for test coverage
	const std::string wrongFilename = "no.exist";
	EXPECT_THROW(commons::io::readTextFile(wrongFilename), std::exception);
}
