/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <WiFi.h>
#include <FirebaseESP32.h>

#define WIFI_SSID "COE CHROMIUM"
#define WIFI_PASSWORD "Welcom@123"
#define FIREBASE_HOST "iot-workshop-848e7-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Dpw5e3xNXX0bOxZztBe8lZQRDK68hcoicTAvueMn"

FirebaseData fbdo;

//const char* WIFI_SSID     = "COE CHROMIUM";
//const char* WIFI_PASSWORD = "Welcom@123";

void setup()
{
    Serial.begin(115200);
    //Firebase.begin();
    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    
    Serial.println(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
    
}

int value = 0;

void loop()
{
  for(int i=0;i<=5;i++){
    Firebase.setString(fbdo, "/name", "Shirley");
    //delay (1000);
    }
}
