#pragma systemFile

void auton()
{
	startDrivePID(5);
	skyControl(true);
	moveLift(300);
	changeDrive(-1000);
	moveLift(-300);
	skyControl(true);
}
