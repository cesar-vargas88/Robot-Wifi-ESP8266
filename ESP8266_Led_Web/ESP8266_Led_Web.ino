
#include <ESP8266WiFi.h>    
#include <aREST.h>          
#include <aREST_UI.h>       

// Intancia aREST_UI
aREST_UI myRest = aREST_UI();

// Parametros Wifi
const char* ssid = "iPhone de Lenovo";
const char* password = "lcj5rc7ojsaa";

// Puerto para escuhar conexiones entrantes
#define LISTEN_PORT           80

// Inatancia del servidor
WiFiServer server(LISTEN_PORT);


void setup(void)
{  
  Serial.begin(115200);
  
  // Titulo de la página Web
  myRest.title("Robot Wifi CIATEQ");

  // Crea dos botnes ON/OFF asociados a la salida digital 2 del ESP8266
  myRest.button(2);

  // Crea dos botnes ON/OFF asociados a la salida digital 0 del ESP8266
  myRest.button(0);
    
  // Asigna ID del dispositivo
  myRest.set_id("1");
  myRest.set_name("esp8266");
  
  // Se conecta a la red e inicia el servidor
  connectWifi();
}

void loop() 
{
  restLoop();  
}


void connectWifi(){
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  //Espera la conexión
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Imprime que la conexión fue un exito
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  //Indica que el servidor ha iniciado
  server.begin();
  Serial.println("Server started");
}

boolean restLoop()
{
  WiFiClient client = server.available();
  
  if (!client) 
  { 
    return false;
  }

  while(!client.available())
  { //Espera entradas del cliente
    delay(1);
  }

  myRest.handle(client);  //Gestiona las solicitudes del cliente

  return true; 
}

