#pragma systemFile
bool hasInit = false;
void init() {
	if(!hasInit) {
		SmartMotorsInit();
		//SmartMotorsAddPowerExtender(liftLB, liftLC, liftRB, liftRC);
		//SmartMotorSetPowerExpanderStatusPort(powerExpander);
		SmartMotorLinkMotors(driveLF, driveLB);
		SmartMotorLinkMotors(driveRF, driveRB);
		SmartMotorLinkMotors(liftLA, liftLB);
		SmartMotorLinkMotors(liftLA, liftLC);
		SmartMotorLinkMotors(liftRA, liftRB);
		SmartMotorLinkMotors(liftRA, liftRC);
		//SmartMotorCurrentMonitorEnable();
		SmartMotorsSetEncoderGearing(liftLA, 1.0/3.0);
		SmartMotorsSetEncoderGearing(liftLB, 1.0/3.0);
		SmartMotorsSetEncoderGearing(liftLC, 1.0/3.0);
		SmartMotorsSetEncoderGearing(liftRA, 1.0/3.0);
		SmartMotorsSetEncoderGearing(liftRB, 1.0/3.0);
		SmartMotorsSetEncoderGearing(liftRC, 1.0/3.0);
		SmartMotorRun();
		startLiftPID(10);
		hasInit = true;
	}
}

void userControl(bool isArcade, bool isArmPID) {
	if(isArcade) {
		arcade();
	} else {
		tank();
	}
	if(isArmPID) {
		userControlArmPID();
	} else {
		stopTask(liftPID);
		userControlArmPID();
	}
}
