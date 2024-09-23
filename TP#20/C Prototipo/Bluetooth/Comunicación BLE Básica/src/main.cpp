#include <BLEDevice.h>        // Librería para manejar las funciones BLE en el ESP32
#include <BLEUtils.h>         // Utilidades adicionales para trabajar con BLE
#include <BLEServer.h>        // Librería para crear un servidor BLE
#include <HardwareSerial.h>

// Definimos los UUIDs para identificar el servicio y la característica BLE
#define SERVICE_UUID "12345678-1234-1234-1234-123456789012"         // Identificador único para el servicio BLE
#define CHARACTERISTIC_UUID "87654321-4321-4321-4321-210987654321"  // Identificador único para la característica BLE

const int led = 2;  // Definimos el pin GPIO donde está conectado el LED integrado (GPIO 2)
bool ledState = false;  // Variable para llevar el estado del LED (encendido/apagado)

// Creamos punteros para el servidor BLE y la característica BLE
BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;

// Clase personalizada que manejará lo que sucede cuando un dispositivo se conecta o desconecta del ESP32
class MyServerCallbacks: public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    Serial.println("Dispositivo Conectado.");  // Mensaje al conectar
  }

  void onDisconnect(BLEServer* pServer) {
    Serial.println("Dispositivo Desconectado.");  // Mensaje al desconectar
    pServer->getAdvertising()->start();  // Reiniciamos la publicidad para aceptar nuevas conexiones
    Serial.println("Esperando conexiones...");
  }
};

// Clase para manejar los eventos cuando un dispositivo escribe un valor en la característica BLE
class MyCallbacks: public BLECharacteristicCallbacks {
  void onWrite(BLECharacteristic *pCharacteristic) {
    std::string rxValue = pCharacteristic->getValue();  // Obtenemos el valor recibido
    if (rxValue.length() > 0) {  // Verificamos que haya un valor recibido
      Serial.print("Valor Recibido: ");
      for (int i = 0; i < rxValue.length(); i++)
        Serial.print(rxValue[i]);  // Imprimimos cada carácter del valor recibido

      // Si recibimos "on", encendemos el LED
      if (rxValue == "on") {
        digitalWrite(led, HIGH);  // Encendemos el LED conectado a GPIO 2
        ledState = true;  // Actualizamos el estado del LED
        Serial.println("\nLED Encendido");
      } 
      // Si recibimos "off", apagamos el LED
      else if (rxValue == "off") {
        digitalWrite(led, LOW);  // Apagamos el LED
        ledState = false;  // Actualizamos el estado del LED
        Serial.println("\nLED Apagado");
      }
    }
  }
};

void setup() {
  Serial.begin(115200);  // Iniciamos la comunicación serie
  pinMode(led, OUTPUT);  // Configuramos el pin del LED como salida

  // Inicializamos el dispositivo BLE con el nombre "ESP32_BLE"
  BLEDevice::init("ESP32_BLE");
  pServer = BLEDevice::createServer();  // Creamos el servidor BLE
  pServer->setCallbacks(new MyServerCallbacks());  // Asignamos callbacks para conexión/desconexión

  // Creamos un servicio BLE usando el UUID definido
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Creamos una característica BLE, permitiendo lectura y escritura
  pCharacteristic = pService->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ |   
                      BLECharacteristic::PROPERTY_WRITE    
                    );

  // Asignamos la clase de callbacks para manejar las escrituras en la característica
  pCharacteristic->setCallbacks(new MyCallbacks());

  // Iniciamos el servicio y comenzamos a publicitar
  pService->start();
  pServer->getAdvertising()->start();
  Serial.println("Esperando conexiones BLE...");
}

void loop() {
  
}
