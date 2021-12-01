#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ESP8266HTTPClient.h>

const char ssid = "Rutgers IEEE 2.4";
const char pswd = "RutgersIEEE"

const String endpoint = "https://aerisweather1.p.rapidapi.com/sunmoon/piscataway,nj/?rapidapi-key=";
const String key = "0f5f2241d8msh3dc553f7c2e026ap1011a6jsn5509553ca852";

void wifiSetup() {
    WiFi.begin(ssid,pswd);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void makeRequest() {
    HTTPClient http;
    http.begin(endpoint + key);
    int httpCode = http.GET(); // Request
 
    if (httpCode > 0) { // Request success check
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Close connection
  }
 
  delay(900000); // 15 minute delay
  // 100 api calls/day limit -> 4.1666 api calls/hour
}

typedef struct AerisForecastData {
  uint64_t timestamp; //  1526706000
  String validTime; // "2018-05-19T07:00:00+02:00"
  String dateTimeISO; //"2018-05-19T07:00:00+02:00"
//   sint16_t maxTempC; //20
//   sint16_t maxTempF; //69
//   sint16_t minTempC; //14
//   sint16_t minTempF; // 56
//   sint16_t avgTempC; // 17
//   sint16_t avgTempF; // 62
  sint16_t tempC; // null
  sint16_t tempF; // null
//   float precipMM; // 3.53
//   float precipIN; // 0.14
//   float iceaccum; // null
//   float iceaccumMM; // null
//   float iceaccumIN; // null
//   uint8_t maxHumidity; // 82
//   uint8_t minHumidity; // 53
//   uint8_t humidity; // 68
  uint8_t uvi; // 6
//   uint16_t pressureMB; // 1018
//   float pressureIN; // 30.06
  uint8_t sky; // 99
//   uint16_t snowCM; // 0
//   uint16_t snowIN; // 0
  sint16_t feelslikeC; // 14
  sint16_t feelslikeF; // 56
  sint16_t minFeelslikeC; // 14
  sint16_t minFeelslikeF; // 56
  sint16_t maxFeelslikeC; // 20
  sint16_t maxFeelslikeF; // 69
  sint16_t avgFeelslikeC; // 17
  sint16_t avgFeelslikeF; // 63
//   sint16_t dewpointC; // 11
//   sint16_t dewpointF; // 51
//   sint16_t maxDewpointC; // 13
//   sint16_t maxDewpointF; // 55
//   sint16_t minDewpointC; // 10
//   sint16_t minDewpointF; // 51
//   sint16_t avgDewpointC; // 11
//   sint16_t avgDewpointF; // 52
//   uint16_t windDirDEG; // 2
//   String windDir; // "N"
//   uint16_t windDirMaxDEG; // 40
//   String windDirMax; // "NE"
//   sint16_t windDirMinDEG; // 39
//   String windDirMin; // "NE"
//   uint16_t windGustKTS; // 6
//   uint16_t windGustKPH; // 11
//   uint16_t windGustMPH; // 7
//   uint16_t windSpeedKTS; // 4
//   uint16_t windSpeedKPH; // 7
//   uint16_t windSpeedMPH; // 5
//   uint16_t windSpeedMaxKTS; // 6
//   uint16_t windSpeedMaxKPH; // 11
//   uint16_t windSpeedMaxMPH; // 7
//   uint16_t windSpeedMinKTS; // 1
//   uint16_t windSpeedMinKPH; // 2
//   uint16_t windSpeedMinMPH; // 1
//   uint16_t windDir80mDEG; // 5
//   String windDir80m; // "N"
//   uint16_t windDirMax80mDEG; // 40
//   String windDirMax80m; // "NE"
//   uint16_t windDirMin80mDEG; // 39
//   String windDirMin80m; // "NE"
//   uint16_t windGust80mKTS; // 9
//   uint16_t windGust80mKPH; // 17
//   uint16_t windGust80mMPH; // 11
//   uint16_t windSpeed80mKTS; // 6
//   uint16_t windSpeed80mKPH; // 11
//   uint16_t windSpeed80mMPH; // 7
//   uint16_t windSpeedMax80mKTS; // 9
//   uint16_t windSpeedMax80mKPH; // 17
//   uint16_t windSpeedMax80mMPH; // 11
//   uint16_t windSpeedMin80mKTS; // 4
//   uint16_t windSpeedMin80mKPH; // 7
//   uint16_t windSpeedMin80mMPH; // 4
  String weather; // "Cloudy with Drizzle"
  String weatherPrimary; // "Drizzle"
  String weatherPrimaryCoded; // "IS:VL:RW"
  String cloudsCoded; // "OV"
//   String icon; // "drizzle.png"
//   String iconMeteoCon; // Q
//   boolean isDay; // true
  uint64_t sunrise; // 1526701425
  String sunriseISO; // "2018-05-19T05:43:45+02:00"
  uint64_t sunset; // 1526756450
  String sunsetISO; // "2018-05-19T21:00:50+02:00"
}