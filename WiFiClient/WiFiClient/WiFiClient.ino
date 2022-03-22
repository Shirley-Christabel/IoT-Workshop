/*
    This sketch sends data via HTTP GET requests to data.sparkfun.com service.

    You need to get streamId and privateKey at data.sparkfun.com and paste them
    below. Or just customize this script to talk to other HTTP servers.

*/

#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//#define WIFI_SSID "COE CHROMIUM"
//#define WIFI_PASSWORD "Welcome@123"
#define FIREBASE_HOST "iot-workshop-848e7-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Dpw5e3xNXX0bOxZztBe8lZQRDK68hcoicTAvueMn"
#define DHTPIN 2
#define DHTTYPE    DHT11

FirebaseData fbdo;
DHT_Unified dht(DHTPIN, DHTTYPE);

const char* ssid     = "COE CHROMIUM";
const char* password = "Welcome@123";

void setup()
{
  Serial.begin(115200);
  //Firebase.begin();
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  dht.begin();
}

String a;

void loop()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temp = event.temperature;
  
  dht.humidity().getEvent(&event);
  float humi = event.relative_humidity;
  

  Firebase.setFloat(fbdo,"/temp",temp);
  delay(100);
  Firebase.setFloat(fbdo,"/humi",humi);
  delay(100);
}
