// #include "ppch.h"
// #include "Core.h"

// using namespace Pandemonium::Math::Vector;
// using namespace Pandemonium::Math::Matrix;

// namespace Pandemonium {
// 	void Print() {
// 		printf("Welcome to the Pandemonium Engine!\n");
// 	}
// }

// int main() {
//     int a = 5;
// 	char* b = "BYE";

// 	ASSERT(a < 1);
// 	ASSERT(a < 1, "HELLO");
// 	ASSERT(a < 1, "HELLO %d", a);

// 	DEBUG_BREAK();

// 	LOG_DEBUG("HELLO %d %s", a, b);
// 	LOG_INFO("HELLO %d %s", a, b);
// 	LOG_WARN("HELLO %d %s", a, b);
// 	LOG_ERROR("HELLO %d %s", a, b);

//     Vector2 Vec2(3, 3);
// 	Vector2 Vec22(6, 6);
	
// 	std::cout << Vec2.Distance(Vec22) << std::endl;

// 	Matrix4x4 test = Matrix4x4::Identity();
	
// 	for (int i = 0; i < 4; i++) {
// 		for (int j = 0; j < 4; j++) {
// 			std::cout << test.Get()[i][j] << " ";
// 		}
// 		std::cout << std::endl;
// 	}
// }