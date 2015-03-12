#pragma systemFile
int drivekp = 0;
int drivekd = 0;
int driveki = 0;
int driveLSetPt = 0;
int driveRSetPt = 0;

void setDriveRight(int power) {
	SetMotor(driveRF, power);
}

void setDriveLeft(int power) {
	SetMotor(driveLF, power);
}

void setDrive(int power) {
	setDriveRight(power);
	setDriveLeft(power);
}

float leftDrive() { return getEncoderForMotor(driveLF); }

float rightDrive() { return getEncoderForMotor(driveRF); }

task drivePID() {
	int lError = 0;
	int lPrevError = 0;
	int lIntegral = 0;
	int lDerivative = 0;
	int rError = 0;
	int rPrevError = 0;
	int rIntegral = 0;
	int rDerivative = 0;
	while(true) {
		lError = driveLSetPt - leftdrive();
		rError = driveRSetPt - leftdrive();
		lIntegral += lError;
		rIntegral += rError;
		lDerivative = lError - lPrevError;
		rDerivative = rError - rPrevError;
		setDriveLeft((drivekp*lError)+(driveki*lIntegral)+(drivekd*lDerivative));
		setDriveRight((drivekp*rError)+(driveki*rIntegral)+(drivekd*rDerivative));
		lPrevError = lError;
		rPrevError = rError;
	}
}

void startDrivePID(int kp, int kd = 0, int ki = 0) {
	drivekp = kp;
	drivekd = kd;
	driveki = ki;
	startTask(drivePID);
}

void changeLDrive(int change) {
	driveLSetPt += change;
}

void changeRDrive(int change) {
	driveRSetPt += change;
}
