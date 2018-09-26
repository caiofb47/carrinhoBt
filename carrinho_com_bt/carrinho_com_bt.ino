#include "DFRobotL298PShield.h" // Biblioteca do motorshield

// Pinos usados 4,5,6,7,5v

//-----------------------BLUETOOTH--------------------------------------
// Configurando conexoes bluetooth H5-05
// EN-M - Se n tem o pulsador n conecta
// 5V - 5V
// GND - GND do Digital (pq ta perto)
// TX - Vai no RX
// RX - Vai no TX
// State - nao usa

//---------------------VARIAVEL DE LEITURA-----------------------------
byte command; // Variavel que recebe o dado do aplicativo
//----------------------MOTORES----------------------------------------

DFRobotL298PShield motors; // Defininto motores com o nome <motors>

// Configurando pino dos motores || Pinos usados 4, 5, 6 e 7
// M1
int E1 = 4;
int motor1 = 5;
// M2
int E2 = 7;
int motor2 = 6;
//---------------------------------------------------------------------

void setup() {
//--------------------Configurando o Bluetooth-------------------------
  Serial.begin(9600);
//--------------------------Inicializando motores----------------------
  motors.init();
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
//---------------------------------------------------------------------


}

void loop() { // Inicio loop

if (Serial.available()){
   command = Serial.read();
   Serial.print(command);

 }
   // Recebe um byte
    if (command == 1){
      
        command = '\0'; // Obriga a saida do if
        
        motors.left_set_pwm(255);  // M2 - Velocidade <255> valor max, valor min <-255>
        //motors.right_set_pwm(255); // M1 - Velocidade <255> valor max, valor min <-255>
       
        delay(2000); // Configurar conforme o deslocamento
        
       //motors.right_set_pwm(0); // M1 - Velocidade <255> valor max, valor min <-255>
       motors.left_set_pwm(0);  // M2 - Velocidade <255> valor max, valor min <-255>
    }


} // FIM loop()
