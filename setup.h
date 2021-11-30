// Motor Driver Standby Pin (Drive to HIGH to make motor driver function)
#define STBY 5

// Motor A for rod/chain
Encoder chainEncoder(4, 5);
#define pwmChain 3
#define chainIn1 5
#define chainIn2 6

// Motor for string
Encoder stringEncoder(10, 11);
#define pwmString 9
#define stringIn1 12
#define stringIn2 13

pinMode(pwmChain, OUTPUT);
pinMode(chainIn1, OUTPUT);
pinMode(chainIn2, OUTPUT);
pinMode(pwmString, OUTPUT);
pinMode(stringIn1, OUTPUT);
pinMode(stringIn2, OUTPUT);  

// Pull the chain/rod in one direction until the motor cannot pull it anymore

void ends(string chain_or_string, string back_or_forth) {
    if(chain_or_string == "chain") {
        if(back_or_forth == "back") {
            analogWrite(pwmChain, 40);
            digitalWrite(chainIn1, HIGH);
            digitalWrite(chainIn2, LOW);
        } else {
            analogWrite(pwmChain, 40);
            digitalWrite(chainIn1, LOW);
            digitalWrite(chainIn2, HIGH);
        }
    } else {
        if(back_or_forth == "back") {
            analogWrite(pwmString, 40);
            digitalWrite(stringIn1, HIGH);
            digitalWrite(stringIn2, LOW);
        } else {
            analogWrite(pwmString, 40);
            digitalWrite(stringIn1, LOW);
            digitalWrite(stringIn2, HIGH);
        }
    }

    oldEnc = chainEncoder.read();
    delay(100); \\ 0.1 seconds
    currentEnc = chainEncoder.read();

    if(oldEnc - currentEnc <= 5) {
        analogWrite(pwmString, 0);
        analogWrite(pwmChain, 0)
        digitalWrite(stringIn1, LOW);
        digitalWrite(stringIn2, LOW);
        digitalWrite(chainIn1, LOW);
        digitalWrite(chainIn2, LOW);
    }
  }
}

void centralizeChain(int furthestBackwards, int furthestForward) {
  
}