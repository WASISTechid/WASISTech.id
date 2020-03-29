#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


// Your WiFi credentials.
// Set password to "" for open networks.
#ifndef STASSID
#define STASSID "Your SSID"
#define STAPSK  "Your Password"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;

#include <Keypad.h>
 
const byte n_rows = 4;
const byte n_cols = 4;
 
char keys[n_rows][n_cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

// Wemos 
//byte colPins[n_rows] = {D3, D2, D1, D0};
//byte rowPins[n_cols] = {D7, D6, D5, D4};

//Generic ESP8266
byte colPins[n_rows] = {0, 4, 5, 16};
byte rowPins[n_cols] = {13, 12, 14, 2};

Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols);

int ledState = HIGH;
int btnState = HIGH;
int ledState2 = HIGH;
int btnState2 = HIGH;
int ledState3 = HIGH;
int btnState3 = HIGH;
int ledStateA = HIGH;
int btnStateA = HIGH;
int ledState4 = HIGH;
int btnState4 = HIGH;
int ledState5 = HIGH;
int btnState5 = HIGH;
int ledState6 = HIGH;
int btnState6 = HIGH;
int ledStateB = HIGH;
int btnStateB = HIGH;
int ledState7 = HIGH;
int btnState7 = HIGH;
int ledState8 = HIGH;
int btnState8 = HIGH;
int ledState9 = HIGH;
int btnState9 = HIGH;
int ledStateC = HIGH;
int btnStateC = HIGH;
int ledStateBintang = HIGH;
int btnStateBintang = HIGH;
int ledState0 = HIGH;
int btnState0 = HIGH;
int ledStatePagar = HIGH;
int btnStatePagar = HIGH;
int ledStateD = HIGH;
int btnStateD = HIGH;

