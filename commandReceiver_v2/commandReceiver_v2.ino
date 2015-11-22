#define DXL_BUS_SERIAL3 3
#define ID_NUM 1
#define DIM_ID_ARRAY 3
#define DIM_CMD_ARRAY 2
#define DIM_VAL_ARRAY 4

Dynamixel Dxl(DXL_BUS_SERIAL3);
  int id;
  int command;
  int sollPosition;

void setup() {
  Dxl.begin(3);
  Dxl.jointMode(ID_NUM);
}

void loop() {
   id = getValue();
   command = getValue();
   sollPosition = getValue();
   if((id != -1) & (command != -1) & (sollPosition != -1)) Dxl.writeWord(id, command, sollPosition);
   delay(100);
}

int getValue(){
  int inValue;
  int cntr;
  int motorId[DIM_ID_ARRAY];
  int command[DIM_CMD_ARRAY];
  int value[DIM_VAL_ARRAY];
   
  // Check if there is something to receive
  cntr = SerialUSB.available();  
  if(cntr>0){
    // Read the first parameter to the first semicolon
  for(unsigned int i=0; i < cntr;i++){
      inValue = (SerialUSB.read())-48;
      if(inValue != 11) {
        motorId[i] = inValue; 
      }
      else return calcValue(motorId, i,calcMult(i));;
    }
    }
    else return -1;
  } 

// Caclulate the multiplicator
int calcMult(int steps){
    int multiplicator = 1;
    
    for(unsigned int i=0; i < steps-1;i++){
      multiplicator = multiplicator*10;
   }
   return multiplicator;
}

// Calculate the value
int calcValue(int data[], int dim, int factor){
  int retVal = 0;

    for(unsigned int i=0; i <= dim-1;i++){
      retVal = retVal+(data[i]*factor);
      factor = factor/10;
   }  
   return retVal;
}

