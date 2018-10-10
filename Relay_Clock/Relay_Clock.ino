//Time Code Generator
//https://www.w3schools.com/code/tryit.asp?filename=FVY0WEMW3RAY
//On & Off Code Generator
//https://www.w3schools.com/code/tryit.asp?filename=FVYAW7WY04J9

#include <DS3231.h>
int Relay = 13;
DS3231  rtc(SDA, SCL);
Time t;
//
//TESTER 1 BURST MORNING
//const int OnH0725 = 2;
//const int OnM0725 = 41;
//const int OffH0725 = 2;
//const int OffM0725 = 41;
////TESTER 2 BLEEP
//const int AOnH0740 = 11;
//const int AOnM0740 = 12;
//const int AOffH0740 = 11;
//const int AOffM0740 = 12;
////TESTER 1 BLEEP
//const int POnH0820 = 00;
//const int POnM0820 = 34;
//const int POffH0820 = 00;
//const int POffM0820 = 34;
////TESTER 1 BURST GO HOME
//const int AOnH1520 = 00;
//const int AOnM1520 = 35;
//const int AOffH1520 = 00;
//const int AOffM1520 = 35;
//--------------------------------

//Constant Seconds
const int OnSec = 1;
const int OffSec = 10;

//07:25 MORNING
const int OnH0725 = 7;
const int OnM0725 = 25;
const int OffH0725 = 7;
const int OffM0725 = 25;

//07:40
const int AOnH0740 = 7;
const int AOnM0740 = 40;
const int AOffH0740 = 7;
const int AOffM0740 = 40;
//08:20
const int POnH0820 = 8;
const int POnM0820 = 20;
const int POffH0820 = 8;
const int POffM0820 = 20;

//08:25
const int AOnH0825 = 8;
const int AOnM0825 = 25;
const int AOffH0825 = 8;
const int AOffM0825 = 25;
//09:00
const int POnH0900 = 9;
const int POnM0900 = 0;
const int POffH0900 = 9;
const int POffM0900 = 0;
//09:10
const int AOnH0910 = 9;
const int AOnM0910 = 10;
const int AOffH0910 = 9;
const int AOffM0910 = 10;
//09:30
const int POnH0930 = 9;
const int POnM0930 = 30;
const int POffH0930 = 9;
const int POffM0930 = 30;
//09:40
const int POnH0940 = 9;
const int POnM0940 = 40;
const int POffH0940 = 9;
const int POffM0940 = 40;
//09:55
const int AOnH0955 = 9;
const int AOnM0955 = 55;
const int AOffH0955 = 9;
const int AOffM0955 = 55;

//10:10
const int POnH1010 = 10;
const int POnM1010 = 10;
const int POffH1010 = 10;
const int POffM1010 = 10;
//10:40
const int AOnH1040 = 10;
const int AOnM1040 = 40;
const int AOffH1040 = 10;
const int AOffM1040 = 40;
//10:45
const int POnH1045 = 10;
const int POnM1045 = 45;
const int POffH1045 = 10;
const int POffM1045 = 45;
//10:50
const int POnH1050 = 10;
const int POnM1050 = 50;
const int POffH1050 = 10;
const int POffM1050 = 50;
//11:10
const int AOnH1110 = 11;
const int AOnM1110 = 10;
const int AOffH1110 = 11;
const int AOffM1110 = 10;
//11:30
const int POnH1130 = 11;
const int POnM1130 = 30;
const int POffH1130 = 11;
const int POffM1130 = 30;
//11:55
const int AOnH1155 = 11;
const int AOnM1155 = 55;
const int AOffH1155 = 11;
const int AOffM1155 = 55;
//12:10
const int POnH1210 = 12;
const int POnM1210 = 10;
const int POffH1210 = 12;
const int POffM1210 = 10;
//12:15
const int AOnH1215 = 12;
const int AOnM1215 = 15;
const int AOffH1215 = 12;
const int AOffM1215 = 15;
//12:40
const int AOnH1240 = 12;
const int AOnM1240 = 40;
const int AOffH1240 = 12;
const int AOffM1240 = 40;
//12:50
const int POnH1250 = 12;
const int POnM1250 = 50;
const int POffH1250 = 12;
const int POffM1250 = 50;
//13:00
const int AOnH1300 = 13;
const int AOnM1300 = 0;
const int AOffH1300 = 13;
const int AOffM1300 = 0;
//13:20
const int POnH1320 = 13;
const int POnM1320 = 20;
const int POffH1320 = 13;
const int POffM1320 = 20;
//13:25
const int AOnH1325 = 13;
const int AOnM1325 = 25;
const int AOffH1325 = 13;
const int AOffM1325 = 25;
//13:50
const int AOnH1350 = 13;
const int AOnM1350 = 50;
const int AOffH1350 = 13;
const int AOffM1350 = 50;
//14:00
const int POnH1400 = 14;
const int POnM1400 = 0;
const int POffH1400 = 14;
const int POffM1400 = 0;
//14:35
const int AOnH1435 = 14;
const int AOnM1435 = 35;
const int AOffH1435 = 14;
const int AOffM1435 = 35;
//--------------- Go Home ---------------
//14:40
const int AOnH1440 = 14;
const int AOnM1440 = 40;
const int AOffH1440 = 14;
const int AOffM1440 = 40;
//15:20
const int AOnH1520 = 15;
const int AOnM1520 = 20;
const int AOffH1520 = 15;
const int AOffM1520 = 20;



void setup() {
  Serial.begin(115200);
  rtc.begin();
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);
}

