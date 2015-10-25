int LED_Y = 13;
int LED_R = 13; 
int buzzerPin = 13;
int dot = 150;

char* morseLetters[] = {
  /* A */ ".-", 
  /* B */ "-...", 
  /* C */"-.-.", 
  /* D */"-..", 
  /* E */".", 
  /* F*/"..-.", 
  /* G */"--.", 
  /* H */"....", 
  /* I */"..",
  /* J */".---", 
  /* K */"-.-", 
  /* L */".-..",
  /* M */"--", 
  /* N */"-.", 
  /* O */"---", 
  /* P */".--.", 
  /* Q */"--.-", 
  /* R */".-.",
  /* S */"...", 
  /* T */"-", 
  /* U */"..-", 
  /* V */"...-", 
  /* W */".--", 
  /* X */"-..-", 
  /* Y */"-.--", 
  /* Z */"--.." 
  };
char* morseNumbers[] = {
  /* 0 */"-----",
  /* 1 */".----",
  /* 2 */"..---",
  /* 3 */"...--",
  /* 4 */"....-",
  /* 5 */".....",
  /* 6 */"-....",
  /* 7 */"--...",
  /* 8 */"---..",
  /* 9 */"----."
  };

void setup()                
{
  pinMode(LED_Y, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop()                   
{
  char info;
  if (Serial.available() > 0) {
    info = Serial.read();
    /* && AND , || OR */
    if (info >= 'a' && info <= 'z') {
      //We can use use this by the fact that each ASCII code is a number
      letterId(morseLetters[info - 'a'], LED_Y);
    }
    else if(info >= 'A' && info <= 'Z') {
      letterId(morseLetters[info - 'A'], LED_Y);
    }
    else if(info >= '0' && info <= '9') {
      letterId(morseNumbers[info - '0'], LED_R);
    }
    else if(info == ' ') {
      delay(dot * 4); 
    }
  }
}

void letterId(char* character, int led_pin) {
  int i = 0;
   while(character[i] != '\0') {
    output(character[i], led_pin);
    i++;
  }
  delay(dot * 3);
}

void output(char ID, int led_pin) {
  digitalWrite(led_pin, HIGH);
  digitalWrite(buzzerPin,HIGH);
  if (ID == '.') {
    delay(dot);          
  }
  else {
    delay(dot * 3);          
  }
  digitalWrite(led_pin, LOW);
  digitalWrite(buzzerPin,LOW); 
  delay(dot);
}
