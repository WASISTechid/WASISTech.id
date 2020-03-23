/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2018 by ThingPulse, Daniel Eichhorn
 * Copyright (c) 2018 by Fabrice Weinberg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * ThingPulse invests considerable time and money to develop these open source libraries.
 * Please support us by buying our products (and not the clones) from
 * https://thingpulse.com
 *
 */
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
// WiFi includes
#include <ESP8266WiFi.h>

// Include the correct display library
// For a connection via I2C using Wire include
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
//#include "SSD1306Wire.h" // legacy include: `#include "SSD1306.h"`
#include "SH1106Wire.h", legacy include: `#include "SH1106.h"`
// For a connection via I2C using brzo_i2c (must be installed) include
// #include <brzo_i2c.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Brzo.h"
// #include "SH1106Brzo.h"
// For a connection via SPI include
// #include <SPI.h> // Only needed for Arduino 1.6.5 and earlier
// #include "SSD1306Spi.h"
//#include "SH1106SPi.h"
// Include the UI lib
#include "OLEDDisplayUi.h"
#include <TimeLib.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
// OTA Includes
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
// Include custom images

#include "wasislogo.h"

// Use the corresponding display class:

// Initialize the OLED display using SPI
// D5 -> CLK
// D7 -> MOSI (DOUT)
// D0 -> RES
// D2 -> DC
// D8 -> CS
// SSD1306Spi        display(D0, D2, D8);
// or
// SH1106Spi         display(D0, D2);

// Initialize the OLED display using brzo_i2c
// D3 -> SDA
// D5 -> SCL
// SSD1306Brzo display(0x3c, D3, D5);
// or
// SH1106Brzo  display(0x3c, D3, D5);

// Initialize the OLED display using Wire library
//SSD1306Wire  display(0x3c, D3, D5);
SH1106Wire display(0x3c, D1, D2);

// NTP Servers:
static const char ntpServerName[] = "id.pool.ntp.org";
const int timeZone = 7;     // 1 Central European Time, 7 Indonesia

WiFiUDP Udp;
unsigned int localPort = 8888;  // local port to listen for UDP packets

time_t getNtpTime();
void digitalClockDisplay();
void printDigits(int digits);
void sendNTPpacket(IPAddress &address);

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Isi dengan Token Blynk"; // jika tidak menggunakan Blynk bisa dihapus semua yang berhubungan dengan Blynk

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Isi SSID";
char pass[] = "Isi Password";
char server[] = "Isi server Blynk Local Server";

String Title = "Isi dengan Judul";
int IDPositif,IDMeninggal,IDSembuh;
String IDTanggal;
String IDNegara;

int ITPositif,ITMeninggal,ITSembuh;
String ITTanggal;
String ITNegara;

int CNPositif,CNMeninggal,CNSembuh;
String CNTanggal;
String CNNegara;

int SGPositif,SGMeninggal,SGSembuh;
String SGTanggal;
String SGNegara;

int ALLPositif,ALLMeninggal,ALLSembuh;
String ALLTanggal;

BlynkTimer timer;
WidgetBridge bridge1(V100);

BLYNK_CONNECTED() {
  // Request the latest state from the server
  //Blynk.syncVirtual(V1);
  //bridge1.setAuthToken("Token Blynk kedua");
  // Alternatively, you could override server state using:
  //Blynk.virtualWrite(V2, ledState);
}

OLEDDisplayUi ui     ( &display );

void msOverlay(OLEDDisplay *display, OLEDDisplayUiState* state) {
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(120, 0, String(millis()));
  String timenow = String(hour())+":"+twoDigits(minute())+":"+twoDigits(second());
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 , 0, timenow );
  String datenow = String(day())+"."+String(month())+"."+String(year());
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 , 50, datenow );
}

void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  // draw an xbm image.
  // Please note that everything that should be transitioned
  // needs to be drawn relative to x and y
  // The coordinates define the center of the text
  display->setTextAlignment(TEXT_ALIGN_CENTER);
  display->drawString(64 + x, 10 + y, Title);
  display->drawXbm(x + 47, y + 20, wasislogo_width, wasislogo_height, wasislogo_bits);
}

