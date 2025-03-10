#pragma once
#include <random>

class Utils
{
public:
	template<typename T>
	static T GetRandom(T min, T max)
	{
		// 시드값
		std::random_device randomDevice;
		// 난수 생성 엔진 초기화
		std::mt19937 generator(randomDevice());
		// 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의

		if constexpr (std::is_integral_v<T>) // 컴파일 타임에 딱 만들어짐!
		{
			std::uniform_int_distribution distribution(min, max);
			return distribution(generator);
		}
		else
		{
			std::uniform_real_distribution<T> distribution(min, max);
			return distribution(generator);
		}
	}
};

