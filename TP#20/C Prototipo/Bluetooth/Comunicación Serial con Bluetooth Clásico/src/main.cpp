#include "BluetoothSerial.h"  // Incluir la librería para Bluetooth

BluetoothSerial SerialBT;  // Crear un objeto BluetoothSerial

void setup() {
  Serial.begin(115200);  // Iniciar comunicación serial para el monitor
  SerialBT.begin("ESP32_BT");  // Nombre Bluetooth del ESP32
  Serial.println("Bluetooth iniciado,");
}

void loop() {
  // Si se recibe un dato por Bluetooth, se envía al Monitor Serial
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();  // Leer el dato entrante
    Serial.print("Recibido por Bluetooth: ");
    Serial.println(incomingChar);  // Mostrar datos en el monitor serie
  }

  // Si se escribe un dato en el Monitor Serie, se envía por Bluetooth
  if (Serial.available()) {
    char outgoingChar = Serial.read();  // Leer el dato entrante
    SerialBT.write(outgoingChar);  // Enviar el dato por Bluetooth
    Serial.print("Enviado por Bluetooth: ");
    Serial.println(outgoingChar);  // Mostrar lo enviado en el Monitor Serie
  }
}
