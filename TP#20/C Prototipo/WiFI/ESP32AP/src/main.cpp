#include <WiFi.h> //libreria que vamos a utilizar 

// Definimos el SSID y la contraseña de la red Wi-Fi para ESP32
const char* ssid = "ESP32_AP";       // Nombre de la red WiFi (SSID)
const char* password = "12345678";     // Contraseña de la red WiFi

int ledPin = 2;  // LED integrado en el ESP32

void setup() {
  // Iniciamos  el puerto serial para la depuración
  Serial.begin(115200);

  // Configuramos el pin del LED como salida
  pinMode(ledPin, OUTPUT);


 
  Serial.println("configurando el ESP32 en modo Access Point..."); // Iniciar el ESP32 en modo Access Point
  WiFi.softAP(ssid, password);

  
  IPAddress IP = WiFi.softAPIP();// Mostramos la dirección IP del ESP32 como punto de acceso
  Serial.print("Punto de acceso creado con IP: ");
  Serial.println(IP);
}

void loop() {
 
  int numConnectedDevices = WiFi.softAPgetStationNum(); // Comprobamos cuántos dispositivos están conectados al AP

  
  if (numConnectedDevices > 0) {// Si hay algun dispositivo conectado, encender el LED
    digitalWrite(ledPin, HIGH);  // Encender el LED
    Serial.println("Dispositivo conectado, LED encendido.");
  } else {
    digitalWrite(ledPin, LOW);   // Apagar el LED si no hay dispositivos conectados
    Serial.println("Sin dispositivos conectados, LED apagado.");
  }

  delay(1000); 
}
