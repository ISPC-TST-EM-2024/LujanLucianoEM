![alt text](/Recursos/visuales/caratula.png)
# Tecnicatura Superior en Telecomunicaciones
### Profesor: C.Gonzalo Vera   
### Alumno: Luciano Lujan

### Informacion General
***
Extructura pedida por el profesor  
En la carpeta ***"A Requisitos":*** se encuentran los requisitos de la tarea.   
En la carpeta ***"B Investigación":*** se encuentran las investigaciones sobre la tarea pedida.  
En la carpeta ***"C Prototipo":*** se encuentran las primera inplemntaciones de las 2 carpetas anteriores.   
En la carpeta ***"D presentación":*** se encuentran la preecentacion de trabajo concluido.  

# TP#20. Trabajo Practico
## Objetivos:
- Familiarizarse con las tecnologías de los módulos de comunicación incorporados en el ESP32.
- Conocer las librerías asociadas a cada modulo de comunicación para el ESP32 incluidas en el framework Arduino.

***Realizar los siguientes ejercicios según se solicita a continuación, dejar los registros de desarrollo en el repositorio personal de la materia, con la estructura ABP de trabajo habitual.***

## ¿Qué es BLE (Bluetooth Low Energy)?

BLE es una versión optimizada de Bluetooth tradicional que está diseñada para consumir mucha menos energía. Se usa principalmente en aplicaciones de IoT, como sensores y dispositivos que necesitan estar conectados todo el tiempo, pero sin usar demasiada batería.  

Librerías que usamos:

***BLEDevice.h:*** Esta es la librería principal para manejar el dispositivo BLE.
***BLEServer.h:*** Se usa para crear y manejar el servidor BLE en el ESP32.
***BLECharacteristic.h:*** Define características BLE, que son como variables que otros dispositivos pueden leer o escribir.
¿Cómo funciona?

Primero, configuramos el ESP32 como un servidor BLE, luego definimos un UUID (Identificador Único Universal) para nuestro servicio y una característica que otros dispositivos podrán leer y escribir.

# Comunicación Serial con Bluetooth Clásico 

¿Qué es Bluetooth Clásico (SPP)?

El perfil de puerto serie (SPP) permite una comunicación directa y constante entre el ESP32 y otros dispositivos, como un teléfono o una PC, usando Bluetooth clásico. Se usa cuando necesitas transferir más datos o tener una conexión estable y continua.

Librerías que usamos:

***BluetoothSerial.h:*** Proporciona las herramientas necesarias para que el ESP32 funcione como un dispositivo Bluetooth Serial.

# Crear un Servidor Web en el ESP32 

¿Qué es un servidor web en ESP32?

El ESP32 puede actuar como un pequeño servidor web. Esto te permite controlarlo desde cualquier navegador web, ideal para interfaces gráficas o control remoto.

Librerías que usamos:

***WiFi.h:*** Maneja la conexión Wi-Fi del ESP32.
***WebServer.h:*** Permite crear un servidor web que puede manejar múltiples rutas.

# ESP32 en Modo Punto de Acceso (AP Mode)

¿Qué es el modo AP en ESP32?

El modo Punto de Acceso (AP) permite que el ESP32 cree su propia red Wi-Fi. Esto es útil cuando no tienes una red Wi-Fi disponible o si quieres conectar directamente dispositivos a tu ESP32.

Librerías que usamos:

***WiFi.h:*** La misma librería que usamos para conectarnos a una red, pero en este caso configuramos el ESP32 para crear una.