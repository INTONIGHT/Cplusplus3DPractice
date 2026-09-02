#include "All.h"


int main() {
	//can add debug points to various points by just adding a debug point to the left hand side can press F10 or continue
	try {
		dx3d::Game game({dx3d::Logger::LogLevel::Info});
		game.run();
	}
	catch (const std::runtime_error&) {
		return EXIT_FAILURE;
	}
	//catch any generic exceptions
	catch (const std::exception&) {
		return EXIT_FAILURE;
	}
	//catch all handler
	catch (...) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}