void loop() {
  t = rtc.getTime();
  Serial.print("Date: ");
  Serial.print(t.date, DEC);
  Serial.print(". Month: ");
  Serial.print(rtc.getMonthStr());
  Serial.print(". Year: ");
  Serial.print(t.year, DEC);
  Serial.println(".");
  Serial.print("Weekday: ");
  Serial.print(t.dow, DEC);
  Serial.print(". Hour:");
  Serial.print(t.hour, DEC);
  Serial.print(". Minute:");
  Serial.print(t.min, DEC);
  Serial.print(". Seconds:");
  Serial.print(t.sec, DEC);
  Serial.print(".");
  Serial.println("  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -  -");
  delay (1000);

  //MORNING
  if ((t.hour == OnH0725 && t.min == OnM0725) && t.sec == OnSec) {
    digitalWrite(Relay, LOW);
    Serial.println("LIGHT ON");
  } else if (t.hour == OffH0725 && t.min == OffM0725 && t.sec == OffSec) {
    digitalWrite(Relay, HIGH);
    Serial.println("LIGHT Off");
  }


  //GENERAL HOURS
  if (t.sec == OnSec) {
    if (t.hour == POnH0820 && t.min == POnM0820
       || t.hour == POnH0900 && t.min == POnM0900
       || t.hour == POnH0930 && t.min == POnM0930
       || t.hour == POnH0940 && t.min == POnM0940
       || t.hour == POnH1010 && t.min == POnM1010
       || t.hour == POnH1045 && t.min == POnM1045
       || t.hour == POnH1050 && t.min == POnM1050
       || t.hour == POnH1130 && t.min == POnM1130
       || t.hour == POnH1210 && t.min == POnM1210
       || t.hour == POnH1250 && t.min == POnM1250
       || t.hour == POnH1320 && t.min == POnM1320
       || t.hour == POnH1400 && t.min == POnM1400
  
    ) {
      digitalWrite(Relay, LOW);
      Serial.println("LIGHT ON");
      delay (1500);
      digitalWrite(Relay, HIGH);
      Serial.println("LIGHT Off");
      
    } else if (t.hour == AOnH0740 && t.min == AOnM0740
       || t.hour == AOnH0825 && t.min == AOnM0825
       || t.hour == AOnH0910 && t.min == AOnM0910
       || t.hour == AOnH0955 && t.min == AOnM0955
       || t.hour == AOnH1040 && t.min == AOnM1040
       || t.hour == AOnH1110 && t.min == AOnM1110
       || t.hour == AOnH1155 && t.min == AOnM1155
       || t.hour == AOnH1215 && t.min == AOnM1215
       || t.hour == AOnH1240 && t.min == AOnM1240
       || t.hour == AOnH1300 && t.min == AOnM1300
       || t.hour == AOnH1325 && t.min == AOnM1325
       || t.hour == AOnH1350 && t.min == AOnM1350
       || t.hour == AOnH1435 && t.min == AOnM1435
      
    ) {
      digitalWrite(Relay, LOW);
      Serial.println("LIGHT ON");
      delay (1500);
      digitalWrite(Relay, HIGH);
      Serial.println("LIGHT Off");
      delay (1500);
      digitalWrite(Relay, LOW);
      Serial.println("LIGHT ON");
      delay (1500);
      digitalWrite(Relay, HIGH);
      Serial.println("LIGHT Off");
    }
  } else if ((t.hour == AOffH0740 && t.min == AOffM0740
       || t.hour == POffH0820 && t.min == POffM0820
       || t.hour == AOffH0825 && t.min == AOffM0825
       || t.hour == POffH0900 && t.min == POffM0900
       || t.hour == AOffH0910 && t.min == AOffM0910
       || t.hour == POffH0930 && t.min == POffM0930
       || t.hour == POffH0940 && t.min == POffM0940
       || t.hour == AOffH0955 && t.min == AOffM0955
       || t.hour == POffH1010 && t.min == POffM1010
       || t.hour == AOffH1040 && t.min == AOffM1040
       || t.hour == POffH1045 && t.min == POffM1045
       || t.hour == POffH1050 && t.min == POffM1050
       || t.hour == AOffH1110 && t.min == AOffM1110
       || t.hour == POffH1130 && t.min == POffM1130
       || t.hour == AOffH1155 && t.min == AOffM1155
       || t.hour == POffH1210 && t.min == POffM1210
       || t.hour == AOffH1215 && t.min == AOffM1215
       || t.hour == AOffH1240 && t.min == AOffM1240
       || t.hour == POffH1250 && t.min == POffM1250
       || t.hour == AOffH1300 && t.min == AOffM1300
       || t.hour == POffH1320 && t.min == POffM1320
       || t.hour == AOffH1325 && t.min == AOffM1325
       || t.hour == AOffH1350 && t.min == AOffM1350
       || t.hour == POffH1400 && t.min == POffM1400
       || t.hour == AOffH1435 && t.min == AOffM1435
              ) && t.sec == OffSec) {

  }


  //GO HOME
  if (( t.hour == AOnH1440 && t.min == AOnM1440
       || t.hour == AOnH1520 && t.min == AOnM1520
     ) && t.sec == OnSec) {
    digitalWrite(Relay, LOW);
    Serial.println("LIGHT ON");
  } else if ((t.hour == AOffH1440 && t.min == AOffM1440
             || t.hour == AOffH1520 && t.min == AOffM1520
            ) && t.sec == OffSec) {
    digitalWrite(Relay, HIGH);
    Serial.println("LIGHT Off");
  }
}
