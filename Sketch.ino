int trigger = 4;
int qLeft = A0;
int qBottom = A1;

int St0 = 0;
int St1 = 0;

void setup(){
	pinMode(trigger, OUTPUT);
	Serial.begin(9600);
}

int Random(){
	// Generate pulse
	digitalWrite(trigger, HIGH);
	delay(300);
	digitalWrite(trigger, LOW);

	//read pulse
	St0 = analogRead(qLeft);
	St1 = analogRead(qBottom);

	// more "photons" on left sensor
	if(St0 > St1){
		return 0;
	} if(St0 < St1) { //more "photons" on bottom sensor
		return 1;
	}else{ // par
		Random();
	}

	delay(300);
}

void loop() {
	Serial.println(Random());
}
	
