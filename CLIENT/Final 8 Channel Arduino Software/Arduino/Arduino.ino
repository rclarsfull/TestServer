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

const String an="HIGH";
const String aus="LOW";
 
void setup() {
  Serial.begin(9600);
  delay(10);
  
 pinMode(D1,OUTPUT);
 pinMode(D2,OUTPUT);
 pinMode(D3,OUTPUT);
 pinMode(D4,OUTPUT);
 pinMode(D5,OUTPUT);
 pinMode(D6,OUTPUT);
 pinMode(D7,OUTPUT);
 pinMode(D8,OUTPUT);

 
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
    
    if(((String)incomingPacket)=="1"+aus){
       Serial.println("1-"+aus);
       digitalWrite(D1,LOW);
    } 
    if(((String)incomingPacket)=="1"+an){
       Serial.println("1-"+an);
       digitalWrite(D1,HIGH);
    }
    
    if(((String)incomingPacket)=="2"+aus){
       Serial.println("2-"+aus);
       digitalWrite(D2,LOW);
    } 
    if(((String)incomingPacket)=="2"+an){
       Serial.println("2-"+an);
       digitalWrite(D2,HIGH);
    }
    
    if(((String)incomingPacket)=="3"+aus){
       Serial.println("3-"+aus);
       digitalWrite(D3,LOW);
    } 
    if(((String)incomingPacket)=="3"+an){
       Serial.println("3-"+an);
       digitalWrite(D3,HIGH);
    }
    
    if(((String)incomingPacket)=="4"+aus){
       Serial.println("4-"+aus);
       digitalWrite(D4,LOW);
    } 
    if(((String)incomingPacket)=="4"+an){
       Serial.println("4-"+an);
       digitalWrite(D4,HIGH);
    }
    
    if(((String)incomingPacket)=="5"+aus){
       Serial.println("5-"+aus);
       digitalWrite(D5,LOW);
    } 
    if(((String)incomingPacket)=="5"+an){
       Serial.println("5-"+an);
       digitalWrite(D5,HIGH);
    }
    
    if(((String)incomingPacket)=="6"+aus){
       Serial.println("6-"+aus);
       digitalWrite(D6,LOW);
    } 
    if(((String)incomingPacket)=="6"+an){
       Serial.println("6-"+an);
       digitalWrite(D6,HIGH);
    }
    
    if(((String)incomingPacket)=="7"+aus){
       Serial.println("7-"+aus);
       digitalWrite(D7,LOW);
    } 
    if(((String)incomingPacket)=="7"+an){
       Serial.println("7-"+an);
       digitalWrite(D7,HIGH);
    }

    if(((String)incomingPacket)=="E"+aus){
       Serial.println("Fehler-"+aus);
       digitalWrite(D8,LOW);
    } 
    if(((String)incomingPacket)=="E"+an){
       Serial.println("Fehler-"+an);
       digitalWrite(D8,HIGH);
    }
   
    
    
    
  }
  


}
  }
}
