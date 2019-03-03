#pragma once

// constexpr 쓰는 이유: 컴파일 타임에 상수인지를 체크하려고
//constexpr int itcannot_runtime_integer = temp; 
namespace constants
{
	constexpr double pi(3.141592);
	constexpr double avogadro(6.0221413e23);
	constexpr double moon_gravity(9.8 / 6.0);
}
