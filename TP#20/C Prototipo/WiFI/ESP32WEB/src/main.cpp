#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "casa";        // Nombre dela red Wi-Fi
const char* password = "12345678"; // Contraseña del Wi-Fi


WebServer server(80);// Configuración del servidor web

// Pin donde está conectado el LED (puede ser el LED integrado en el ESP32)
const int ledPin = 2;  // GPIO 2 (LED integrado)
bool ledEncendido = false;  // Estado inicial del LED (apagado)


String paginaHTML() {// Función para generar la página web con el botón de alternar
  String estadoLED = ledEncendido ? "Encendido" : "Apagado";
  String html = "<html><head><title>Control del LED</title></head><body style='text-align:center;'>";
  html += "<h1>Control del LED</h1>";
  html += "<p>Estado actual del LED: " + estadoLED + "</p>";
  html += "<p><a href=\"/toggle\"><button style='font-size:24px; padding:10px 20px;'>Alternar LED</button></a></p>";
  html += "</body></html>";
  return html;
}


void LED() {
  ledEncendido = !ledEncendido;  
  digitalWrite(ledPin, ledEncendido ? HIGH : LOW);  // Enciende o apaga el LED
  server.send(200, "text/html", paginaHTML());  // Enviar la página web actualizada al cliente
}

void setup() {

  Serial.begin(115200);  // Inicializar el monitor serial

  
  pinMode(ledPin, OUTPUT);// aonfigurar el pin del LED como salida
  digitalWrite(ledPin, LOW);  //LED estado de apagado al iniciar

  
  Serial.println("Conectando a WiFi..");// Conectarse a la red WiFi
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConectado a la red Wi-Fi.");// Inprime que esta conectado ala red
  Serial.print("Dirección IP: ");
  Serial.println(WiFi.localIP());


  server.on("/", []() {  // Configurar las rutas del servidor web
    server.send(200, "text/html", paginaHTML());  // Enviar la página principal
  });
  server.on("/toggle", LED);  // Ruta para alternar el LED


  server.begin();  // Iniciar el servidor web
  Serial.println("Servidor web iniciado.");
}

void loop() {
 
  server.handleClient();  //peticiones HTTP entrantes
}
