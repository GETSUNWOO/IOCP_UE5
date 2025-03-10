#pragma once
#include <random>

class Utils
{
public:
	template<typename T>
	static T GetRandom(T min, T max)
	{
		// �õ尪
		std::random_device randomDevice;
		// ���� ���� ���� �ʱ�ȭ
		std::mt19937 generator(randomDevice());
		// �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����

		if constexpr (std::is_integral_v<T>) // ������ Ÿ�ӿ� �� �������!
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

