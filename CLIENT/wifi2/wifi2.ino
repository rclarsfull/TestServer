#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <string.h> 

String test;
WiFiUDP Udp;
unsigned int localUdpPort = 5000;
char incomingPacket[256];
char replyPacket[] = "Hi there! Got the message :-)";
 
const char* ssid = "fritzbox-oben 2,4-GHz";
const char* password = "przybylekprzybylek";
 
void setup() {
  Serial.begin(9600);
  delay(10);
 pinMode(D2,OUTPUT);
  Serial.print("Connect to Wifi ");
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());


  Udp.begin(localUdpPort);
  
}
 
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    int packetSize = Udp.parsePacket();
if (packetSize)
{
  Serial.printf("Received %d bytes from %s, port %d\n", packetSize, Udp.remoteIP().toString().c_str(), Udp.remotePort());
  int len = Udp.read(incomingPacket, 255);
  if (len > 0)
  {
    incomingPacket[len] = '\0';
    Serial.println(incomingPacket);
    if(((String)incomingPacket)=="an"){
       Serial.println("an");
       digitalWrite(D2,LOW);
    } 
    if(((String)incomingPacket)=="aus"){
       Serial.println('0');
       digitalWrite(D2,HIGH);
    }
    
    
  }
  


}
  }
}
