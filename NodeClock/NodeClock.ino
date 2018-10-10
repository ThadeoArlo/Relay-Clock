#include <DS3231.h>
#include <ESP8266WiFi.h>
const char* ssid = "TK_Rep4"; // ssid
const char* pass = "anakpapa3";// pass
IPAddress ip(192, 168, 1, 109); //set static ip
IPAddress gateway(192, 168, 1, 1); //set getteway
IPAddress subnet(255, 255, 255, 0);//set subnet

//int Relay = LED_BUILTIN; 
int Relay = 13;
//int inPin = 2;
int stat1;

WiFiServer Server(80);

DS3231  rtc(SDA, SCL);
Time t;

void setup() {
  pinMode(Relay, OUTPUT);
//  pinMode(LED_BUILTIN, OUTPUT);
//  pinMode(inPin, INPUT);
//  digitalWrite(Relay, LOW);
  Serial.begin(115200);
  delay(10); 

  rtc.begin();
  pinMode(Relay, OUTPUT);
  digitalWrite(Relay, HIGH);

  // Connection to wireless network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.config(ip, gateway, subnet);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  server.begin();
  Serial.println("Server started");

  // Print the IP address in serial monitor. It must be the same we entered above
  Serial.print("Type this address in URL to connect: ");
  Serial.print("http://");
  Serial.println(ip);
  Serial.println("/");
}

void loop() {
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  Serial.println("new client");
  while (!client.available()) {
    delay(1);
  }
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();

  //  int stat1 = 0;
  if (request.indexOf("/Relay=on") != -1)  {
    digitalWrite(Relay, HIGH);
//    delay (5000);
//    digitalWrite(Relay, LOW);
    stat1 = 1;
  }
  if (request.indexOf("/Relay=off") != -1)  {
    digitalWrite(Relay, LOW);
    stat1 = 0;

  }

  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE html>");
  client.println("<html>");
  client.println("  <head>");
  client.println("    <meta charset=\"utf-8\">");
  client.println("    <title>HomeIot</title>");
  client.println("    <link rel=\"stylesheet\" href=\"https://raw.githubusercontent.com/ThadeoArlo/squared.css/master/squared.min.css\"/>");
  client.println("  </head>");
  client.println("  <body>");
  client.println("    <div class=\"sq-container-halfs sq-bg-gray1\">");
  client.println("      <a href=\"/Relay=on\">");
  client.println("        <div class=\"sq-card-halfs sq-card-btn sq-bg-yellow2 sq-card-padding\">");
  client.println("          <h1 class=\"sq-textcolor-white sq-undraggable\">ON</h1>");
  client.println("        </div>");
  client.println("      </a>");
  client.println("    </div>");
  client.println("    <div class=\"sq-container-halfs sq-bg-gray1\">");
  client.println("      <a href=\"/Relay=off\">");
  client.println("        <div class=\"sq-card-halfs sq-card-btn sq-bg-blue3 sq-card-padding\">");
  client.println("          <h1 class=\"sq-textcolor-white sq-undraggable\">OFF</h1>");
  client.println("        </div>");
  client.println("      </a>");
  client.println("    </div>");
  /// Relay part. GUI, etc
  client.print("Lights is now ");
  if (stat1 == 1) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<!DOCTYPE HTML>");
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");


//----------------------------------------------------


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


  
}