void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  char bufALLPositif[32];
  Serial.println(ltos(ALLPositif, bufALLPositif, 10));
  char bufALLSembuh[32];
  Serial.println(ltos(ALLSembuh, bufALLSembuh, 10));
  char bufALLMeninggal[32];
  Serial.println(ltos(ALLMeninggal, bufALLMeninggal, 10));
  
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "All Covid19 Tracker");
  display->drawString(0 + x, 20 + y, "Positif : ");
  display->drawString(60 + x, 20 + y, bufALLPositif);
  display->drawString(0 + x, 30 + y, "Sembuh : ");
  display->drawString(60 + x, 30 + y, bufALLSembuh);
  display->drawString(0 + x, 40 + y, "Meninggal :");
  display->drawString(60 + x, 40 + y, bufALLMeninggal);
}

void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  char bufIDPositif[32];
  Serial.println(ltos(IDPositif, bufIDPositif, 10));
  char bufIDSembuh[32];
  Serial.println(ltos(IDSembuh, bufIDSembuh, 10));
  char bufIDMeninggal[32];
  Serial.println(ltos(IDMeninggal, bufIDMeninggal, 10)); 
  
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Indonesia Covid19 Tracker");
  display->drawString(0 + x, 20 + y, "Positif : ");
  display->drawString(60 + x, 20 + y, bufIDPositif);
  display->drawString(0 + x, 30 + y, "Sembuh : ");
  display->drawString(60 + x, 30 + y, bufIDSembuh);
  display->drawString(0 + x, 40 + y, "Meninggal :");
  display->drawString(60 + x, 40 + y, bufIDMeninggal);
}

void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  char bufCNPositif[32];
  Serial.println(ltos(CNPositif, bufCNPositif, 10));
  char bufCNSembuh[32];
  Serial.println(ltos(CNSembuh, bufCNSembuh, 10));
  char bufCNMeninggal[32];
  Serial.println(ltos(CNMeninggal, bufCNMeninggal, 10));
  
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "China Covid19 Tracker");
  display->drawString(0 + x, 20 + y, "Positif : ");
  display->drawString(60 + x, 20 + y, bufCNPositif);
  display->drawString(0 + x, 30 + y, "Sembuh : ");
  display->drawString(60 + x, 30 + y, bufCNSembuh);
  display->drawString(0 + x, 40 + y, "Meninggal :");
  display->drawString(60 + x, 40 + y, bufCNMeninggal);
}

void drawFrame5(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  char bufITPositif[32];
  Serial.println(ltos(ITPositif, bufITPositif, 10));
  char bufITSembuh[32];
  Serial.println(ltos(ITSembuh, bufITSembuh, 10));
  char bufITMeninggal[32];
  Serial.println(ltos(ITMeninggal, bufITMeninggal, 10));
  
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Italy Covid19 Tracker");
  display->drawString(0 + x, 20 + y, "Positif : ");
  display->drawString(60 + x, 20 + y, bufITPositif);
  display->drawString(0 + x, 30 + y, "Sembuh : ");
  display->drawString(60 + x, 30 + y, bufITSembuh);
  display->drawString(0 + x, 40 + y, "Meninggal :");
  display->drawString(60 + x, 40 + y, bufITMeninggal);
}

void drawFrame6(OLEDDisplay *display, OLEDDisplayUiState* state, int16_t x, int16_t y) {
  char bufSGPositif[32];
  Serial.println(ltos(SGPositif, bufSGPositif, 10));
  char bufSGSembuh[32];
  Serial.println(ltos(SGSembuh, bufSGSembuh, 10));
  char bufSGMeninggal[32];
  Serial.println(ltos(SGMeninggal, bufSGMeninggal, 10));
  
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(0 + x, 10 + y, "Singapore Covid19 Tracker");
  display->drawString(0 + x, 20 + y, "Positif : ");
  display->drawString(60 + x, 20 + y, bufSGPositif);
  display->drawString(0 + x, 30 + y, "Sembuh : ");
  display->drawString(60 + x, 30 + y, bufSGSembuh);
  display->drawString(0 + x, 40 + y, "Meninggal :");
  display->drawString(60 + x, 40 + y, bufSGMeninggal);
}

// This array keeps function pointers to all frames
// frames are the single views that slide in
FrameCallback frames[] = { drawFrame1, drawFrame2, drawFrame3, drawFrame4, drawFrame5, drawFrame6 };

// how many frames are there?
int frameCount = 6;

// Overlays are statically drawn on top of a frame eg. a clock
OverlayCallback overlays[] = { msOverlay };
int overlaysCount = 1;

/*-------- NTP code ----------*/

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

