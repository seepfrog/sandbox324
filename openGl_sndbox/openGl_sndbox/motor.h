#pragma once
#include "stdafx.h"

namespace motor {
	class Motor_Data {
	private:
		//モータに入力されるpwmの設定
		constexpr static int pwm_Resolution = 1024;
		constexpr static int motor_Absolute_PWMLimit = 1024; //仮パラメータ

		//RE35モータのデータ
		constexpr static double motor_Power_supply = 24.0;
		constexpr static double motor_Ratio = 18.0; //仮パラメータ
		constexpr static double motor_Speed_constant = 491.0; //RE35仮パラメータ(rpm/V)
		constexpr static double motor_Terminal_resistance = 0.313; //RE35仮パラメータ(Ω)
		constexpr static double motor_Nominal_current = 4.0; //RE35仮パラメータ(A)
		constexpr static double motor_Nominal_speed = 6500; //RE35仮パラメータ(rpm)
		
		//エンコーダのデータ
		constexpr static long encoder_resolution = 500;

	};

} // namespace motor