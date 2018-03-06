#pragma once
#include "stdafx.h"

namespace motor {
	class Motor_Data {
	private:
		//���[�^�ɓ��͂����pwm�̐ݒ�
		constexpr static int pwm_Resolution = 1024;
		constexpr static int motor_Absolute_PWMLimit = 1024; //���p�����[�^

		//RE35���[�^�̃f�[�^
		constexpr static double motor_Power_supply = 24.0;
		constexpr static double motor_Ratio = 18.0; //���p�����[�^
		constexpr static double motor_Speed_constant = 491.0; //RE35���p�����[�^(rpm/V)
		constexpr static double motor_Terminal_resistance = 0.313; //RE35���p�����[�^(��)
		constexpr static double motor_Nominal_current = 4.0; //RE35���p�����[�^(A)
		constexpr static double motor_Nominal_speed = 6500; //RE35���p�����[�^(rpm)
		
		//�G���R�[�_�̃f�[�^
		constexpr static long encoder_resolution = 500;

	};

} // namespace motor