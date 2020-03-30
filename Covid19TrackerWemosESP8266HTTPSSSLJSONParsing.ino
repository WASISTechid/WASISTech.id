/**
   BasicHTTPSClient.ino

   Created on: 20.08.2018
   
   https://youtu.be/YYyyz4ieiWE
*/

#include <Arduino.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

#include <WiFiClientSecureBearSSL.h>
// Fingerprint for demo URL, expires on June 2, 2021, needs to be updated well before this date
const uint8_t fingerprint[20] = {0xe5, 0x37, 0x76, 0x46, 0x01, 0xf6, 0x5d, 0xdf, 0x5d, 0x6a, 0x6c, 0x10, 0xde, 0xba, 0x4d, 0x9e, 0x8e, 0xc9, 0xd1, 0x49};

ESP8266WiFiMulti WiFiMulti;

void setup() {

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("WASISTech", "");
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);

    HTTPClient https;

    Serial.print("[HTTPS] Italy begin...\n");
    if (https.begin(*client, "https://covid19.mathdro.id/api/countries/IT")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);

          char json[500];
          payload.toCharArray(json, 500);
          StaticJsonDocument<200> doc;
          deserializeJson(doc, json);
          String ITTanggal = doc["lastUpdate"];
          //String ITNegara = doc["locations"][0]["country"];
          int ITPositif = doc["confirmed"]["value"];
          int ITMeninggal = doc["deaths"]["value"];
          int ITSembuh = doc["recovered"]["value"];
      
          Serial.print("Last Updated : " + ITTanggal + "\n");
          Serial.print("Negara       : Italy\n");
          Serial.print("Positif      : " + String(ITPositif) + "\n");
          Serial.print("Meninggal    : " + String(ITMeninggal) + "\n");
          Serial.print("Sembuh       : " + String(ITSembuh) + "\n");
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }

    Serial.print("[HTTPS] Indonesia begin...\n");
    if (https.begin(*client, "https://covid19.mathdro.id/api/countries/ID")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);

          char json[500];
          payload.toCharArray(json, 500);
          StaticJsonDocument<200> doc;
          deserializeJson(doc, json);
          String IDTanggal = doc["lastUpdate"];
          //String IDNegara = doc["locations"][0]["country"];
          int IDPositif = doc["confirmed"]["value"];
          int IDMeninggal = doc["deaths"]["value"];
          int IDSembuh = doc["recovered"]["value"];
      
          Serial.print("Last Updated : " + IDTanggal + "\n");
          Serial.print("Negara       : Indonesia\n");
          Serial.print("Positif      : " + String(IDPositif) + "\n");
          Serial.print("Meninggal    : " + String(IDMeninggal) + "\n");
          Serial.print("Sembuh       : " + String(IDSembuh) + "\n");
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
    Serial.print("[HTTPS] China begin...\n");
    if (https.begin(*client, "https://covid19.mathdro.id/api/countries/CN")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);

          char json[500];
          payload.toCharArray(json, 500);
          StaticJsonDocument<200> doc;
          deserializeJson(doc, json);
          String CNTanggal = doc["lastUpdate"];
          //String CNNegara = doc["locations"][0]["country"];
          int CNPositif = doc["confirmed"]["value"];
          int CNMeninggal = doc["deaths"]["value"];
          int CNSembuh = doc["recovered"]["value"];
      
          Serial.print("Last Updated : " + CNTanggal + "\n");
          Serial.print("Negara       : China\n");
          Serial.print("Positif      : " + String(CNPositif) + "\n");
          Serial.print("Meninggal    : " + String(CNMeninggal) + "\n");
          Serial.print("Sembuh       : " + String(CNSembuh) + "\n");
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
    Serial.print("[HTTPS] Singapore begin...\n");
    if (https.begin(*client, "https://covid19.mathdro.id/api/countries/SG")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);

          char json[500];
          payload.toCharArray(json, 500);
          StaticJsonDocument<200> doc;
          deserializeJson(doc, json);
          String SGTanggal = doc["lastUpdate"];
          //String SGNegara = doc["locations"][0]["country"];
          int SGPositif = doc["confirmed"]["value"];
          int SGMeninggal = doc["deaths"]["value"];
          int SGSembuh = doc["recovered"]["value"];
      
          Serial.print("Last Updated : " + SGTanggal + "\n");
          Serial.print("Negara       : Singapore\n");
          Serial.print("Positif      : " + String(SGPositif) + "\n");
          Serial.print("Meninggal    : " + String(SGMeninggal) + "\n");
          Serial.print("Sembuh       : " + String(SGSembuh) + "\n");
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
    Serial.print("[HTTPS] Malaysia begin...\n");
    if (https.begin(*client, "https://covid19.mathdro.id/api/countries/MY")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);

          char json[500];
          payload.toCharArray(json, 500);
          StaticJsonDocument<200> doc;
          deserializeJson(doc, json);
          String MYTanggal = doc["lastUpdate"];
          //String MYNegara = doc["locations"][0]["country"];
          int MYPositif = doc["confirmed"]["value"];
          int MYMeninggal = doc["deaths"]["value"];
          int MYSembuh = doc["recovered"]["value"];
      
          Serial.print("Last Updated : " + MYTanggal + "\n");
          Serial.print("Negara       : Malaysia\n");
          Serial.print("Positif      : " + String(MYPositif) + "\n");
          Serial.print("Meninggal    : " + String(MYMeninggal) + "\n");
          Serial.print("Sembuh       : " + String(MYSembuh) + "\n");
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
    Serial.print("[HTTPS] Amerika begin...\n");
    if (https.begin(*client, "https://covid19.mathdro.id/api/countries/USA")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);

          char json[500];
          payload.toCharArray(json, 500);
          StaticJsonDocument<200> doc;
          deserializeJson(doc, json);
          String USTanggal = doc["lastUpdate"];
          //String USNegara = doc["locations"][0]["country"];
          int USPositif = doc["confirmed"]["value"];
          int USMeninggal = doc["deaths"]["value"];
          int USSembuh = doc["recovered"]["value"];
      
          Serial.print("Last Updated : " + USTanggal + "\n");
          Serial.print("Negara       : America\n");
          Serial.print("Positif      : " + String(USPositif) + "\n");
          Serial.print("Meninggal    : " + String(USMeninggal) + "\n");
          Serial.print("Sembuh       : " + String(USSembuh) + "\n");
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }

  Serial.println("Wait 60s before next round...");
  delay(60000);
}
