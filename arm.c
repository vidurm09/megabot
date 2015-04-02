#pragma systemFile
int liftkp = 10;
int liftkd = 0;
int liftki = 0;
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

float leftLift() { return getEncoderForMotor(liftLA); }

float rightLift() { return getEncoderForMotor(liftRA); }

float liftAvg() { return ((leftLift() + rightLift())/2);}

task liftPID() {
	int lError = 0;
	int lPrevError = 0;
	int lIntegral = 0;
	int lDerivative = 0;
	int rError = 0;
	int rPrevError = 0;
	int rIntegral = 0;
	int rDerivative = 0;
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

void startLiftPID(int kp, int kd = 0, int ki = 0) {
	liftkp = kp;
	liftkd = kd;
	liftki = ki;
	startTask(liftPID);
}

void moveLift(int change) {
	liftSetPt += change;
}

void userControlArmPID() {
	if(vexRT[Btn6D]) {
		liftSetPt = liftAvg() - 40;
		armLoop = false;
	} else if(vexRT[Btn6U]) {
		liftSetPt = liftAvg() + 40;
		armLoop = false;
	} else {
		if(!armLoop) {
			liftSetPt = liftAvg();
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
		setLift(10);
	}
}