void Button1On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=1&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button1Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=1&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button2On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=2&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button2Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=2&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button3On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=3&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button3Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=3&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button4On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=4&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button4Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=4&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button5On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=5&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button5Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=5&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button6On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=6&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button6Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=6&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button7On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=7&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button7Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=7&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button8On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=8&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button8Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=8&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button9On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=9&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button9Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=9&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button10On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=10&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button10Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=10&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button11On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=11&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button11Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=11&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button12On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=12&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button12Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=12&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button13On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=13&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button13Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=13&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button14On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=14&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button14Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=14&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button15On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=15&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button15Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=15&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button16On()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=16&state=1")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void Button16Off()
{
    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "http://10.57.57.208/update?relay=16&state=0")) {  // HTTP


      Serial.print("[HTTP] GET...\n");
      // start connection and send HTTP header
      int httpCode = http.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void setup()
{
  // Debug console
  Serial.begin(115200);
    
  //Blynk.begin(auth, ssid, pass);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
  ArduinoOTA.setHostname("ESP8266-Keypad");

  // No authentication by default
  // ArduinoOTA.setPassword("admin");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");
  
  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) {
      type = "sketch";
    } else { // U_SPIFFS
      type = "filesystem";
    }

    // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop()
{
  ArduinoOTA.handle();
  char myKey = myKeypad.getKey();
 
  if (myKey != NULL){
    Serial.print("Key pressed : ");
    Serial.println(myKey);
    if (myKey == '1'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState);
        // Toggle LED state
        ledState = !ledState;
        Serial.print("ledState : ");
        Serial.println(ledState);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button1On();
          Serial.print("LOW 1 :");
          //Serial.println(dim);
        } else {
          //dim = 1024;
          //bridge1.virtualWrite(V1, dim);
          Button1Off();
          Serial.print("HIGH 1 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState);
    } else {
      btnState = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState);
    }
    
    
    if (myKey == '11'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState != LOW) {

        // Toggle LED state
        ledState = !ledState;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //int dim;
        if (ledState == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button1On();
          Serial.print("LOW 11 :");
          //Serial.println(dim);
        } else {
          //dim = 1024;
          //bridge1.virtualWrite(V1, dim);
          Button1Off();
          Serial.print("HIGH 11 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState = LOW;
    } else {
      btnState = HIGH;
    }
    
    if (myKey == '2'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState2 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState2);
        // Toggle LED state
        ledState2 = !ledState2;
        Serial.print("ledState : ");
        Serial.println(ledState2);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState2 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button2On();
          Serial.print("LOW 2 :");
          //Serial.println(dim);
        } else {
          //dim = 1024;
          //bridge1.virtualWrite(V1, dim);
          Button2Off();
          Serial.print("HIGH 2 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState2 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState2);
    } else {
      btnState2 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState2);
    }
    
    
    if (myKey == '22'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState2 != LOW) {

        // Toggle LED state
        ledState2 = !ledState2;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //int dim;
        if (ledState2 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button2On();
          Serial.print("LOW 22 :");
          //Serial.println(dim);
        } else {
          //dim = 1024;
          //bridge1.virtualWrite(V1, dim);
          Button2Off();
          Serial.print("HIGH 22 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState2 = LOW;
    } else {
      btnState2 = HIGH;
    }

    if (myKey == '3'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState3 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState3);
        // Toggle LED state
        ledState3 = !ledState3;
        Serial.print("ledState : ");
        Serial.println(ledState3);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState3 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button3On();
          Serial.print("LOW 3 :");
          //Serial.println(dim);
        } else {
          //dim = 1034;
          //bridge1.virtualWrite(V1, dim);
          Button3Off();
          Serial.print("HIGH 3 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState3 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState3);
    } else {
      btnState3 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState3);
    }
    
    
    if (myKey == '33'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState3 != LOW) {

        // Toggle LED state
        ledState3 = !ledState3;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //int dim;
        if (ledState3 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button3On();
          Serial.print("LOW 33 :");
          //Serial.println(dim);
        } else {
          //dim = 1034;
          //bridge1.virtualWrite(V1, dim);
          Button3Off();
          Serial.print("HIGH 33 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState3 = LOW;
    } else {
      btnState3 = HIGH;
    }
    
    if (myKey == 'A'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateA != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnStateA);
        // Toggle LED state
        ledStateA = !ledStateA;
        Serial.print("ledState : ");
        Serial.println(ledStateA);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1A, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledStateA == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button4On();
          Serial.print("LOW A :");
          //Serial.println(dim);
        } else {
          //dim = 10AA;
          //bridge1.virtualWrite(V1, dim);
          Button4Off();
          Serial.print("HIGH A :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateA = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnStateA);
    } else {
      btnStateA = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnStateA);
    }
    
    
    if (myKey == 'AA'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateA != LOW) {

        // Toggle LED state
        ledStateA = !ledStateA;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1A, ledState);
        //int dim;
        if (ledStateA == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button4On();
          Serial.print("LOW AA :");
          //Serial.println(dim);
        } else {
          //dim = 10AA;
          //bridge1.virtualWrite(V1, dim);
          Button4Off();
          Serial.print("HIGH AA :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateA = LOW;
    } else {
      btnStateA = HIGH;
    }

    if (myKey == '4'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState4 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState4);
        // Toggle LED state
        ledState4 = !ledState4;
        Serial.print("ledState : ");
        Serial.println(ledState4);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState4 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button5On();
          Serial.print("LOW 4 :");
          //Serial.println(dim);
        } else {
          //dim = 1044;
          //bridge1.virtualWrite(V1, dim);
          Button5Off();
          Serial.print("HIGH 4 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState4 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState4);
    } else {
      btnState4 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState4);
    }
    
    
    if (myKey == '44'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState4 != LOW) {

        // Toggle LED state
        ledState4 = !ledState4;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //int dim;
        if (ledState4 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button5On();
          Serial.print("LOW 44 :");
          //Serial.println(dim);
        } else {
          //dim = 1044;
          //bridge1.virtualWrite(V1, dim);
          Button5Off();
          Serial.print("HIGH 44 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState4 = LOW;
    } else {
      btnState4 = HIGH;
    }

    if (myKey == '5'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState5 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState5);
        // Toggle LED state
        ledState5 = !ledState5;
        Serial.print("ledState : ");
        Serial.println(ledState5);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState5 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button6On();
          Serial.print("LOW 5 :");
          //Serial.println(dim);
        } else {
          //dim = 1055;
          //bridge1.virtualWrite(V1, dim);
          Button6Off();
          Serial.print("HIGH 5 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState5 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState5);
    } else {
      btnState5 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState5);
    }
    
    
    if (myKey == '55'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState5 != LOW) {

        // Toggle LED state
        ledState5 = !ledState5;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(15, ledState);
        //int dim;
        if (ledState5 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button6On();
          Serial.print("LOW 55 :");
          //Serial.println(dim);
        } else {
          //dim = 1055;
          //bridge1.virtualWrite(V1, dim);
          Button6Off();
          Serial.print("HIGH 55 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState5 = LOW;
    } else {
      btnState5 = HIGH;
    }

    if (myKey == '6'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState6 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState6);
        // Toggle LED state
        ledState6 = !ledState6;
        Serial.print("ledState : ");
        Serial.println(ledState6);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(16, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState6 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button7On();
          Serial.print("LOW 6 :");
          //Serial.println(dim);
        } else {
          //dim = 1066;
          //bridge1.virtualWrite(V1, dim);
          Button7Off();
          Serial.print("HIGH 6 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState6 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState6);
    } else {
      btnState6 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState6);
    }
    
    
    if (myKey == '66'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState6 != LOW) {

        // Toggle LED state
        ledState6 = !ledState6;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(16, ledState);
        //int dim;
        if (ledState6 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button7On();
          Serial.print("LOW 66 :");
          //Serial.println(dim);
        } else {
          //dim = 1066;
          //bridge1.virtualWrite(V1, dim);
          Button7Off();
          Serial.print("HIGH 66 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState6 = LOW;
    } else {
      btnState6 = HIGH;
    }

    if (myKey == 'B'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateB != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnStateB);
        // Toggle LED state
        ledStateB = !ledStateB;
        Serial.print("ledState : ");
        Serial.println(ledStateB);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1B, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledStateB == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button8On();
          Serial.print("LOW B :");
          //Serial.println(dim);
        } else {
          //dim = 10BB;
          //bridge1.virtualWrite(V1, dim);
          Button8Off();
          Serial.print("HIGH B :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateB = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnStateB);
    } else {
      btnStateB = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnStateB);
    }
    
    
    if (myKey == 'BB'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateB != LOW) {

        // Toggle LED state
        ledStateB = !ledStateB;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1B, ledState);
        //int dim;
        if (ledStateB == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button8On();
          Serial.print("LOW BB :");
          //Serial.println(dim);
        } else {
          //dim = 10BB;
          //bridge1.virtualWrite(V1, dim);
          Button8Off();
          Serial.print("HIGH BB :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateB = LOW;
    } else {
      btnStateB = HIGH;
    }

    if (myKey == '7'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState7 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState7);
        // Toggle LED state
        ledState7 = !ledState7;
        Serial.print("ledState : ");
        Serial.println(ledState7);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(17, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState7 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button9On();
          Serial.print("LOW 7 :");
          //Serial.println(dim);
        } else {
          //dim = 1077;
          //bridge1.virtualWrite(V1, dim);
          Button9Off();
          Serial.print("HIGH 7 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState7 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState7);
    } else {
      btnState7 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState7);
    }
    
    
    if (myKey == '77'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState7 != LOW) {

        // Toggle LED state
        ledState7 = !ledState7;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(17, ledState);
        //int dim;
        if (ledState7 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button9On();
          Serial.print("LOW 77 :");
          //Serial.println(dim);
        } else {
          //dim = 1077;
          //bridge1.virtualWrite(V1, dim);
          Button9Off();
          Serial.print("HIGH 77 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState7 = LOW;
    } else {
      btnState7 = HIGH;
    }

    if (myKey == '8'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState8 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState8);
        // Toggle LED state
        ledState8 = !ledState8;
        Serial.print("ledState : ");
        Serial.println(ledState8);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(18, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState8 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button10On();
          Serial.print("LOW 8 :");
          //Serial.println(dim);
        } else {
          //dim = 1088;
          //bridge1.virtualWrite(V1, dim);
          Button10Off();
          Serial.print("HIGH 8 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState8 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState8);
    } else {
      btnState8 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState8);
    }
    
    
    if (myKey == '88'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState8 != LOW) {

        // Toggle LED state
        ledState8 = !ledState8;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(18, ledState);
        //int dim;
        if (ledState8 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button10On();
          Serial.print("LOW 88 :");
          //Serial.println(dim);
        } else {
          //dim = 1088;
          //bridge1.virtualWrite(V1, dim);
          Button10Off();
          Serial.print("HIGH 88 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState8 = LOW;
    } else {
      btnState8 = HIGH;
    }

    if (myKey == '9'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState9 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState9);
        // Toggle LED state
        ledState9 = !ledState9;
        Serial.print("ledState : ");
        Serial.println(ledState9);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(19, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState9 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button11On();
          Serial.print("LOW 9 :");
          //Serial.println(dim);
        } else {
          //dim = 1099;
          //bridge1.virtualWrite(V1, dim);
          Button11Off();
          Serial.print("HIGH 9 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState9 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState9);
    } else {
      btnState9 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState9);
    }
    
    
    if (myKey == '99'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState9 != LOW) {

        // Toggle LED state
        ledState9 = !ledState9;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(19, ledState);
        //int dim;
        if (ledState9 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button11On();
          Serial.print("LOW 99 :");
          //Serial.println(dim);
        } else {
          //dim = 1099;
          //bridge1.virtualWrite(V1, dim);
          Button11Off();
          Serial.print("HIGH 99 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState9 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState9);
    } else {
      btnState9 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState9);
    }

    if (myKey == 'C'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateC != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnStateC);
        // Toggle LED state
        ledStateC = !ledStateC;
        Serial.print("ledState : ");
        Serial.println(ledStateC);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1C, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledStateC == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button12On();
          Serial.print("LOW C :");
          //Serial.println(dim);
        } else {
          //dim = 10CC;
          //bridge1.virtualWrite(V1, dim);
          Button12Off();
          Serial.print("HIGH C :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateC = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnStateC);
    } else {
      btnStateC = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnStateC);
    }
     
    if (myKey == 'CC'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateC != LOW) {

        // Toggle LED state
        ledStateC = !ledStateC;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1C, ledState);
        //int dim;
        if (ledStateC == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button12On();
          Serial.print("LOW CC :");
          //Serial.println(dim);
        } else {
          //dim = 10CC;
          //bridge1.virtualWrite(V1, dim);
          Button12Off();
          Serial.print("HIGH CC :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateC = LOW;
    } else {
      btnStateC = HIGH;
    }
        
    if (myKey == '*'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateBintang != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnStateBintang);
        // Toggle LED state
        ledStateBintang = !ledStateBintang;
        Serial.print("ledState : ");
        Serial.println(ledStateBintang);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1Bintang, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledStateBintang == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button13On();
          Serial.print("LOW Bintang :");
          //Serial.println(dim);
        } else {
          //dim = 10BintangBintang;
          //bridge1.virtualWrite(V1, dim);
          Button13Off();
          Serial.print("HIGH Bintang :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateBintang = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnStateBintang);
    } else {
      btnStateBintang = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnStateBintang);
    }
    
    
    if (myKey == '**'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateBintang != LOW) {

        // Toggle LED state
        ledStateBintang = !ledStateBintang;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1Bintang, ledState);
        //int dim;
        if (ledStateBintang == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button13On();
          Serial.print("LOW BintangBintang :");
          //Serial.println(dim);
        } else {
          //dim = 10BintangBintang;
          //bridge1.virtualWrite(V1, dim);
          Button13Off();
          Serial.print("HIGH BintangBintang :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateBintang = LOW;
    } else {
      btnStateBintang = HIGH;
    }

    if (myKey == '0'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState0 != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnState0);
        // Toggle LED state
        ledState0 = !ledState0;
        Serial.print("ledState : ");
        Serial.println(ledState0);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(10, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledState0 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button14On();
          Serial.print("LOW 0 :");
          //Serial.println(dim);
        } else {
          //dim = 1000;
          //bridge1.virtualWrite(V1, dim);
          Button14Off();
          Serial.print("HIGH 0 :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState0 = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnState0);
    } else {
      btnState0 = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnState0);
    }
    
    
    if (myKey == '00'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnState0 != LOW) {

        // Toggle LED state
        ledState0 = !ledState0;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(10, ledState);
        //int dim;
        if (ledState0 == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button14On();
          Serial.print("LOW 00 :");
          //Serial.println(dim);
        } else {
          //dim = 1000;
          //bridge1.virtualWrite(V1, dim);
          Button14Off();
          Serial.print("HIGH 00 :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnState0 = LOW;
    } else {
      btnState0 = HIGH;
    }

    if (myKey == '#'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStatePagar != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnStatePagar);
        // Toggle LED state
        ledStatePagar = !ledStatePagar;
        Serial.print("ledState : ");
        Serial.println(ledStatePagar);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1Pagar, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledStatePagar == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button15On();
          Serial.print("LOW Pagar :");
          //Serial.println(dim);
        } else {
          //dim = 10PagarPagar;
          //bridge1.virtualWrite(V1, dim);
          Button15Off();
          Serial.print("HIGH Pagar :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStatePagar = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnStatePagar);
    } else {
      btnStatePagar = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnStatePagar);
    }
    
    
    if (myKey == '##'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStatePagar != LOW) {

        // Toggle LED state
        ledStatePagar = !ledStatePagar;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1Pagar, ledState);
        //int dim;
        if (ledStatePagar == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button15On();
          Serial.print("LOW PagarPagar :");
          //Serial.println(dim);
        } else {
          //dim = 10PagarPagar;
          //bridge1.virtualWrite(V1, dim);
          Button15Off();
          Serial.print("HIGH PagarPagar :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStatePagar = LOW;
    } else {
      btnStatePagar = HIGH;
    }

    if (myKey == 'D'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateD != LOW) {
        Serial.print("btnState : ");
        Serial.println(btnStateD);
        // Toggle LED state
        ledStateD = !ledStateD;
        Serial.print("ledState : ");
        Serial.println(ledStateD);
       // digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1D, ledState);
        //Serial.print("LedState: ");
        //Serial.println(ledState);
        //int dim;
        if (ledStateD == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button16On();
          Serial.print("LOW D :");
          //Serial.println(dim);
        } else {
          //dim = 10DD;
          //bridge1.virtualWrite(V1, dim);
          Button16Off();
          Serial.print("HIGH D :");
          //Serial.println(dim);
        }
        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateD = LOW;
      Serial.print("btnState posisi low :");
      Serial.println(btnStateD);
    } else {
      btnStateD = HIGH;
      Serial.print("btnState posisi high :");
      Serial.println(btnStateD);
    }
    
    
    if (myKey == 'DD'){
      Serial.println("if checked");
      // btnState is used to avoid sequential toggles
      if (btnStateD != LOW) {

        // Toggle LED state
        ledStateD = !ledStateD;
        //digitalWrite(ledPin, ledState);
        //bridge1.digitalWrite(1D, ledState);
        //int dim;
        if (ledStateD == LOW){
          //dim = 0;
          //bridge1.virtualWrite(V1, dim);
          Button16On();
          Serial.print("LOW DD :");
          //Serial.println(dim);
        } else {
          //dim = 10DD;
          //bridge1.virtualWrite(V1, dim);
          Button16Off();
          Serial.print("HIGH DD :");
          //Serial.println(dim);
        }
        
        //Serial.print("LedState: ");
        //Serial.println(ledState);

        // Update Button Widget
        //Blynk.virtualWrite(V1, ledState);
      }
      btnStateD = LOW;
    } else {
      btnStateD = HIGH;
    }
  }
}
