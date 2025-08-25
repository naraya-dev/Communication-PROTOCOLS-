#include <ESP8266WiFi.h>  
#include <WiFiUdp.h>  
#define SOCKET 8888  // define udp port   
#define BUFFERLEN 255  // length of buffer   
//=======include DHT SENSOR===========  
#include <dht11.h>  
#define DHT11PIN 0  
dht11 DHT11;  
//========================  
char inBUFFER[BUFFERLEN];   // for storing receiving packet  
char outBUFFER[BUFFERLEN];  // for storing sending packets  
WiFiUDP UDP;  
const char ssid[]= "abc";  
const char password[]="11111111";  
void setup() {  
Serial.begin(115200);  
Serial.print("Trying to connect to Wifi");  
Serial.print(ssid);  
WiFi.begin(ssid,password);  
while(WiFi.status() != WL_CONNECTED)  
{  
delay(500);  
Serial.print("\n");  
Serial.print("not Connected to Wifi Yet");  
}  
Serial.print("\n");  
Serial.println("Successfully connected with Wifi");  
Serial.print("Ip Address : ");  
Serial.println(WiFi.localIP());  
Serial.print("Mac Address of Board : ");  
Serial.println(WiFi.macAddress());  
Serial.print("Subnet Mask  : ");  
Serial.println(WiFi.subnetMask());  
Serial.print("Gateway IP  : ");  
Serial.println(WiFi.gatewayIP());  
if ( UDP.begin(SOCKET))  
{  
Serial.print("\n");  
Serial.print("Initialization is successful");  
}  
else   
{  
Serial.print("Initialization is Failed");  
}  
pinMode(LED_BUILTIN, OUTPUT);  
}  
void loop()   
{  
int chk = DHT11.read(DHT11PIN);  
int packetsize = 0;  // tp store size of packet   
packetsize = UDP.parsePacket();    // to check if there is any UDP packet  
if (packetsize)  
{  
} 
UDP.read(inBUFFER,BUFFERLEN);    // read udp packet and store in inbuffer  
inBUFFER[packetsize] = '\0' ;      
// read untill null  
if (strcmp("DATA",inBUFFER) == 0)  
{  
digitalWrite(LED_BUILTIN, LOW);  
Serial.print("Humidity (%): ");  
Serial.println((float)DHT11.humidity, 2);  
}  
{  
if (strcmp("NODATA",inBUFFER) == 0)  
digitalWrite(LED_BUILTIN, HIGH);// LED TURNS OFF  
}  
Serial.print(packetsize);    
Serial.println("bytes");  
Serial.print("Contents:");   
Serial.println(inBUFFER);     
Serial.print("From IP ");    
Serial.println(UDP.remoteIP());    
Serial.print("From Port ");     
Serial.println(UDP.remotePort());   
}  
}