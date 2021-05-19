//this is the code written by PATAN MUSTHAKHEEM KHAN ON 10/02/2018 AT 4:30 PM

//This code is public and can edit by anyone

//lets start

#include <ESP8266WiFi.h> //include esp8266 wifi library

 

const char* ssid = "Your wifi name"; //edit to your wifi ssid

const char* password = "your wifi pswd"; //edit to your wifi pswd

int R1=D2; // GPIO13 or for NodeMCU you can directly write D7 

int R2=D3;

int R3=D4;

int R4=D5;

WiFiServer server(80); // Creates a server that listens for incoming connections on the specified port, here in this case port is 80.

 

void setup() {

  Serial.begin(115200);

  delay(10);

 

  pinMode(R1, OUTPUT);

  pinMode(R2, OUTPUT);

  pinMode(R3, OUTPUT);

  pinMode(R4, OUTPUT);

  

  digitalWrite(R1,HIGH);

  digitalWrite(R2,HIGH);

  digitalWrite(R3,HIGH);

  digitalWrite(R4,HIGH);

  

 

  // Connect to WiFi network

  Serial.println();

  Serial.println();

  Serial.print("Connecting to ");

  Serial.println(ssid);

 

  WiFi.begin(ssid, password);

 

  while (WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.println("WiFi connected");

 

  // Start the server

  server.begin();

  Serial.println("Server started");//start the server with port 20

 

  // Print the IP address

  Serial.print("Use this URL to connect: ");

  Serial.print("http://");

  Serial.print(WiFi.localIP()); //Gets the WiFi shield's IP address and Print the IP address of serial monitor

  Serial.println("/");

 

}

 

void loop() {

  // Check if a client has connected

  WiFiClient client = server.available();

  if (!client) {

    return;

  }

 

  // Wait until the client sends some data

  Serial.println("new client");

  while(!client.available()){

    delay(1);

  }

 

  // Read the first line of the request

  String request = client.readStringUntil('\r');

  Serial.println(request);

  client.flush();

 

  // Match the request

 

 

  if (request.indexOf("/LIGHT ON") != -1)  {

    digitalWrite(R1,LOW);

     

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("LIGHT IS ON");

      client.println("</html>");

      client.stop();

      delay(1);

  }

  if (request.indexOf("/LIGHT OFF") != -1)  {

    digitalWrite(R1, HIGH);

   

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("LIGHT IS OFF");

      client.println("</html>");

      client.stop();

      delay(1);

  }

  if (request.indexOf("/FAN ON") != -1)  {

    digitalWrite(R2,LOW);

    

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("FAN IS ON");

      client.println("</html>");

      client.stop();

      delay(1);

  }

  if (request.indexOf("/FAN OFF") != -1)  {

    digitalWrite(R2, HIGH);

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("FAN IS OFF");

      client.println("</html>");

      client.stop();

      delay(1);

  }

  if (request.indexOf("/COMPUTER ON") != -1)  {

    digitalWrite(R3,LOW);

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("COMPUTER is ON");

      client.println("</html>");

      client.stop();

      delay(1);

  }

  if (request.indexOf("/COMPUTER OFF") != -1)  {

    digitalWrite(R3, HIGH);

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("COMPUTER is OFF");

      client.println("</html>");

      client.stop();

      delay(1);

  }

  if (request.indexOf("/TV ON") != -1)  {

    digitalWrite(R4,LOW);

    

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("TV is ON");

      client.println("</html>");

      client.stop();

      delay(1);

  }

  if (request.indexOf("/TV OFF") != -1)  {

    digitalWrite(R4, HIGH);

      client.println("HTTP/1.1 200 OK");

      client.println("Content-Type: text/html");

      client.println("");

      client.println("<!DOCTYPE HTML>");

      client.println("<html>");

      client.println("TV is OFF");

      client.println("</html>");

      client.stop();

      delay(1);

  }

}

© 2021 GitHub, Inc.

Terms

Privacy

Security

Status

Docs

Contact GitHub

Pricing

API

Training

Blog

About

