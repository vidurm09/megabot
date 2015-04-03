#pragma systemFile
float liftkp = 10;
float liftkd = 0;
float liftki = 0;
int liftSetPt = 0;
int prevSetPt = 0;
bool armLoop = false;

void setLiftRight(int power) {
	SetMotor(liftRA, power);
	SetMotor(liftRB, power);
	SetMotor(liftRC, power);
}

void setLiftLeft(int power) {
	SetMotor(liftLA, power);
	SetMotor(liftLB, power);
	SetMotor(liftLC, power);
}

void setLift(int power) {
	setLiftRight(power);
	setLiftLeft(power);
}

float leftLift() { return SensorValue[lLiftEncoder]; }

float rightLift() { return SensorValue[rLiftEncoder]; }

float liftAvg() { return ((leftLift() + rightLift())/2);}

task liftPID() {
	float lError = 0;
	float lPrevError = 0;
	float lIntegral = 0;
	float lDerivative = 0;
	float rError = 0;
	float rPrevError = 0;
	float rIntegral = 0;
	float rDerivative = 0;
	while(true) {
		lError = liftSetPt - leftLift();
		rError = liftSetPt - rightLift();
		lIntegral += lError;
		rIntegral += rError;
		lDerivative = lError - lPrevError;
		rDerivative = rError - rPrevError;
		setLiftLeft((liftkp*lError)+(liftki*lIntegral)+(liftkd*lDerivative));
		setLiftRight((liftkp*rError)+(liftki*rIntegral)+(liftkd*rDerivative));
		lPrevError = lError;
		rPrevError = rError;
	}
}

void startLiftPID(float kp, float kd = 0, float ki = 0) {
	liftkp = 1.8;
	liftkd = 100;
	liftki = 0.000001;
	startTask(liftPID);
}

void moveLift(int change) {
	liftSetPt += change;
}

void userControlArmPID() {
	if(vexRT[Btn6D]) {
		liftSetPt = liftAvg() - 70;
		armLoop = false;
	} else if(vexRT[Btn6U]) {
		liftSetPt = liftAvg() + 70;
		armLoop = false;
	} else {
		if(!armLoop) {
			liftSetPt = liftAvg();
			writeDebugStreamLine("Set PID to: %d, avg is at %d", liftSetPt, liftAvg());
		}
		armLoop = true;
	}
}

void userControlArmNoPID() {
	if(vexRT[Btn6D]) {
		setLift(-127);
	} else if(vexRT[Btn6U]) {
		setLift(127);
	} else {
		setLift(0);
	}
}