time_t getNtpTime()
{
  IPAddress ntpServerIP; // NTP server's ip address

  while (Udp.parsePacket() > 0) ; // discard any previously received packets
  Serial.println("Transmit NTP Request");
  // get a random server from the pool
  WiFi.hostByName(ntpServerName, ntpServerIP);
  Serial.print(ntpServerName);
  Serial.print(": ");
  Serial.println(ntpServerIP);
  sendNTPpacket(ntpServerIP);
  uint32_t beginWait = millis();
  while (millis() - beginWait < 1500) {
    int size = Udp.parsePacket();
    if (size >= NTP_PACKET_SIZE) {
      Serial.println("Receive NTP Response");
      Udp.read(packetBuffer, NTP_PACKET_SIZE);  // read packet into the buffer
      unsigned long secsSince1900;
      // convert four bytes starting at location 40 to a long integer
      secsSince1900 =  (unsigned long)packetBuffer[40] << 24;
      secsSince1900 |= (unsigned long)packetBuffer[41] << 16;
      secsSince1900 |= (unsigned long)packetBuffer[42] << 8;
      secsSince1900 |= (unsigned long)packetBuffer[43];
      return secsSince1900 - 2208988800UL + timeZone * SECS_PER_HOUR;
    }
  }
  Serial.println("No NTP Response :-(");
  return 0; // return 0 if unable to get the time
}

// send an NTP request to the time server at the given address
void sendNTPpacket(IPAddress &address)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)
  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12] = 49;
  packetBuffer[13] = 0x4E;
  packetBuffer[14] = 49;
  packetBuffer[15] = 52;
  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(address, 123); //NTP requests are to port 123
  Udp.write(packetBuffer, NTP_PACKET_SIZE);
  Udp.endPacket();
}

