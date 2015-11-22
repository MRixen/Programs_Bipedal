/* Serial device defines for dxl bus */
#define DXL_BUS_SERIAL1 1  //Dynamixel on Serial1(USART1)  <-OpenCM9.04
#define DXL_BUS_SERIAL2 2  //Dynamixel on Serial2(USART2)  <-LN101,BT210
#define DXL_BUS_SERIAL3 3  //Dynamixel on Serial3(USART3)  <-OpenCM 485EXP
/* Dynamixel ID defines */
#define ID_NUM 1
/* Control table defines */
#define GOAL_POSITION 30

int inValue;
int multiplicator;
int sollPosition;

Dynamixel Dxl(DXL_BUS_SERIAL3);

void setup(){
  //You can attach your serialUSB interrupt
  //or, also detach the interrupt by detachInterrupt(void) method
  SerialUSB.attachInterrupt(usbInterrupt);
  pinMode(BOARD_LED_PIN, OUTPUT);  //toggleLED_Pin_Out

  // Dynamixel 2.0 Baudrate -> 0: 9600, 1: 57600, 2: 115200, 3: 1Mbps 
  Dxl.begin(3);
  Dxl.jointMode(ID_NUM); //jointMode() is to use position mod
}

//USB max packet data is maximum 64byte, so nCount can not exceeds 64 bytes
void usbInterrupt(byte* bufferData, byte dataLength){
  // Read incoming data from buffer
  
  multiplicator = 1;
  sollPosition = 0;
    for(unsigned int i=0; i < dataLength-1;i++){
      multiplicator = multiplicator*10;
  }
  for(unsigned int i=0; i < dataLength;i++){
    inValue = (bufferData[i])-48;   
    sollPosition = sollPosition+(inValue*multiplicator);
    multiplicator = multiplicator/10;
  }
  Dxl.writeWord(ID_NUM, GOAL_POSITION, sollPosition);
}

void loop(){
  delay(100);         
}


