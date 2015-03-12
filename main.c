#pragma config(Sensor, in1,    powerExpander,  sensorAnalog)
#pragma config(Sensor, dgtl1,  rDriveEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  lDriveEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  rLiftEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  lLiftEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  dumpSolenoid,   sensorDigitalOut)
#pragma config(Sensor, dgtl11, liftDetectLeft, sensorTouch)
#pragma config(Sensor, dgtl12, liftDetectRight, sensorTouch)
#pragma config(Motor,  port1,           driveLB,       tmotorVex393HighSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           driveLF,       tmotorVex393HighSpeed_MC29, openLoop, encoderPort, dgtl1)
#pragma config(Motor,  port3,           driveRB,       tmotorVex393HighSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           driveRF,       tmotorVex393HighSpeed_MC29, openLoop, encoderPort, dgtl3)
#pragma config(Motor,  port5,           liftLA,        tmotorVex393_MC29, openLoop, encoderPort, dgtl5)
#pragma config(Motor,  port6,           liftLB,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           liftLC,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           liftRA,        tmotorVex393_MC29, openLoop, encoderPort, dgtl7)
#pragma config(Motor,  port9,           liftRB,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          liftRC,        tmotorVex393_HBridge, openLoop)

#pragma platform(VEX)

#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"
#include "SmartMotorLib.c"
#include "drive.c"
#include "arm.c"
#include "general.c"
#include "auton.c"

void pre_auton()
{
  init();
}

task autonomous()
{
  init();
}

task usercontrol()
{
	init();
	while (true)
	{

	}
}