void printDigits(int digits)
{
  // utility for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

// utility function for digital clock display: prints leading 0
String twoDigits(int digits){
  if(digits < 10) {
    String i = '0'+String(digits);
    return i;
  }
  else {
    return String(digits);
  }
}

void request() {
  HTTPClient http;

  http.begin("http://dutarayamakmur.net/covid19/index.php");
  int httpCode = http.GET();

  if (httpCode > 0) {

    String payload = http.getString();
    //Serial.println(payload); //print json response
    char json[500];
    payload.toCharArray(json, 500);
    StaticJsonDocument<200> doc;
    deserializeJson(doc, json);
    String IDTanggal = doc["update"];
    String IDNegara = doc["negara"];
    IDPositif = doc["positif"];
    IDMeninggal = doc["meninggal"];
    IDSembuh = doc["sembuh"];

    Serial.println(IDTanggal);
    Serial.println(IDNegara);
    Serial.println(IDPositif);
    Serial.println(IDMeninggal);
    Serial.println(IDSembuh);

    virtualWrite(
  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode);
  }

  http.end();
}

void request2() {
  HTTPClient http2;

  http2.begin("http://dutarayamakmur.net/covid19/italy.php");
  int httpCode2 = http2.GET();

  if (httpCode2 > 0) {

    String payload2 = http2.getString();
    //Serial.println(payload); //print json response
    char json2[500];
    payload2.toCharArray(json2, 500);
    StaticJsonDocument<200> doc2;
    deserializeJson(doc2, json2);
    String ITTanggal = doc2["update"];
    String ITNegara = doc2["negara"];
    ITPositif = doc2["positif"];
    ITMeninggal = doc2["meninggal"];
    ITSembuh = doc2["sembuh"];

    Serial.println(ITTanggal);
    Serial.println(ITNegara);
    Serial.println(ITPositif);
    Serial.println(ITMeninggal);
    Serial.println(ITSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode2);
  }

  http2.end();
}

void request3() {
  HTTPClient http3;

  http3.begin("http://dutarayamakmur.net/covid19/china.php");
  int httpCode3 = http3.GET();

  if (httpCode3 > 0) {

    String payload3 = http3.getString();
    //Serial.println(payload); //print json response
    char json3[500];
    payload3.toCharArray(json3, 500);
    StaticJsonDocument<300> doc3;
    deserializeJson(doc3, json3);
    String CNTanggal = doc3["update"];
    String CNNegara = doc3["negara"];
    CNPositif = doc3["positif"];
    CNMeninggal = doc3["meninggal"];
    CNSembuh = doc3["sembuh"];

    Serial.println(CNTanggal);
    Serial.println(CNNegara);
    Serial.println(CNPositif);
    Serial.println(CNMeninggal);
    Serial.println(CNSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode3);
  }

  http3.end();
}

void request4() {
  HTTPClient http4;

  http4.begin("http://dutarayamakmur.net/covid19/singapore.php");
  int httpCode4 = http4.GET();

  if (httpCode4 > 0) {

    String payload4 = http4.getString();
    //Serial.println(payload); //print json response
    char json4[500];
    payload4.toCharArray(json4, 500);
    StaticJsonDocument<300> doc4;
    deserializeJson(doc4, json4);
    String SGTanggal = doc4["update"];
    String SGNegara = doc4["negara"];
    SGPositif = doc4["positif"];
    SGMeninggal = doc4["meninggal"];
    SGSembuh = doc4["sembuh"];

    Serial.println(SGTanggal);
    Serial.println(SGNegara);
    Serial.println(SGPositif);
    Serial.println(SGMeninggal);
    Serial.println(SGSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode4);
  }

  http4.end();
}

void request5() {
  HTTPClient http5;

  http5.begin("http://dutarayamakmur.net/covid19/latest.php");
  int httpCode5 = http5.GET();

  if (httpCode5 > 0) {

    String payload5 = http5.getString();
    //Serial.println(payload); //print json response
    char json5[500];
    payload5.toCharArray(json5, 500);
    StaticJsonDocument<300> doc5;
    deserializeJson(doc5, json5);
    String ALLTanggal = doc5["update"];
    ALLPositif = doc5["positif"];
    ALLMeninggal = doc5["meninggal"];
    ALLSembuh = doc5["sembuh"];

    Serial.println(ALLTanggal);
    Serial.println(ALLPositif);
    Serial.println(ALLMeninggal);
    Serial.println(ALLSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode5);
  }

  http5.end();
}

/* Thousand Code*/

char *ultos_recursive(unsigned long val, char *s, unsigned radix, int pos)
{
  int c;

  if (val >= radix)
    s = ultos_recursive(val / radix, s, radix, pos+1);
  c = val % radix;
  c += (c < 10 ? '0' : 'a' - 10);
  *s++ = c;
  if (pos % 3 == 0) *s++ = ',';
  return s;
}

char *ltos(long val, char *s, int radix)
{
  if (radix < 2 || radix > 36) {
    s[0] = 0;
  } else {
    char *p = s;
    if (radix == 10 && val < 0) {
      val = -val;
      *p++ = '-';
    }
    p = ultos_recursive(val, p, radix, 0) - 1;
    *p = 0;
  }
  return s;
}

/* Thousand Code*/

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println();

	// The ESP is capable of rendering 60fps in 80Mhz mode
	// but that won't give you much time for anything else
	// run it in 160Mhz mode or just set it to 30 fps
  ui.setTargetFPS(60);

	// Customize the active and inactive symbol
  ui.setActiveSymbol(activeSymbol);
  ui.setInactiveSymbol(inactiveSymbol);

  // You can change this to
  // TOP, LEFT, BOTTOM, RIGHT
  ui.setIndicatorPosition(RIGHT);

  // Defines where the first frame is located in the bar.
  ui.setIndicatorDirection(LEFT_RIGHT);

  // You can change the transition that is used
  // SLIDE_LEFT, SLIDE_RIGHT, SLIDE_UP, SLIDE_DOWN
  ui.setFrameAnimation(SLIDE_LEFT);

  // Add frames
  ui.setFrames(frames, frameCount);

  // Add overlays
  ui.setOverlays(overlays, overlaysCount);

  // Initialising the UI will init the display too.
  ui.init();

  display.flipScreenVertically();

  Blynk.begin(auth, ssid, pass, server, 8000);
  timer.setInterval(60000L, request);
  timer.setInterval(60000L, request2);
  timer.setInterval(60000L, request3);
  timer.setInterval(60000L, request4);
  
  ArduinoOTA.begin();
  ArduinoOTA.onStart([]() {
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawString(display.getWidth()/2, display.getHeight()/2 - 10, "OTA Update");
    display.display();
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    display.drawProgressBar(4, 32, 120, 8, progress / (total / 100) );
    display.display();
  });

  ArduinoOTA.onEnd([]() {
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawString(display.getWidth()/2, display.getHeight()/2, "Restart");
    display.display();
  });

  // Align text vertical/horizontal center
  display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
  display.setFont(ArialMT_Plain_10);
  display.drawString(display.getWidth()/2, display.getHeight()/2, "Ready for OTA:\n" + WiFi.localIP().toString());
  display.display();
  
  Serial.println("Starting UDP");
  Udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(Udp.localPort());
  Serial.println("waiting for sync");
  setSyncProvider(getNtpTime);
  setSyncInterval(300);

  /* Indonesia Json Covid19 Tracker*/
  HTTPClient http;

  http.begin("http://dutarayamakmur.net/covid19/index.php");
  int httpCode = http.GET();

  if (httpCode > 0) {

    String payload = http.getString();
    //Serial.println(payload); //print json response
    char json[500];
    payload.toCharArray(json, 500);
    StaticJsonDocument<200> doc;
    deserializeJson(doc, json);
    String IDTanggal = doc["update"];
    String IDNegara = doc["negara"];
    IDPositif = doc["positif"];
    IDMeninggal = doc["meninggal"];
    IDSembuh = doc["sembuh"];

    Serial.println(IDTanggal);
    Serial.println(IDNegara);
    Serial.println(IDPositif);
    Serial.println(IDMeninggal);
    Serial.println(IDSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode);
  }

  http.end();

  /* China Json Covid19 Tracker*/
  HTTPClient http2;

  http2.begin("http://dutarayamakmur.net/covid19/italy.php");
  int httpCode2 = http2.GET();

  if (httpCode2 > 0) {

    String payload2 = http2.getString();
    //Serial.println(payload); //print json response
    char json2[500];
    payload2.toCharArray(json2, 500);
    StaticJsonDocument<200> doc2;
    deserializeJson(doc2, json2);
    String ITTanggal = doc2["update"];
    String ITNegara = doc2["negara"];
    ITPositif = doc2["positif"];
    ITMeninggal = doc2["meninggal"];
    ITSembuh = doc2["sembuh"];

    Serial.println(ITTanggal);
    Serial.println(ITNegara);
    Serial.println(ITPositif);
    Serial.println(ITMeninggal);
    Serial.println(ITSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode2);
  }

  http2.end();

  /* Italy Json Covid19 Tracker*/
  HTTPClient http3;

  http3.begin("http://dutarayamakmur.net/covid19/china.php");
  int httpCode3 = http3.GET();

  if (httpCode3 > 0) {

    String payload3 = http3.getString();
    //Serial.println(payload); //print json response
    char json3[500];
    payload3.toCharArray(json3, 500);
    StaticJsonDocument<300> doc3;
    deserializeJson(doc3, json3);
    String CNTanggal = doc3["update"];
    String CNNegara = doc3["negara"];
    CNPositif = doc3["positif"];
    CNMeninggal = doc3["meninggal"];
    CNSembuh = doc3["sembuh"];

    Serial.println(CNTanggal);
    Serial.println(CNNegara);
    Serial.println(CNPositif);
    Serial.println(CNMeninggal);
    Serial.println(CNSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode3);
  }

  http3.end();
  
  /* Singapore Json Covid19 Tracker*/
  HTTPClient http4;

  http4.begin("http://dutarayamakmur.net/covid19/singapore.php");
  int httpCode4 = http4.GET();

  if (httpCode4 > 0) {

    String payload4 = http4.getString();
    //Serial.println(payload); //print json response
    char json4[500];
    payload4.toCharArray(json4, 500);
    StaticJsonDocument<300> doc4;
    deserializeJson(doc4, json4);
    String SGTanggal = doc4["update"];
    String SGNegara = doc4["negara"];
    SGPositif = doc4["positif"];
    SGMeninggal = doc4["meninggal"];
    SGSembuh = doc4["sembuh"];

    Serial.println(SGTanggal);
    Serial.println(SGNegara);
    Serial.println(SGPositif);
    Serial.println(SGMeninggal);
    Serial.println(SGSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode4);
  }

  http4.end(); 

  HTTPClient http5;

  http5.begin("http://dutarayamakmur.net/covid19/latest.php");
  int httpCode5 = http5.GET();

  if (httpCode5 > 0) {

    String payload5 = http5.getString();
    //Serial.println(payload); //print json response
    char json5[500];
    payload5.toCharArray(json5, 500);
    StaticJsonDocument<300> doc5;
    deserializeJson(doc5, json5);
    String ALLTanggal = doc5["update"];
    ALLPositif = doc5["positif"];
    ALLMeninggal = doc5["meninggal"];
    ALLSembuh = doc5["sembuh"];

    Serial.println(ALLTanggal);
    Serial.println(ALLPositif);
    Serial.println(ALLMeninggal);
    Serial.println(ALLSembuh);

  } else {
    Serial.print("ERROR : ");
    Serial.println(httpCode5);
  }

  http5.end();
}

void loop() {
  int remainingTimeBudget = ui.update();

  if (remainingTimeBudget > 0) {
    // You can do some work here
    // Don't do stuff if you are below your
    // time budget.
    delay(remainingTimeBudget);
  }
  Blynk.run();
  timer.run();
  ArduinoOTA.handle();
}
