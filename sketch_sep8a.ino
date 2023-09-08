#define BLYNK_TEMPLATE_ID "TMPL3zyYcvEPy"
#define BLYNK_TEMPLATE_NAME "DHT IOT Prakat"
#define BLYNK_AUTH_TOKEN "Bm7ax8lfC0tzNzwm9IviCoPvGZ09zvyp"


#include<DHT.h>
#include<BlynkSimpleEsp8266.h>

#define DHTPIN 4//Data pin is connected to D2 on E
#define DHTTYPE DHT11//Name the sensor as an object


char auth[]="Bm7ax8lfC0tzNzwm9IviCoPvGZ09zvyp";
char ssid[]="wifi";
char pass[]="prakat123";
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  //github
   Serial.begin(9600);
   Serial.println("DHT Test Successful");
   Blynk.begin(auth,ssid,pass);
   Serial.println("Blynk Connected Successfully");
   dht.begin();
   
}

void loop() {
  // put your main code here, to run repeatedly:
   float h=dht.readHumidity();               
   float t =dht.readTemperature();
   float f =dht.readTemperature(true);
    if (isnan(h) || isnan(t) || isnan(f))

   {
    Serial.println("Soemthing is not working as integer ");
     return ;
   }
  
  Serial.println("Humidity:");
  Serial.print(h);
  Serial.print("%");
  Serial.println("Temperature");
  Serial.print(t);
  Serial.print("degrees celsius");
  Blynk.virtualWrite(V0,t);
  Blynk.virtualWrite(V1,h);

  delay(1000);


}
